#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MDEntryTypeBook
{
    public:
    enum class Value : char
    {
        Bid = '0',
        Offer = '1',
        ImpliedBid = 'E',
        ImpliedOffer = 'F',
        BookReset = 'J',
        MarketBestOffer = 'w',
        MarketBestBid = 'x',
        nullValue = 0,
    };
    
    public:
    static constexpr const char* to_string(Value value) noexcept
    {
        switch (value)
        {
        case Value::Bid:
            return "Bid";
        case Value::Offer:
            return "Offer";
        case Value::ImpliedBid:
            return "ImpliedBid";
        case Value::ImpliedOffer:
            return "ImpliedOffer";
        case Value::BookReset:
            return "BookReset";
        case Value::MarketBestOffer:
            return "MarketBestOffer";
        case Value::MarketBestBid:
            return "MarketBestBid";
        case Value::nullValue:
            return "nullValue";
        default:
            return "Invalid";
        }
    }
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDEntryTypeBook::Value val)
{
    os << fastsbe::MDEntryTypeBook::to_string(val);
    return os;
}

}
