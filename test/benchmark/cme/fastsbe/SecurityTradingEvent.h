#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityTradingEvent
{
    public:
    enum class Value : std::uint8_t
    {
        NoEvent = 0,
        NoCancel = 1,
        ResetStatistics = 4,
        ImpliedMatchingON = 5,
        ImpliedMatchingOFF = 6,
        EndOfWorkup = 7,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::NoEvent:
            return "NoEvent";
        case Value::NoCancel:
            return "NoCancel";
        case Value::ResetStatistics:
            return "ResetStatistics";
        case Value::ImpliedMatchingON:
            return "ImpliedMatchingON";
        case Value::ImpliedMatchingOFF:
            return "ImpliedMatchingOFF";
        case Value::EndOfWorkup:
            return "EndOfWorkup";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityTradingEvent::Value val)
{
    os << fastsbe::SecurityTradingEvent::to_string(val);
    return os;
}

}
