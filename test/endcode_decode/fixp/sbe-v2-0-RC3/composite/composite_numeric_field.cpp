#include <iostream>
#include <limits>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <TestMessage.h>

namespace sbetool
{
    template <typename... T>
    std::size_t offset()
    {
        static constexpr const std::size_t field_offset{10};
        return (field_offset + ... + sizeof(T));
    }

    TEST(composite_numeric, field_info_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty_u64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(composite.order_qty_u64_offset(), offset());
        EXPECT_EQ(composite.order_qty_u64_name(), "OrderQtyU64");

        EXPECT_EQ(composite.order_qty_u64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(composite.order_qty_u64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(composite_numeric, field_values_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::uint64_t>();
        composite.set_order_qty_u64(value);
        EXPECT_EQ(composite.order_qty_u64(), value);
        composite.set_order_qty_u64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(composite.order_qty_u64(), std::numeric_limits<std::uint64_t>::min());
        composite.set_order_qty_u64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u64(), std::numeric_limits<std::uint64_t>::max() - 1);
        // null
        composite.set_order_qty_u64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(composite.order_qty_u64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(composite_numeric, field_info_int64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty64_size(), sizeof(std::int64_t));
        EXPECT_EQ(composite.order_qty64_offset(), offset<std::uint64_t>());
        EXPECT_EQ(composite.order_qty64_name(), "OrderQty64");

        EXPECT_EQ(composite.order_qty64_min_value(), std::numeric_limits<std::int64_t>::min() + 1);
        EXPECT_EQ(composite.order_qty64_max_value(), std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(composite.order_qty64_null_value(), std::numeric_limits<std::int64_t>::min());
    }

    TEST(composite_numeric, field_values_int64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::int64_t>();
        composite.set_order_qty64(value);
        EXPECT_EQ(composite.order_qty64(), value);
        composite.set_order_qty64(std::numeric_limits<std::int64_t>::min());
        EXPECT_EQ(composite.order_qty64(), std::numeric_limits<std::int64_t>::min());
        composite.set_order_qty64(std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(composite.order_qty64(), std::numeric_limits<std::int64_t>::max());
        // null
        composite.set_order_qty64(std::numeric_limits<std::int64_t>::max());
        EXPECT_EQ(composite.order_qty64(), std::numeric_limits<std::int64_t>::max());
    }

    TEST(composite_numeric, field_info_uint32)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty_u32_size(), sizeof(std::uint32_t));
        EXPECT_EQ(composite.order_qty_u32_offset(), (offset<std::uint64_t, std::int64_t>()));
        EXPECT_EQ(composite.order_qty_u32_name(), "OrderQtyU32");

        EXPECT_EQ(composite.order_qty_u32_min_value(), std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(composite.order_qty_u32_max_value(), std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u32_null_value(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(composite_numeric, field_values_uint32)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::uint32_t>();
        composite.set_order_qty_u32(value);
        EXPECT_EQ(composite.order_qty_u32(), value);
        composite.set_order_qty_u32(std::numeric_limits<std::uint32_t>::min());
        EXPECT_EQ(composite.order_qty_u32(), std::numeric_limits<std::uint32_t>::min());
        composite.set_order_qty_u32(std::numeric_limits<std::uint32_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u32(), std::numeric_limits<std::uint32_t>::max() - 1);
        // null
        composite.set_order_qty_u32(std::numeric_limits<std::uint32_t>::max());
        EXPECT_EQ(composite.order_qty_u32(), std::numeric_limits<std::uint32_t>::max());
    }

    TEST(composite_numeric, field_info_int32)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty32_size(), sizeof(std::int32_t));
        EXPECT_EQ(composite.order_qty32_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t>()));
        EXPECT_EQ(composite.order_qty32_name(), "OrderQty32");

        EXPECT_EQ(composite.order_qty32_min_value(), std::numeric_limits<std::int32_t>::min() + 1);
        EXPECT_EQ(composite.order_qty32_max_value(), std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(composite.order_qty32_null_value(), std::numeric_limits<std::int32_t>::min());
    }

    TEST(composite_numeric, field_values_int32)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::int32_t>();
        composite.set_order_qty32(value);
        EXPECT_EQ(composite.order_qty32(), value);
        composite.set_order_qty32(std::numeric_limits<std::int32_t>::min());
        EXPECT_EQ(composite.order_qty32(), std::numeric_limits<std::int32_t>::min());
        composite.set_order_qty32(std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(composite.order_qty32(), std::numeric_limits<std::int32_t>::max());
        // null
        composite.set_order_qty32(std::numeric_limits<std::int32_t>::max());
        EXPECT_EQ(composite.order_qty32(), std::numeric_limits<std::int32_t>::max());
    }

    TEST(composite_numeric, field_info_uint16)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty_u16_size(), sizeof(std::uint16_t));
        EXPECT_EQ(composite.order_qty_u16_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t>()));
        EXPECT_EQ(composite.order_qty_u16_name(), "OrderQtyU16");

        EXPECT_EQ(composite.order_qty_u16_min_value(), std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(composite.order_qty_u16_max_value(), std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u16_null_value(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(composite_numeric, field_values_uint16)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::uint16_t>();
        composite.set_order_qty_u16(value);
        EXPECT_EQ(composite.order_qty_u16(), value);
        composite.set_order_qty_u16(std::numeric_limits<std::uint16_t>::min());
        EXPECT_EQ(composite.order_qty_u16(), std::numeric_limits<std::uint16_t>::min());
        composite.set_order_qty_u16(std::numeric_limits<std::uint16_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u16(), std::numeric_limits<std::uint16_t>::max() - 1);
        // null
        composite.set_order_qty_u16(std::numeric_limits<std::uint16_t>::max());
        EXPECT_EQ(composite.order_qty_u16(), std::numeric_limits<std::uint16_t>::max());
    }

    TEST(composite_numeric, field_info_int16)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty16_size(), sizeof(std::int16_t));
        EXPECT_EQ(composite.order_qty16_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t>()));
        EXPECT_EQ(composite.order_qty16_name(), "OrderQty16");

        EXPECT_EQ(composite.order_qty16_min_value(), std::numeric_limits<std::int16_t>::min() + 1);
        EXPECT_EQ(composite.order_qty16_max_value(), std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(composite.order_qty16_null_value(), std::numeric_limits<std::int16_t>::min());
    }

    TEST(composite_numeric, field_values_int16)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::int16_t>();
        composite.set_order_qty16(value);
        EXPECT_EQ(composite.order_qty16(), value);
        composite.set_order_qty16(std::numeric_limits<std::int16_t>::min());
        EXPECT_EQ(composite.order_qty16(), std::numeric_limits<std::int16_t>::min());
        composite.set_order_qty16(std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(composite.order_qty16(), std::numeric_limits<std::int16_t>::max());
        // null
        composite.set_order_qty16(std::numeric_limits<std::int16_t>::max());
        EXPECT_EQ(composite.order_qty16(), std::numeric_limits<std::int16_t>::max());
    }

    TEST(composite_numeric, field_info_uint8)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty_u8_size(), sizeof(std::uint8_t));
        EXPECT_EQ(composite.order_qty_u8_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t>()));
        EXPECT_EQ(composite.order_qty_u8_name(), "OrderQtyU8");

        EXPECT_EQ(composite.order_qty_u8_min_value(), std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(composite.order_qty_u8_max_value(), std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u8_null_value(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(composite_numeric, field_values_uint8)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::uint8_t>();
        composite.set_order_qty_u8(value);
        EXPECT_EQ(composite.order_qty_u8(), value);
        composite.set_order_qty_u8(std::numeric_limits<std::uint8_t>::min());
        EXPECT_EQ(composite.order_qty_u8(), std::numeric_limits<std::uint8_t>::min());
        composite.set_order_qty_u8(std::numeric_limits<std::uint8_t>::max() - 1);
        EXPECT_EQ(composite.order_qty_u8(), std::numeric_limits<std::uint8_t>::max() - 1);
        // null
        composite.set_order_qty_u8(std::numeric_limits<std::uint8_t>::max());
        EXPECT_EQ(composite.order_qty_u8(), std::numeric_limits<std::uint8_t>::max());
    }

    TEST(composite_numeric, field_info_int8)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.order_qty8_size(), sizeof(std::int8_t));
        EXPECT_EQ(composite.order_qty8_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t>()));
        EXPECT_EQ(composite.order_qty8_name(), "OrderQty8");

        EXPECT_EQ(composite.order_qty8_min_value(), std::numeric_limits<std::int8_t>::min() + 1);
        EXPECT_EQ(composite.order_qty8_max_value(), std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(composite.order_qty8_null_value(), std::numeric_limits<std::int8_t>::min());
    }

    TEST(composite_numeric, field_values_int8)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::int8_t>();
        composite.set_order_qty8(value);
        EXPECT_EQ(composite.order_qty8(), value);
        composite.set_order_qty8(std::numeric_limits<std::int8_t>::min());
        EXPECT_EQ(composite.order_qty8(), std::numeric_limits<std::int8_t>::min());
        composite.set_order_qty8(std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(composite.order_qty8(), std::numeric_limits<std::int8_t>::max());
        // null
        composite.set_order_qty8(std::numeric_limits<std::int8_t>::max());
        EXPECT_EQ(composite.order_qty8(), std::numeric_limits<std::int8_t>::max());
    }

    TEST(composite_numeric, optional_field_info_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.optional_order_qty_u64_size(), sizeof(std::uint64_t));
        EXPECT_EQ(composite.optional_order_qty_u64_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t>()));
        EXPECT_EQ(composite.optional_order_qty_u64_name(), "OptionalOrderQtyU64");

        EXPECT_EQ(composite.optional_order_qty_u64_min_value(), std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(composite.optional_order_qty_u64_max_value(), std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(composite.optional_order_qty_u64_null_value(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(composite_numeric, optional_field_values_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        auto value = random_number<std::uint64_t>();
        composite.set_optional_order_qty_u64(value);
        EXPECT_EQ(composite.optional_order_qty_u64(), value);
        composite.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::min());
        EXPECT_EQ(composite.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::min());
        composite.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::max() - 1);
        EXPECT_EQ(composite.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::max() - 1);
        // null
        composite.set_optional_order_qty_u64(std::numeric_limits<std::uint64_t>::max());
        EXPECT_EQ(composite.optional_order_qty_u64(), std::numeric_limits<std::uint64_t>::max());
    }

    TEST(composite_numeric, const_field_info_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();
        EXPECT_EQ(composite.const_order_qty64_size(), 0);
        EXPECT_EQ(composite.const_order_qty64_offset(), (offset<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::uint64_t>()));
        EXPECT_EQ(composite.const_order_qty64_name(), "ConstOrderQty64");
    }

    TEST(composite_numeric, const_field_values_uint64)
    {
        TestMessage msg{};
        auto &composite = msg.test_composite();

        EXPECT_EQ(composite.const_order_qty64(), 42545);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
