#include <gtest/gtest.h>

#include <MonthYear.h>
#include <PaddedComposite.h>
#include <TestMessage.h>

// Composite layout tests: member offsets, packed total size, explicit-offset
// padding, and the composite's footprint inside its enclosing message. The
// same contracts CME relies on for Decimal9 / MaturityMonthYear / PRICENULL9.
namespace sbetool
{
    TEST(composite_layout, member_offsets_are_honored)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        EXPECT_EQ(c.cl_ord_id_offset(), 0u);          // char[8]
        EXPECT_EQ(c.party_id_source_offset(), 8u);    // enums follow the string
        EXPECT_EQ(c.optional_party_id_source_offset(), 9u);
        EXPECT_EQ(c.order_qty_u64_offset(), 10u);     // numeric run starts
        EXPECT_EQ(c.optional_order_qty_u64_offset(), 40u);
        EXPECT_EQ(c.party_char_offset(), 48u);
        EXPECT_EQ(c.event_set_offset(), 49u);
    }

    TEST(composite_layout, members_are_packed_contiguously)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        // each member starts exactly where the previous one ends (pack(1))
        EXPECT_EQ(c.order_qty64_offset(), c.order_qty_u64_offset() + c.order_qty_u64_size());
        EXPECT_EQ(c.order_qty_u32_offset(), c.order_qty64_offset() + c.order_qty64_size());
        EXPECT_EQ(c.party_char_offset(),
                  c.optional_order_qty_u64_offset() + c.optional_order_qty_u64_size());
        EXPECT_EQ(c.event_set_offset(), c.party_char_offset() + c.party_char_size());
    }

    TEST(composite_layout, packed_size_matches_last_member_end)
    {
        TestMessage msg{};
        auto &c = msg.test_composite();
        EXPECT_EQ(sizeof(TestComposite), 50u); // pack(1): no alignment padding
        EXPECT_EQ(sizeof(TestComposite), c.event_set_offset() + c.event_set_size());
        EXPECT_EQ(msg.test_composite_size(), sizeof(TestComposite));
    }

    TEST(composite_layout, message_field_after_composite_starts_at_its_size)
    {
        // the enclosing message places the next field directly after the
        // composite: its footprint in the message is exactly sizeof(composite)
        TestMessage msg{};
        EXPECT_EQ(msg.cl_ord_id_offset(), sizeof(TestComposite));
    }

    // MonthYear is the MaturityMonthYear shape from the CME schema:
    // year u16 @0, month u8 @2, day u8 @3, week u8 @4 - 5 bytes packed.
    TEST(composite_layout, month_year_matches_cme_maturity_month_year_shape)
    {
        MonthYear my{};
        EXPECT_EQ(my.year_offset(), 0u);
        EXPECT_EQ(my.month_offset(), 2u);
        EXPECT_EQ(my.day_offset(), 3u);
        EXPECT_EQ(my.week_offset(), 4u);
        EXPECT_EQ(sizeof(MonthYear), 5u);
    }

    TEST(composite_layout, explicit_offset_gap_is_padded)
    {
        // PaddedComposite declares exponent at offset 12, leaving a 4-byte gap
        // after the 8-byte mantissa; the generator must pad so the member
        // lands at the declared offset and the gap is part of the size.
        PaddedComposite pc{};
        EXPECT_EQ(pc.mantissa_offset(), 0u);
        EXPECT_EQ(pc.exponent_offset(), 12u);
        EXPECT_EQ(sizeof(PaddedComposite), 13u);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
