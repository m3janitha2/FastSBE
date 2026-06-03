#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityAltIDSource
{
    public:
    enum class Value : std::uint8_t
    {
        CUSIP = 1,
        ISIN = 4,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::CUSIP:
            return "CUSIP";
        case Value::ISIN:
            return "ISIN";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityAltIDSource::Value val)
{
    os << fastsbe::SecurityAltIDSource::to_string(val);
    return os;
}

}
