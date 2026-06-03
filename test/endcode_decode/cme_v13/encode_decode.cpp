#include <iostream>
#include <vector>
#include <cstdint>

#include <gtest/gtest.h>
#include <random_gen.h>

#include <MDIncrementalRefreshBook46.h>

namespace cme
{
    template <typename Msg>
    inline void print_message(Msg &msg)
    {
        std::cout << "[ MESSEGE  ]" << std::endl;
        std::cout << msg << std::endl;
        std::cout << "[----------]" << std::endl;
    }

    // Enum / set fields are held as their underlying type so the member names
    // can match the schema without colliding with the generated type names.
    struct MDIncrementalRefreshBook46Data
    {
        std::uint64_t TransactTime{random_number<std::uint64_t>()};
        std::uint8_t MatchEventIndicator{random_number<std::uint8_t>()};

        struct MDEntry
        {
            std::int64_t MDEntryPx{random_number<std::int64_t>()};   // PRICENULL9 mantissa
            std::int32_t MDEntrySize{random_number<std::int32_t>()};
            std::int32_t SecurityID{random_number<std::int32_t>()};
            std::uint32_t RptSeq{random_number<std::uint32_t>()};
            std::int32_t NumberOfOrders{random_number<std::int32_t>()};
            std::uint8_t MDPriceLevel{random_number<std::uint8_t>()};
            std::uint8_t MDUpdateAction{random_enum_underlying_type<std::uint8_t>(0, 5)};
            char MDEntryType{random_enum_underlying_type<char>('0', '1')};
            std::int32_t TradeableSize{random_number<std::int32_t>()};
        };
        std::vector<MDEntry> MDEntries{};

        struct OrderIDEntry
        {
            std::uint64_t OrderID{random_number<std::uint64_t>()};
            std::uint64_t MDOrderPriority{random_number<std::uint64_t>()};
            std::int32_t MDDisplayQty{random_number<std::int32_t>()};
            std::uint8_t ReferenceID{random_number<std::uint8_t>()};
            std::uint8_t OrderUpdateAction{random_enum_underlying_type<std::uint8_t>(0, 2)};
        };
        std::vector<OrderIDEntry> OrderIDEntries{};

        MDIncrementalRefreshBook46Data()
            : MDEntries(random_number<std::size_t>(0, 10)),
              OrderIDEntries(random_number<std::size_t>(0, 10)) {}
    };

    void encode(MDIncrementalRefreshBook46Data &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<MDIncrementalRefreshBook46 *>(buffer);

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

        print_message(msg);
    }

    void decode(MDIncrementalRefreshBook46Data &values, char *buffer)
    {
        auto &msg = *reinterpret_cast<MDIncrementalRefreshBook46 *>(buffer);

        EXPECT_EQ(msg.transact_time(), values.TransactTime);
        EXPECT_EQ(msg.match_event_indicator(), static_cast<MatchEventIndicator::value_type>(values.MatchEventIndicator));

        auto &NoMDEntries = msg.no_md_entries();
        EXPECT_EQ(static_cast<std::size_t>(NoMDEntries.num_in_group()), values.MDEntries.size());
        for (auto i = 0u; i < values.MDEntries.size(); i++)
        {
            auto &entry = NoMDEntries.get(i);
            auto &e = values.MDEntries[i];
            EXPECT_EQ(entry.md_entry_px().mantissa(), e.MDEntryPx);
            EXPECT_EQ(entry.md_entry_px().exponent(), static_cast<std::int8_t>(-9));
            EXPECT_EQ(entry.md_entry_size(), e.MDEntrySize);
            EXPECT_EQ(entry.security_id(), e.SecurityID);
            EXPECT_EQ(entry.rpt_seq(), e.RptSeq);
            EXPECT_EQ(entry.number_of_orders(), e.NumberOfOrders);
            EXPECT_EQ(entry.md_price_level(), e.MDPriceLevel);
            EXPECT_EQ(entry.md_update_action(), static_cast<MDUpdateAction::Value>(e.MDUpdateAction));
            EXPECT_EQ(entry.md_entry_type(), static_cast<MDEntryTypeBook::Value>(e.MDEntryType));
            EXPECT_EQ(entry.tradeable_size(), e.TradeableSize);
        }

        auto &NoOrderIDEntries = msg.no_order_id_entries();
        EXPECT_EQ(static_cast<std::size_t>(NoOrderIDEntries.num_in_group()), values.OrderIDEntries.size());
        for (auto i = 0u; i < values.OrderIDEntries.size(); i++)
        {
            auto &entry = NoOrderIDEntries.get(i);
            auto &e = values.OrderIDEntries[i];
            EXPECT_EQ(entry.order_id(), e.OrderID);
            EXPECT_EQ(entry.md_order_priority(), e.MDOrderPriority);
            EXPECT_EQ(entry.md_display_qty(), e.MDDisplayQty);
            EXPECT_EQ(entry.reference_id(), e.ReferenceID);
            EXPECT_EQ(entry.order_update_action(), static_cast<OrderUpdateAction::Value>(e.OrderUpdateAction));
        }

        print_message(msg);
    }

    class EncodeDecodeFixture : public testing::Test
    {
    protected:
        char buffer_[4096]{};
        MDIncrementalRefreshBook46Data values_{};
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
