#pragma once

#include <cstdint>
#include <vector>

#include <random_gen.h>

// Plain data holder for one MDIncrementalRefreshBook46 message. All values are
// generated once (member initialisers + constructor) so the benchmark loop can
// measure pure encode/decode without any data-generation cost.
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
        char MDEntryType{random_enum_underlying_type<char>('0', '1')};                 // MDEntryTypeBook
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

    MDIncrementalRefreshBook46Data(std::size_t md_entries, std::size_t order_id_entries)
        : MDEntries(md_entries), OrderIDEntries(order_id_entries) {}
};
