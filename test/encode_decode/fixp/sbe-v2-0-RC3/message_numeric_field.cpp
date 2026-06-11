#include <iostream>
#include <limits>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    template<typename... T>
    std::size_t offset()
    {
        // OrderQtyU64's offset in TestMessage = 50-byte TestComposite block + ClOrdId[8] + 3 one-byte enums.
        // offset<Ts...>() folds in each preceding field's size, so the type pack reads as the field list.
        static constexpr const std::size_t field_offset{61};
        return (field_offset + ... + sizeof(T));
    }

    TEST(message_numeric, field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty_u64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(msg.order_qty_u64_offset(), offset());
        EXPECT_EQ(msg.order_qty_u64_id(), 38);
        EXPECT_EQ(msg.order_qty_u64_name(), "OrderQtyU64");

        EXPECT_EQ(msg.order_qty_u64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.order_qty_u64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(message_numeric, field_values_uint64)
    {
        TestMessage msg{};
        auto value = random_number<std::uint64_t>();
        msg.set_order_qty_u64(value);
        EXPECT_EQ(msg.order_qty_u64(), value);
        msg.set_order_qty_u64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.order_qty_u64(), std::numeric_limits<std::uint64_t>::min());
        msg.set_order_qty_u64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u64(), std::numeric_limits<std::uint64_t>::max() - 1);
        msg.set_order_qty_u64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(msg.order_qty_u64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(message_numeric, field_info_int64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty64_size(), sizeof(std::int64_t));
        EXPECT_EQ(msg.order_qty64_offset(), offset<std::uint64_t>());
        EXPECT_EQ(msg.order_qty64_id(), 381);
        EXPECT_EQ(msg.order_qty64_name(), "OrderQty64");

        EXPECT_EQ(msg.order_qty64_min_value(), std::numeric_limits<std::int64_t>::min() + 1);
        EXPECT_EQ(msg.order_qty64_max_value(), std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(msg.order_qty64_null_value(), std::numeric_limits<std::int64_t>::min());
    }

    TEST(message_numeric, field_values_int64)
    {
        TestMessage msg{};
        auto value = random_number<std::int64_t>();
        msg.set_order_qty64(value);
        EXPECT_EQ(msg.order_qty64(), value);
        msg.set_order_qty64(std::numeric_limits<std::int64_t>::min());
        EXPECT_EQ(msg.order_qty64(), std::numeric_limits<std::int64_t>::min());
        msg.set_order_qty64(std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(msg.order_qty64(), std::numeric_limits<std::int64_t>::max());
        msg.set_order_qty64(std::numeric_limits<std::int64_t>::max() - 1);
        EXPECT_EQ(msg.order_qty64(), std::numeric_limits<std::int64_t>::max() - 1);
    }

    TEST(message_numeric, field_info_uint32)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty_u32_size(), sizeof(std::uint32_t));
        EXPECT_EQ(msg.order_qty_u32_offset(), (offset<std::uint64_t, std::int64_t>()));
        EXPECT_EQ(msg.order_qty_u32_id(), 382);
        EXPECT_EQ(msg.order_qty_u32_name(), "OrderQtyU32");

        EXPECT_EQ(msg.order_qty_u32_min_value(), std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(msg.order_qty_u32_max_value(), std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u32_null_value(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(message_numeric, field_values_uint32)
    {
        TestMessage msg{};
        auto value = random_number<std::uint32_t>();
        msg.set_order_qty_u32(value);
        EXPECT_EQ(msg.order_qty_u32(), value);
        msg.set_order_qty_u32(std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(msg.order_qty_u32(), std::numeric_limits<std::uint32_t>::min());
        msg.set_order_qty_u32(std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u32(), std::numeric_limits<std::uint32_t>::max() - 1);
        msg.set_order_qty_u32(std::numeric_limits<std::uint32_t>::max());
        EXPECT_EQ(msg.order_qty_u32(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(message_numeric, field_info_int32)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty32_size(), sizeof(std::int32_t));
        EXPECT_EQ(msg.order_qty32_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t>()));
        EXPECT_EQ(msg.order_qty32_id(), 383);
        EXPECT_EQ(msg.order_qty32_name(), "OrderQty32");

        EXPECT_EQ(msg.order_qty32_min_value(), std::numeric_limits<std::int32_t>::min() + 1);
        EXPECT_EQ(msg.order_qty32_max_value(), std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(msg.order_qty32_null_value(), std::numeric_limits<std::int32_t>::min());
    }

    TEST(message_numeric, field_values_int32)
    {
        TestMessage msg{};
        auto value = random_number<std::int32_t>();
        msg.set_order_qty32(value);
        EXPECT_EQ(msg.order_qty32(), value);
        msg.set_order_qty32(std::numeric_limits<std::int32_t>::min());
        EXPECT_EQ(msg.order_qty32(), std::numeric_limits<std::int32_t>::min());
        msg.set_order_qty32(std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(msg.order_qty32(), std::numeric_limits<std::int32_t>::max());
        msg.set_order_qty32(std::numeric_limits<std::int32_t>::max() - 1);
        EXPECT_EQ(msg.order_qty32(), std::numeric_limits<std::int32_t>::max() - 1);
    } 

    TEST(message_numeric, field_info_uint16)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty_u16_size(), sizeof(std::uint16_t));
        EXPECT_EQ(msg.order_qty_u16_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t>()));
        EXPECT_EQ(msg.order_qty_u16_id(), 384);
        EXPECT_EQ(msg.order_qty_u16_name(), "OrderQtyU16");

        EXPECT_EQ(msg.order_qty_u16_min_value(), std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(msg.order_qty_u16_max_value(), std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u16_null_value(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(message_numeric, field_values_uint16)
    {
        TestMessage msg{};
        auto value = random_number<std::uint16_t>();
        msg.set_order_qty_u16(value);
        EXPECT_EQ(msg.order_qty_u16(), value);
        msg.set_order_qty_u16(std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(msg.order_qty_u16(), std::numeric_limits<std::uint16_t>::min());
        msg.set_order_qty_u16(std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u16(), std::numeric_limits<std::uint16_t>::max() - 1);
        msg.set_order_qty_u16(std::numeric_limits<std::uint16_t>::max());
        EXPECT_EQ(msg.order_qty_u16(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(message_numeric, field_info_int16)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty16_size(), sizeof(std::int16_t));
        EXPECT_EQ(msg.order_qty16_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t>()));
        EXPECT_EQ(msg.order_qty16_id(), 385);
        EXPECT_EQ(msg.order_qty16_name(), "OrderQty16");

        EXPECT_EQ(msg.order_qty16_min_value(), std::numeric_limits<std::int16_t>::min() + 1);
        EXPECT_EQ(msg.order_qty16_max_value(), std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(msg.order_qty16_null_value(), std::numeric_limits<std::int16_t>::min());
    }

    TEST(message_numeric, field_values_int16)
    {
        TestMessage msg{};
        auto value = random_number<std::int16_t>();
        msg.set_order_qty16(value);
        EXPECT_EQ(msg.order_qty16(), value);
        msg.set_order_qty16(std::numeric_limits<std::int16_t>::min());
        EXPECT_EQ(msg.order_qty16(), std::numeric_limits<std::int16_t>::min());
        msg.set_order_qty16(std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(msg.order_qty16(), std::numeric_limits<std::int16_t>::max());
        msg.set_order_qty16(std::numeric_limits<std::int16_t>::max() - 1);
        EXPECT_EQ(msg.order_qty16(), std::numeric_limits<std::int16_t>::max() - 1);
    }    

    TEST(message_numeric, field_info_uint8)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty_u8_size(), sizeof(std::uint8_t));
        EXPECT_EQ(msg.order_qty_u8_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t>()));
        EXPECT_EQ(msg.order_qty_u8_id(), 386);
        EXPECT_EQ(msg.order_qty_u8_name(), "OrderQtyU8");

        EXPECT_EQ(msg.order_qty_u8_min_value(), std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(msg.order_qty_u8_max_value(), std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u8_null_value(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(message_numeric, field_values_uint8)
    {
        TestMessage msg{};
        auto value = random_number<std::uint8_t>();
        msg.set_order_qty_u8(value);
        EXPECT_EQ(msg.order_qty_u8(), value);
        msg.set_order_qty_u8(std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(msg.order_qty_u8(), std::numeric_limits<std::uint8_t>::min());
        msg.set_order_qty_u8(std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(msg.order_qty_u8(), std::numeric_limits<std::uint8_t>::max() - 1);
        msg.set_order_qty_u8(std::numeric_limits<std::uint8_t>::max());
        EXPECT_EQ(msg.order_qty_u8(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(message_numeric, field_info_int8)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.order_qty8_size(), sizeof(std::int8_t));
        EXPECT_EQ(msg.order_qty8_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t>()));
        EXPECT_EQ(msg.order_qty8_id(), 387);
        EXPECT_EQ(msg.order_qty8_name(), "OrderQty8");

        EXPECT_EQ(msg.order_qty8_min_value(), std::numeric_limits<std::int8_t>::min() + 1);
        EXPECT_EQ(msg.order_qty8_max_value(), std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(msg.order_qty8_null_value(), std::numeric_limits<std::int8_t>::min());
    }

    TEST(message_numeric, field_values_int8)
    {
        TestMessage msg{};
        auto value = random_number<std::int8_t>();
        msg.set_order_qty8(value);
        EXPECT_EQ(msg.order_qty8(), value);
        msg.set_order_qty8(std::numeric_limits<std::int8_t>::min());
        EXPECT_EQ(msg.order_qty8(), std::numeric_limits<std::int8_t>::min());
        msg.set_order_qty8(std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(msg.order_qty8(), std::numeric_limits<std::int8_t>::max());
        msg.set_order_qty8(std::numeric_limits<std::int8_t>::max() - 1);
        EXPECT_EQ(msg.order_qty8(), std::numeric_limits<std::int8_t>::max() - 1);
    }  

    // ----- char: a single-char field is an SBE numeric primitive (sentinels
    // min 32 ' ', max (char)255, null 0 '\0'), distinct from char-array strings.
    // EventChar is appended after ConstOrderQty64 at the end of the message. -----
    TEST(message_numeric, field_info_char)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.event_char_size(), sizeof(char));
        EXPECT_EQ(msg.event_char_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t
            , std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::uint64_t>())); // after OptionalOrderQtyU64; const adds 0
        EXPECT_EQ(msg.event_char_id(), 900);
        EXPECT_EQ(msg.event_char_name(), "EventChar");
        EXPECT_EQ(msg.event_char_min_value(), static_cast<char>(32));
        EXPECT_EQ(msg.event_char_max_value(), static_cast<char>(255));
        EXPECT_EQ(msg.event_char_null_value(), static_cast<char>(0));
    }

    TEST(message_numeric, field_values_char)
    {
        TestMessage msg{};
        msg.set_event_char('A');
        EXPECT_EQ(msg.event_char(), 'A');
        msg.set_event_char(msg.event_char_min_value());
        EXPECT_EQ(msg.event_char(), static_cast<char>(32));
        msg.set_event_char(msg.event_char_max_value());
        EXPECT_EQ(msg.event_char(), static_cast<char>(255));
        msg.set_event_char(msg.event_char_null_value());
        EXPECT_EQ(msg.event_char(), static_cast<char>(0));
        const auto value = random_char();
        msg.set_event_char(value);
        EXPECT_EQ(msg.event_char(), value);
    }

    // ----- presence variants: optional and constant -----
    TEST(message_numeric, optional_field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.optional_order_qty_u64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(msg.optional_order_qty_u64_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t
            , std::uint16_t, std::int16_t, std::uint8_t, std::int8_t>()));
        EXPECT_EQ(msg.optional_order_qty_u64_id(), 388);
        EXPECT_EQ(msg.optional_order_qty_u64_name(), "OptionalOrderQtyU64");

        EXPECT_EQ(msg.optional_order_qty_u64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.optional_order_qty_u64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.optional_order_qty_u64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(message_numeric, optional_field_values_uint64)
    {
        TestMessage msg{};
        auto value = random_number<std::uint64_t>();
        msg.set_optional_order_qty_u64(value);
        EXPECT_EQ(msg.optional_order_qty_u64(), value);
        msg.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(msg.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::min());
        msg.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(msg.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::max() - 1);
        msg.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(msg.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(message_numeric, const_field_info_uint64)
    {
        TestMessage msg{};
        EXPECT_EQ(msg.const_order_qty64_size(), 0);
        EXPECT_EQ(msg.const_order_qty64_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t
            , std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::uint64_t>())); // last arg = preceding OptionalOrderQtyU64 size; const itself adds 0
        EXPECT_EQ(msg.const_order_qty64_id(), 389);
        EXPECT_EQ(msg.const_order_qty64_name(), "ConstOrderQty64");
    }

    TEST(message_numeric, const_field_values_uint64)
    {
        TestMessage msg{};

        EXPECT_EQ(msg.const_order_qty64(), 42545);
    }

    // ----- behavioral: setter return value (chaining) and const-object access -----
    TEST(message_numeric, setter_returns_message_for_chaining)
    {
        TestMessage msg{};
        EXPECT_EQ(&msg.set_order_qty_u64(1), &msg);
        // fluent chain across fields, each setter returns the message
        msg.set_order_qty_u64(7).set_order_qty32(-3).set_event_char('Q');
        EXPECT_EQ(msg.order_qty_u64(), 7u);
        EXPECT_EQ(msg.order_qty32(), -3);
        EXPECT_EQ(msg.event_char(), 'Q');
    }

    TEST(message_numeric, const_object_read)
    {
        TestMessage msg{};
        msg.set_order_qty_u64(99).set_order_qty16(-5);

        const auto &cmsg = msg; // TestMessage is a class template; bind via auto
        EXPECT_EQ(cmsg.order_qty_u64(), 99u);
        EXPECT_EQ(cmsg.order_qty16(), -5);
        EXPECT_EQ(cmsg.const_order_qty64(), 42545); // const getter on const object
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
