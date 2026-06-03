#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "SecurityTradingStatus.h"
#include "HaltReason.h"
#include "SecurityTradingEvent.h"

namespace fastsbe
{

#pragma pack(push, 1)
class SecurityStatus30
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "SecurityStatus30"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 30; 
    	}
    
    	static constexpr std::size_t schema() noexcept
    	{  
    		return 1; 
    	}
    
    	static constexpr std::size_t version() noexcept
    	{ 
    		return 13; 
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
    	char security_group_[6]{};
    
    public:
    	static constexpr std::size_t security_group_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t security_group_offset() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t security_group_id() noexcept
    	{
    		return 1151;
    	}
    
    	static constexpr const char *security_group_name() noexcept
    	{
    		return "SecurityGroup";
    	}
    
    	constexpr char *security_group() noexcept
    	{
    		return security_group_;
    	}
    
    	constexpr const char *security_group() const noexcept
    	{
    		return security_group_;
    	}
    
    	constexpr std::string_view security_group_view() noexcept
    	{
    		return std::string_view(security_group_, 6);
    	}
    
    	constexpr const std::string_view security_group_view() const noexcept
    	{
    		return std::string_view(security_group_, 6);
    	}
    
    	const std::string security_group_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(security_group_ + length) != '\0'; ++length);
    		return std::string(security_group_, length);
    	}
    
    	constexpr auto &set_security_group(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(security_group_, value, security_group_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_security_group(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(security_group_size(), value.size());
    		std::memcpy(security_group_, value.data(), security_group_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char asset_[6]{};
    
    public:
    	static constexpr std::size_t asset_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t asset_offset() noexcept
    	{
    		return 14;
    	}
    
    	static constexpr std::size_t asset_id() noexcept
    	{
    		return 6937;
    	}
    
    	static constexpr const char *asset_name() noexcept
    	{
    		return "Asset";
    	}
    
    	constexpr char *asset() noexcept
    	{
    		return asset_;
    	}
    
    	constexpr const char *asset() const noexcept
    	{
    		return asset_;
    	}
    
    	constexpr std::string_view asset_view() noexcept
    	{
    		return std::string_view(asset_, 6);
    	}
    
    	constexpr const std::string_view asset_view() const noexcept
    	{
    		return std::string_view(asset_, 6);
    	}
    
    	const std::string asset_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(asset_ + length) != '\0'; ++length);
    		return std::string(asset_, length);
    	}
    
    	constexpr auto &set_asset(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(asset_, value, asset_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_asset(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(asset_size(), value.size());
    		std::memcpy(asset_, value.data(), asset_size());
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
    		return INT32_MAX;
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
    	std::uint16_t trade_date_{};
    
    public:
    	static constexpr std::size_t trade_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trade_date_offset() noexcept
    	{ 
    		return 24; 
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
    	MatchEventIndicator::value_type match_event_indicator_{};
    
    public:
    	static constexpr std::size_t match_event_indicator_size() noexcept
    	{
    		return sizeof(MatchEventIndicator::value_type);
    	}
    
    	static constexpr std::size_t match_event_indicator_offset() noexcept
    	{
    		return 26;
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
    	SecurityTradingStatus::Value security_trading_status_{};
    
    public:
    	static constexpr std::size_t security_trading_status_size() noexcept
    	{
    		return sizeof(SecurityTradingStatus);
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
    
    	static constexpr SecurityTradingStatus::Value security_trading_status_null_value() noexcept
    	{
    		return SecurityTradingStatus::Value::nullValue;
    	}
    
    	constexpr SecurityTradingStatus::Value security_trading_status() const noexcept
    	{ 
    		return security_trading_status_;
    	}
    	
    	constexpr auto& set_security_trading_status(SecurityTradingStatus::Value value) noexcept
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
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SecurityStatus30 &msg)
{
	os << msg.transact_time_name() << ": " << msg.transact_time() << " ";
	os << msg.security_group_name() << ": " << msg.security_group() << " ";
	os << msg.asset_name() << ": " << msg.asset() << " ";
	os << msg.security_id_name() << ": " << msg.security_id() << " ";
	os << msg.trade_date_name() << ": " << msg.trade_date() << " ";
	os << msg.match_event_indicator_name() << ": " << MatchEventIndicator::to_string(msg.match_event_indicator()) << " ";
	os << msg.security_trading_status_name() << ": " << msg.security_trading_status() << " ";
	os << msg.halt_reason_name() << ": " << msg.halt_reason() << " ";
	os << msg.security_trading_event_name() << ": " << msg.security_trading_event() << " ";
	return os;
}
}
