#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class AggressorSide
{
    public:
    enum class Value : std::uint8_t
    {
        NoAggressor = 0,
        Buy = 1,
        Sell = 2,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::NoAggressor:
            return "NoAggressor";
        case Value::Buy:
            return "Buy";
        case Value::Sell:
            return "Sell";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::AggressorSide::Value val)
{
    os << fastsbe::AggressorSide::to_string(val);
    return os;
}

}
