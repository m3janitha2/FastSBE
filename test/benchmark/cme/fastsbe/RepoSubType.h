#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class RepoSubType
{
    public:
    enum class Value : std::uint8_t
    {
        Special = 0,
        GC = 1,
        GCForDBV = 2,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Special:
            return "Special";
        case Value::GC:
            return "GC";
        case Value::GCForDBV:
            return "GCForDBV";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::RepoSubType::Value val)
{
    os << fastsbe::RepoSubType::to_string(val);
    return os;
}

}
