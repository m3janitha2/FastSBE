#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    template <typename... T>
    std::size_t offset()
    {
        static constexpr const std::size_t field_offset{8};
        return (field_offset + ... + sizeof(T));
    }

    TEST(composite_enums, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.party_id_source_size(), 1);
        EXPECT_EQ(composite.party_id_source_offset(), offset());
        EXPECT_EQ(composite.party_id_source_name(), "PartyIDSource");
        EXPECT_EQ(composite.party_id_source_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(composite_enums, field_values)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(composite.party_id_source(), PartyIDSourceEnum::Value::BIC);

        composite.set_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(composite.party_id_source(), PartyIDSourceEnum::Value::Proprietary);

        composite.set_party_id_source(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(composite.party_id_source(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(composite_enums, optional_field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.optional_party_id_source_size(), 1);
        EXPECT_EQ(composite.optional_party_id_source_offset(), (offset<PartyIDSourceEnum>()));
        EXPECT_EQ(composite.optional_party_id_source_name(), "OptionalPartyIDSource");
        EXPECT_EQ(composite.optional_party_id_source_null_value(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(composite_enums, optional_field_values)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.optional_party_id_source(), PartyIDSourceEnum::Value::nullValue);

        composite.set_optional_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_EQ(composite.optional_party_id_source(), PartyIDSourceEnum::Value::BIC);

        composite.set_optional_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        EXPECT_EQ(composite.optional_party_id_source(), PartyIDSourceEnum::Value::Proprietary);

        composite.set_optional_party_id_source(PartyIDSourceEnum::Value::nullValue);
        EXPECT_EQ(composite.optional_party_id_source(), PartyIDSourceEnum::Value::nullValue);
    }

    TEST(composite_enums, const_field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.const_party_id_source_size(), 0);
        EXPECT_EQ(composite.const_party_id_source_offset(), (offset<PartyIDSourceEnum, PartyIDSourceEnum>()));
        EXPECT_EQ(composite.const_party_id_source_name(), "ConstPartyIDSource");
    }

    TEST(composite_enums, const_field_values)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.const_party_id_source(), PartyIDSourceEnum::Value::Proprietary);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
