#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    // EventSet (OrderEventSet, uint8) is the last TestMessage field, after
    // EventChar. choices: New=bit0, Filled=bit1, Cancelled=bit2.
    using Choice = OrderEventSet::Choice;
    using set_value_type = OrderEventSet::value_type;

    static constexpr const std::size_t field_offset{100}; // after EventChar (offset 99, size 1)

    TEST(message_set, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.event_set_size(), sizeof(set_value_type));
        EXPECT_EQ(msg.event_set_offset(), field_offset);
        EXPECT_EQ(msg.event_set_id(), 901);
        EXPECT_EQ(msg.event_set_name(), "EventSet");
    }

    TEST(message_set, default_is_empty)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.event_set(), static_cast<set_value_type>(0));
        EXPECT_FALSE(msg.event_set(Choice::New));
        EXPECT_FALSE(msg.event_set(Choice::Filled));
        EXPECT_FALSE(msg.event_set(Choice::Cancelled));
    }

    TEST(message_set, set_and_test_choice)
    {
        TestMessage msg{};
        msg.set_event_set(Choice::New);
        EXPECT_TRUE(msg.event_set(Choice::New));
        EXPECT_FALSE(msg.event_set(Choice::Filled));

        msg.set_event_set(Choice::Filled);
        EXPECT_TRUE(msg.event_set(Choice::New));
        EXPECT_TRUE(msg.event_set(Choice::Filled));
        EXPECT_FALSE(msg.event_set(Choice::Cancelled));
    }

    TEST(message_set, clear_choice)
    {
        TestMessage msg{};
        msg.set_event_set(Choice::New);
        msg.set_event_set(Choice::Filled);
        msg.clear_event_set(Choice::New);
        EXPECT_FALSE(msg.event_set(Choice::New));
        EXPECT_TRUE(msg.event_set(Choice::Filled));
    }

    TEST(message_set, raw_value_round_trip)
    {
        TestMessage msg{};
        const auto raw = static_cast<set_value_type>(
            static_cast<set_value_type>(Choice::New) |
            static_cast<set_value_type>(Choice::Cancelled));
        msg.set_event_set(raw);
        EXPECT_EQ(msg.event_set(), raw);
        EXPECT_TRUE(msg.event_set(Choice::New));
        EXPECT_FALSE(msg.event_set(Choice::Filled));
        EXPECT_TRUE(msg.event_set(Choice::Cancelled));
    }

    TEST(message_set, choice_or_operator)
    {
        TestMessage msg{};
        msg.set_event_set(Choice::New | Choice::Filled);
        EXPECT_TRUE(msg.event_set(Choice::New));
        EXPECT_TRUE(msg.event_set(Choice::Filled));
        EXPECT_FALSE(msg.event_set(Choice::Cancelled));
    }

    TEST(message_set, to_string_json_array)
    {
        EXPECT_EQ(OrderEventSet::to_string(static_cast<set_value_type>(0)), "[]");
        const auto combined = static_cast<set_value_type>(
            static_cast<set_value_type>(Choice::New) |
            static_cast<set_value_type>(Choice::Filled));
        EXPECT_EQ(OrderEventSet::to_string(combined), "[\"New\", \"Filled\"]");
    }

    TEST(message_set, setters_return_message_for_chaining)
    {
        TestMessage msg{};
        EXPECT_EQ(&msg.set_event_set(Choice::New), &msg);
        EXPECT_EQ(&msg.clear_event_set(Choice::New), &msg);
        EXPECT_EQ(&msg.set_event_set(static_cast<set_value_type>(0)), &msg);
    }

    TEST(message_set, const_object_read)
    {
        TestMessage msg{};
        msg.set_event_set(Choice::Filled);
        const auto &cmsg = msg; // TestMessage is a class template; bind via auto
        EXPECT_TRUE(cmsg.event_set(Choice::Filled));
        EXPECT_FALSE(cmsg.event_set(Choice::New));
        EXPECT_EQ(cmsg.event_set_name(), "EventSet");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
