#pragma once

#include<cstdint>
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
};
#pragma pack(pop)

constexpr InstAttribValue::Choice operator|(InstAttribValue::Choice a, InstAttribValue::Choice b) noexcept
{
	return static_cast<InstAttribValue::Choice>(
		static_cast<InstAttribValue::value_type>(a) | static_cast<InstAttribValue::value_type>(b));
}
}
