#include <sstream>
#include <string>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

// Tests the composite's operator<< (JSON dump). This is the presentation path,
// separate from the per-field accessor tests: it is where the string-overrun and
// bare-char bugs lived, so each field kind's rendering is asserted here.
namespace sbetool
{
    template <typename Composite>
    std::string dump(const Composite &c)
    {
        std::ostringstream os;
        os << c;
        return os.str();
    }

    bool contains(const std::string &haystack, const std::string &needle)
    {
        return haystack.find(needle) != std::string::npos;
    }

    TEST(composite_ostream, well_formed_json_printable_and_balanced)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_cl_ord_id("ORD123", 6);
        c.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        c.set_optional_party_id_source(PartyIDSourceEnum::Value::Proprietary);
        c.set_order_qty_u64(100);
        c.set_party_char('Z');
        c.set_event_set(OrderEventSet::Choice::New);

        const auto json = dump(c);

        ASSERT_FALSE(json.empty());
        EXPECT_EQ(json.front(), '{');
        EXPECT_EQ(json.back(), '}');

        // every byte is printable ASCII - catches NUL/control bytes and the
        // high bytes that the old char-array overrun leaked into the stream.
        for (unsigned char ch : json)
        {
            EXPECT_TRUE(ch >= 0x20 && ch <= 0x7e) << "non-printable byte: " << static_cast<int>(ch);
        }

        // balanced object braces and set-array brackets
        int braces = 0;
        int brackets = 0;
        for (char ch : json)
        {
            braces += (ch == '{') - (ch == '}');
            brackets += (ch == '[') - (ch == ']');
        }
        EXPECT_EQ(braces, 0);
        EXPECT_EQ(brackets, 0);
    }

    // a char array filled to its full width has no NUL terminator: the dump must
    // print exactly the field's characters and not run past them.
    TEST(composite_ostream, string_field_quoted_no_overrun)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_cl_ord_id("ABCDEFGH", 8);
        EXPECT_TRUE(contains(dump(c), "\"ClOrdId\": \"ABCDEFGH\""));
    }

    TEST(composite_ostream, char_field_quoted)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_party_char('A');
        EXPECT_TRUE(contains(dump(c), "\"PartyChar\": \"A\""));
    }

    TEST(composite_ostream, char_field_null_renders_empty_string)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_party_char('\0');
        EXPECT_TRUE(contains(dump(c), "\"PartyChar\": \"\""));
    }

    TEST(composite_ostream, enum_field_renders_name)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_party_id_source(PartyIDSourceEnum::Value::BIC);
        EXPECT_TRUE(contains(dump(c), "\"PartyIDSource\": \"BIC\""));
    }

    TEST(composite_ostream, set_field_renders_json_array)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();

        EXPECT_TRUE(contains(dump(c), "\"EventSet\": []")); // default: empty set

        c.set_event_set(OrderEventSet::Choice::New | OrderEventSet::Choice::Filled);
        EXPECT_TRUE(contains(dump(c), "\"EventSet\": [\"New\", \"Filled\"]"));
    }

    TEST(composite_ostream, numeric_field_bare_number)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_order_qty_u64(12345);
        EXPECT_TRUE(contains(dump(c), "\"OrderQtyU64\": 12345"));
    }

    // int8/uint8 must print as numbers, not characters (the unary-+ promotion).
    TEST(composite_ostream, small_int_printed_as_number_not_char)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        c.set_order_qty8(65); // would be 'A' if streamed as a raw char
        const auto json = dump(c);
        EXPECT_TRUE(contains(json, "\"OrderQty8\": 65"));
        EXPECT_FALSE(contains(json, "\"OrderQty8\": \"A\""));
    }

    TEST(composite_ostream, const_fields_rendered)
    {
        TestMessage msg{};
        const auto json = dump(msg.test_composite());
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
