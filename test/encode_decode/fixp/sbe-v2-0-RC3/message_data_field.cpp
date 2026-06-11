#include <cstring>
#include <string>

#include <gtest/gtest.h>

#include <NewOrderSingle.h>

// Variable-length data field tests (<data> Text / ClearingFirm). Data fields
// live in the wire buffer after the repeating groups, so reinterpret a message
// over a byte array and append the groups (empty) before the data sections.
namespace sbetool
{
    template <std::size_t BufSize = 2048>
    struct WireMessage
    {
        char buffer[BufSize]{};
        NewOrderSingle<> &msg{*reinterpret_cast<NewOrderSingle<> *>(buffer)};

        NewOrderSingle<> &with_empty_groups()
        {
            msg.AppendPartiesGrp(0);
            msg.AppendAllocsGrp(0);
            msg.AppendTradingSessionsGrp(0);
            return msg;
        }
    };

    TEST(message_data, field_info)
    {
        EXPECT_EQ(NewOrderSingle<>::text_id(), 58u);
        EXPECT_EQ(NewOrderSingle<>::text_name(), std::string("Text"));
        EXPECT_EQ(NewOrderSingle<>::clearing_firm_id(), 439u);
        EXPECT_EQ(NewOrderSingle<>::clearing_firm_name(), std::string("ClearingFirm"));
    }

    TEST(message_data, append_and_read_string_view)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();

        msg.AppendText(std::string_view("hello world"));
        const auto text = msg.text().get_str();
        EXPECT_EQ(std::string(text.data(), text.size()), "hello world");
        EXPECT_EQ(msg.text().length(), 11u);
        EXPECT_EQ(msg.text_data_length(), 11u);
    }

    TEST(message_data, append_and_read_pointer_length)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();

        const char raw[] = "ptr-data";
        msg.AppendText(raw, 8);
        EXPECT_EQ(msg.text().get_str(), std::string_view("ptr-data"));
        EXPECT_EQ(std::memcmp(msg.text().get(), raw, 8), 0); // raw get() matches
    }

    TEST(message_data, empty_data_field)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();

        msg.AppendText(std::string_view(""));
        EXPECT_EQ(msg.text().length(), 0u);
        EXPECT_EQ(msg.text().get_str().size(), 0u);
        EXPECT_EQ(msg.text_data_length(), 0u);
    }

    TEST(message_data, two_data_fields_in_order)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();

        msg.AppendText(std::string_view("some text"));
        msg.AppendClearingFirm(std::string_view("FIRM"));

        // both readable, second placed after the first
        EXPECT_EQ(msg.text().get_str(), std::string_view("some text"));
        EXPECT_EQ(msg.clearing_firm().get_str(), std::string_view("FIRM"));
        EXPECT_GT(msg.clearing_firm_offset(), msg.text_offset());
    }

    TEST(message_data, const_access)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();
        msg.AppendText(std::string_view("const-read"));

        const auto &cmsg = msg;
        EXPECT_EQ(cmsg.text().get_str(), std::string_view("const-read"));
        EXPECT_EQ(cmsg.text().length(), 10u);
    }

    TEST(message_data, encoded_size_includes_data)
    {
        WireMessage<> wire{};
        auto &msg = wire.with_empty_groups();
        msg.AppendText(std::string_view("0123456789")); // 10 bytes
        msg.AppendClearingFirm(std::string_view(""));

        const auto size_with_10 = msg.encoded_size();

        WireMessage<> wire2{};
        auto &msg2 = wire2.with_empty_groups();
        msg2.AppendText(std::string_view(""));
        msg2.AppendClearingFirm(std::string_view(""));

        EXPECT_EQ(size_with_10, msg2.encoded_size() + 10);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
