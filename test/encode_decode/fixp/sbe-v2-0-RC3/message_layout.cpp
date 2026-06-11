#include <gtest/gtest.h>

#include <NewOrderSingle.h>
#include <TestMessage.h>

// Layout tests: block length, encoded size, and that field offsets are honored -
// including an explicit offset gap that the generator must satisfy with padding.
namespace sbetool
{
    TEST(message_layout, block_length_matches_schema)
    {
        EXPECT_EQ(TestMessage<>::block_length(), 111u);
        EXPECT_EQ(NewOrderSingle<>::block_length(), 54u);
    }

    TEST(message_layout, fixed_message_encoded_size_equals_block_length)
    {
        // TestMessage has no repeating groups or variable-length data, so its
        // encoded size is exactly the fixed block length.
        TestMessage msg{};
        EXPECT_EQ(msg.encoded_size(), TestMessage<>::block_length());
        EXPECT_EQ(msg.encoded_size(), 111u);
    }

    TEST(message_layout, field_offsets_are_honored)
    {
        TestMessage msg{};
        // ClOrdId sits right after the 50-byte TestComposite at offset 0.
        EXPECT_EQ(msg.cl_ord_id_offset(), 50u);
        EXPECT_EQ(msg.order_qty_u64_offset(), 61u);
        EXPECT_EQ(msg.event_char_offset(), 99u);
        EXPECT_EQ(msg.event_set_offset(), 100u);
    }

    TEST(message_layout, explicit_offset_gap_is_padded)
    {
        TestMessage msg{};
        // GapField declares offset 110 with a 9-byte gap after EventSet (100, 1);
        // the generator emits pre-padding so the field lands at the declared offset.
        EXPECT_EQ(msg.gap_field_offset(), 110u);
        EXPECT_EQ(msg.gap_field_offset() + msg.gap_field_size(), TestMessage<>::block_length());
    }

    TEST(message_layout, group_block_length_matches_schema)
    {
        char buffer[256]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &parties = msg.AppendPartiesGrp(1);
        EXPECT_EQ(parties.block_length(), 20u); // PartiesGrp blockLength=20
    }

    // Group offsets are relative to the variable-length section, which begins
    // directly after the fixed block: the first group's offset is 0, and its
    // wire position from the message start is exactly block_length().
    TEST(message_layout, first_group_sits_after_fixed_block)
    {
        char buffer[256]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        EXPECT_EQ(msg.parties_grp_offset(), 0u);
        const auto *group_pos = reinterpret_cast<const char *>(&msg.parties_grp());
        EXPECT_EQ(group_pos - buffer, NewOrderSingle<>::block_length()); // 54
    }

    TEST(message_layout, second_group_sits_after_first_group_data)
    {
        char buffer[2048]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &parties = msg.AppendPartiesGrp(2);
        // groupSizeEncoding header = 4 x uint16 (blockLength, numInGroup,
        // numGroups, numVarDataFields) = 8 bytes, then 2 entries of 20.
        EXPECT_EQ(msg.allocs_grp_offset(),
                  msg.parties_grp_offset() + 8 + 2 * parties.block_length());
        const auto *first = reinterpret_cast<const char *>(&msg.parties_grp());
        const auto *second = reinterpret_cast<const char *>(&msg.allocs_grp());
        EXPECT_EQ(second - first, 8 + 2 * static_cast<std::ptrdiff_t>(parties.block_length()));
    }

    TEST(message_layout, group_entry_field_offsets_match_schema)
    {
        // Entry is private inside the group class; reach its static offset
        // accessors through an entry reference.
        char buffer[256]{};
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        auto &entry = msg.AppendPartiesGrp(1).get(0);
        EXPECT_EQ(entry.party_id_offset(), 0u);
        EXPECT_EQ(entry.party_id_source_offset(), 8u);
        EXPECT_EQ(entry.party_role_offset(), 9u);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
