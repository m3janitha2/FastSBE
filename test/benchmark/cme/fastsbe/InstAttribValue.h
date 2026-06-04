#pragma once

#include<cstdint>
#include<string>
#include<ostream>

namespace fastsbe
{

#pragma pack(push, 1)
class InstAttribValue
{
    public:
    using value_type = std::uint32_t;
    enum class Choice : value_type
    {
        ElectronicMatchEligible = static_cast<value_type>(1u << 0),
        OrderCrossEligible = static_cast<value_type>(1u << 1),
        BlockTradeEligible = static_cast<value_type>(1u << 2),
        EFPEligible = static_cast<value_type>(1u << 3),
        EBFEligible = static_cast<value_type>(1u << 4),
        EFSEligible = static_cast<value_type>(1u << 5),
        EFREligible = static_cast<value_type>(1u << 6),
        OTCEligible = static_cast<value_type>(1u << 7),
        iLinkIndicativeMassQuotingEligible = static_cast<value_type>(1u << 8),
        NegativeStrikeEligible = static_cast<value_type>(1u << 9),
        NegativePriceOutrightEligible = static_cast<value_type>(1u << 10),
        IsFractional = static_cast<value_type>(1u << 11),
        VolatilityQuotedOption = static_cast<value_type>(1u << 12),
        RFQCrossEligible = static_cast<value_type>(1u << 13),
        ZeroPriceOutrightEligible = static_cast<value_type>(1u << 14),
        DecayingProductEligibility = static_cast<value_type>(1u << 15),
        VariableProductEligibility = static_cast<value_type>(1u << 16),
        DailyProductEligibility = static_cast<value_type>(1u << 17),
        GTOrdersEligibility = static_cast<value_type>(1u << 18),
        ImpliedMatchingEligibility = static_cast<value_type>(1u << 19),
        TriangulationEligible = static_cast<value_type>(1u << 20),
        VariableCabEligible = static_cast<value_type>(1u << 21),
        InvertedBook = static_cast<value_type>(1u << 22),
        IsAoNInstrument = static_cast<value_type>(1u << 23),
        SEFRegulated = static_cast<value_type>(1u << 24),
        MTFRegulated = static_cast<value_type>(1u << 25),
        eFIXInstrument = static_cast<value_type>(1u << 26),
        HedgeInstrument = static_cast<value_type>(1u << 27),
    };
    static std::string to_string(value_type value)
    {
        std::string result = "[";
        bool first = true;
        if(value & static_cast<value_type>(Choice::ElectronicMatchEligible))
        {
            if(!first) { result += ", "; }
            result += "\"ElectronicMatchEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::OrderCrossEligible))
        {
            if(!first) { result += ", "; }
            result += "\"OrderCrossEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::BlockTradeEligible))
        {
            if(!first) { result += ", "; }
            result += "\"BlockTradeEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::EFPEligible))
        {
            if(!first) { result += ", "; }
            result += "\"EFPEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::EBFEligible))
        {
            if(!first) { result += ", "; }
            result += "\"EBFEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::EFSEligible))
        {
            if(!first) { result += ", "; }
            result += "\"EFSEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::EFREligible))
        {
            if(!first) { result += ", "; }
            result += "\"EFREligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::OTCEligible))
        {
            if(!first) { result += ", "; }
            result += "\"OTCEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::iLinkIndicativeMassQuotingEligible))
        {
            if(!first) { result += ", "; }
            result += "\"iLinkIndicativeMassQuotingEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::NegativeStrikeEligible))
        {
            if(!first) { result += ", "; }
            result += "\"NegativeStrikeEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::NegativePriceOutrightEligible))
        {
            if(!first) { result += ", "; }
            result += "\"NegativePriceOutrightEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::IsFractional))
        {
            if(!first) { result += ", "; }
            result += "\"IsFractional\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::VolatilityQuotedOption))
        {
            if(!first) { result += ", "; }
            result += "\"VolatilityQuotedOption\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::RFQCrossEligible))
        {
            if(!first) { result += ", "; }
            result += "\"RFQCrossEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::ZeroPriceOutrightEligible))
        {
            if(!first) { result += ", "; }
            result += "\"ZeroPriceOutrightEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::DecayingProductEligibility))
        {
            if(!first) { result += ", "; }
            result += "\"DecayingProductEligibility\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::VariableProductEligibility))
        {
            if(!first) { result += ", "; }
            result += "\"VariableProductEligibility\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::DailyProductEligibility))
        {
            if(!first) { result += ", "; }
            result += "\"DailyProductEligibility\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::GTOrdersEligibility))
        {
            if(!first) { result += ", "; }
            result += "\"GTOrdersEligibility\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::ImpliedMatchingEligibility))
        {
            if(!first) { result += ", "; }
            result += "\"ImpliedMatchingEligibility\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::TriangulationEligible))
        {
            if(!first) { result += ", "; }
            result += "\"TriangulationEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::VariableCabEligible))
        {
            if(!first) { result += ", "; }
            result += "\"VariableCabEligible\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::InvertedBook))
        {
            if(!first) { result += ", "; }
            result += "\"InvertedBook\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::IsAoNInstrument))
        {
            if(!first) { result += ", "; }
            result += "\"IsAoNInstrument\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::SEFRegulated))
        {
            if(!first) { result += ", "; }
            result += "\"SEFRegulated\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::MTFRegulated))
        {
            if(!first) { result += ", "; }
            result += "\"MTFRegulated\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::eFIXInstrument))
        {
            if(!first) { result += ", "; }
            result += "\"eFIXInstrument\"";
            first = false;
        }
        if(value & static_cast<value_type>(Choice::HedgeInstrument))
        {
            if(!first) { result += ", "; }
            result += "\"HedgeInstrument\"";
            first = false;
        }
        result += "]";
        return result;
    }
};
#pragma pack(pop)

constexpr InstAttribValue::Choice operator|(InstAttribValue::Choice a, InstAttribValue::Choice b) noexcept
{
	return static_cast<InstAttribValue::Choice>(
		static_cast<InstAttribValue::value_type>(a) | static_cast<InstAttribValue::value_type>(b));
}
}
