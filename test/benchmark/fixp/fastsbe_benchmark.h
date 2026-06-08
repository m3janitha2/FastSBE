#pragma once

#include <benchmark/benchmark.h>

#include <random_gen.h>
#include <print_message.h>
#include <fastsbe/NewOrderSingle.h>
#include <NewOrderSingleData.h>

namespace fastsbe
{
    void encode_NewOrderSingle_from_struct(char *buffer, NewOrderSingleData &values, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::NewOrderSingle<> *>(buffer);

        msg.set_cl_ord_id(values.ClOrdId.c_str())
            .set_account(values.Account.c_str())
            .set_symbol(values.Symbol.c_str())
            .set_side(static_cast<SideEnum::Value>(values.Side))
            .set_transact_time(values.TransactTime);
        msg.order_qty().set_mantissa(values.OrderQty.mantissa);
        msg.set_ord_type(static_cast<OrdTypeEnum::Value>(values.OrdType));
        msg.price().set_mantissa(values.Price.mantissa);
        msg.stop_px().set_mantissa(values.StopPx.mantissa);

        auto &PartiesGrp = msg.AppendPartiesGrp(values.PartiesGrps.size());
        for (auto i = 0u; i < values.PartiesGrps.size(); i++)
        {
            auto &party = values.PartiesGrps[i];
            PartiesGrp.get(i)
                .set_party_id(party.PartyID.c_str())
                .set_party_id_source(static_cast<fastsbe::PartyIDSourceEnum::Value>(party.PartyIDSource))
                .set_party_role(static_cast<fastsbe::PartyRoleEnum::Value>(party.PartyRole));
        }

        auto &AllocsGrp = msg.AppendAllocsGrp(values.AllocsGrps.size());
        for (auto i = 0u; i < values.AllocsGrps.size(); i++)
        {
            auto &alloc = values.AllocsGrps[i];
            AllocsGrp.get(i)
                .set_alloc_account(alloc.AllocAccount.c_str())
                .alloc_shares().set_mantissa(alloc.AllocShares.mantissa);
        }

        auto &TradingSessionsGrp = msg.AppendTradingSessionsGrp(values.TradingSessionsGrps.size());
        for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
        {
            auto &tradingSession = values.TradingSessionsGrps[i];
            TradingSessionsGrp.get(i)
                .set_trading_session_id(tradingSession.TradingSessionID.c_str());
        }
        msg.AppendText(values.Text.c_str(), values.Text.length());
        msg.AppendClearingFirm(values.ClearingFirm.c_str(), values.ClearingFirm.length());

        if (display)
            print_message(msg);
    }

    void decode_NewOrderSingle(char *buffer, bool display)
    {
        auto &msg = *reinterpret_cast<fastsbe::NewOrderSingle<> *>(buffer);

        auto clodr_id = msg.cl_ord_id();
        benchmark::DoNotOptimize(clodr_id);
        auto Account = msg.account();
        benchmark::DoNotOptimize(Account);
        auto Symbol = msg.symbol();
        benchmark::DoNotOptimize(Symbol);
        auto Side = msg.side();
        benchmark::DoNotOptimize(Side);
        auto TransactTime = msg.transact_time();
        benchmark::DoNotOptimize(TransactTime);

        auto &OrderQty = msg.order_qty();
        auto oq_mantissa = OrderQty.mantissa();
        benchmark::DoNotOptimize(oq_mantissa);
        auto oq_exponent = OrderQty.exponent();
        benchmark::DoNotOptimize(oq_exponent);

        auto &Price = msg.price();
        auto p_mantissa = Price.mantissa();
        benchmark::DoNotOptimize(p_mantissa);
        auto p_exponent = Price.exponent();
        benchmark::DoNotOptimize(p_exponent);

        auto &StopPx = msg.stop_px();
        auto sp_mantissa = StopPx.mantissa();
        benchmark::DoNotOptimize(sp_mantissa);
        auto sp_exponent = StopPx.exponent();
        benchmark::DoNotOptimize(sp_exponent);

        auto &PartiesGrp = msg.parties_grp();
        for (auto i = 0u; i < PartiesGrp.num_in_group(); i++)
        {
            auto &party = PartiesGrp.get(i);

            auto PartyID = party.party_id();
            benchmark::DoNotOptimize(PartyID);
            auto PartyIDSource = party.party_id_source();
            benchmark::DoNotOptimize(PartyIDSource);
            auto PartyRole = party.party_role();
            benchmark::DoNotOptimize(PartyRole);
        }

        auto &AllocsGrp = msg.allocs_grp();
        for (auto i = 0u; i < AllocsGrp.num_in_group(); i++)
        {
            auto &alloc = AllocsGrp.get(i);

            auto AllocAccount = alloc.alloc_account();
            benchmark::DoNotOptimize(AllocAccount);
            auto &AllocShares = alloc.alloc_shares();
            auto mantissa = AllocShares.mantissa();
            benchmark::DoNotOptimize(mantissa);
            auto exponent = AllocShares.exponent();
            benchmark::DoNotOptimize(exponent);
        }

        auto &TradingSessionsGrp = msg.trading_sessions_grp();
        for (auto i = 0u; i < TradingSessionsGrp.num_in_group(); i++)
        {
            auto &tradingSession = TradingSessionsGrp.get(i);

            auto TradingSessionID = tradingSession.trading_session_id();
            benchmark::DoNotOptimize(TradingSessionID);
        }

        auto Text = msg.text().get_str();
        benchmark::DoNotOptimize(Text);

        auto ClearingFirm = msg.clearing_firm().get_str();
        benchmark::DoNotOptimize(ClearingFirm);

        if (display)
            print_message(msg);
    }
}