#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class OrdTypeEnum
{
    public:
    enum class Value : char
    {
        Market = '1',
        Limit = '2',
        Stop = '3',
        StopLimit = '4',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Market:
            return "Market";
        case Value::Limit:
            return "Limit";
        case Value::Stop:
            return "Stop";
        case Value::StopLimit:
            return "StopLimit";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::OrdTypeEnum::Value val)
{
    os << fastsbe::OrdTypeEnum::to_string(val);
    return os;
}

}
