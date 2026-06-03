#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class EventType
{
    public:
    enum class Value : std::uint8_t
    {
        Activation = 5,
        LastEligibleTradeDate = 7,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Activation:
            return "Activation";
        case Value::LastEligibleTradeDate:
            return "LastEligibleTradeDate";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::EventType::Value val)
{
    os << fastsbe::EventType::to_string(val);
    return os;
}

}
