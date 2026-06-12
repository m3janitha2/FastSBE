#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    static constexpr const std::size_t field_offset{0}; // ClOrdId is the first TestComposite member

    TEST(composite_string, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.cl_ord_id_size(), 8); // idString = char[8]
        EXPECT_EQ(composite.cl_ord_id_offset(), field_offset);
        EXPECT_EQ(composite.cl_ord_id_name(), "ClOrdId");
    }

    TEST(composite_string, empty_string)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_cl_ord_id("");
        EXPECT_EQ(std::string(composite.cl_ord_id()), std::string(""));
        EXPECT_EQ(composite.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(composite.cl_ord_id_string(), std::string(""));
    }

    TEST(composite_string, const_empty_string)
    {
        const TestMessage msg{};
        const auto &composite = msg.test_composite();
        const_cast<TestComposite &>(composite).set_cl_ord_id("");

        EXPECT_EQ(std::string(composite.cl_ord_id()), std::string(""));
        EXPECT_EQ(composite.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(composite.cl_ord_id_string(), std::string(""));
    }

    // Use field_length-1 characters so the stored value keeps a NUL terminator.
    TEST(composite_string, max_length_minus_one)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        auto ClOrdId = random_string(7);
        composite.set_cl_ord_id(ClOrdId);

        EXPECT_EQ(std::string(composite.cl_ord_id()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(composite.cl_ord_id_view(), ClOrdId_view);
        EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
    }

    TEST(composite_string, const_max_length_minus_one)
    {
        const TestMessage msg{};
        const auto &composite = msg.test_composite();

        auto ClOrdId = random_string(7);
        const_cast<TestComposite &>(composite).set_cl_ord_id(ClOrdId);

        EXPECT_EQ(std::string(composite.cl_ord_id()), ClOrdId);
        auto ClOrdId_view = ClOrdId;
        ClOrdId_view.push_back('\0');
        EXPECT_EQ(composite.cl_ord_id_view(), ClOrdId_view);
        EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
    }

    TEST(composite_string, max_length)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        auto ClOrdId = random_string(8);
        composite.set_cl_ord_id(ClOrdId);

        // At max length there is no NUL terminator, so cl_ord_id() (a raw
        // pointer) cannot be wrapped in std::string; use the bounded view.
        EXPECT_EQ(composite.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
    }

    TEST(composite_string, const_max_length)
    {
        const TestMessage msg{};
        const auto &composite = msg.test_composite();

        auto ClOrdId = random_string(8);
        const_cast<TestComposite &>(composite).set_cl_ord_id(ClOrdId);

        EXPECT_EQ(composite.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
    }

    TEST(composite_string, set_from_string_view)
    {
        {
            TestMessage msg{};
            auto &composite = msg.test_composite();

            std::string_view ClOrdId("");
            composite.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(std::string(composite.cl_ord_id()), std::string(""));
            EXPECT_EQ(composite.cl_ord_id_view().at(0), '\0');
            EXPECT_EQ(composite.cl_ord_id_string(), std::string(""));
        }
        {
            TestMessage msg{};
            auto &composite = msg.test_composite();

            const auto value = random_string(7); // keep the string alive for the view
            std::string_view ClOrdId(value.c_str());
            composite.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(std::string(composite.cl_ord_id()), ClOrdId);
            std::string ClOrdId_view = ClOrdId.data();
            ClOrdId_view.push_back('\0');

            EXPECT_EQ(composite.cl_ord_id_view(), std::string_view(ClOrdId_view));
            EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
        }
        {
            TestMessage msg{};
            auto &composite = msg.test_composite();

            const auto value = random_string(8); // keep the string alive for the view
            std::string_view ClOrdId(value.c_str());
            composite.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(composite.cl_ord_id_view(), std::string_view(ClOrdId));
            EXPECT_EQ(composite.cl_ord_id_string(), ClOrdId);
        }
    }

    // set_cl_ord_id(const char*, size): bounded setter - copy size bytes (capped
    // at the field width) and NUL-pad the remainder.
    TEST(composite_string, set_sized_shorter_than_field_nul_pads)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        const char data[]{"ABC"};
        composite.set_cl_ord_id(data, 3);

        EXPECT_EQ(composite.cl_ord_id_string(), std::string("ABC"));
        const auto view = composite.cl_ord_id_view();
        EXPECT_EQ(view.size(), 8u);
        for (std::size_t i = 3; i < view.size(); ++i)
        {
            EXPECT_EQ(view[i], '\0');
        }
    }

    TEST(composite_string, set_sized_equal_field_fills_exactly)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        const auto value = random_string(8);
        composite.set_cl_ord_id(value.data(), 8);

        EXPECT_EQ(composite.cl_ord_id_view(), std::string_view(value));
        EXPECT_EQ(composite.cl_ord_id_string(), value);
    }

    TEST(composite_string, set_sized_larger_than_field_is_capped)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        // 12 chars offered, field holds 8: only the first 8 must be stored.
        const char data[]{"ABCDEFGHIJKL"};
        composite.set_cl_ord_id(data, 12);

        EXPECT_EQ(composite.cl_ord_id_view(), std::string_view("ABCDEFGH"));
        EXPECT_EQ(composite.cl_ord_id_string(), std::string("ABCDEFGH"));
    }

    TEST(composite_string, set_sized_clears_previous_tail)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        composite.set_cl_ord_id("ABCDEFGH", 8); // fill the field
        composite.set_cl_ord_id("XY", 2);        // shorter: stale tail must clear

        EXPECT_EQ(composite.cl_ord_id_string(), std::string("XY"));
        const auto view = composite.cl_ord_id_view();
        for (std::size_t i = 2; i < view.size(); ++i)
        {
            EXPECT_EQ(view[i], '\0');
        }
    }

    TEST(composite_string, setters_return_composite_for_chaining)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(&composite.set_cl_ord_id("ABCDEFGH"), &composite);
        EXPECT_EQ(&composite.set_cl_ord_id("XY", 2), &composite);
        EXPECT_EQ(&composite.set_cl_ord_id(std::string_view("ABCDEFGH")), &composite);
    }

    TEST(composite_string_const, field_info)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.const_cl_ord_id_size(), 0);
        EXPECT_EQ(composite.const_cl_ord_id_offset(), field_offset + 8); // +8 past ClOrdId char[8]
        EXPECT_EQ(composite.const_cl_ord_id_name(), "ConstClOrdId");
    }

    TEST(composite_string_const, field)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        const char *ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(composite.const_cl_ord_id(), ConstClOrdId);
        EXPECT_EQ(composite.const_cl_ord_id_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(composite.const_cl_ord_id_string(), std::string(ConstClOrdId));
    }

    TEST(composite_string_const, field_const)
    {
        const TestMessage msg{};
        const auto &composite = msg.test_composite();
        const char *ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(composite.const_cl_ord_id(), ConstClOrdId);
        EXPECT_EQ(composite.const_cl_ord_id_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(composite.const_cl_ord_id_string(), std::string(ConstClOrdId));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
