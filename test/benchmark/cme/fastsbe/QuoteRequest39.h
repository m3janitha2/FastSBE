#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
template <std::size_t N = 1>
class QuoteRequest39
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "QuoteRequest39"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 39; 
    	}
    
    	static constexpr std::uint16_t schema() noexcept
    	{  
    		return 1; 
    	}
    
    	static constexpr std::uint16_t version() noexcept
    	{
    		return 13;
    	}
    
    	static constexpr std::uint16_t block_length() noexcept
    	{
    		return 35;
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	std::uint64_t transact_time_{};
    
    public:
    	static constexpr std::size_t transact_time_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t transact_time_offset() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr std::size_t transact_time_id() noexcept
    	{ 
    		return 60; 
    	}
    	
    	static constexpr const char* transact_time_name() noexcept
    	{ 
    		return "TransactTime"; 
    	}
    	
    	static constexpr std::uint64_t transact_time_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t transact_time_max_value() noexcept
    	{
    		return (UINT64_MAX - 1);
    	}
    	
    	static constexpr std::uint64_t transact_time_null_value() noexcept
    	{
    		return UINT64_MAX;
    	}
    
    	constexpr std::uint64_t transact_time() const noexcept
    	{ 
    		return transact_time_;
    	}
    	
    	constexpr auto& set_transact_time(std::uint64_t value) noexcept
    	{
    		transact_time_ = value;
    		return *this;
    	}
    
    
    private:
    	char quote_req_id_[23]{};
    
    public:
    	static constexpr std::size_t quote_req_id_size() noexcept
    	{
    		return 23;
    	}
    
    	static constexpr std::size_t quote_req_id_offset() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t quote_req_id_id() noexcept
    	{
    		return 131;
    	}
    
    	static constexpr const char *quote_req_id_name() noexcept
    	{
    		return "QuoteReqID";
    	}
    
    	constexpr char *quote_req_id() noexcept
    	{
    		return quote_req_id_;
    	}
    
    	constexpr const char *quote_req_id() const noexcept
    	{
    		return quote_req_id_;
    	}
    
    	constexpr std::string_view quote_req_id_view() noexcept
    	{
    		return std::string_view(quote_req_id_, 23);
    	}
    
    	constexpr const std::string_view quote_req_id_view() const noexcept
    	{
    		return std::string_view(quote_req_id_, 23);
    	}
    
    	const std::string quote_req_id_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 23 && *(quote_req_id_ + length) != '\0'; ++length);
    		return std::string(quote_req_id_, length);
    	}
    
    	constexpr auto &set_quote_req_id(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#pragma GCC diagnostic ignored "-Wstringop-overread"
    	#endif
    		std::memcpy(quote_req_id_, value, quote_req_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	// Safe: copy size bytes (capped at the field width) and NUL-pad the remainder.
    	auto &set_quote_req_id(const char *value, std::size_t size) noexcept
    	{
    		const auto length = size < quote_req_id_size() ? size : quote_req_id_size();
    		std::memcpy(quote_req_id_, value, length);
    		std::memset(quote_req_id_ + length, 0, quote_req_id_size() - length);
    		return *this;
    	}
    
    	auto &set_quote_req_id(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#pragma GCC diagnostic ignored "-Wstringop-overread"
    	#endif
    		// auto size = std::min(quote_req_id_size(), value.size());
    		std::memcpy(quote_req_id_, value.data(), quote_req_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	MatchEventIndicator::value_type match_event_indicator_{};
    
    public:
    	static constexpr std::size_t match_event_indicator_size() noexcept
    	{
    		return sizeof(MatchEventIndicator::value_type);
    	}
    
    	static constexpr std::size_t match_event_indicator_offset() noexcept
    	{
    		return 31;
    	}
    
    	static constexpr std::size_t match_event_indicator_id() noexcept
    	{
    		return 5799;
    	}
    
    	static constexpr const char* match_event_indicator_name() noexcept
    	{
    		return "MatchEventIndicator";
    	}
    
    	// raw whole-field access (low-latency path)
    	constexpr MatchEventIndicator::value_type match_event_indicator() const noexcept
    	{
    		return match_event_indicator_;
    	}
    
    	constexpr auto& set_match_event_indicator(MatchEventIndicator::value_type value) noexcept
    	{
    		match_event_indicator_ = value;
    		return *this;
    	}
    
    	// per-choice access; choices combine with operator| (A | B | C)
    	constexpr bool match_event_indicator(MatchEventIndicator::Choice choice) const noexcept
    	{
    		return (match_event_indicator_ & static_cast<MatchEventIndicator::value_type>(choice))
    			== static_cast<MatchEventIndicator::value_type>(choice);
    	}
    
    	constexpr auto& set_match_event_indicator(MatchEventIndicator::Choice choice) noexcept
    	{
    		match_event_indicator_ = static_cast<MatchEventIndicator::value_type>(
    			match_event_indicator_ | static_cast<MatchEventIndicator::value_type>(choice));
    		return *this;
    	}
    
    	constexpr auto& clear_match_event_indicator(MatchEventIndicator::Choice choice) noexcept
    	{
    		match_event_indicator_ = static_cast<MatchEventIndicator::value_type>(
    			match_event_indicator_ & ~static_cast<MatchEventIndicator::value_type>(choice));
    		return *this;
    	}
    
    private:
    	char block_trailing_padding_[3]{};
    
    
    private:
    	char buffer_[N]{};
    
    	const char *buffer() const
    	{
    		return buffer_;
    	}
    
    	char *buffer()
    	{
    		return buffer_;
    	}
    
    public:
    
    #pragma pack(push, 1)
    class NoRelatedSym
    {
    	template <std::size_t> friend class QuoteRequest39;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	char symbol_[20]{};
            
            public:
            	static constexpr std::size_t symbol_size() noexcept
            	{
            		return 20;
            	}
            
            	static constexpr std::size_t symbol_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t symbol_id() noexcept
            	{
            		return 55;
            	}
            
            	static constexpr const char *symbol_name() noexcept
            	{
            		return "Symbol";
            	}
            
            	constexpr char *symbol() noexcept
            	{
            		return symbol_;
            	}
            
            	constexpr const char *symbol() const noexcept
            	{
            		return symbol_;
            	}
            
            	constexpr std::string_view symbol_view() noexcept
            	{
            		return std::string_view(symbol_, 20);
            	}
            
            	constexpr const std::string_view symbol_view() const noexcept
            	{
            		return std::string_view(symbol_, 20);
            	}
            
            	const std::string symbol_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 20 && *(symbol_ + length) != '\0'; ++length);
            		return std::string(symbol_, length);
            	}
            
            	constexpr auto &set_symbol(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#pragma GCC diagnostic ignored "-Wstringop-overread"
            	#endif
            		std::memcpy(symbol_, value, symbol_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	// Safe: copy size bytes (capped at the field width) and NUL-pad the remainder.
            	auto &set_symbol(const char *value, std::size_t size) noexcept
            	{
            		const auto length = size < symbol_size() ? size : symbol_size();
            		std::memcpy(symbol_, value, length);
            		std::memset(symbol_ + length, 0, symbol_size() - length);
            		return *this;
            	}
            
            	auto &set_symbol(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#pragma GCC diagnostic ignored "-Wstringop-overread"
            	#endif
            		// auto size = std::min(symbol_size(), value.size());
            		std::memcpy(symbol_, value.data(), symbol_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	std::int32_t security_id_{};
            
            public:
            	static constexpr std::size_t security_id_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t security_id_offset() noexcept
            	{ 
            		return 20; 
            	}
            
            	static constexpr std::size_t security_id_id() noexcept
            	{ 
            		return 48; 
            	}
            	
            	static constexpr const char* security_id_name() noexcept
            	{ 
            		return "SecurityID"; 
            	}
            	
            	static constexpr std::int32_t security_id_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t security_id_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t security_id_null_value() noexcept
            	{
            		return INT32_MIN;
            	}
            
            	constexpr std::int32_t security_id() const noexcept
            	{ 
            		return security_id_;
            	}
            	
            	constexpr auto& set_security_id(std::int32_t value) noexcept
            	{
            		security_id_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int32_t order_qty_{};
            
            public:
            	static constexpr std::size_t order_qty_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t order_qty_offset() noexcept
            	{ 
            		return 24; 
            	}
            
            	static constexpr std::size_t order_qty_id() noexcept
            	{ 
            		return 38; 
            	}
            	
            	static constexpr const char* order_qty_name() noexcept
            	{ 
            		return "OrderQty"; 
            	}
            	
            	static constexpr std::int32_t order_qty_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t order_qty_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t order_qty_null_value() noexcept
            	{
            		return INT32_MAX;
            	}
            
            	constexpr std::int32_t order_qty() const noexcept
            	{ 
            		return order_qty_;
            	}
            	
            	constexpr auto& set_order_qty(std::int32_t value) noexcept
            	{
            		order_qty_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int8_t quote_type_{};
            
            public:
            	static constexpr std::size_t quote_type_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t quote_type_offset() noexcept
            	{ 
            		return 28; 
            	}
            
            	static constexpr std::size_t quote_type_id() noexcept
            	{ 
            		return 537; 
            	}
            	
            	static constexpr const char* quote_type_name() noexcept
            	{ 
            		return "QuoteType"; 
            	}
            	
            	static constexpr std::int8_t quote_type_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t quote_type_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t quote_type_null_value() noexcept
            	{
            		return INT8_MIN;
            	}
            
            	constexpr std::int8_t quote_type() const noexcept
            	{ 
            		return quote_type_;
            	}
            	
            	constexpr auto& set_quote_type(std::int8_t value) noexcept
            	{
            		quote_type_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int8_t side_{};
            
            public:
            	static constexpr std::size_t side_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t side_offset() noexcept
            	{ 
            		return 29; 
            	}
            
            	static constexpr std::size_t side_id() noexcept
            	{ 
            		return 54; 
            	}
            	
            	static constexpr const char* side_name() noexcept
            	{ 
            		return "Side"; 
            	}
            	
            	static constexpr std::int8_t side_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t side_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t side_null_value() noexcept
            	{
            		return INT8_MAX;
            	}
            
            	constexpr std::int8_t side() const noexcept
            	{ 
            		return side_;
            	}
            	
            	constexpr auto& set_side(std::int8_t value) noexcept
            	{
            		side_ = value;
            		return *this;
            	}
            
            
            private:
            	char block_trailing_padding_[2]{};
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoRelatedSym() = default;
    	NoRelatedSym(std::uint8_t count)
    		:header_(sizeof(NoRelatedSym::Entry), count) {}
    
    	Entry& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(GroupSize)
    			+ (this->header_.block_length() * group_id);
    		return *reinterpret_cast<Entry*>(buffer);
    	}
    
    	const Entry& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(GroupSize)
    			+ (this->header_.block_length() * group_id);
    		return *reinterpret_cast<const Entry*>(buffer);
    	}
    
    	const auto block_length() const noexcept
    	{
    		return header_.block_length();
    	}
    
    	const auto num_in_group() const noexcept
    	{
    		return header_.num_in_group();
    	}
    
    
    	template <class CharT, class Traits = std::char_traits<CharT>>
    	friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const NoRelatedSym &group)
    	{
    		os << "[";
    		for (auto i = 0; i < group.num_in_group(); i++)
    		{
    			if (i) { os << ", "; }
    			auto &g = group.get(i);
    			os << "{";
    			bool comma = false;
    			if(comma) { os << ", "; } os << "\"Symbol\": " << "\"" << g.symbol() << "\""; comma = true;
    			if(comma) { os << ", "; } os << "\"SecurityID\": " << g.security_id(); comma = true;
    			if(comma) { os << ", "; } os << "\"OrderQty\": " << g.order_qty(); comma = true;
    			if(comma) { os << ", "; } os << "\"QuoteType\": " << +g.quote_type(); comma = true;
    			if(comma) { os << ", "; } os << "\"Side\": " << +g.side(); comma = true;
    			os << "}";
    		}
    		os << "]";
    		return os;
    	}
    };
    #pragma pack(pop)
    
    private:
    	NoRelatedSym no_related_sym_{};
    
    public:
    	static constexpr std::size_t no_related_sym_size() noexcept
    	{
    		return sizeof(typename NoRelatedSym::Entry);
    	}
    
    	static constexpr std::size_t no_related_sym_id() noexcept
    	{ 
    		return 146; 
    	}
    	
    	static constexpr const char* no_related_sym_name() noexcept
    	{ 
    		return "NoRelatedSym"; 
    	}
    
    	std::size_t no_related_sym_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t no_related_sym_data_length() const noexcept
    	{
    		auto& group = no_related_sym();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoRelatedSym& no_related_sym() const noexcept
    	{ 
    		const auto* buf = buffer() + no_related_sym_offset();
    		return *reinterpret_cast<const NoRelatedSym*>(buf);
    	}
    	
    	NoRelatedSym& no_related_sym() noexcept
    	{
    		auto* buf = buffer() + no_related_sym_offset();
    		return *reinterpret_cast<NoRelatedSym*>(buf);
    	}
    
    	NoRelatedSym& AppendNoRelatedSym(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_related_sym_offset();
    		auto& group = *reinterpret_cast<NoRelatedSym*>(buf);
    		group.header_.set_block_length(sizeof(typename NoRelatedSym::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <std::size_t N, class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::QuoteRequest39<N> &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"TransactTime\": " << msg.transact_time(); comma = true;
	if(comma) { os << ", "; } os << "\"QuoteReqID\": " << "\"" << msg.quote_req_id() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"MatchEventIndicator\": " << MatchEventIndicator::to_string(msg.match_event_indicator()); comma = true;
	if(comma) { os << ", "; } os << "\"NoRelatedSym\": " << msg.no_related_sym(); comma = true;
	os << "}";
	return os;
}
}
