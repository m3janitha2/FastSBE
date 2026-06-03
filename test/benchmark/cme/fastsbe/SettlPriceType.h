#pragma once

#include<cstdint>
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
};
#pragma pack(pop)

constexpr SettlPriceType::Choice operator|(SettlPriceType::Choice a, SettlPriceType::Choice b) noexcept
{
	return static_cast<SettlPriceType::Choice>(
		static_cast<SettlPriceType::value_type>(a) | static_cast<SettlPriceType::value_type>(b));
}
}
