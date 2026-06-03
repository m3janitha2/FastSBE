#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityTradingStatus
{
    public:
    enum class Value : std::uint8_t
    {
        TradingHalt = 2,
        Close = 4,
        NewPriceIndication = 15,
        ReadyToTrade = 17,
        NotAvailableForTrading = 18,
        UnknownorInvalid = 20,
        PreOpen = 21,
        PreCross = 24,
        Cross = 25,
        PostClose = 26,
        NoChange = 103,
        PrivateWorkup = 201,
        PublicWorkup = 202,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::TradingHalt:
            return "TradingHalt";
        case Value::Close:
            return "Close";
        case Value::NewPriceIndication:
            return "NewPriceIndication";
        case Value::ReadyToTrade:
            return "ReadyToTrade";
        case Value::NotAvailableForTrading:
            return "NotAvailableForTrading";
        case Value::UnknownorInvalid:
            return "UnknownorInvalid";
        case Value::PreOpen:
            return "PreOpen";
        case Value::PreCross:
            return "PreCross";
        case Value::Cross:
            return "Cross";
        case Value::PostClose:
            return "PostClose";
        case Value::NoChange:
            return "NoChange";
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
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityTradingStatus::Value val)
{
    os << fastsbe::SecurityTradingStatus::to_string(val);
    return os;
}

}
