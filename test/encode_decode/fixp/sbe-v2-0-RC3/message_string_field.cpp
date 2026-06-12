#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    static constexpr const std::size_t field_offset{50}; // ClOrdId sits right after the 50-byte TestComposite block

    TEST(message_string, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.cl_ord_id_size(), 8); // idString = char[8]
        EXPECT_EQ(msg.cl_ord_id_offset(), field_offset);
        EXPECT_EQ(msg.cl_ord_id_id(), 11);
        EXPECT_EQ(msg.cl_ord_id_name(), "ClOrdId");
    }

    TEST(message_string, empty_string)
    {
        TestMessage msg{};
        msg.set_cl_ord_id(std::string_view{});
        EXPECT_EQ(std::string(msg.cl_ord_id()), std::string(""));
        EXPECT_EQ(msg.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(msg.cl_ord_id_string(), std::string(""));
    }

    TEST(message_string, const_empty_string)
    {
        const TestMessage msg{};
        const_cast<TestMessage<>&>(msg).set_cl_ord_id(std::string_view{});

        EXPECT_EQ(std::string(msg.cl_ord_id()), std::string(""));
        EXPECT_EQ(msg.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(msg.cl_ord_id_string(), std::string(""));
    }

    // Use field_length-1 characters so the stored value keeps a NUL terminator.
    TEST(message_string, max_length_minus_one)
    {
        TestMessage msg{};
        auto ClOrdId = random_string(7);
        msg.set_cl_ord_id(ClOrdId);

        EXPECT_EQ(std::string(msg.cl_ord_id()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(msg.cl_ord_id_view(), ClOrdId_view);
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(message_string, const_max_length_minus_one)
    {
        const TestMessage msg{};
        auto ClOrdId = random_string(7);
        const_cast<TestMessage<>&>(msg).set_cl_ord_id(ClOrdId);

        EXPECT_EQ(std::string(msg.cl_ord_id()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(msg.cl_ord_id_view(), ClOrdId_view);
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(message_string, max_length)
    {
        TestMessage msg{};
        auto ClOrdId = random_string(8);
        msg.set_cl_ord_id(ClOrdId);

        // At max length there is no NUL terminator, so cl_ord_id() (a raw
        // pointer) cannot be wrapped in std::string; use the bounded view.
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(message_string, const_max_length)
    {
        const TestMessage msg{};
        auto ClOrdId = random_string(8);
        const_cast<TestMessage<>&>(msg).set_cl_ord_id(ClOrdId);

        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(message_string, set_from_string_view)
    {
        {
            TestMessage msg{};
            std::string_view ClOrdId("");
            msg.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(std::string(msg.cl_ord_id()), std::string(""));
            EXPECT_EQ(msg.cl_ord_id_view().at(0), '\0');
            EXPECT_EQ(msg.cl_ord_id_string(), std::string(""));
        }
        {
            TestMessage msg{};
            const auto value = random_string(7); // keep the string alive for the view
            std::string_view ClOrdId(value.c_str());
            msg.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(std::string(msg.cl_ord_id()), ClOrdId);
            std::string ClOrdId_view = ClOrdId.data();
            ClOrdId_view.push_back('\0');

            EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId_view));
            EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
        }
        {
            TestMessage msg{};
            const auto value = random_string(8); // keep the string alive for the view
            std::string_view ClOrdId(value.c_str());
            msg.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
            EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
        }
    }

    // The string_view overload shares the bounded setter's contract: cap at the
    // field width, NULL-pad the tail.
    TEST(message_string, set_view_longer_than_field_is_capped)
    {
        TestMessage msg{};
        msg.set_cl_ord_id(std::string_view("ABCDEFGHIJKL")); // field holds 8: store first 8 only
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view("ABCDEFGH"));
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("ABCDEFGH"));
    }

    TEST(message_string, set_view_shorter_clears_previous_tail)
    {
        TestMessage msg{};
        msg.set_cl_ord_id(std::string_view("ABCDEFGH")); // fill the field
        msg.set_cl_ord_id(std::string_view("XY"));        // shorter: stale tail must clear
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("XY"));
        const auto view = msg.cl_ord_id_view();
        for (std::size_t i = 2; i < view.size(); ++i)
        {
            EXPECT_EQ(view[i], '\0');
        }
    }

    // set_cl_ord_id(const char*, size): bounded setter - copy size bytes (capped
    // at the field width) and NULL-pad the remainder.
    TEST(message_string, set_sized_shorter_than_field_nul_pads)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("ABC", 3);
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("ABC"));
        const auto view = msg.cl_ord_id_view();
        EXPECT_EQ(view.size(), 8u);
        for (std::size_t i = 3; i < view.size(); ++i)
        {
            EXPECT_EQ(view[i], '\0');
        }
    }

    TEST(message_string, set_sized_equal_field_fills_exactly)
    {
        TestMessage msg{};
        const auto value = random_string(8);
        msg.set_cl_ord_id(value.data(), 8);
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(value));
        EXPECT_EQ(msg.cl_ord_id_string(), value);
    }

    TEST(message_string, set_sized_larger_than_field_is_capped)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("ABCDEFGHIJKL", 12); // field holds 8: store first 8 only
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view("ABCDEFGH"));
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("ABCDEFGH"));
    }

    TEST(message_string, set_sized_clears_previous_tail)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("ABCDEFGH", 8); // fill the field
        msg.set_cl_ord_id("XY", 2);        // shorter: stale tail must clear
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("XY"));
        const auto view = msg.cl_ord_id_view();
        for (std::size_t i = 2; i < view.size(); ++i)
        {
            EXPECT_EQ(view[i], '\0');
        }
    }

    // The single-arg setter is the fast path: one fixed-width copy with no
    // length scan or padding; the source must span the full field width.
    TEST(message_string, set_fast_path_copies_full_width)
    {
        TestMessage msg{};
        const char scratch[8]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        msg.set_cl_ord_id(scratch);
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(scratch, 8));
        EXPECT_EQ(msg.cl_ord_id_string(), std::string("ABCDEFGH"));
    }

    TEST(message_string, setters_return_message_for_chaining)
    {
        TestMessage msg{};
        EXPECT_EQ(&msg.set_cl_ord_id("ABCDEFGH"), &msg);
        EXPECT_EQ(&msg.set_cl_ord_id("XY", 2), &msg);
        EXPECT_EQ(&msg.set_cl_ord_id(std::string_view("ABCDEFGH")), &msg);
    }

    TEST(message_string_const, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.const_cl_ord_id_size(), 0);
        EXPECT_EQ(msg.const_cl_ord_id_offset(), field_offset + 8); // +8 past ClOrdId char[8] -> 56
        EXPECT_EQ(msg.const_cl_ord_id_id(), 1);
        EXPECT_EQ(msg.const_cl_ord_id_name(), "ConstClOrdId");
    }

    TEST(message_string_const, field)
    {
        TestMessage msg{};
        const char* ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(msg.const_cl_ord_id(), ConstClOrdId);
        EXPECT_EQ(msg.const_cl_ord_id_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(msg.const_cl_ord_id_string(), std::string(ConstClOrdId));
    }

    TEST(message_string_const, field_const)
    {
        const TestMessage msg{};
        const char* ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(msg.const_cl_ord_id(), ConstClOrdId);
        EXPECT_EQ(msg.const_cl_ord_id_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(msg.const_cl_ord_id_string(), std::string(ConstClOrdId));
    }

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
