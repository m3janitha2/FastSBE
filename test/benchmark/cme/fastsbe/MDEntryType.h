#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MDEntryType
{
    public:
    enum class Value : char
    {
        Bid = '0',
        Offer = '1',
        Trade = '2',
        OpenPrice = '4',
        SettlementPrice = '6',
        TradingSessionHighPrice = '7',
        TradingSessionLowPrice = '8',
        VWAP = '9',
        ClearedVolume = 'B',
        OpenInterest = 'C',
        ImpliedBid = 'E',
        ImpliedOffer = 'F',
        BookReset = 'J',
        SessionHighBid = 'N',
        SessionLowOffer = 'O',
        FixingPrice = 'W',
        ElectronicVolume = 'e',
        ThresholdLimitsandPriceBandVariation = 'g',
        MarketBestOffer = 'w',
        MarketBestBid = 'x',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Bid:
            return "Bid";
        case Value::Offer:
            return "Offer";
        case Value::Trade:
            return "Trade";
        case Value::OpenPrice:
            return "OpenPrice";
        case Value::SettlementPrice:
            return "SettlementPrice";
        case Value::TradingSessionHighPrice:
            return "TradingSessionHighPrice";
        case Value::TradingSessionLowPrice:
            return "TradingSessionLowPrice";
        case Value::VWAP:
            return "VWAP";
        case Value::ClearedVolume:
            return "ClearedVolume";
        case Value::OpenInterest:
            return "OpenInterest";
        case Value::ImpliedBid:
            return "ImpliedBid";
        case Value::ImpliedOffer:
            return "ImpliedOffer";
        case Value::BookReset:
            return "BookReset";
        case Value::SessionHighBid:
            return "SessionHighBid";
        case Value::SessionLowOffer:
            return "SessionLowOffer";
        case Value::FixingPrice:
            return "FixingPrice";
        case Value::ElectronicVolume:
            return "ElectronicVolume";
        case Value::ThresholdLimitsandPriceBandVariation:
            return "ThresholdLimitsandPriceBandVariation";
        case Value::MarketBestOffer:
            return "MarketBestOffer";
        case Value::MarketBestBid:
            return "MarketBestBid";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDEntryType::Value val)
{
    os << fastsbe::MDEntryType::to_string(val);
    return os;
}

}
