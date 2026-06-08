#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include <NewOrderSingleData.h>
#include <benchmark_fastsbe.h> // fastsbe encode + fastsbe::NewOrderSingle
#include <benchmark_sbetool.h> // sbetool encode + sbetool::NewOrderSingle

// Cross-codec interop: a buffer produced by one codec must decode, field for
// field, with the other. This is what proves fastsbe stays wire-compatible with
// the sbe-tool reference codec — each codec's own round-trip is covered
// elsewhere, only the crossing is checked here. Exercises fixed strings,
// decimals, enums, three repeating groups and trailing variable-length data.

namespace
{
    using Data = NewOrderSingleData;

    // Decode with fastsbe and check every field against the source data.
    void verify_fastsbe(char *buffer, const Data &d)
    {
        auto &msg = *reinterpret_cast<fastsbe::NewOrderSingle<> *>(buffer);
        EXPECT_EQ(std::string(msg.cl_ord_id()), d.ClOrdId);
        EXPECT_EQ(std::string(msg.account()), d.Account);
        EXPECT_EQ(std::string(msg.symbol()), d.Symbol);
        EXPECT_EQ(static_cast<char>(msg.side()), d.Side);
        EXPECT_EQ(msg.transact_time(), d.TransactTime);
        EXPECT_EQ(msg.order_qty().mantissa(), d.OrderQty.mantissa);
        EXPECT_EQ(static_cast<char>(msg.ord_type()), d.OrdType);
        EXPECT_EQ(msg.price().mantissa(), d.Price.mantissa);
        EXPECT_EQ(msg.stop_px().mantissa(), d.StopPx.mantissa);

        auto &parties = msg.parties_grp();
        ASSERT_EQ(parties.num_in_group(), d.PartiesGrps.size());
        for (std::size_t i = 0; i < d.PartiesGrps.size(); ++i)
        {
            auto &g = parties.get(i);
            EXPECT_EQ(std::string(g.party_id()), d.PartiesGrps[i].PartyID);
            EXPECT_EQ(static_cast<char>(g.party_id_source()), d.PartiesGrps[i].PartyIDSource);
            EXPECT_EQ(static_cast<std::uint8_t>(g.party_role()), d.PartiesGrps[i].PartyRole);
        }

        auto &allocs = msg.allocs_grp();
        ASSERT_EQ(allocs.num_in_group(), d.AllocsGrps.size());
        for (std::size_t i = 0; i < d.AllocsGrps.size(); ++i)
        {
            auto &g = allocs.get(i);
            EXPECT_EQ(std::string(g.alloc_account()), d.AllocsGrps[i].AllocAccount);
            EXPECT_EQ(g.alloc_shares().mantissa(), d.AllocsGrps[i].AllocShares.mantissa);
        }

        auto &sessions = msg.trading_sessions_grp();
        ASSERT_EQ(sessions.num_in_group(), d.TradingSessionsGrps.size());
        for (std::size_t i = 0; i < d.TradingSessionsGrps.size(); ++i)
        {
            auto &g = sessions.get(i);
            EXPECT_EQ(std::string(g.trading_session_id()), d.TradingSessionsGrps[i].TradingSessionID);
        }

        auto Text = msg.text().get_str();
        EXPECT_EQ(std::string(Text.data(), Text.length()), d.Text);
        auto ClearingFirm = msg.clearing_firm().get_str();
        EXPECT_EQ(std::string(ClearingFirm.data(), ClearingFirm.length()), d.ClearingFirm);
    }

    // Decode with the sbe-tool reference codec and check the same fields.
    void verify_sbetool(char *buffer, std::size_t length, const Data &d)
    {
        sbetool::NewOrderSingle msg;
        msg.wrapForDecode(buffer, 0, msg.sbeBlockLength(), msg.sbeSchemaVersion(), length);
        EXPECT_EQ(std::string(msg.clOrdId()), d.ClOrdId);
        EXPECT_EQ(std::string(msg.account()), d.Account);
        EXPECT_EQ(std::string(msg.symbol()), d.Symbol);
        EXPECT_EQ(static_cast<char>(msg.side()), d.Side);
        EXPECT_EQ(msg.transactTime(), d.TransactTime);
        EXPECT_EQ(msg.orderQty().mantissa(), d.OrderQty.mantissa);
        EXPECT_EQ(static_cast<char>(msg.ordType()), d.OrdType);
        EXPECT_EQ(msg.price().mantissa(), d.Price.mantissa);
        EXPECT_EQ(msg.stopPx().mantissa(), d.StopPx.mantissa);

        auto &parties = msg.partiesGrp();
        ASSERT_EQ(parties.count(), d.PartiesGrps.size());
        for (std::size_t i = 0; parties.hasNext(); ++i)
        {
            parties.next();
            EXPECT_EQ(std::string(parties.partyID()), d.PartiesGrps[i].PartyID);
            EXPECT_EQ(static_cast<char>(parties.partyIDSource()), d.PartiesGrps[i].PartyIDSource);
            EXPECT_EQ(static_cast<std::uint8_t>(parties.partyRole()), d.PartiesGrps[i].PartyRole);
        }

        auto &allocs = msg.allocsGrp();
        ASSERT_EQ(allocs.count(), d.AllocsGrps.size());
        for (std::size_t i = 0; allocs.hasNext(); ++i)
        {
            allocs.next();
            EXPECT_EQ(std::string(allocs.allocAccount()), d.AllocsGrps[i].AllocAccount);
            EXPECT_EQ(allocs.allocShares().mantissa(), d.AllocsGrps[i].AllocShares.mantissa);
        }

        auto &sessions = msg.tradingSessionsGrp();
        ASSERT_EQ(sessions.count(), d.TradingSessionsGrps.size());
        for (std::size_t i = 0; sessions.hasNext(); ++i)
        {
            sessions.next();
            EXPECT_EQ(std::string(sessions.tradingSessionID()), d.TradingSessionsGrps[i].TradingSessionID);
        }

        EXPECT_EQ(msg.getTextAsString(), d.Text);
        EXPECT_EQ(msg.getClearingFirmAsString(), d.ClearingFirm);
    }

    // Empty, single, and multi-entry groups.
    constexpr std::size_t kEntryCounts[] = {0, 1, 5, 10};
}

TEST(FixpInterop, sbetool_encode_fastsbe_decode)
{
    for (std::size_t n : kEntryCounts)
    {
        SCOPED_TRACE(n);
        Data data{n, n, n};
        char buffer[4096]{};
        sbetool::encode_NewOrderSingle_from_struct(buffer, sizeof(buffer), data, false);
        ASSERT_LE(reinterpret_cast<fastsbe::NewOrderSingle<> *>(buffer)->encoded_size(), sizeof(buffer));
        verify_fastsbe(buffer, data);
    }
}

TEST(FixpInterop, fastsbe_encode_sbetool_decode)
{
    for (std::size_t n : kEntryCounts)
    {
        SCOPED_TRACE(n);
        Data data{n, n, n};
        char buffer[4096]{};
        fastsbe::encode_NewOrderSingle_from_struct(buffer, data, false);
        ASSERT_LE(reinterpret_cast<fastsbe::NewOrderSingle<> *>(buffer)->encoded_size(), sizeof(buffer));
        verify_sbetool(buffer, sizeof(buffer), data);
    }
}

// Encodes one message with each codec and prints both operator<< renderings so
// the two JSON formats can be eyeballed side by side.
TEST(FixpInterop, DumpBothJson)
{
    Data data{1, 1, 1};

    char fastsbe_buffer[4096]{};
    fastsbe::encode_NewOrderSingle_from_struct(fastsbe_buffer, data, false);
    std::cout << "FastSBE : "
              << *reinterpret_cast<fastsbe::NewOrderSingle<> *>(fastsbe_buffer)
              << "\n";

    char sbetool_buffer[4096]{};
    sbetool::encode_NewOrderSingle_from_struct(sbetool_buffer,
                                               sizeof(sbetool_buffer), data,
                                               false);
    sbetool::NewOrderSingle msg;
    msg.wrapForDecode(sbetool_buffer, 0, msg.sbeBlockLength(),
                      msg.sbeSchemaVersion(), sizeof(sbetool_buffer));
    std::cout << "SbeTool : " << msg << "\n";
}
