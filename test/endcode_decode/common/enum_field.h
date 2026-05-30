#include <iostream>

#include <gtest/gtest.h>

namespace sbetool
{
    template <typename Msg>
    void validate_field_info()
    {
        Msg msg{};
        EXPECT_EQ(msg.party_id_source_size(), 1);
        EXPECT_EQ(msg.party_id_source_offset(), 16);
        EXPECT_EQ(msg.party_id_source_id(), 447);
        EXPECT_EQ(msg.party_id_source_name(), "PartyIDSource");
    }

    template <typename Msg>
    void validate_field_values(Msg &msg)
    {
        msg.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::BIC);
        msg.set_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::Proprietary);
        msg.set_party_id_source(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::nullValue);
    }

    template <typename Msg>
    void validate_optional_field_info()
    {
        Msg msg{};
        EXPECT_EQ(msg.optional_party_id_source_size(), 1);
        EXPECT_EQ(msg.optional_party_id_source_offset(), 17);
        EXPECT_EQ(msg.optional_party_id_source_id(), 448);
        EXPECT_EQ(msg.optional_party_id_source_name(), "OptionalPartyIDSource");
    }

    template <typename Msg>
    void optional_field_values()
    {
        Msg msg{};
        EXPECT_EQ(msg.party_id_source(), PartyIDSourceEnum::Value::nullValue);

        validate_field_values(msg);
    }
}