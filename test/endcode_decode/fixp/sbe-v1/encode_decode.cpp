#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <NewOrderSingle.h>
#include <SbeMessage.h>

namespace test::sbe
{
    template <typename Msg>
    inline void print_message(Msg &msg)
    {
        std::cout << "[ MESSEGE  ]" << std::endl;
        std::cout << msg << std::endl;
        std::cout << "[----------]" << std::endl;
    }

    // NewOrderSingle is a fixed-size message: nine root fields, no repeating
    // groups or variable-length data.
    struct NewOrderSingleData
    {
        std::string ClOrdId{random_length_string(7).c_str()};
        std::string Account{random_length_string(7).c_str()};
        std::string Symbol{random_length_string(7).c_str()};
        SideEnum::Value Side{random_enum<SideEnum::Value>('1', '2')};
        std::uint64_t TransactTime{random_number<std::uint64_t>()};
        struct qtyEncoding
        {
            std::int32_t mantissa{random_number<std::int32_t>()};
        };
        qtyEncoding OrderQty{};
        OrdTypeEnum::Value OrdType{random_enum<OrdTypeEnum::Value>('1', '4')};
        struct decimalEncoding
        {
            std::int64_t mantissa{random_number<std::int64_t>()};
        };
        decimalEncoding Price{};
        decimalEncoding StopPx{};
    };

    void encode_body(NewOrderSingleData &values, NewOrderSingle<> &msg)
    {
        msg.set_cl_ord_id(values.ClOrdId)
            .set_account(values.Account)
            .set_symbol(values.Symbol)
            .set_side(values.Side)
            .set_transact_time(values.TransactTime)
            .set_ord_type(values.OrdType);
        msg.order_qty().set_mantissa(values.OrderQty.mantissa);
        msg.price().set_mantissa(values.Price.mantissa);
        msg.stop_px().set_mantissa(values.StopPx.mantissa);
    }

    void encode_message(NewOrderSingleData &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        encode_body(values, msg);
        print_message(msg);
    }

    void encode_message_with_header(NewOrderSingleData &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<SbeMessage<NewOrderSingle<>> *>(buffer);
        msg = {};   // reinterpret_cast runs no ctor; assign a default to stamp the header
        encode_body(values, msg.body());
        print_message(msg);
    }

    void decode_body(NewOrderSingleData &values, NewOrderSingle<> &msg)
    {
        EXPECT_EQ(msg.cl_ord_id_string(), values.ClOrdId);
        EXPECT_EQ(msg.account_string(), values.Account);
        EXPECT_EQ(msg.symbol_string(), values.Symbol);
        EXPECT_EQ(msg.side(), values.Side);
        EXPECT_EQ(msg.transact_time(), values.TransactTime);
        EXPECT_EQ(msg.order_qty().mantissa(), values.OrderQty.mantissa);
        EXPECT_EQ(msg.ord_type(), values.OrdType);
        EXPECT_EQ(msg.price().mantissa(), values.Price.mantissa);
        EXPECT_EQ(msg.stop_px().mantissa(), values.StopPx.mantissa);
    }

    void decode_message(NewOrderSingleData &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer);
        decode_body(values, msg);
        print_message(msg);
    }

    void decode_message_with_header(NewOrderSingleData &values, char *buffer)
    {
        // a received message is just a view over the wire bytes - construct nothing
        auto &msg = *reinterpret_cast<SbeMessage<NewOrderSingle<>> *>(buffer);

        EXPECT_EQ(msg.header().block_length(), NewOrderSingle<>::block_length());
        EXPECT_EQ(msg.header().template_id(), NewOrderSingle<>::template_id());
        EXPECT_EQ(msg.header().schema_id(), NewOrderSingle<>::schema());
        EXPECT_EQ(msg.header().version(), NewOrderSingle<>::version());

        decode_body(values, msg.body());
        print_message(msg);
    }

    class EncodeDecodeFixture : public testing::Test
    {
    protected:
        char buffer_[256]{};
        NewOrderSingleData values_{};
    };

    TEST_F(EncodeDecodeFixture, encode_and_decode)
    {
        encode_message(values_, buffer_);
        decode_message(values_, buffer_);
    }

    TEST_F(EncodeDecodeFixture, encode_and_decode_with_header)
    {
        encode_message_with_header(values_, buffer_);
        decode_message_with_header(values_, buffer_);
    }

    // A fixed-size message's on-wire body is exactly the root block, so
    // encoded_size() is a compile-time constant equal to block_length().
    static_assert(NewOrderSingle<>::encoded_size() ==
                  NewOrderSingle<>::block_length());

    TEST_F(EncodeDecodeFixture, encoded_size_matches_block_length)
    {
        auto &msg = *reinterpret_cast<NewOrderSingle<> *>(buffer_);
        encode_body(values_, msg);
        EXPECT_EQ(msg.encoded_size(), NewOrderSingle<>::block_length());
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
