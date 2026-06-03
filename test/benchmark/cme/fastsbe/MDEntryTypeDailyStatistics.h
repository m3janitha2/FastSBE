#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MDEntryTypeDailyStatistics
{
    public:
    enum class Value : char
    {
        SettlementPrice = '6',
        ClearedVolume = 'B',
        OpenInterest = 'C',
        FixingPrice = 'W',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::SettlementPrice:
            return "SettlementPrice";
        case Value::ClearedVolume:
            return "ClearedVolume";
        case Value::OpenInterest:
            return "OpenInterest";
        case Value::FixingPrice:
            return "FixingPrice";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDEntryTypeDailyStatistics::Value val)
{
    os << fastsbe::MDEntryTypeDailyStatistics::to_string(val);
    return os;
}

}
