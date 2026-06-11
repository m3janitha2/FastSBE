#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    // EventSet (OrderEventSet, uint8) is the last member of TestComposite, after
    // PartyChar. choices: New=bit0, Filled=bit1, Cancelled=bit2.
    using Choice = OrderEventSet::Choice;
    using set_value_type = OrderEventSet::value_type;

    static constexpr const std::size_t field_offset{49}; // after PartyChar (offset 48, size 1)

    TEST(composite_set, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.event_set_size(), sizeof(set_value_type));
        EXPECT_EQ(composite.event_set_offset(), field_offset);
        EXPECT_EQ(composite.event_set_name(), "EventSet");
    }

    TEST(composite_set, default_is_empty)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.event_set(), static_cast<set_value_type>(0));
        EXPECT_FALSE(composite.event_set(Choice::New));
        EXPECT_FALSE(composite.event_set(Choice::Filled));
        EXPECT_FALSE(composite.event_set(Choice::Cancelled));
    }

    TEST(composite_set, set_and_test_choice)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_event_set(Choice::New);
        EXPECT_TRUE(composite.event_set(Choice::New));
        EXPECT_FALSE(composite.event_set(Choice::Filled));

        composite.set_event_set(Choice::Filled);
        EXPECT_TRUE(composite.event_set(Choice::New));
        EXPECT_TRUE(composite.event_set(Choice::Filled));
        EXPECT_FALSE(composite.event_set(Choice::Cancelled));
    }

    TEST(composite_set, clear_choice)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_event_set(Choice::New);
        composite.set_event_set(Choice::Filled);
        composite.clear_event_set(Choice::New);

        EXPECT_FALSE(composite.event_set(Choice::New));
        EXPECT_TRUE(composite.event_set(Choice::Filled));
    }

    TEST(composite_set, raw_value_round_trip)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        const auto raw = static_cast<set_value_type>(
            static_cast<set_value_type>(Choice::New) |
            static_cast<set_value_type>(Choice::Cancelled));
        composite.set_event_set(raw);

        EXPECT_EQ(composite.event_set(), raw);
        EXPECT_TRUE(composite.event_set(Choice::New));
        EXPECT_FALSE(composite.event_set(Choice::Filled));
        EXPECT_TRUE(composite.event_set(Choice::Cancelled));
    }

    TEST(composite_set, choice_or_operator)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_event_set(Choice::New | Choice::Filled);
        EXPECT_TRUE(composite.event_set(Choice::New));
        EXPECT_TRUE(composite.event_set(Choice::Filled));
        EXPECT_FALSE(composite.event_set(Choice::Cancelled));
    }

    TEST(composite_set, to_string_json_array)
    {
        EXPECT_EQ(OrderEventSet::to_string(static_cast<set_value_type>(0)), "[]");

        const auto combined = static_cast<set_value_type>(
            static_cast<set_value_type>(Choice::New) |
            static_cast<set_value_type>(Choice::Filled));
        EXPECT_EQ(OrderEventSet::to_string(combined), "[\"New\", \"Filled\"]");
    }

    TEST(composite_set, setters_return_composite_for_chaining)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(&composite.set_event_set(Choice::New), &composite);
        EXPECT_EQ(&composite.clear_event_set(Choice::New), &composite);
        EXPECT_EQ(&composite.set_event_set(static_cast<set_value_type>(0)), &composite);
    }

    TEST(composite_set, const_object_read)
    {
        TestMessage msg{};
        msg.test_composite().set_event_set(Choice::Filled);

        const auto &cmsg = msg; // TestMessage is a class template; bind via auto
        const auto &composite = cmsg.test_composite();
        EXPECT_TRUE(composite.event_set(Choice::Filled));
        EXPECT_FALSE(composite.event_set(Choice::New));
        EXPECT_EQ(composite.event_set_name(), "EventSet");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
