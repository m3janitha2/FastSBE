#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    template <typename... T>
    std::size_t offset()
    {
        static constexpr const std::size_t field_offset{58}; // after the 50-byte TestComposite + ClOrdId[8]
        return (field_offset + ... + sizeof(T));
    }

    TEST(message_enum, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.party_id_source_size(), 1);
        EXPECT_EQ(msg.party_id_source_offset(), offset());
        EXPECT_EQ(msg.party_id_source_id(), 447);
        EXPECT_EQ(msg.party_id_source_name(), "PartyIDSource");
        EXPECT_EQ(msg.party_id_source_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(message_enum, field_values)
    {
        TestMessage msg{};
        msg.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::BIC);
        msg.set_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_party_id_source(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(message_enum, to_string)
    {
        TestMessage msg{};
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::BIC), "BIC");
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::Proprietary), "Proprietary");
        EXPECT_EQ(PartyIDSourceEnum::to_string(PartyIDSourceEnum::Value::nullValue), "nullValue");
    }

    // a wire value outside the declared choices must fall back to "Invalid"
    // (never a null pointer or garbage) - e.g. a default-constructed PartyRole
    // is 0, which PartyRoleEnum does not define.
    TEST(message_enum, to_string_unknown_value_is_invalid)
    {
        EXPECT_EQ(PartyIDSourceEnum::to_string(static_cast<PartyIDSourceEnum::Value>('X')), "Invalid");
        EXPECT_EQ(PartyRoleEnum::to_string(static_cast<PartyRoleEnum::Value>(0)), "Invalid");
    }

    TEST(message_enum, optional_field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.optional_party_id_source_size(), 1);
        EXPECT_EQ(msg.optional_party_id_source_offset(),(offset<PartyIDSourceEnum>()));
        EXPECT_EQ(msg.optional_party_id_source_id(), 448);
        EXPECT_EQ(msg.optional_party_id_source_name(), "OptionalPartyIDSource");
        EXPECT_EQ(msg.optional_party_id_source_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(message_enum, optional_field_values)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.optional_party_id_source(), PartyIDSourceEnum::Value::nullValue);

        msg.set_optional_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.optional_party_id_source(), PartyIDSourceEnum::Value::BIC);
        msg.set_optional_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.optional_party_id_source(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_optional_party_id_source(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.optional_party_id_source(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(message_enum, const_field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.const_party_id_source_size(), 0);
        EXPECT_EQ(msg.const_party_id_source_offset(), (offset<PartyIDSourceEnum, PartyIDSourceEnum>()));
        EXPECT_EQ(msg.const_party_id_source_id(), 449);
        EXPECT_EQ(msg.const_party_id_source_name(), "ConstPartyIDSource");
    }

    TEST(message_enum, const_field_values)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.const_party_id_source(), PartyIDSourceEnum::Value::Proprietary);
    } 

    TEST(message_numeric_enum, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.party_role_size(), 1);
        EXPECT_EQ(msg.party_role_offset(), (offset<PartyIDSourceEnum, PartyIDSourceEnum>()));
        EXPECT_EQ(msg.party_role_id(), 452);
        EXPECT_EQ(msg.party_role_name(), "PartyRole");
        EXPECT_EQ(msg.party_role_null_value(), PartyRoleEnum::Value::nullValue);
    }

    TEST(message_numeric_enum, field_values)
    {
        TestMessage msg{};

        msg.set_party_role(PartyRoleEnum::Value::ExecutingFirm);
        EXPECT_EQ(msg.party_role(), PartyRoleEnum::Value::ExecutingFirm);
        msg.set_party_role(PartyRoleEnum::Value::BrokerOfCredit);
        EXPECT_EQ(msg.party_role(), PartyRoleEnum::Value::BrokerOfCredit);
        msg.set_party_role(PartyRoleEnum::Value::ClientID);
        EXPECT_EQ(msg.party_role(), PartyRoleEnum::Value::ClientID);
        msg.set_party_role(PartyRoleEnum::Value::nullValue);
        EXPECT_EQ(msg.party_role(), PartyRoleEnum::Value::nullValue);
    }       
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
