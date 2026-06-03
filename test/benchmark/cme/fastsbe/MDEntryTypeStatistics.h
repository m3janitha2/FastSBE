#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MDEntryTypeStatistics
{
    public:
    enum class Value : char
    {
        OpenPrice = '4',
        HighTrade = '7',
        LowTrade = '8',
        VWAP = '9',
        HighestBid = 'N',
        LowestOffer = 'O',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::OpenPrice:
            return "OpenPrice";
        case Value::HighTrade:
            return "HighTrade";
        case Value::LowTrade:
            return "LowTrade";
        case Value::VWAP:
            return "VWAP";
        case Value::HighestBid:
            return "HighestBid";
        case Value::LowestOffer:
            return "LowestOffer";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDEntryTypeStatistics::Value val)
{
    os << fastsbe::MDEntryTypeStatistics::to_string(val);
    return os;
}

}
