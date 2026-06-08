#pragma once

#include <iostream>

#include <benchmark/benchmark.h>

#include <random_gen.h>
#include <print_message.h>
#include <sbetool/MDIncrementalRefreshBook46.h>
#include <MDIncrementalRefreshBook46Data.h>

// The sbe-tool codec lives in namespace mktdata (the schema's package); the
// helpers stay in namespace sbetool so the benchmark calls match fixp's.
namespace sbetool
{
    void encode_MDIncrementalRefreshBook46_from_struct(char *buffer, std::size_t length, MDIncrementalRefreshBook46Data &values, bool display)
    {
        mktdata::MDIncrementalRefreshBook46 msg;
        msg.wrapForEncode(buffer, 0, length)
            .transactTime(values.TransactTime);
        msg.matchEventIndicator().rawValue(static_cast<std::uint8_t>(values.MatchEventIndicator));

        auto &NoMDEntries = msg.noMDEntriesCount(values.MDEntries.size());
        for (auto i = 0u; i < values.MDEntries.size(); i++)
        {
            auto &e = values.MDEntries[i];
            NoMDEntries.next();
            NoMDEntries.mDEntryPx().mantissa(e.MDEntryPx);
            NoMDEntries.mDEntrySize(e.MDEntrySize)
                .securityID(e.SecurityID)
                .rptSeq(e.RptSeq)
                .numberOfOrders(e.NumberOfOrders)
                .mDPriceLevel(e.MDPriceLevel)
                .mDUpdateAction(static_cast<mktdata::MDUpdateAction::Value>(e.MDUpdateAction))
                .mDEntryType(static_cast<mktdata::MDEntryTypeBook::Value>(e.MDEntryType))
                .tradeableSize(e.TradeableSize);
        }

        auto &NoOrderIDEntries = msg.noOrderIDEntriesCount(values.OrderIDEntries.size());
        for (auto i = 0u; i < values.OrderIDEntries.size(); i++)
        {
            auto &e = values.OrderIDEntries[i];
            NoOrderIDEntries.next()
                .orderID(e.OrderID)
                .mDOrderPriority(e.MDOrderPriority)
                .mDDisplayQty(e.MDDisplayQty)
                .referenceID(e.ReferenceID)
                .orderUpdateAction(static_cast<mktdata::OrderUpdateAction::Value>(e.OrderUpdateAction));
        }

        if (display)
            print_message(msg);
    }

    void decode_MDIncrementalRefreshBook46(char *buffer, std::size_t length, bool display)
    {
        mktdata::MDIncrementalRefreshBook46 msg;
        msg.wrapForDecode(buffer, 0, msg.sbeBlockLength(), msg.sbeSchemaVersion(), length);

        auto TransactTime = msg.transactTime();
        benchmark::DoNotOptimize(TransactTime);
        auto MatchEventIndicator = msg.matchEventIndicator().rawValue();
        benchmark::DoNotOptimize(MatchEventIndicator);

        auto &NoMDEntries = msg.noMDEntries();
        while (NoMDEntries.hasNext())
        {
            NoMDEntries.next();
            auto MDEntryPx = NoMDEntries.mDEntryPx().mantissa();
            benchmark::DoNotOptimize(MDEntryPx);
            auto MDEntrySize = NoMDEntries.mDEntrySize();
            benchmark::DoNotOptimize(MDEntrySize);
            auto SecurityID = NoMDEntries.securityID();
            benchmark::DoNotOptimize(SecurityID);
            auto RptSeq = NoMDEntries.rptSeq();
            benchmark::DoNotOptimize(RptSeq);
            auto NumberOfOrders = NoMDEntries.numberOfOrders();
            benchmark::DoNotOptimize(NumberOfOrders);
            auto MDPriceLevel = NoMDEntries.mDPriceLevel();
            benchmark::DoNotOptimize(MDPriceLevel);
            auto MDUpdateAction = NoMDEntries.mDUpdateAction();
            benchmark::DoNotOptimize(MDUpdateAction);
            auto MDEntryType = NoMDEntries.mDEntryType();
            benchmark::DoNotOptimize(MDEntryType);
            auto TradeableSize = NoMDEntries.tradeableSize();
            benchmark::DoNotOptimize(TradeableSize);
        }

        auto &NoOrderIDEntries = msg.noOrderIDEntries();
        while (NoOrderIDEntries.hasNext())
        {
            NoOrderIDEntries.next();
            auto OrderID = NoOrderIDEntries.orderID();
            benchmark::DoNotOptimize(OrderID);
            auto MDOrderPriority = NoOrderIDEntries.mDOrderPriority();
            benchmark::DoNotOptimize(MDOrderPriority);
            auto MDDisplayQty = NoOrderIDEntries.mDDisplayQty();
            benchmark::DoNotOptimize(MDDisplayQty);
            auto ReferenceID = NoOrderIDEntries.referenceID();
            benchmark::DoNotOptimize(ReferenceID);
            auto OrderUpdateAction = NoOrderIDEntries.orderUpdateAction();
            benchmark::DoNotOptimize(OrderUpdateAction);
        }

        if (display)
            print_message(msg);
    }
}
