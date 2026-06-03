#pragma once

#include<cstdint>
#include<ostream>

namespace fastsbe
{

#pragma pack(push, 1)
class MatchEventIndicator
{
    public:
    using value_type = std::uint8_t;
    enum class Choice : value_type
    {
        LastTradeMsg = static_cast<value_type>(1u << 0),
        LastVolumeMsg = static_cast<value_type>(1u << 1),
        LastQuoteMsg = static_cast<value_type>(1u << 2),
        LastStatsMsg = static_cast<value_type>(1u << 3),
        LastImpliedMsg = static_cast<value_type>(1u << 4),
        RecoveryMsg = static_cast<value_type>(1u << 5),
        Reserved = static_cast<value_type>(1u << 6),
        EndOfEvent = static_cast<value_type>(1u << 7),
    };
};
#pragma pack(pop)

constexpr MatchEventIndicator::Choice operator|(MatchEventIndicator::Choice a, MatchEventIndicator::Choice b) noexcept
{
	return static_cast<MatchEventIndicator::Choice>(
		static_cast<MatchEventIndicator::value_type>(a) | static_cast<MatchEventIndicator::value_type>(b));
}
}
