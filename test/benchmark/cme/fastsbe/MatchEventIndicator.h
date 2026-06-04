#pragma once

#include<cstdint>
#include<string>
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
    static std::string to_string(value_type value)
    {
        std::string result = "[";
        bool first = true;
        if(value & static_cast<value_type>(Choice::LastTradeMsg))
        {
            if(!first) { result += ", "; }
            result += "\"LastTradeMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::LastVolumeMsg))
        {
            if(!first) { result += ", "; }
            result += "\"LastVolumeMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::LastQuoteMsg))
        {
            if(!first) { result += ", "; }
            result += "\"LastQuoteMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::LastStatsMsg))
        {
            if(!first) { result += ", "; }
            result += "\"LastStatsMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::LastImpliedMsg))
        {
            if(!first) { result += ", "; }
            result += "\"LastImpliedMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::RecoveryMsg))
        {
            if(!first) { result += ", "; }
            result += "\"RecoveryMsg\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::Reserved))
        {
            if(!first) { result += ", "; }
            result += "\"Reserved\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::EndOfEvent))
        {
            if(!first) { result += ", "; }
            result += "\"EndOfEvent\"";
            first = false;
        }
        result += "]";
        return result;
    }
};
#pragma pack(pop)

constexpr MatchEventIndicator::Choice operator|(MatchEventIndicator::Choice a, MatchEventIndicator::Choice b) noexcept
{
	return static_cast<MatchEventIndicator::Choice>(
		static_cast<MatchEventIndicator::value_type>(a) | static_cast<MatchEventIndicator::value_type>(b));
}
}
