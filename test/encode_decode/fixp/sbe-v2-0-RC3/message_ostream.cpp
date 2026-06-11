#include <sstream>
#include <string>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

// Tests the message body operator<< (JSON dump). Same presentation path as the
// composite, plus a nested composite object and the message's own char/set/enum
// fields.
namespace sbetool
{
    template <typename Message>
    std::string dump(const Message &m)
    {
        std::ostringstream os;
        os << m;
        return os.str();
    }

    bool contains(const std::string &haystack, const std::string &needle)
    {
        return haystack.find(needle) != std::string::npos;
    }

    TEST(message_ostream, well_formed_json_printable_and_balanced)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("ORD123", 6);
        msg.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        msg.set_order_qty_u64(100);
        msg.set_event_char('Z');
        msg.set_event_set(OrderEventSet::Choice::New);

        const auto json = dump(msg);

        ASSERT_FALSE(json.empty());
        EXPECT_EQ(json.front(), '{');
        EXPECT_EQ(json.back(), '}');
        for (unsigned char ch : json)
        {
            EXPECT_TRUE(ch >= 0x20 && ch <= 0x7e) << "non-printable byte: " << static_cast<int>(ch);
        }
        int braces = 0;
        int brackets = 0;
        for (char ch : json)
        {
            braces += (ch == '{') - (ch == '}');
            brackets += (ch == '[') - (ch == ']');
        }
        EXPECT_EQ(braces, 0);   // outer object + nested TestComposite object
        EXPECT_EQ(brackets, 0); // composite EventSet array + message EventSet array
    }

    TEST(message_ostream, nested_composite_is_object)
    {
        TestMessage msg{};
        EXPECT_TRUE(contains(dump(msg), "\"TestComposite\": {"));
    }

    TEST(message_ostream, string_field_quoted_no_overrun)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("ABCDEFGH", 8); // fills char[8], no NUL terminator
        EXPECT_TRUE(contains(dump(msg), "\"ClOrdId\": \"ABCDEFGH\""));
    }

    TEST(message_ostream, char_field_quoted_and_null_empty)
    {
        TestMessage msg{};
        msg.set_event_char('A');
        EXPECT_TRUE(contains(dump(msg), "\"EventChar\": \"A\""));
        msg.set_event_char('\0');
        EXPECT_TRUE(contains(dump(msg), "\"EventChar\": \"\""));
    }

    TEST(message_ostream, enum_field_renders_name)
    {
        TestMessage msg{};
        msg.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_TRUE(contains(dump(msg), "\"PartyIDSource\": \"BIC\""));
    }

    TEST(message_ostream, set_field_renders_json_array)
    {
        TestMessage msg{};
        EXPECT_TRUE(contains(dump(msg), "\"EventSet\": []"));
        msg.set_event_set(OrderEventSet::Choice::New | OrderEventSet::Choice::Filled);
        EXPECT_TRUE(contains(dump(msg), "\"EventSet\": [\"New\", \"Filled\"]"));
    }

    TEST(message_ostream, numeric_and_small_int_rendering)
    {
        TestMessage msg{};
        msg.set_order_qty_u64(12345);
        msg.set_order_qty8(65); // 'A' if mistakenly streamed as a char
        const auto json = dump(msg);
        EXPECT_TRUE(contains(json, "\"OrderQtyU64\": 12345"));
        EXPECT_TRUE(contains(json, "\"OrderQty8\": 65"));
        EXPECT_FALSE(contains(json, "\"OrderQty8\": \"A\""));
    }

    TEST(message_ostream, const_fields_rendered)
    {
        TestMessage msg{};
        const auto json = dump(msg);
        EXPECT_TRUE(contains(json, "\"ConstClOrdId\": \"ABCDEFGH\""));
        EXPECT_TRUE(contains(json, "\"ConstPartyIDSource\": \"Proprietary\""));
        EXPECT_TRUE(contains(json, "\"ConstOrderQty64\": 42545"));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
