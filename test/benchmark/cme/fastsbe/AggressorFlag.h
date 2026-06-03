#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class AggressorFlag
{
    public:
    enum class Value : std::uint8_t
    {
        NotAggressor = 0,
        Aggressor = 1,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::NotAggressor:
            return "NotAggressor";
        case Value::Aggressor:
            return "Aggressor";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::AggressorFlag::Value val)
{
    os << fastsbe::AggressorFlag::to_string(val);
    return os;
}

}
