#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityUpdateAction
{
    public:
    enum class Value : char
    {
        Add = 'A',
        Delete = 'D',
        Modify = 'M',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Add:
            return "Add";
        case Value::Delete:
            return "Delete";
        case Value::Modify:
            return "Modify";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityUpdateAction::Value val)
{
    os << fastsbe::SecurityUpdateAction::to_string(val);
    return os;
}

}
