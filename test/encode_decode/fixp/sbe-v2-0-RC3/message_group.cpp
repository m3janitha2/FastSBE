#include <cstdint>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include <NewOrderSingle.h>

// Repeating-group accessor tests: Append, num_in_group, get(i) entry field
// round-trip, iteration, and multiple independent groups. NewOrderSingle's
// groups live in the wire buffer, so reinterpret a message over a byte array.
namespace sbetool
{
    TEST(message_group, append_sets_num_in_group)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &grp = msg.AppendPartiesGrp(3);
        EXPECT_EQ(grp.num_in_group(), 3u);
        EXPECT_EQ(msg.parties_grp().num_in_group(), 3u);
    }

    TEST(message_group, append_zero_entries)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &grp = msg.AppendPartiesGrp(0);
        EXPECT_EQ(grp.num_in_group(), 0u);
    }

    TEST(message_group, entry_field_round_trip)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &grp = msg.AppendPartiesGrp(2);

        grp.get(0)
            .set_party_id("AAA", 3)
            .set_party_id_source(PartyIDSourceEnum::Value::BIC)
            .set_party_role(PartyRoleEnum::Value::ClientID);
        grp.get(1)
            .set_party_id("BBBBBBBB", 8)
            .set_party_id_source(PartyIDSourceEnum::Value::Proprietary)
            .set_party_role(PartyRoleEnum::Value::ExecutingFirm);

        const auto &read = msg.parties_grp();
        EXPECT_EQ(read.get(0).party_id_string(), "AAA");
        EXPECT_EQ(read.get(0).party_id_source(), PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(read.get(0).party_role(), PartyRoleEnum::Value::ClientID);
        EXPECT_EQ(read.get(1).party_id_string(), "BBBBBBBB"); // full width, no overrun
        EXPECT_EQ(read.get(1).party_role(), PartyRoleEnum::Value::ExecutingFirm);
    }

    TEST(message_group, index_iteration_covers_all_entries)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &grp = msg.AppendPartiesGrp(4);
        for (std::uint16_t i = 0; i < grp.num_in_group(); ++i)
        {
            grp.get(i).set_party_role(PartyRoleEnum::Value::ClientID);
        }

        const auto &read = msg.parties_grp();
        std::uint16_t count = 0;
        for (std::uint16_t i = 0; i < read.num_in_group(); ++i)
        {
            EXPECT_EQ(read.get(i).party_role(), PartyRoleEnum::Value::ClientID);
            ++count;
        }
        EXPECT_EQ(count, 4u);
    }

    TEST(message_group, multiple_groups_independent)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);

        auto &parties = msg.AppendPartiesGrp(2);
        parties.get(0).set_party_id("P0", 2);
        parties.get(1).set_party_id("P1", 2);

        // AllocsGrp is appended after PartiesGrp in the buffer; both stay readable.
        auto &allocs = msg.AppendAllocsGrp(1);
        allocs.get(0).set_alloc_account("ACC", 3);

        EXPECT_EQ(msg.parties_grp().num_in_group(), 2u);
        EXPECT_EQ(msg.allocs_grp().num_in_group(), 1u);
        EXPECT_EQ(msg.parties_grp().get(1).party_id_string(), "P1");
        EXPECT_EQ(msg.allocs_grp().get(0).alloc_account_string(), "ACC");
    }

    // ----- rendering: group operator<< emits a JSON array of objects -----
    TEST(message_group, ostream_renders_array_of_objects)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &grp = msg.AppendPartiesGrp(2);
        grp.get(0).set_party_id("P0", 2).set_party_id_source(PartyIDSourceEnum::Value::BIC);
        grp.get(1).set_party_id("P1", 2).set_party_id_source(PartyIDSourceEnum::Value::Proprietary);

        std::ostringstream os;
        os << msg.parties_grp();
        const auto json = os.str();

        EXPECT_EQ(json.front(), '[');
        EXPECT_EQ(json.back(), ']');
        EXPECT_NE(json.find("{\"PartyID\": \"P0\", \"PartyIDSource\": \"BIC\""), std::string::npos);
        EXPECT_NE(json.find("}, {\"PartyID\": \"P1\""), std::string::npos); // entry separator
    }

    TEST(message_group, ostream_empty_group_renders_empty_array)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        msg.AppendPartiesGrp(0);

        std::ostringstream os;
        os << msg.parties_grp();
        EXPECT_EQ(os.str(), "[]");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
