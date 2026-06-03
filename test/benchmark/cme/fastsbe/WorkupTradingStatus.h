#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class WorkupTradingStatus
{
    public:
    enum class Value : std::uint8_t
    {
        ReadyToTrade = 17,
        NotAvailableForTrading = 18,
        PrivateWorkup = 201,
        PublicWorkup = 202,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::ReadyToTrade:
            return "ReadyToTrade";
        case Value::NotAvailableForTrading:
            return "NotAvailableForTrading";
        case Value::PrivateWorkup:
            return "PrivateWorkup";
        case Value::PublicWorkup:
            return "PublicWorkup";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::WorkupTradingStatus::Value val)
{
    os << fastsbe::WorkupTradingStatus::to_string(val);
    return os;
}

}
