#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MDUpdateAction
{
    public:
    enum class Value : std::uint8_t
    {
        New = 0,
        Change = 1,
        Delete = 2,
        DeleteThru = 3,
        DeleteFrom = 4,
        Overlay = 5,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::New:
            return "New";
        case Value::Change:
            return "Change";
        case Value::Delete:
            return "Delete";
        case Value::DeleteThru:
            return "DeleteThru";
        case Value::DeleteFrom:
            return "DeleteFrom";
        case Value::Overlay:
            return "Overlay";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDUpdateAction::Value val)
{
    os << fastsbe::MDUpdateAction::to_string(val);
    return os;
}

}
