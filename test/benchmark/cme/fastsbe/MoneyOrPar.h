#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MoneyOrPar
{
    public:
    enum class Value : std::uint8_t
    {
        Money = 1,
        Par = 2,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Money:
            return "Money";
        case Value::Par:
            return "Par";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MoneyOrPar::Value val)
{
    os << fastsbe::MoneyOrPar::to_string(val);
    return os;
}

}
