#pragma once

#include <iostream>

#include <benchmark/benchmark.h>

#include <random_gen.h>
#include <print_message.h>
#include <fastsbe/MDIncrementalRefreshBook46.h>
#include <MDIncrementalRefreshBook46Data.h>

namespace fastsbe
{
    void encode_MDIncrementalRefreshBook46_from_struct(char *buffer, MDIncrementalRefreshBook46Data &values, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::MDIncrementalRefreshBook46<> *>(buffer);

        msg.set_transact_time(values.TransactTime)
            .set_match_event_indicator(static_cast<MatchEventIndicator::value_type>(values.MatchEventIndicator));

        auto &NoMDEntries = msg.AppendNoMDEntries(values.MDEntries.size());
        for (auto i = 0u; i < values.MDEntries.size(); i++)
        {
            auto &e = values.MDEntries[i];
            auto &entry = NoMDEntries.get(i);
            entry.md_entry_px().set_mantissa(e.MDEntryPx);
            entry.set_md_entry_size(e.MDEntrySize)
                .set_security_id(e.SecurityID)
                .set_rpt_seq(e.RptSeq)
                .set_number_of_orders(e.NumberOfOrders)
                .set_md_price_level(e.MDPriceLevel)
                .set_md_update_action(static_cast<MDUpdateAction::Value>(e.MDUpdateAction))
                .set_md_entry_type(static_cast<MDEntryTypeBook::Value>(e.MDEntryType))
                .set_tradeable_size(e.TradeableSize);
        }

        auto &NoOrderIDEntries = msg.AppendNoOrderIDEntries(values.OrderIDEntries.size());
        for (auto i = 0u; i < values.OrderIDEntries.size(); i++)
        {
            auto &e = values.OrderIDEntries[i];
            NoOrderIDEntries.get(i)
                .set_order_id(e.OrderID)
                .set_md_order_priority(e.MDOrderPriority)
                .set_md_display_qty(e.MDDisplayQty)
                .set_reference_id(e.ReferenceID)
                .set_order_update_action(static_cast<OrderUpdateAction::Value>(e.OrderUpdateAction));
        }

        if (display)
            print_message(msg);
    }

    void decode_MDIncrementalRefreshBook46(char *buffer, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::MDIncrementalRefreshBook46<> *>(buffer);

        auto TransactTime = msg.transact_time();
        benchmark::DoNotOptimize(TransactTime);
        auto MatchEventIndicator = msg.match_event_indicator();
        benchmark::DoNotOptimize(MatchEventIndicator);

        auto &NoMDEntries = msg.no_md_entries();
        for (auto i = 0u; i < NoMDEntries.num_in_group(); i++)
        {
            auto &entry = NoMDEntries.get(i);
            auto MDEntryPx = entry.md_entry_px().mantissa();
            benchmark::DoNotOptimize(MDEntryPx);
            auto MDEntrySize = entry.md_entry_size();
            benchmark::DoNotOptimize(MDEntrySize);
            auto SecurityID = entry.security_id();
            benchmark::DoNotOptimize(SecurityID);
            auto RptSeq = entry.rpt_seq();
            benchmark::DoNotOptimize(RptSeq);
            auto NumberOfOrders = entry.number_of_orders();
            benchmark::DoNotOptimize(NumberOfOrders);
            auto MDPriceLevel = entry.md_price_level();
            benchmark::DoNotOptimize(MDPriceLevel);
            auto MDUpdateAction = entry.md_update_action();
            benchmark::DoNotOptimize(MDUpdateAction);
            auto MDEntryType = entry.md_entry_type();
            benchmark::DoNotOptimize(MDEntryType);
            auto TradeableSize = entry.tradeable_size();
            benchmark::DoNotOptimize(TradeableSize);
        }

        auto &NoOrderIDEntries = msg.no_order_id_entries();
        for (auto i = 0u; i < NoOrderIDEntries.num_in_group(); i++)
        {
            auto &entry = NoOrderIDEntries.get(i);
            auto OrderID = entry.order_id();
            benchmark::DoNotOptimize(OrderID);
            auto MDOrderPriority = entry.md_order_priority();
            benchmark::DoNotOptimize(MDOrderPriority);
            auto MDDisplayQty = entry.md_display_qty();
            benchmark::DoNotOptimize(MDDisplayQty);
            auto ReferenceID = entry.reference_id();
            benchmark::DoNotOptimize(ReferenceID);
            auto OrderUpdateAction = entry.order_update_action();
            benchmark::DoNotOptimize(OrderUpdateAction);
        }

        if (display)
            print_message(msg);
    }
}
