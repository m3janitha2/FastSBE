#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class PriceSource
{
    public:
    enum class Value : std::uint8_t
    {
        MarketPlaceAssistant = 0,
        Globex = 1,
        Refinitiv = 2,
        ICAP = 3,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::MarketPlaceAssistant:
            return "MarketPlaceAssistant";
        case Value::Globex:
            return "Globex";
        case Value::Refinitiv:
            return "Refinitiv";
        case Value::ICAP:
            return "ICAP";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::PriceSource::Value val)
{
    os << fastsbe::PriceSource::to_string(val);
    return os;
}

}
