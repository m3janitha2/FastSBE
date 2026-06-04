#pragma once

#include<cstdint>
#include<string>
#include<ostream>

namespace fastsbe
{

#pragma pack(push, 1)
class SettlPriceType
{
    public:
    using value_type = std::uint8_t;
    enum class Choice : value_type
    {
        FinalDaily = static_cast<value_type>(1u << 0),
        Actual = static_cast<value_type>(1u << 1),
        Rounded = static_cast<value_type>(1u << 2),
        Intraday = static_cast<value_type>(1u << 3),
        ReservedBits = static_cast<value_type>(1u << 4),
        NullValue = static_cast<value_type>(1u << 7),
    };
    static std::string to_string(value_type value)
    {
        std::string result = "[";
        bool first = true;
        if(value & static_cast<value_type>(Choice::FinalDaily))
        {
            if(!first) { result += ", "; }
            result += "\"FinalDaily\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::Actual))
        {
            if(!first) { result += ", "; }
            result += "\"Actual\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::Rounded))
        {
            if(!first) { result += ", "; }
            result += "\"Rounded\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::Intraday))
        {
            if(!first) { result += ", "; }
            result += "\"Intraday\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::ReservedBits))
        {
            if(!first) { result += ", "; }
            result += "\"ReservedBits\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::NullValue))
        {
            if(!first) { result += ", "; }
            result += "\"NullValue\"";
            first = false;
        }
        result += "]";
        return result;
    }
};
#pragma pack(pop)

constexpr SettlPriceType::Choice operator|(SettlPriceType::Choice a, SettlPriceType::Choice b) noexcept
{
	return static_cast<SettlPriceType::Choice>(
		static_cast<SettlPriceType::value_type>(a) | static_cast<SettlPriceType::value_type>(b));
}
}
