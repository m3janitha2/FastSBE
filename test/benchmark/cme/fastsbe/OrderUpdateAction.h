#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class OrderUpdateAction
{
    public:
    enum class Value : std::uint8_t
    {
        New = 0,
        Update = 1,
        Delete = 2,
        nullValue = UINT8_MAX,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::New:
            return "New";
        case Value::Update:
            return "Update";
        case Value::Delete:
            return "Delete";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::OrderUpdateAction::Value val)
{
    os << fastsbe::OrderUpdateAction::to_string(val);
    return os;
}

}
