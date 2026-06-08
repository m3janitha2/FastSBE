#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    static constexpr const std::size_t field_offset{48}; // ClOrdId sits right after the 48-byte TestComposite block

    TEST(string, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.cl_ord_id_size(), 8); // idString = char[8]
        EXPECT_EQ(msg.cl_ord_id_offset(), field_offset);
        EXPECT_EQ(msg.cl_ord_id_id(), 11);
        EXPECT_EQ(msg.cl_ord_id_name(), "ClOrdId");
    }

    TEST(string, empty_string)
    {
        TestMessage msg{};
        msg.set_cl_ord_id("");
        EXPECT_EQ(std::string(msg.cl_ord_id()), std::string(""));
        EXPECT_EQ(msg.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(msg.cl_ord_id_string(), std::string(""));
    }

    TEST(string, const_empty_string)
    {
        const TestMessage msg{};
        const_cast<TestMessage<>&>(msg).set_cl_ord_id("");

        EXPECT_EQ(std::string(msg.cl_ord_id()), std::string(""));
        EXPECT_EQ(msg.cl_ord_id_view().at(0), '\0');
        EXPECT_EQ(msg.cl_ord_id_string(), std::string(""));
    }

    // always set field_length – 1 characters in string fields for efficient decoding.
    TEST(string, max_length_minus_one)
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

    TEST(string, const_max_length_minus_one)
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

    TEST(string, max_length)
    {
        TestMessage msg{};
        auto ClOrdId = random_string(8);
        msg.set_cl_ord_id(ClOrdId);

        // At max length there is no NUL terminator, so cl_ord_id() (a raw
        // pointer) cannot be wrapped in std::string; use the bounded view.
        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(string, const_max_length)
    {
        const TestMessage msg{};
        auto ClOrdId = random_string(8);
        const_cast<TestMessage<>&>(msg).set_cl_ord_id(ClOrdId);

        EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
        EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
    }

    TEST(string, set_from_string_view)
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
            std::string_view ClOrdId(random_string(7).c_str());
            msg.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(std::string(msg.cl_ord_id()), ClOrdId);
            std::string ClOrdId_view = ClOrdId.data();
            ClOrdId_view.push_back('\0');

            EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId_view));
            EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
        }
        {
            TestMessage msg{};
            std::string_view ClOrdId(random_string(8).c_str());
            msg.set_cl_ord_id(ClOrdId);

            EXPECT_EQ(msg.cl_ord_id_view(), std::string_view(ClOrdId));
            EXPECT_EQ(msg.cl_ord_id_string(), ClOrdId);
        }
    }

    TEST(string_const, field_info)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.const_cl_ord_id_size(), 0);
        EXPECT_EQ(msg.const_cl_ord_id_offset(), field_offset + 8); // +8 past ClOrdId char[8] -> 56
        EXPECT_EQ(msg.const_cl_ord_id_id(), 1);
        EXPECT_EQ(msg.const_cl_ord_id_name(), "ConstClOrdId");
    }

    TEST(string_const, field)
    {
        TestMessage msg{};
        const char* ConstClOrdId = "ABCDEFGH";

        EXPECT_EQ(msg.const_cl_ord_id(), ConstClOrdId);
        EXPECT_EQ(msg.const_cl_ord_id_view(), std::string_view(ConstClOrdId));
        EXPECT_EQ(msg.const_cl_ord_id_string(), std::string(ConstClOrdId));
    }

    TEST(string_const, field_const)
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
