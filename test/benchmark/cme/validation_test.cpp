#include <cstddef>
#include <cstdint>

#include <gtest/gtest.h>

#include <MDIncrementalRefreshBook46Data.h>
#include <fastsbe_benchmark.h> // fastsbe encode + fastsbe::MDIncrementalRefreshBook46
#include <sbetool_benchmark.h> // sbetool encode + mktdata::MDIncrementalRefreshBook46

// Cross-codec interop: a buffer produced by one codec must decode, field for
// field, with the other. This is what proves fastsbe stays wire-compatible with
// the sbe-tool reference codec — each codec's own round-trip is covered
// elsewhere, only the crossing is checked here.

namespace
{
    using Data = MDIncrementalRefreshBook46Data;

    // Decode with fastsbe and check every field against the source data.
    void verify_fastsbe(char *buffer, const Data &d)
    {
        auto &msg = *reinterpret_cast<fastsbe::MDIncrementalRefreshBook46<> *>(buffer);
        EXPECT_EQ(msg.transact_time(), d.TransactTime);
        EXPECT_EQ(msg.match_event_indicator(), d.MatchEventIndicator);

        auto &md = msg.no_md_entries();
        ASSERT_EQ(md.num_in_group(), d.MDEntries.size());
        for (std::size_t i = 0; i < d.MDEntries.size(); ++i)
        {
            const auto &e = d.MDEntries[i];
            auto &g = md.get(i);
            EXPECT_EQ(g.md_entry_px().mantissa(), e.MDEntryPx);
            EXPECT_EQ(g.md_entry_size(), e.MDEntrySize);
            EXPECT_EQ(g.security_id(), e.SecurityID);
            EXPECT_EQ(g.rpt_seq(), e.RptSeq);
            EXPECT_EQ(g.number_of_orders(), e.NumberOfOrders);
            EXPECT_EQ(g.md_price_level(), e.MDPriceLevel);
            EXPECT_EQ(static_cast<std::uint8_t>(g.md_update_action()), e.MDUpdateAction);
            EXPECT_EQ(static_cast<char>(g.md_entry_type()), e.MDEntryType);
            EXPECT_EQ(g.tradeable_size(), e.TradeableSize);
        }

        auto &oid = msg.no_order_id_entries();
        ASSERT_EQ(oid.num_in_group(), d.OrderIDEntries.size());
        for (std::size_t i = 0; i < d.OrderIDEntries.size(); ++i)
        {
            const auto &e = d.OrderIDEntries[i];
            auto &g = oid.get(i);
            EXPECT_EQ(g.order_id(), e.OrderID);
            EXPECT_EQ(g.md_order_priority(), e.MDOrderPriority);
            EXPECT_EQ(g.md_display_qty(), e.MDDisplayQty);
            EXPECT_EQ(g.reference_id(), e.ReferenceID);
            EXPECT_EQ(static_cast<std::uint8_t>(g.order_update_action()), e.OrderUpdateAction);
        }
    }

    // Decode with the sbe-tool reference codec and check the same fields.
    void verify_sbetool(char *buffer, std::size_t length, const Data &d)
    {
        mktdata::MDIncrementalRefreshBook46 msg;
        msg.wrapForDecode(buffer, 0, msg.sbeBlockLength(), msg.sbeSchemaVersion(), length);
        EXPECT_EQ(msg.transactTime(), d.TransactTime);
        EXPECT_EQ(msg.matchEventIndicator().rawValue(), d.MatchEventIndicator);

        auto &md = msg.noMDEntries();
        ASSERT_EQ(md.count(), d.MDEntries.size());
        for (std::size_t i = 0; md.hasNext(); ++i)
        {
            md.next();
            const auto &e = d.MDEntries[i];
            EXPECT_EQ(md.mDEntryPx().mantissa(), e.MDEntryPx);
            EXPECT_EQ(md.mDEntrySize(), e.MDEntrySize);
            EXPECT_EQ(md.securityID(), e.SecurityID);
            EXPECT_EQ(md.rptSeq(), e.RptSeq);
            EXPECT_EQ(md.numberOfOrders(), e.NumberOfOrders);
            EXPECT_EQ(md.mDPriceLevel(), e.MDPriceLevel);
            EXPECT_EQ(static_cast<std::uint8_t>(md.mDUpdateAction()), e.MDUpdateAction);
            EXPECT_EQ(static_cast<char>(md.mDEntryType()), e.MDEntryType);
            EXPECT_EQ(md.tradeableSize(), e.TradeableSize);
        }

        auto &oid = msg.noOrderIDEntries();
        ASSERT_EQ(oid.count(), d.OrderIDEntries.size());
        for (std::size_t i = 0; oid.hasNext(); ++i)
        {
            oid.next();
            const auto &e = d.OrderIDEntries[i];
            EXPECT_EQ(oid.orderID(), e.OrderID);
            EXPECT_EQ(oid.mDOrderPriority(), e.MDOrderPriority);
            EXPECT_EQ(oid.mDDisplayQty(), e.MDDisplayQty);
            EXPECT_EQ(oid.referenceID(), e.ReferenceID);
            EXPECT_EQ(static_cast<std::uint8_t>(oid.orderUpdateAction()), e.OrderUpdateAction);
        }
    }

    // Empty, single, and multi-entry groups.
    constexpr std::size_t kEntryCounts[] = {0, 1, 5, 10};
}

TEST(CmeInterop, sbetool_encode_fastsbe_decode)
{
    for (std::size_t n : kEntryCounts)
    {
        SCOPED_TRACE(n);
        Data data{n, n};
        char buffer[4096]{};
        sbetool::encode_MDIncrementalRefreshBook46_from_struct(buffer, sizeof(buffer), data, false);
        ASSERT_LE(reinterpret_cast<fastsbe::MDIncrementalRefreshBook46<> *>(buffer)->encoded_size(), sizeof(buffer));
        verify_fastsbe(buffer, data);
    }
}

TEST(CmeInterop, fastsbe_encode_sbetool_decode)
{
    for (std::size_t n : kEntryCounts)
    {
        SCOPED_TRACE(n);
        Data data{n, n};
        char buffer[4096]{};
        fastsbe::encode_MDIncrementalRefreshBook46_from_struct(buffer, data, false);
        ASSERT_LE(reinterpret_cast<fastsbe::MDIncrementalRefreshBook46<> *>(buffer)->encoded_size(), sizeof(buffer));
        verify_sbetool(buffer, sizeof(buffer), data);
    }
}
