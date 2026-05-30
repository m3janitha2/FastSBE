#include <iostream>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <BusinessMessageReject.h>
#include <ExecutionReportTrade.h>
#include <NewOrderSingle.h>

namespace sbetool
{
    template <typename Msg>
    inline void print_message(Msg &msg)
    {
        std::cout << "[ MESSEGE  ]" << std::endl;
        std::cout << msg << std::endl;
        std::cout << "[----------]" << std::endl;
    }

    /* string encoding: Array of char of specified length, delimited by NUL character if a string is shorter than the length specified for a field.*/
    /* use max length as (length -1) in encoding to make it always null terminated */
    struct NewOrderSingleData
    {
        std::string ClOrdId{random_length_string(7).c_str()};
        std::string Account{random_length_string(7).c_str()};
        std::string Symbol{random_length_string(7).c_str()};
        SideEnum::Value Side{random_enum<SideEnum::Value>('1', '2')};
        struct timestampEncoding
        {
            std::uint64_t time{random_number<std::uint64_t>()};
        };
        timestampEncoding TransactTime{};
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
        struct PartiesGrp
        {
            std::string PartyID{random_length_string(7).c_str()};
            PartyIDSourceEnum::Value PartyIDSource{random_enum<PartyIDSourceEnum::Value>('B', 'C')};
            PartyRoleEnum::Value PartyRole{random_enum<PartyRoleEnum::Value>(1, 3)};
        };
        std::vector<PartiesGrp> PartiesGrps{};
        struct AllocsGrp
        {
            std::string AllocAccount{random_length_string(15).c_str()};
            qtyEncoding AllocShares{};
        };
        std::vector<AllocsGrp> AllocsGrps{};
        struct TradingSessionsGrp
        {
            std::string TradingSessionID{random_length_string(7).c_str()};
        };
        std::vector<TradingSessionsGrp> TradingSessionsGrps{};
        std::string Text{random_length_string(20).c_str()};
        std::string ClearingFirm{random_length_string(20).c_str()};

        NewOrderSingleData()
            : PartiesGrps(random_number<std::size_t>(0, 10)),
              AllocsGrps(random_number<std::size_t>(0, 10)),
              TradingSessionsGrps(random_number<std::size_t>(0, 10)) {}
    };

    void encode(NewOrderSingleData &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<NewOrderSingle *>(buffer);

        msg.set_cl_ord_id(values.ClOrdId)
            .set_account(values.Account)
            .set_symbol(values.Symbol)
            .set_side(values.Side);
        msg.transact_time().set_time(values.TransactTime.time);
        msg.order_qty().set_mantissa(values.OrderQty.mantissa);
        msg.set_ord_type(values.OrdType);
        msg.price().set_mantissa(values.Price.mantissa);
        msg.stop_px().set_mantissa(values.StopPx.mantissa);

        auto &PartiesGrp = msg.AppendPartiesGrp(values.PartiesGrps.size());
        for (auto i = 0u; i < values.PartiesGrps.size(); i++)
        {
            auto &party = values.PartiesGrps[i];
            PartiesGrp.get(i)
                .set_party_id(party.PartyID)
                .set_party_id_source(party.PartyIDSource)
                .set_party_role(party.PartyRole);
        }

        auto &AllocsGrp = msg.AppendAllocsGrp(values.AllocsGrps.size());
        for (auto i = 0u; i < values.AllocsGrps.size(); i++)
        {
            auto &alloc = values.AllocsGrps[i];
            AllocsGrp.get(i)
                .set_alloc_account(alloc.AllocAccount)
                .alloc_shares()
                .set_mantissa(alloc.AllocShares.mantissa);
        }

        auto &TradingSessionsGrp = msg.AppendTradingSessionsGrp(values.TradingSessionsGrps.size());
        for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
        {
            auto &tradingSession = values.TradingSessionsGrps[i];
            TradingSessionsGrp.get(i)
                .set_trading_session_id(tradingSession.TradingSessionID);
        }
        msg.AppendText(values.Text.c_str(), values.Text.length());
        msg.AppendClearingFirm(values.ClearingFirm.c_str(), values.ClearingFirm.length());

        print_message(msg);
    }

    void decode(NewOrderSingleData &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<NewOrderSingle *>(buffer);

        EXPECT_EQ(msg.cl_ord_id(), values.ClOrdId);
        EXPECT_EQ(msg.account(), values.Account);
        EXPECT_EQ(msg.symbol(), values.Symbol);
        /*EXPECT_EQ(msg.side(), values.Side);*/

        auto &TransactTime = msg.transact_time();
        EXPECT_EQ(TransactTime.time(), values.TransactTime.time);
        /*EXPECT_EQ(TransactTime.unit(), TimeUnit::Value::nanosecond);*/

        auto &OrderQty = msg.order_qty();
        EXPECT_EQ(OrderQty.mantissa(), values.OrderQty.mantissa);
        EXPECT_EQ(OrderQty.exponent(), static_cast<std::int8_t>(0));

        auto &Price = msg.price();
        EXPECT_EQ(Price.mantissa(), values.Price.mantissa);
        EXPECT_EQ(Price.exponent(), static_cast<std::int8_t>(-3));

        auto &StopPx = msg.stop_px();
        EXPECT_EQ(StopPx.mantissa(), values.StopPx.mantissa);
        EXPECT_EQ(StopPx.exponent(), static_cast<std::int8_t>(-3));

        auto &PartiesGrp = msg.parties_grp();
        for (auto i = 0u; i < values.PartiesGrps.size(); i++)
        {
            auto &party = PartiesGrp.get(i);
            auto &party_t = values.PartiesGrps[i];
            EXPECT_EQ(party.party_id(), party_t.PartyID);
            /*EXPECT_EQ(party.party_id_source(), party_t.PartyIDSource);*/
            /*EXPECT_EQ(party.party_role(), party_t.PartyRole);*/
        }

        auto &AllocsGrp = msg.allocs_grp();
        for (auto i = 0u; i < values.AllocsGrps.size(); i++)
        {
            auto &alloc = AllocsGrp.get(i);
            auto &alloc_t = values.AllocsGrps[i];

            EXPECT_EQ(alloc.alloc_account(), alloc_t.AllocAccount);

            auto &AllocShares = alloc.alloc_shares();
            EXPECT_EQ(AllocShares.mantissa(), alloc_t.AllocShares.mantissa);
            EXPECT_EQ(AllocShares.exponent(), static_cast<std::int8_t>(0));
        }

        auto &TradingSessionsGrp = msg.trading_sessions_grp();
        for (auto i = 0u; i < values.TradingSessionsGrps.size(); i++)
        {
            auto &tradingSession = TradingSessionsGrp.get(i);
            auto &tradingSession_t = values.TradingSessionsGrps[i];

            EXPECT_EQ(tradingSession.trading_session_id(), tradingSession_t.TradingSessionID);
        }

        auto Text = msg.text().get_str();
        EXPECT_EQ(std::string(Text.data(), Text.length()), values.Text);

        auto ClearingFirm = msg.clearing_firm().get_str();
        EXPECT_EQ(std::string(ClearingFirm.data(), ClearingFirm.length()), values.ClearingFirm);

        print_message(msg);
    }

    class EncodeDecodeFixture : public testing::Test
    {
    protected:
        char buffer_[2048]{};
        NewOrderSingleData values_{};
    };

    TEST_F(EncodeDecodeFixture, encode_and_decode)
    {
        encode(values_, buffer_);
        decode(values_, buffer_);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}