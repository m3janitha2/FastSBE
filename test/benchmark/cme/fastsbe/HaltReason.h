#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class HaltReason
{
    public:
    enum class Value : std::uint8_t
    {
        GroupSchedule = 0,
        SurveillanceIntervention = 1,
        MarketEvent = 2,
        InstrumentActivation = 3,
        InstrumentExpiration = 4,
        Unknown = 5,
        RecoveryInProcess = 6,
        TradeDateRoll = 7,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::GroupSchedule:
            return "GroupSchedule";
        case Value::SurveillanceIntervention:
            return "SurveillanceIntervention";
        case Value::MarketEvent:
            return "MarketEvent";
        case Value::InstrumentActivation:
            return "InstrumentActivation";
        case Value::InstrumentExpiration:
            return "InstrumentExpiration";
        case Value::Unknown:
            return "Unknown";
        case Value::RecoveryInProcess:
            return "RecoveryInProcess";
        case Value::TradeDateRoll:
            return "TradeDateRoll";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::HaltReason::Value val)
{
    os << fastsbe::HaltReason::to_string(val);
    return os;
}

}
