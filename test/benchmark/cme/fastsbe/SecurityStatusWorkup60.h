#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "Pricenull9.h"
#include "MatchEventIndicator.h"
#include "WorkupTradingStatus.h"
#include "HaltReason.h"
#include "SecurityTradingEvent.h"
#include "Side.h"
#include "AggressorFlag.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityStatusWorkup60
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "SecurityStatusWorkup60"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 60; 
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
    		return 30;
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
    	Pricenull9 md_entry_px_{};
    
    public:
    	static constexpr std::size_t md_entry_px_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t md_entry_px_offset() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t md_entry_px_id() noexcept
    	{
    		return 270;
    	}
    
    	static constexpr const char *md_entry_px_name() noexcept
    	{
    		return "MDEntryPx";
    	}
    
    	constexpr const Pricenull9 &md_entry_px() const noexcept
    	{
    		return md_entry_px_;
    	}
    
    	constexpr Pricenull9 &md_entry_px() noexcept
    	{
    		return md_entry_px_;
    	}
    	constexpr auto &set_md_entry_px(Pricenull9 &value) noexcept
    	{
    		md_entry_px_ = value;
    		return *this;
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
    		return 16; 
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
    	MatchEventIndicator::value_type match_event_indicator_{};
    
    public:
    	static constexpr std::size_t match_event_indicator_size() noexcept
    	{
    		return sizeof(MatchEventIndicator::value_type);
    	}
    
    	static constexpr std::size_t match_event_indicator_offset() noexcept
    	{
    		return 20;
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
    	std::uint16_t trade_date_{};
    
    public:
    	static constexpr std::size_t trade_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trade_date_offset() noexcept
    	{ 
    		return 21; 
    	}
    
    	static constexpr std::size_t trade_date_id() noexcept
    	{ 
    		return 75; 
    	}
    	
    	static constexpr const char* trade_date_name() noexcept
    	{ 
    		return "TradeDate"; 
    	}
    	
    	static constexpr std::uint16_t trade_date_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t trade_date_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t trade_date_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t trade_date() const noexcept
    	{ 
    		return trade_date_;
    	}
    	
    	constexpr auto& set_trade_date(std::uint16_t value) noexcept
    	{
    		trade_date_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint32_t trade_link_id_{};
    
    public:
    	static constexpr std::size_t trade_link_id_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t trade_link_id_offset() noexcept
    	{ 
    		return 23; 
    	}
    
    	static constexpr std::size_t trade_link_id_id() noexcept
    	{ 
    		return 820; 
    	}
    	
    	static constexpr const char* trade_link_id_name() noexcept
    	{ 
    		return "TradeLinkID"; 
    	}
    	
    	static constexpr std::uint32_t trade_link_id_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t trade_link_id_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t trade_link_id_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t trade_link_id() const noexcept
    	{ 
    		return trade_link_id_;
    	}
    	
    	constexpr auto& set_trade_link_id(std::uint32_t value) noexcept
    	{
    		trade_link_id_ = value;
    		return *this;
    	}
    
    
    private:
    	WorkupTradingStatus::Value security_trading_status_{};
    
    public:
    	static constexpr std::size_t security_trading_status_size() noexcept
    	{
    		return sizeof(WorkupTradingStatus);
    	}
    
    	static constexpr std::size_t security_trading_status_offset() noexcept
    	{ 
    		return 27; 
    	}
    
    	static constexpr std::size_t security_trading_status_id() noexcept
    	{ 
    		return 326; 
    	}
    
    	static constexpr const char* security_trading_status_name() noexcept
    	{ 
    		return "SecurityTradingStatus"; 
    	}
    
    	static constexpr WorkupTradingStatus::Value security_trading_status_null_value() noexcept
    	{
    		return WorkupTradingStatus::Value::nullValue;
    	}
    
    	constexpr WorkupTradingStatus::Value security_trading_status() const noexcept
    	{ 
    		return security_trading_status_;
    	}
    	
    	constexpr auto& set_security_trading_status(WorkupTradingStatus::Value value) noexcept
    	{
    		security_trading_status_ = value;
    		return *this;
    	}
    
    
    private:
    	HaltReason::Value halt_reason_{};
    
    public:
    	static constexpr std::size_t halt_reason_size() noexcept
    	{
    		return sizeof(HaltReason);
    	}
    
    	static constexpr std::size_t halt_reason_offset() noexcept
    	{ 
    		return 28; 
    	}
    
    	static constexpr std::size_t halt_reason_id() noexcept
    	{ 
    		return 327; 
    	}
    
    	static constexpr const char* halt_reason_name() noexcept
    	{ 
    		return "HaltReason"; 
    	}
    
    	static constexpr HaltReason::Value halt_reason_null_value() noexcept
    	{
    		return HaltReason::Value::nullValue;
    	}
    
    	constexpr HaltReason::Value halt_reason() const noexcept
    	{ 
    		return halt_reason_;
    	}
    	
    	constexpr auto& set_halt_reason(HaltReason::Value value) noexcept
    	{
    		halt_reason_ = value;
    		return *this;
    	}
    
    
    private:
    	SecurityTradingEvent::Value security_trading_event_{};
    
    public:
    	static constexpr std::size_t security_trading_event_size() noexcept
    	{
    		return sizeof(SecurityTradingEvent);
    	}
    
    	static constexpr std::size_t security_trading_event_offset() noexcept
    	{ 
    		return 29; 
    	}
    
    	static constexpr std::size_t security_trading_event_id() noexcept
    	{ 
    		return 1174; 
    	}
    
    	static constexpr const char* security_trading_event_name() noexcept
    	{ 
    		return "SecurityTradingEvent"; 
    	}
    
    	static constexpr SecurityTradingEvent::Value security_trading_event_null_value() noexcept
    	{
    		return SecurityTradingEvent::Value::nullValue;
    	}
    
    	constexpr SecurityTradingEvent::Value security_trading_event() const noexcept
    	{ 
    		return security_trading_event_;
    	}
    	
    	constexpr auto& set_security_trading_event(SecurityTradingEvent::Value value) noexcept
    	{
    		security_trading_event_ = value;
    		return *this;
    	}
    
    
    private:
    	char buffer_[1024]{};
    
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
    class NoOrderIDEntries
    {
    	friend SecurityStatusWorkup60;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	std::uint64_t order_id_{};
            
            public:
            	static constexpr std::size_t order_id_size() noexcept
            	{
            		return sizeof(std::uint64_t);
            	}
            
            	static constexpr std::size_t order_id_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t order_id_id() noexcept
            	{ 
            		return 37; 
            	}
            	
            	static constexpr const char* order_id_name() noexcept
            	{ 
            		return "OrderID"; 
            	}
            	
            	static constexpr std::uint64_t order_id_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint64_t order_id_max_value() noexcept
            	{
            		return (UINT64_MAX - 1);
            	}
            	
            	static constexpr std::uint64_t order_id_null_value() noexcept
            	{
            		return UINT64_MAX;
            	}
            
            	constexpr std::uint64_t order_id() const noexcept
            	{ 
            		return order_id_;
            	}
            	
            	constexpr auto& set_order_id(std::uint64_t value) noexcept
            	{
            		order_id_ = value;
            		return *this;
            	}
            
            
            private:
            	Side::Value side_{};
            
            public:
            	static constexpr std::size_t side_size() noexcept
            	{
            		return sizeof(Side);
            	}
            
            	static constexpr std::size_t side_offset() noexcept
            	{ 
            		return 8; 
            	}
            
            	static constexpr std::size_t side_id() noexcept
            	{ 
            		return 54; 
            	}
            
            	static constexpr const char* side_name() noexcept
            	{ 
            		return "Side"; 
            	}
            
            	static constexpr Side::Value side_null_value() noexcept
            	{
            		return Side::Value::nullValue;
            	}
            
            	constexpr Side::Value side() const noexcept
            	{ 
            		return side_;
            	}
            	
            	constexpr auto& set_side(Side::Value value) noexcept
            	{
            		side_ = value;
            		return *this;
            	}
            
            
            private:
            	AggressorFlag::Value aggressor_indicator_{};
            
            public:
            	static constexpr std::size_t aggressor_indicator_size() noexcept
            	{
            		return sizeof(AggressorFlag);
            	}
            
            	static constexpr std::size_t aggressor_indicator_offset() noexcept
            	{ 
            		return 9; 
            	}
            
            	static constexpr std::size_t aggressor_indicator_id() noexcept
            	{ 
            		return 1057; 
            	}
            
            	static constexpr const char* aggressor_indicator_name() noexcept
            	{ 
            		return "AggressorIndicator"; 
            	}
            
            	static constexpr AggressorFlag::Value aggressor_indicator_null_value() noexcept
            	{
            		return AggressorFlag::Value::nullValue;
            	}
            
            	constexpr AggressorFlag::Value aggressor_indicator() const noexcept
            	{ 
            		return aggressor_indicator_;
            	}
            	
            	constexpr auto& set_aggressor_indicator(AggressorFlag::Value value) noexcept
            	{
            		aggressor_indicator_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoOrderIDEntries() = default;
    	NoOrderIDEntries(std::uint8_t count)
    		:header_(sizeof(NoOrderIDEntries::Entry), count) {}
    
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
    
    };
    #pragma pack(pop)
    
    private:
    	NoOrderIDEntries no_order_id_entries_{};
    
    public:
    	static constexpr std::size_t no_order_id_entries_size() noexcept
    	{
    		return sizeof(NoOrderIDEntries::Entry);
    	}
    
    	static constexpr std::size_t no_order_id_entries_id() noexcept
    	{ 
    		return 37705; 
    	}
    	
    	static constexpr const char* no_order_id_entries_name() noexcept
    	{ 
    		return "NoOrderIDEntries"; 
    	}
    
    	std::size_t no_order_id_entries_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t no_order_id_entries_data_length() const noexcept
    	{
    		auto& group = no_order_id_entries();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoOrderIDEntries& no_order_id_entries() const noexcept
    	{ 
    		const auto* buf = buffer() + no_order_id_entries_offset();
    		return *reinterpret_cast<const NoOrderIDEntries*>(buf);
    	}
    	
    	NoOrderIDEntries& no_order_id_entries() noexcept
    	{
    		auto* buf = buffer() + no_order_id_entries_offset();
    		return *reinterpret_cast<NoOrderIDEntries*>(buf);
    	}
    
    	NoOrderIDEntries& AppendNoOrderIDEntries(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_order_id_entries_offset();
    		auto& group = *reinterpret_cast<NoOrderIDEntries*>(buf);
    		group.header_.set_block_length(sizeof(NoOrderIDEntries::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityStatusWorkup60::NoOrderIDEntries &group)
{
	os << "[";
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		if (i) { os << ", "; }
		auto &g = group.get(i);
		os << "{";
		bool comma = false;
		if(comma) { os << ", "; } os << "\"OrderID\": " << g.order_id(); comma = true;
		if(comma) { os << ", "; } os << "\"Side\": " << "\"" << g.side() << "\""; comma = true;
		if(comma) { os << ", "; } os << "\"AggressorIndicator\": " << "\"" << g.aggressor_indicator() << "\""; comma = true;
		os << "}";
	}
	os << "]";
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityStatusWorkup60 &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"TransactTime\": " << msg.transact_time(); comma = true;
	if(comma) { os << ", "; } os << "\"MDEntryPx\": " << msg.md_entry_px(); comma = true;
	if(comma) { os << ", "; } os << "\"SecurityID\": " << msg.security_id(); comma = true;
	if(comma) { os << ", "; } os << "\"MatchEventIndicator\": " << MatchEventIndicator::to_string(msg.match_event_indicator()); comma = true;
	if(comma) { os << ", "; } os << "\"TradeDate\": " << msg.trade_date(); comma = true;
	if(comma) { os << ", "; } os << "\"TradeLinkID\": " << msg.trade_link_id(); comma = true;
	if(comma) { os << ", "; } os << "\"SecurityTradingStatus\": " << "\"" << msg.security_trading_status() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"HaltReason\": " << "\"" << msg.halt_reason() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"SecurityTradingEvent\": " << "\"" << msg.security_trading_event() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"NoOrderIDEntries\": " << msg.no_order_id_entries(); comma = true;
	os << "}";
	return os;
}
}
