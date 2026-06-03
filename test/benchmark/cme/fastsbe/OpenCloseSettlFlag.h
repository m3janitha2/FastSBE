#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class OpenCloseSettlFlag
{
    public:
    enum class Value : std::uint8_t
    {
        DailyOpenPrice = 0,
        IndicativeOpeningPrice = 5,
        IntradayVWAP = 100,
        RepoAverage8_30AM = 101,
        RepoAverage10AM = 102,
        PrevSessionRepoAverage10AM = 103,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::DailyOpenPrice:
            return "DailyOpenPrice";
        case Value::IndicativeOpeningPrice:
            return "IndicativeOpeningPrice";
        case Value::IntradayVWAP:
            return "IntradayVWAP";
        case Value::RepoAverage8_30AM:
            return "RepoAverage8_30AM";
        case Value::RepoAverage10AM:
            return "RepoAverage10AM";
        case Value::PrevSessionRepoAverage10AM:
            return "PrevSessionRepoAverage10AM";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::OpenCloseSettlFlag::Value val)
{
    os << fastsbe::OpenCloseSettlFlag::to_string(val);
    return os;
}

}
