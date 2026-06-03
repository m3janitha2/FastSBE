#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "SecurityUpdateAction.h"
#include "SecurityTradingStatus.h"
#include "MaturityMonthYear.h"
#include "Pricenull9.h"
#include "Decimal9.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "SettlPriceType.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "EventType.h"
#include "GroupSize.h"
#include "GroupSize.h"
#include "InstAttribValue.h"
#include "GroupSize.h"
#include "DecimalQty.h"
#include "GroupSize.h"
#include "LegSide.h"
#include "Pricenull9.h"
#include "DecimalQty.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
class MDInstrumentDefinitionSpread56
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "MDInstrumentDefinitionSpread56"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 56; 
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
    	MatchEventIndicator::value_type match_event_indicator_{};
    
    public:
    	static constexpr std::size_t match_event_indicator_size() noexcept
    	{
    		return sizeof(MatchEventIndicator::value_type);
    	}
    
    	static constexpr std::size_t match_event_indicator_offset() noexcept
    	{
    		return 0;
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
    	std::uint32_t tot_num_reports_{};
    
    public:
    	static constexpr std::size_t tot_num_reports_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t tot_num_reports_offset() noexcept
    	{ 
    		return 1; 
    	}
    
    	static constexpr std::size_t tot_num_reports_id() noexcept
    	{ 
    		return 911; 
    	}
    	
    	static constexpr const char* tot_num_reports_name() noexcept
    	{ 
    		return "TotNumReports"; 
    	}
    	
    	static constexpr std::uint32_t tot_num_reports_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t tot_num_reports_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t tot_num_reports_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t tot_num_reports() const noexcept
    	{ 
    		return tot_num_reports_;
    	}
    	
    	constexpr auto& set_tot_num_reports(std::uint32_t value) noexcept
    	{
    		tot_num_reports_ = value;
    		return *this;
    	}
    
    
    private:
    	SecurityUpdateAction::Value security_update_action_{};
    
    public:
    	static constexpr std::size_t security_update_action_size() noexcept
    	{
    		return sizeof(SecurityUpdateAction);
    	}
    
    	static constexpr std::size_t security_update_action_offset() noexcept
    	{ 
    		return 5; 
    	}
    
    	static constexpr std::size_t security_update_action_id() noexcept
    	{ 
    		return 980; 
    	}
    
    	static constexpr const char* security_update_action_name() noexcept
    	{ 
    		return "SecurityUpdateAction"; 
    	}
    
    	static constexpr SecurityUpdateAction::Value security_update_action_null_value() noexcept
    	{
    		return SecurityUpdateAction::Value::nullValue;
    	}
    
    	constexpr SecurityUpdateAction::Value security_update_action() const noexcept
    	{ 
    		return security_update_action_;
    	}
    	
    	constexpr auto& set_security_update_action(SecurityUpdateAction::Value value) noexcept
    	{
    		security_update_action_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint64_t last_update_time_{};
    
    public:
    	static constexpr std::size_t last_update_time_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t last_update_time_offset() noexcept
    	{ 
    		return 6; 
    	}
    
    	static constexpr std::size_t last_update_time_id() noexcept
    	{ 
    		return 779; 
    	}
    	
    	static constexpr const char* last_update_time_name() noexcept
    	{ 
    		return "LastUpdateTime"; 
    	}
    	
    	static constexpr std::uint64_t last_update_time_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t last_update_time_max_value() noexcept
    	{
    		return (UINT64_MAX - 1);
    	}
    	
    	static constexpr std::uint64_t last_update_time_null_value() noexcept
    	{
    		return UINT64_MAX;
    	}
    
    	constexpr std::uint64_t last_update_time() const noexcept
    	{ 
    		return last_update_time_;
    	}
    	
    	constexpr auto& set_last_update_time(std::uint64_t value) noexcept
    	{
    		last_update_time_ = value;
    		return *this;
    	}
    
    
    private:
    	SecurityTradingStatus::Value md_security_trading_status_{};
    
    public:
    	static constexpr std::size_t md_security_trading_status_size() noexcept
    	{
    		return sizeof(SecurityTradingStatus);
    	}
    
    	static constexpr std::size_t md_security_trading_status_offset() noexcept
    	{ 
    		return 14; 
    	}
    
    	static constexpr std::size_t md_security_trading_status_id() noexcept
    	{ 
    		return 1682; 
    	}
    
    	static constexpr const char* md_security_trading_status_name() noexcept
    	{ 
    		return "MDSecurityTradingStatus"; 
    	}
    
    	static constexpr SecurityTradingStatus::Value md_security_trading_status_null_value() noexcept
    	{
    		return SecurityTradingStatus::Value::nullValue;
    	}
    
    	constexpr SecurityTradingStatus::Value md_security_trading_status() const noexcept
    	{ 
    		return md_security_trading_status_;
    	}
    	
    	constexpr auto& set_md_security_trading_status(SecurityTradingStatus::Value value) noexcept
    	{
    		md_security_trading_status_ = value;
    		return *this;
    	}
    
    
    private:
    	std::int16_t appl_id_{};
    
    public:
    	static constexpr std::size_t appl_id_size() noexcept
    	{
    		return sizeof(std::int16_t);
    	}
    
    	static constexpr std::size_t appl_id_offset() noexcept
    	{ 
    		return 15; 
    	}
    
    	static constexpr std::size_t appl_id_id() noexcept
    	{ 
    		return 1180; 
    	}
    	
    	static constexpr const char* appl_id_name() noexcept
    	{ 
    		return "ApplID"; 
    	}
    	
    	static constexpr std::int16_t appl_id_min_value() noexcept
    	{ 
    		return (INT16_MIN + 1); 
    	}
    	
    	static constexpr std::int16_t appl_id_max_value() noexcept
    	{
    		return INT16_MAX;
    	}
    	
    	static constexpr std::int16_t appl_id_null_value() noexcept
    	{
    		return INT16_MIN;
    	}
    
    	constexpr std::int16_t appl_id() const noexcept
    	{ 
    		return appl_id_;
    	}
    	
    	constexpr auto& set_appl_id(std::int16_t value) noexcept
    	{
    		appl_id_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint8_t market_segment_id_{};
    
    public:
    	static constexpr std::size_t market_segment_id_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t market_segment_id_offset() noexcept
    	{ 
    		return 17; 
    	}
    
    	static constexpr std::size_t market_segment_id_id() noexcept
    	{ 
    		return 1300; 
    	}
    	
    	static constexpr const char* market_segment_id_name() noexcept
    	{ 
    		return "MarketSegmentID"; 
    	}
    	
    	static constexpr std::uint8_t market_segment_id_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t market_segment_id_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t market_segment_id_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t market_segment_id() const noexcept
    	{ 
    		return market_segment_id_;
    	}
    	
    	constexpr auto& set_market_segment_id(std::uint8_t value) noexcept
    	{
    		market_segment_id_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint8_t underlying_product_{};
    
    public:
    	static constexpr std::size_t underlying_product_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t underlying_product_offset() noexcept
    	{ 
    		return 18; 
    	}
    
    	static constexpr std::size_t underlying_product_id() noexcept
    	{ 
    		return 462; 
    	}
    	
    	static constexpr const char* underlying_product_name() noexcept
    	{ 
    		return "UnderlyingProduct"; 
    	}
    	
    	static constexpr std::uint8_t underlying_product_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t underlying_product_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t underlying_product_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t underlying_product() const noexcept
    	{ 
    		return underlying_product_;
    	}
    	
    	constexpr auto& set_underlying_product(std::uint8_t value) noexcept
    	{
    		underlying_product_ = value;
    		return *this;
    	}
    
    
    private:
    	char security_exchange_[4]{};
    
    public:
    	static constexpr std::size_t security_exchange_size() noexcept
    	{
    		return 4;
    	}
    
    	static constexpr std::size_t security_exchange_offset() noexcept
    	{
    		return 19;
    	}
    
    	static constexpr std::size_t security_exchange_id() noexcept
    	{
    		return 207;
    	}
    
    	static constexpr const char *security_exchange_name() noexcept
    	{
    		return "SecurityExchange";
    	}
    
    	constexpr char *security_exchange() noexcept
    	{
    		return security_exchange_;
    	}
    
    	constexpr const char *security_exchange() const noexcept
    	{
    		return security_exchange_;
    	}
    
    	constexpr std::string_view security_exchange_view() noexcept
    	{
    		return std::string_view(security_exchange_, 4);
    	}
    
    	constexpr const std::string_view security_exchange_view() const noexcept
    	{
    		return std::string_view(security_exchange_, 4);
    	}
    
    	const std::string security_exchange_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 4 && *(security_exchange_ + length) != '\0'; ++length);
    		return std::string(security_exchange_, length);
    	}
    
    	constexpr auto &set_security_exchange(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(security_exchange_, value, security_exchange_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_security_exchange(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(security_exchange_size(), value.size());
    		std::memcpy(security_exchange_, value.data(), security_exchange_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    		return 23;
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
    		return 29;
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
    	char symbol_[20]{};
    
    public:
    	static constexpr std::size_t symbol_size() noexcept
    	{
    		return 20;
    	}
    
    	static constexpr std::size_t symbol_offset() noexcept
    	{
    		return 35;
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
    	#endif
    		std::memcpy(symbol_, value, symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_symbol(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
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
    		return 55; 
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
    
    
    public:
    	static constexpr std::size_t security_id_source_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t security_id_source_offset() noexcept
    	{ 
    		return 59; 
    	}
    
    	static constexpr std::size_t security_id_source_id() noexcept
    	{ 
    		return 22; 
    	}
    	
    	static constexpr const char* security_id_source_name() noexcept
    	{ 
    		return "SecurityIDSource"; 
    	}
    
    	constexpr char security_id_source() const noexcept
    	{ 
    		return '8';
    	}
    
    
    private:
    	char security_type_[6]{};
    
    public:
    	static constexpr std::size_t security_type_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t security_type_offset() noexcept
    	{
    		return 59;
    	}
    
    	static constexpr std::size_t security_type_id() noexcept
    	{
    		return 167;
    	}
    
    	static constexpr const char *security_type_name() noexcept
    	{
    		return "SecurityType";
    	}
    
    	constexpr char *security_type() noexcept
    	{
    		return security_type_;
    	}
    
    	constexpr const char *security_type() const noexcept
    	{
    		return security_type_;
    	}
    
    	constexpr std::string_view security_type_view() noexcept
    	{
    		return std::string_view(security_type_, 6);
    	}
    
    	constexpr const std::string_view security_type_view() const noexcept
    	{
    		return std::string_view(security_type_, 6);
    	}
    
    	const std::string security_type_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(security_type_ + length) != '\0'; ++length);
    		return std::string(security_type_, length);
    	}
    
    	constexpr auto &set_security_type(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(security_type_, value, security_type_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_security_type(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(security_type_size(), value.size());
    		std::memcpy(security_type_, value.data(), security_type_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char cfi_code_[6]{};
    
    public:
    	static constexpr std::size_t cfi_code_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t cfi_code_offset() noexcept
    	{
    		return 65;
    	}
    
    	static constexpr std::size_t cfi_code_id() noexcept
    	{
    		return 461;
    	}
    
    	static constexpr const char *cfi_code_name() noexcept
    	{
    		return "CFICode";
    	}
    
    	constexpr char *cfi_code() noexcept
    	{
    		return cfi_code_;
    	}
    
    	constexpr const char *cfi_code() const noexcept
    	{
    		return cfi_code_;
    	}
    
    	constexpr std::string_view cfi_code_view() noexcept
    	{
    		return std::string_view(cfi_code_, 6);
    	}
    
    	constexpr const std::string_view cfi_code_view() const noexcept
    	{
    		return std::string_view(cfi_code_, 6);
    	}
    
    	const std::string cfi_code_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(cfi_code_ + length) != '\0'; ++length);
    		return std::string(cfi_code_, length);
    	}
    
    	constexpr auto &set_cfi_code(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(cfi_code_, value, cfi_code_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_cfi_code(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(cfi_code_size(), value.size());
    		std::memcpy(cfi_code_, value.data(), cfi_code_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	MaturityMonthYear maturity_month_year_{};
    
    public:
    	static constexpr std::size_t maturity_month_year_size() noexcept
    	{
    		return sizeof(MaturityMonthYear);
    	}
    
    	static constexpr std::size_t maturity_month_year_offset() noexcept
    	{
    		return 71;
    	}
    
    	static constexpr std::size_t maturity_month_year_id() noexcept
    	{
    		return 200;
    	}
    
    	static constexpr const char *maturity_month_year_name() noexcept
    	{
    		return "MaturityMonthYear";
    	}
    
    	constexpr const MaturityMonthYear &maturity_month_year() const noexcept
    	{
    		return maturity_month_year_;
    	}
    
    	constexpr MaturityMonthYear &maturity_month_year() noexcept
    	{
    		return maturity_month_year_;
    	}
    	constexpr auto &set_maturity_month_year(MaturityMonthYear &value) noexcept
    	{
    		maturity_month_year_ = value;
    		return *this;
    	}
    
    
    private:
    	char currency_[3]{};
    
    public:
    	static constexpr std::size_t currency_size() noexcept
    	{
    		return 3;
    	}
    
    	static constexpr std::size_t currency_offset() noexcept
    	{
    		return 76;
    	}
    
    	static constexpr std::size_t currency_id() noexcept
    	{
    		return 15;
    	}
    
    	static constexpr const char *currency_name() noexcept
    	{
    		return "Currency";
    	}
    
    	constexpr char *currency() noexcept
    	{
    		return currency_;
    	}
    
    	constexpr const char *currency() const noexcept
    	{
    		return currency_;
    	}
    
    	constexpr std::string_view currency_view() noexcept
    	{
    		return std::string_view(currency_, 3);
    	}
    
    	constexpr const std::string_view currency_view() const noexcept
    	{
    		return std::string_view(currency_, 3);
    	}
    
    	const std::string currency_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 3 && *(currency_ + length) != '\0'; ++length);
    		return std::string(currency_, length);
    	}
    
    	constexpr auto &set_currency(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(currency_, value, currency_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_currency(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(currency_size(), value.size());
    		std::memcpy(currency_, value.data(), currency_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char security_sub_type_[5]{};
    
    public:
    	static constexpr std::size_t security_sub_type_size() noexcept
    	{
    		return 5;
    	}
    
    	static constexpr std::size_t security_sub_type_offset() noexcept
    	{
    		return 79;
    	}
    
    	static constexpr std::size_t security_sub_type_id() noexcept
    	{
    		return 762;
    	}
    
    	static constexpr const char *security_sub_type_name() noexcept
    	{
    		return "SecuritySubType";
    	}
    
    	constexpr char *security_sub_type() noexcept
    	{
    		return security_sub_type_;
    	}
    
    	constexpr const char *security_sub_type() const noexcept
    	{
    		return security_sub_type_;
    	}
    
    	constexpr std::string_view security_sub_type_view() noexcept
    	{
    		return std::string_view(security_sub_type_, 5);
    	}
    
    	constexpr const std::string_view security_sub_type_view() const noexcept
    	{
    		return std::string_view(security_sub_type_, 5);
    	}
    
    	const std::string security_sub_type_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 5 && *(security_sub_type_ + length) != '\0'; ++length);
    		return std::string(security_sub_type_, length);
    	}
    
    	constexpr auto &set_security_sub_type(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(security_sub_type_, value, security_sub_type_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_security_sub_type(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(security_sub_type_size(), value.size());
    		std::memcpy(security_sub_type_, value.data(), security_sub_type_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char user_defined_instrument_{};
    
    public:
    	static constexpr std::size_t user_defined_instrument_size() noexcept
    	{
    		return sizeof(char);
    	}
    
    	static constexpr std::size_t user_defined_instrument_offset() noexcept
    	{ 
    		return 84; 
    	}
    
    	static constexpr std::size_t user_defined_instrument_id() noexcept
    	{ 
    		return 9779; 
    	}
    	
    	static constexpr const char* user_defined_instrument_name() noexcept
    	{ 
    		return "UserDefinedInstrument"; 
    	}
    	
    	static constexpr char user_defined_instrument_min_value() noexcept
    	{ 
    		return 32; 
    	}
    	
    	static constexpr char user_defined_instrument_max_value() noexcept
    	{
    		return 255;
    	}
    	
    	static constexpr char user_defined_instrument_null_value() noexcept
    	{
    		return 0;
    	}
    
    	constexpr char user_defined_instrument() const noexcept
    	{ 
    		return user_defined_instrument_;
    	}
    	
    	constexpr auto& set_user_defined_instrument(char value) noexcept
    	{
    		user_defined_instrument_ = value;
    		return *this;
    	}
    
    
    private:
    	char match_algorithm_{};
    
    public:
    	static constexpr std::size_t match_algorithm_size() noexcept
    	{
    		return sizeof(char);
    	}
    
    	static constexpr std::size_t match_algorithm_offset() noexcept
    	{ 
    		return 85; 
    	}
    
    	static constexpr std::size_t match_algorithm_id() noexcept
    	{ 
    		return 1142; 
    	}
    	
    	static constexpr const char* match_algorithm_name() noexcept
    	{ 
    		return "MatchAlgorithm"; 
    	}
    	
    	static constexpr char match_algorithm_min_value() noexcept
    	{ 
    		return 32; 
    	}
    	
    	static constexpr char match_algorithm_max_value() noexcept
    	{
    		return 255;
    	}
    	
    	static constexpr char match_algorithm_null_value() noexcept
    	{
    		return 0;
    	}
    
    	constexpr char match_algorithm() const noexcept
    	{ 
    		return match_algorithm_;
    	}
    	
    	constexpr auto& set_match_algorithm(char value) noexcept
    	{
    		match_algorithm_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint32_t min_trade_vol_{};
    
    public:
    	static constexpr std::size_t min_trade_vol_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t min_trade_vol_offset() noexcept
    	{ 
    		return 86; 
    	}
    
    	static constexpr std::size_t min_trade_vol_id() noexcept
    	{ 
    		return 562; 
    	}
    	
    	static constexpr const char* min_trade_vol_name() noexcept
    	{ 
    		return "MinTradeVol"; 
    	}
    	
    	static constexpr std::uint32_t min_trade_vol_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t min_trade_vol_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t min_trade_vol_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t min_trade_vol() const noexcept
    	{ 
    		return min_trade_vol_;
    	}
    	
    	constexpr auto& set_min_trade_vol(std::uint32_t value) noexcept
    	{
    		min_trade_vol_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint32_t max_trade_vol_{};
    
    public:
    	static constexpr std::size_t max_trade_vol_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t max_trade_vol_offset() noexcept
    	{ 
    		return 90; 
    	}
    
    	static constexpr std::size_t max_trade_vol_id() noexcept
    	{ 
    		return 1140; 
    	}
    	
    	static constexpr const char* max_trade_vol_name() noexcept
    	{ 
    		return "MaxTradeVol"; 
    	}
    	
    	static constexpr std::uint32_t max_trade_vol_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t max_trade_vol_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t max_trade_vol_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t max_trade_vol() const noexcept
    	{ 
    		return max_trade_vol_;
    	}
    	
    	constexpr auto& set_max_trade_vol(std::uint32_t value) noexcept
    	{
    		max_trade_vol_ = value;
    		return *this;
    	}
    
    
    private:
    	Pricenull9 min_price_increment_{};
    
    public:
    	static constexpr std::size_t min_price_increment_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t min_price_increment_offset() noexcept
    	{
    		return 94;
    	}
    
    	static constexpr std::size_t min_price_increment_id() noexcept
    	{
    		return 969;
    	}
    
    	static constexpr const char *min_price_increment_name() noexcept
    	{
    		return "MinPriceIncrement";
    	}
    
    	constexpr const Pricenull9 &min_price_increment() const noexcept
    	{
    		return min_price_increment_;
    	}
    
    	constexpr Pricenull9 &min_price_increment() noexcept
    	{
    		return min_price_increment_;
    	}
    	constexpr auto &set_min_price_increment(Pricenull9 &value) noexcept
    	{
    		min_price_increment_ = value;
    		return *this;
    	}
    
    
    private:
    	Decimal9 display_factor_{};
    
    public:
    	static constexpr std::size_t display_factor_size() noexcept
    	{
    		return sizeof(Decimal9);
    	}
    
    	static constexpr std::size_t display_factor_offset() noexcept
    	{
    		return 102;
    	}
    
    	static constexpr std::size_t display_factor_id() noexcept
    	{
    		return 9787;
    	}
    
    	static constexpr const char *display_factor_name() noexcept
    	{
    		return "DisplayFactor";
    	}
    
    	constexpr const Decimal9 &display_factor() const noexcept
    	{
    		return display_factor_;
    	}
    
    	constexpr Decimal9 &display_factor() noexcept
    	{
    		return display_factor_;
    	}
    	constexpr auto &set_display_factor(Decimal9 &value) noexcept
    	{
    		display_factor_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint8_t price_display_format_{};
    
    public:
    	static constexpr std::size_t price_display_format_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t price_display_format_offset() noexcept
    	{ 
    		return 110; 
    	}
    
    	static constexpr std::size_t price_display_format_id() noexcept
    	{ 
    		return 9800; 
    	}
    	
    	static constexpr const char* price_display_format_name() noexcept
    	{ 
    		return "PriceDisplayFormat"; 
    	}
    	
    	static constexpr std::uint8_t price_display_format_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t price_display_format_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t price_display_format_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t price_display_format() const noexcept
    	{ 
    		return price_display_format_;
    	}
    	
    	constexpr auto& set_price_display_format(std::uint8_t value) noexcept
    	{
    		price_display_format_ = value;
    		return *this;
    	}
    
    
    private:
    	Pricenull9 price_ratio_{};
    
    public:
    	static constexpr std::size_t price_ratio_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t price_ratio_offset() noexcept
    	{
    		return 111;
    	}
    
    	static constexpr std::size_t price_ratio_id() noexcept
    	{
    		return 5770;
    	}
    
    	static constexpr const char *price_ratio_name() noexcept
    	{
    		return "PriceRatio";
    	}
    
    	constexpr const Pricenull9 &price_ratio() const noexcept
    	{
    		return price_ratio_;
    	}
    
    	constexpr Pricenull9 &price_ratio() noexcept
    	{
    		return price_ratio_;
    	}
    	constexpr auto &set_price_ratio(Pricenull9 &value) noexcept
    	{
    		price_ratio_ = value;
    		return *this;
    	}
    
    
    private:
    	std::int8_t tick_rule_{};
    
    public:
    	static constexpr std::size_t tick_rule_size() noexcept
    	{
    		return sizeof(std::int8_t);
    	}
    
    	static constexpr std::size_t tick_rule_offset() noexcept
    	{ 
    		return 119; 
    	}
    
    	static constexpr std::size_t tick_rule_id() noexcept
    	{ 
    		return 6350; 
    	}
    	
    	static constexpr const char* tick_rule_name() noexcept
    	{ 
    		return "TickRule"; 
    	}
    	
    	static constexpr std::int8_t tick_rule_min_value() noexcept
    	{ 
    		return (INT8_MIN + 1); 
    	}
    	
    	static constexpr std::int8_t tick_rule_max_value() noexcept
    	{
    		return INT8_MAX;
    	}
    	
    	static constexpr std::int8_t tick_rule_null_value() noexcept
    	{
    		return INT8_MAX;
    	}
    
    	constexpr std::int8_t tick_rule() const noexcept
    	{ 
    		return tick_rule_;
    	}
    	
    	constexpr auto& set_tick_rule(std::int8_t value) noexcept
    	{
    		tick_rule_ = value;
    		return *this;
    	}
    
    
    private:
    	char unit_of_measure_[30]{};
    
    public:
    	static constexpr std::size_t unit_of_measure_size() noexcept
    	{
    		return 30;
    	}
    
    	static constexpr std::size_t unit_of_measure_offset() noexcept
    	{
    		return 120;
    	}
    
    	static constexpr std::size_t unit_of_measure_id() noexcept
    	{
    		return 996;
    	}
    
    	static constexpr const char *unit_of_measure_name() noexcept
    	{
    		return "UnitOfMeasure";
    	}
    
    	constexpr char *unit_of_measure() noexcept
    	{
    		return unit_of_measure_;
    	}
    
    	constexpr const char *unit_of_measure() const noexcept
    	{
    		return unit_of_measure_;
    	}
    
    	constexpr std::string_view unit_of_measure_view() noexcept
    	{
    		return std::string_view(unit_of_measure_, 30);
    	}
    
    	constexpr const std::string_view unit_of_measure_view() const noexcept
    	{
    		return std::string_view(unit_of_measure_, 30);
    	}
    
    	const std::string unit_of_measure_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 30 && *(unit_of_measure_ + length) != '\0'; ++length);
    		return std::string(unit_of_measure_, length);
    	}
    
    	constexpr auto &set_unit_of_measure(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(unit_of_measure_, value, unit_of_measure_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_unit_of_measure(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(unit_of_measure_size(), value.size());
    		std::memcpy(unit_of_measure_, value.data(), unit_of_measure_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	Pricenull9 trading_reference_price_{};
    
    public:
    	static constexpr std::size_t trading_reference_price_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t trading_reference_price_offset() noexcept
    	{
    		return 150;
    	}
    
    	static constexpr std::size_t trading_reference_price_id() noexcept
    	{
    		return 1150;
    	}
    
    	static constexpr const char *trading_reference_price_name() noexcept
    	{
    		return "TradingReferencePrice";
    	}
    
    	constexpr const Pricenull9 &trading_reference_price() const noexcept
    	{
    		return trading_reference_price_;
    	}
    
    	constexpr Pricenull9 &trading_reference_price() noexcept
    	{
    		return trading_reference_price_;
    	}
    	constexpr auto &set_trading_reference_price(Pricenull9 &value) noexcept
    	{
    		trading_reference_price_ = value;
    		return *this;
    	}
    
    
    private:
    	SettlPriceType::value_type settl_price_type_{};
    
    public:
    	static constexpr std::size_t settl_price_type_size() noexcept
    	{
    		return sizeof(SettlPriceType::value_type);
    	}
    
    	static constexpr std::size_t settl_price_type_offset() noexcept
    	{
    		return 158;
    	}
    
    	static constexpr std::size_t settl_price_type_id() noexcept
    	{
    		return 731;
    	}
    
    	static constexpr const char* settl_price_type_name() noexcept
    	{
    		return "SettlPriceType";
    	}
    
    	// raw whole-field access (low-latency path)
    	constexpr SettlPriceType::value_type settl_price_type() const noexcept
    	{
    		return settl_price_type_;
    	}
    
    	constexpr auto& set_settl_price_type(SettlPriceType::value_type value) noexcept
    	{
    		settl_price_type_ = value;
    		return *this;
    	}
    
    	// per-choice access; choices combine with operator| (A | B | C)
    	constexpr bool settl_price_type(SettlPriceType::Choice choice) const noexcept
    	{
    		return (settl_price_type_ & static_cast<SettlPriceType::value_type>(choice))
    			== static_cast<SettlPriceType::value_type>(choice);
    	}
    
    	constexpr auto& set_settl_price_type(SettlPriceType::Choice choice) noexcept
    	{
    		settl_price_type_ = static_cast<SettlPriceType::value_type>(
    			settl_price_type_ | static_cast<SettlPriceType::value_type>(choice));
    		return *this;
    	}
    
    	constexpr auto& clear_settl_price_type(SettlPriceType::Choice choice) noexcept
    	{
    		settl_price_type_ = static_cast<SettlPriceType::value_type>(
    			settl_price_type_ & ~static_cast<SettlPriceType::value_type>(choice));
    		return *this;
    	}
    
    private:
    	std::int32_t open_interest_qty_{};
    
    public:
    	static constexpr std::size_t open_interest_qty_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t open_interest_qty_offset() noexcept
    	{ 
    		return 159; 
    	}
    
    	static constexpr std::size_t open_interest_qty_id() noexcept
    	{ 
    		return 5792; 
    	}
    	
    	static constexpr const char* open_interest_qty_name() noexcept
    	{ 
    		return "OpenInterestQty"; 
    	}
    	
    	static constexpr std::int32_t open_interest_qty_min_value() noexcept
    	{ 
    		return (INT32_MIN + 1); 
    	}
    	
    	static constexpr std::int32_t open_interest_qty_max_value() noexcept
    	{
    		return INT32_MAX;
    	}
    	
    	static constexpr std::int32_t open_interest_qty_null_value() noexcept
    	{
    		return INT32_MAX;
    	}
    
    	constexpr std::int32_t open_interest_qty() const noexcept
    	{ 
    		return open_interest_qty_;
    	}
    	
    	constexpr auto& set_open_interest_qty(std::int32_t value) noexcept
    	{
    		open_interest_qty_ = value;
    		return *this;
    	}
    
    
    private:
    	std::int32_t cleared_volume_{};
    
    public:
    	static constexpr std::size_t cleared_volume_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t cleared_volume_offset() noexcept
    	{ 
    		return 163; 
    	}
    
    	static constexpr std::size_t cleared_volume_id() noexcept
    	{ 
    		return 5791; 
    	}
    	
    	static constexpr const char* cleared_volume_name() noexcept
    	{ 
    		return "ClearedVolume"; 
    	}
    	
    	static constexpr std::int32_t cleared_volume_min_value() noexcept
    	{ 
    		return (INT32_MIN + 1); 
    	}
    	
    	static constexpr std::int32_t cleared_volume_max_value() noexcept
    	{
    		return INT32_MAX;
    	}
    	
    	static constexpr std::int32_t cleared_volume_null_value() noexcept
    	{
    		return INT32_MAX;
    	}
    
    	constexpr std::int32_t cleared_volume() const noexcept
    	{ 
    		return cleared_volume_;
    	}
    	
    	constexpr auto& set_cleared_volume(std::int32_t value) noexcept
    	{
    		cleared_volume_ = value;
    		return *this;
    	}
    
    
    private:
    	Pricenull9 high_limit_price_{};
    
    public:
    	static constexpr std::size_t high_limit_price_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t high_limit_price_offset() noexcept
    	{
    		return 167;
    	}
    
    	static constexpr std::size_t high_limit_price_id() noexcept
    	{
    		return 1149;
    	}
    
    	static constexpr const char *high_limit_price_name() noexcept
    	{
    		return "HighLimitPrice";
    	}
    
    	constexpr const Pricenull9 &high_limit_price() const noexcept
    	{
    		return high_limit_price_;
    	}
    
    	constexpr Pricenull9 &high_limit_price() noexcept
    	{
    		return high_limit_price_;
    	}
    	constexpr auto &set_high_limit_price(Pricenull9 &value) noexcept
    	{
    		high_limit_price_ = value;
    		return *this;
    	}
    
    
    private:
    	Pricenull9 low_limit_price_{};
    
    public:
    	static constexpr std::size_t low_limit_price_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t low_limit_price_offset() noexcept
    	{
    		return 175;
    	}
    
    	static constexpr std::size_t low_limit_price_id() noexcept
    	{
    		return 1148;
    	}
    
    	static constexpr const char *low_limit_price_name() noexcept
    	{
    		return "LowLimitPrice";
    	}
    
    	constexpr const Pricenull9 &low_limit_price() const noexcept
    	{
    		return low_limit_price_;
    	}
    
    	constexpr Pricenull9 &low_limit_price() noexcept
    	{
    		return low_limit_price_;
    	}
    	constexpr auto &set_low_limit_price(Pricenull9 &value) noexcept
    	{
    		low_limit_price_ = value;
    		return *this;
    	}
    
    
    private:
    	Pricenull9 max_price_variation_{};
    
    public:
    	static constexpr std::size_t max_price_variation_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t max_price_variation_offset() noexcept
    	{
    		return 183;
    	}
    
    	static constexpr std::size_t max_price_variation_id() noexcept
    	{
    		return 1143;
    	}
    
    	static constexpr const char *max_price_variation_name() noexcept
    	{
    		return "MaxPriceVariation";
    	}
    
    	constexpr const Pricenull9 &max_price_variation() const noexcept
    	{
    		return max_price_variation_;
    	}
    
    	constexpr Pricenull9 &max_price_variation() noexcept
    	{
    		return max_price_variation_;
    	}
    	constexpr auto &set_max_price_variation(Pricenull9 &value) noexcept
    	{
    		max_price_variation_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint8_t main_fraction_{};
    
    public:
    	static constexpr std::size_t main_fraction_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t main_fraction_offset() noexcept
    	{ 
    		return 191; 
    	}
    
    	static constexpr std::size_t main_fraction_id() noexcept
    	{ 
    		return 37702; 
    	}
    	
    	static constexpr const char* main_fraction_name() noexcept
    	{ 
    		return "MainFraction"; 
    	}
    	
    	static constexpr std::uint8_t main_fraction_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t main_fraction_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t main_fraction_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t main_fraction() const noexcept
    	{ 
    		return main_fraction_;
    	}
    	
    	constexpr auto& set_main_fraction(std::uint8_t value) noexcept
    	{
    		main_fraction_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint8_t sub_fraction_{};
    
    public:
    	static constexpr std::size_t sub_fraction_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t sub_fraction_offset() noexcept
    	{ 
    		return 192; 
    	}
    
    	static constexpr std::size_t sub_fraction_id() noexcept
    	{ 
    		return 37703; 
    	}
    	
    	static constexpr const char* sub_fraction_name() noexcept
    	{ 
    		return "SubFraction"; 
    	}
    	
    	static constexpr std::uint8_t sub_fraction_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t sub_fraction_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t sub_fraction_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t sub_fraction() const noexcept
    	{ 
    		return sub_fraction_;
    	}
    	
    	constexpr auto& set_sub_fraction(std::uint8_t value) noexcept
    	{
    		sub_fraction_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint16_t trading_reference_date_{};
    
    public:
    	static constexpr std::size_t trading_reference_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trading_reference_date_offset() noexcept
    	{ 
    		return 193; 
    	}
    
    	static constexpr std::size_t trading_reference_date_id() noexcept
    	{ 
    		return 5796; 
    	}
    	
    	static constexpr const char* trading_reference_date_name() noexcept
    	{ 
    		return "TradingReferenceDate"; 
    	}
    	
    	static constexpr std::uint16_t trading_reference_date_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t trading_reference_date_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t trading_reference_date_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t trading_reference_date() const noexcept
    	{ 
    		return trading_reference_date_;
    	}
    	
    	constexpr auto& set_trading_reference_date(std::uint16_t value) noexcept
    	{
    		trading_reference_date_ = value;
    		return *this;
    	}
    
    
    private:
    	char price_quote_method_[5]{};
    
    public:
    	static constexpr std::size_t price_quote_method_size() noexcept
    	{
    		return 5;
    	}
    
    	static constexpr std::size_t price_quote_method_offset() noexcept
    	{
    		return 195;
    	}
    
    	static constexpr std::size_t price_quote_method_id() noexcept
    	{
    		return 1196;
    	}
    
    	static constexpr const char *price_quote_method_name() noexcept
    	{
    		return "PriceQuoteMethod";
    	}
    
    	constexpr char *price_quote_method() noexcept
    	{
    		return price_quote_method_;
    	}
    
    	constexpr const char *price_quote_method() const noexcept
    	{
    		return price_quote_method_;
    	}
    
    	constexpr std::string_view price_quote_method_view() noexcept
    	{
    		return std::string_view(price_quote_method_, 5);
    	}
    
    	constexpr const std::string_view price_quote_method_view() const noexcept
    	{
    		return std::string_view(price_quote_method_, 5);
    	}
    
    	const std::string price_quote_method_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 5 && *(price_quote_method_ + length) != '\0'; ++length);
    		return std::string(price_quote_method_, length);
    	}
    
    	constexpr auto &set_price_quote_method(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(price_quote_method_, value, price_quote_method_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_price_quote_method(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(price_quote_method_size(), value.size());
    		std::memcpy(price_quote_method_, value.data(), price_quote_method_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char risk_set_[6]{};
    
    public:
    	static constexpr std::size_t risk_set_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t risk_set_offset() noexcept
    	{
    		return 200;
    	}
    
    	static constexpr std::size_t risk_set_id() noexcept
    	{
    		return 37721;
    	}
    
    	static constexpr const char *risk_set_name() noexcept
    	{
    		return "RiskSet";
    	}
    
    	constexpr char *risk_set() noexcept
    	{
    		return risk_set_;
    	}
    
    	constexpr const char *risk_set() const noexcept
    	{
    		return risk_set_;
    	}
    
    	constexpr std::string_view risk_set_view() noexcept
    	{
    		return std::string_view(risk_set_, 6);
    	}
    
    	constexpr const std::string_view risk_set_view() const noexcept
    	{
    		return std::string_view(risk_set_, 6);
    	}
    
    	const std::string risk_set_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(risk_set_ + length) != '\0'; ++length);
    		return std::string(risk_set_, length);
    	}
    
    	constexpr auto &set_risk_set(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(risk_set_, value, risk_set_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_risk_set(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(risk_set_size(), value.size());
    		std::memcpy(risk_set_, value.data(), risk_set_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char market_set_[6]{};
    
    public:
    	static constexpr std::size_t market_set_size() noexcept
    	{
    		return 6;
    	}
    
    	static constexpr std::size_t market_set_offset() noexcept
    	{
    		return 206;
    	}
    
    	static constexpr std::size_t market_set_id() noexcept
    	{
    		return 37722;
    	}
    
    	static constexpr const char *market_set_name() noexcept
    	{
    		return "MarketSet";
    	}
    
    	constexpr char *market_set() noexcept
    	{
    		return market_set_;
    	}
    
    	constexpr const char *market_set() const noexcept
    	{
    		return market_set_;
    	}
    
    	constexpr std::string_view market_set_view() noexcept
    	{
    		return std::string_view(market_set_, 6);
    	}
    
    	constexpr const std::string_view market_set_view() const noexcept
    	{
    		return std::string_view(market_set_, 6);
    	}
    
    	const std::string market_set_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 6 && *(market_set_ + length) != '\0'; ++length);
    		return std::string(market_set_, length);
    	}
    
    	constexpr auto &set_market_set(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(market_set_, value, market_set_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_market_set(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(market_set_size(), value.size());
    		std::memcpy(market_set_, value.data(), market_set_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	std::uint64_t instrument_guid_{};
    
    public:
    	static constexpr std::size_t instrument_guid_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t instrument_guid_offset() noexcept
    	{ 
    		return 212; 
    	}
    
    	static constexpr std::size_t instrument_guid_id() noexcept
    	{ 
    		return 37513; 
    	}
    	
    	static constexpr const char* instrument_guid_name() noexcept
    	{ 
    		return "InstrumentGUID"; 
    	}
    	
    	static constexpr std::uint64_t instrument_guid_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t instrument_guid_max_value() noexcept
    	{
    		return (UINT64_MAX - 1);
    	}
    	
    	static constexpr std::uint64_t instrument_guid_null_value() noexcept
    	{
    		return UINT64_MAX;
    	}
    
    	constexpr std::uint64_t instrument_guid() const noexcept
    	{ 
    		return instrument_guid_;
    	}
    	
    	constexpr auto& set_instrument_guid(std::uint64_t value) noexcept
    	{
    		instrument_guid_ = value;
    		return *this;
    	}
    
    
    private:
    	char financial_instrument_full_name_[35]{};
    
    public:
    	static constexpr std::size_t financial_instrument_full_name_size() noexcept
    	{
    		return 35;
    	}
    
    	static constexpr std::size_t financial_instrument_full_name_offset() noexcept
    	{
    		return 220;
    	}
    
    	static constexpr std::size_t financial_instrument_full_name_id() noexcept
    	{
    		return 2714;
    	}
    
    	static constexpr const char *financial_instrument_full_name_name() noexcept
    	{
    		return "FinancialInstrumentFullName";
    	}
    
    	constexpr char *financial_instrument_full_name() noexcept
    	{
    		return financial_instrument_full_name_;
    	}
    
    	constexpr const char *financial_instrument_full_name() const noexcept
    	{
    		return financial_instrument_full_name_;
    	}
    
    	constexpr std::string_view financial_instrument_full_name_view() noexcept
    	{
    		return std::string_view(financial_instrument_full_name_, 35);
    	}
    
    	constexpr const std::string_view financial_instrument_full_name_view() const noexcept
    	{
    		return std::string_view(financial_instrument_full_name_, 35);
    	}
    
    	const std::string financial_instrument_full_name_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 35 && *(financial_instrument_full_name_ + length) != '\0'; ++length);
    		return std::string(financial_instrument_full_name_, length);
    	}
    
    	constexpr auto &set_financial_instrument_full_name(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(financial_instrument_full_name_, value, financial_instrument_full_name_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_financial_instrument_full_name(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(financial_instrument_full_name_size(), value.size());
    		std::memcpy(financial_instrument_full_name_, value.data(), financial_instrument_full_name_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    class NoEvents
    {
    	friend MDInstrumentDefinitionSpread56;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	EventType::Value event_type_{};
            
            public:
            	static constexpr std::size_t event_type_size() noexcept
            	{
            		return sizeof(EventType);
            	}
            
            	static constexpr std::size_t event_type_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t event_type_id() noexcept
            	{ 
            		return 865; 
            	}
            
            	static constexpr const char* event_type_name() noexcept
            	{ 
            		return "EventType"; 
            	}
            
            	static constexpr EventType::Value event_type_null_value() noexcept
            	{
            		return EventType::Value::nullValue;
            	}
            
            	constexpr EventType::Value event_type() const noexcept
            	{ 
            		return event_type_;
            	}
            	
            	constexpr auto& set_event_type(EventType::Value value) noexcept
            	{
            		event_type_ = value;
            		return *this;
            	}
            
            
            private:
            	std::uint64_t event_time_{};
            
            public:
            	static constexpr std::size_t event_time_size() noexcept
            	{
            		return sizeof(std::uint64_t);
            	}
            
            	static constexpr std::size_t event_time_offset() noexcept
            	{ 
            		return 1; 
            	}
            
            	static constexpr std::size_t event_time_id() noexcept
            	{ 
            		return 1145; 
            	}
            	
            	static constexpr const char* event_time_name() noexcept
            	{ 
            		return "EventTime"; 
            	}
            	
            	static constexpr std::uint64_t event_time_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint64_t event_time_max_value() noexcept
            	{
            		return (UINT64_MAX - 1);
            	}
            	
            	static constexpr std::uint64_t event_time_null_value() noexcept
            	{
            		return UINT64_MAX;
            	}
            
            	constexpr std::uint64_t event_time() const noexcept
            	{ 
            		return event_time_;
            	}
            	
            	constexpr auto& set_event_time(std::uint64_t value) noexcept
            	{
            		event_time_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoEvents() = default;
    	NoEvents(std::uint8_t count)
    		:header_(sizeof(NoEvents::Entry), count) {}
    
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
    	NoEvents no_events_{};
    
    public:
    	static constexpr std::size_t no_events_size() noexcept
    	{
    		return sizeof(NoEvents::Entry);
    	}
    
    	static constexpr std::size_t no_events_id() noexcept
    	{ 
    		return 864; 
    	}
    	
    	static constexpr const char* no_events_name() noexcept
    	{ 
    		return "NoEvents"; 
    	}
    
    	std::size_t no_events_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t no_events_data_length() const noexcept
    	{
    		auto& group = no_events();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoEvents& no_events() const noexcept
    	{ 
    		const auto* buf = buffer() + no_events_offset();
    		return *reinterpret_cast<const NoEvents*>(buf);
    	}
    	
    	NoEvents& no_events() noexcept
    	{
    		auto* buf = buffer() + no_events_offset();
    		return *reinterpret_cast<NoEvents*>(buf);
    	}
    
    	NoEvents& AppendNoEvents(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_events_offset();
    		auto& group = *reinterpret_cast<NoEvents*>(buf);
    		group.header_.set_block_length(sizeof(NoEvents::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    #pragma pack(push, 1)
    class NoMDFeedTypes
    {
    	friend MDInstrumentDefinitionSpread56;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	char md_feed_type_[3]{};
            
            public:
            	static constexpr std::size_t md_feed_type_size() noexcept
            	{
            		return 3;
            	}
            
            	static constexpr std::size_t md_feed_type_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t md_feed_type_id() noexcept
            	{
            		return 1022;
            	}
            
            	static constexpr const char *md_feed_type_name() noexcept
            	{
            		return "MDFeedType";
            	}
            
            	constexpr char *md_feed_type() noexcept
            	{
            		return md_feed_type_;
            	}
            
            	constexpr const char *md_feed_type() const noexcept
            	{
            		return md_feed_type_;
            	}
            
            	constexpr std::string_view md_feed_type_view() noexcept
            	{
            		return std::string_view(md_feed_type_, 3);
            	}
            
            	constexpr const std::string_view md_feed_type_view() const noexcept
            	{
            		return std::string_view(md_feed_type_, 3);
            	}
            
            	const std::string md_feed_type_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 3 && *(md_feed_type_ + length) != '\0'; ++length);
            		return std::string(md_feed_type_, length);
            	}
            
            	constexpr auto &set_md_feed_type(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(md_feed_type_, value, md_feed_type_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_md_feed_type(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(md_feed_type_size(), value.size());
            		std::memcpy(md_feed_type_, value.data(), md_feed_type_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	std::int8_t market_depth_{};
            
            public:
            	static constexpr std::size_t market_depth_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t market_depth_offset() noexcept
            	{ 
            		return 3; 
            	}
            
            	static constexpr std::size_t market_depth_id() noexcept
            	{ 
            		return 264; 
            	}
            	
            	static constexpr const char* market_depth_name() noexcept
            	{ 
            		return "MarketDepth"; 
            	}
            	
            	static constexpr std::int8_t market_depth_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t market_depth_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t market_depth_null_value() noexcept
            	{
            		return INT8_MIN;
            	}
            
            	constexpr std::int8_t market_depth() const noexcept
            	{ 
            		return market_depth_;
            	}
            	
            	constexpr auto& set_market_depth(std::int8_t value) noexcept
            	{
            		market_depth_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoMDFeedTypes() = default;
    	NoMDFeedTypes(std::uint8_t count)
    		:header_(sizeof(NoMDFeedTypes::Entry), count) {}
    
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
    	NoMDFeedTypes no_md_feed_types_{};
    
    public:
    	static constexpr std::size_t no_md_feed_types_size() noexcept
    	{
    		return sizeof(NoMDFeedTypes::Entry);
    	}
    
    	static constexpr std::size_t no_md_feed_types_id() noexcept
    	{ 
    		return 1141; 
    	}
    	
    	static constexpr const char* no_md_feed_types_name() noexcept
    	{ 
    		return "NoMDFeedTypes"; 
    	}
    
    	std::size_t no_md_feed_types_offset() const noexcept
    	{
    		return no_events_offset() + sizeof(NoEvents::header_) + no_events_data_length();
    	}
    
    	std::size_t no_md_feed_types_data_length() const noexcept
    	{
    		auto& group = no_md_feed_types();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoMDFeedTypes& no_md_feed_types() const noexcept
    	{ 
    		const auto* buf = buffer() + no_md_feed_types_offset();
    		return *reinterpret_cast<const NoMDFeedTypes*>(buf);
    	}
    	
    	NoMDFeedTypes& no_md_feed_types() noexcept
    	{
    		auto* buf = buffer() + no_md_feed_types_offset();
    		return *reinterpret_cast<NoMDFeedTypes*>(buf);
    	}
    
    	NoMDFeedTypes& AppendNoMDFeedTypes(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_md_feed_types_offset();
    		auto& group = *reinterpret_cast<NoMDFeedTypes*>(buf);
    		group.header_.set_block_length(sizeof(NoMDFeedTypes::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    #pragma pack(push, 1)
    class NoInstAttrib
    {
    	friend MDInstrumentDefinitionSpread56;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            public:
            	static constexpr std::size_t inst_attrib_type_size() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t inst_attrib_type_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t inst_attrib_type_id() noexcept
            	{ 
            		return 871; 
            	}
            	
            	static constexpr const char* inst_attrib_type_name() noexcept
            	{ 
            		return "InstAttribType"; 
            	}
            
            	constexpr std::int8_t inst_attrib_type() const noexcept
            	{ 
            		return 24;
            	}
            
            
            private:
            	InstAttribValue::value_type inst_attrib_value_{};
            
            public:
            	static constexpr std::size_t inst_attrib_value_size() noexcept
            	{
            		return sizeof(InstAttribValue::value_type);
            	}
            
            	static constexpr std::size_t inst_attrib_value_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t inst_attrib_value_id() noexcept
            	{
            		return 872;
            	}
            
            	static constexpr const char* inst_attrib_value_name() noexcept
            	{
            		return "InstAttribValue";
            	}
            
            	// raw whole-field access (low-latency path)
            	constexpr InstAttribValue::value_type inst_attrib_value() const noexcept
            	{
            		return inst_attrib_value_;
            	}
            
            	constexpr auto& set_inst_attrib_value(InstAttribValue::value_type value) noexcept
            	{
            		inst_attrib_value_ = value;
            		return *this;
            	}
            
            	// per-choice access; choices combine with operator| (A | B | C)
            	constexpr bool inst_attrib_value(InstAttribValue::Choice choice) const noexcept
            	{
            		return (inst_attrib_value_ & static_cast<InstAttribValue::value_type>(choice))
            			== static_cast<InstAttribValue::value_type>(choice);
            	}
            
            	constexpr auto& set_inst_attrib_value(InstAttribValue::Choice choice) noexcept
            	{
            		inst_attrib_value_ = static_cast<InstAttribValue::value_type>(
            			inst_attrib_value_ | static_cast<InstAttribValue::value_type>(choice));
            		return *this;
            	}
            
            	constexpr auto& clear_inst_attrib_value(InstAttribValue::Choice choice) noexcept
            	{
            		inst_attrib_value_ = static_cast<InstAttribValue::value_type>(
            			inst_attrib_value_ & ~static_cast<InstAttribValue::value_type>(choice));
            		return *this;
            	}
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoInstAttrib() = default;
    	NoInstAttrib(std::uint8_t count)
    		:header_(sizeof(NoInstAttrib::Entry), count) {}
    
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
    	NoInstAttrib no_inst_attrib_{};
    
    public:
    	static constexpr std::size_t no_inst_attrib_size() noexcept
    	{
    		return sizeof(NoInstAttrib::Entry);
    	}
    
    	static constexpr std::size_t no_inst_attrib_id() noexcept
    	{ 
    		return 870; 
    	}
    	
    	static constexpr const char* no_inst_attrib_name() noexcept
    	{ 
    		return "NoInstAttrib"; 
    	}
    
    	std::size_t no_inst_attrib_offset() const noexcept
    	{
    		return no_md_feed_types_offset() + sizeof(NoMDFeedTypes::header_) + no_md_feed_types_data_length();
    	}
    
    	std::size_t no_inst_attrib_data_length() const noexcept
    	{
    		auto& group = no_inst_attrib();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoInstAttrib& no_inst_attrib() const noexcept
    	{ 
    		const auto* buf = buffer() + no_inst_attrib_offset();
    		return *reinterpret_cast<const NoInstAttrib*>(buf);
    	}
    	
    	NoInstAttrib& no_inst_attrib() noexcept
    	{
    		auto* buf = buffer() + no_inst_attrib_offset();
    		return *reinterpret_cast<NoInstAttrib*>(buf);
    	}
    
    	NoInstAttrib& AppendNoInstAttrib(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_inst_attrib_offset();
    		auto& group = *reinterpret_cast<NoInstAttrib*>(buf);
    		group.header_.set_block_length(sizeof(NoInstAttrib::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    #pragma pack(push, 1)
    class NoLotTypeRules
    {
    	friend MDInstrumentDefinitionSpread56;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	std::int8_t lot_type_{};
            
            public:
            	static constexpr std::size_t lot_type_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t lot_type_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t lot_type_id() noexcept
            	{ 
            		return 1093; 
            	}
            	
            	static constexpr const char* lot_type_name() noexcept
            	{ 
            		return "LotType"; 
            	}
            	
            	static constexpr std::int8_t lot_type_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t lot_type_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t lot_type_null_value() noexcept
            	{
            		return INT8_MIN;
            	}
            
            	constexpr std::int8_t lot_type() const noexcept
            	{ 
            		return lot_type_;
            	}
            	
            	constexpr auto& set_lot_type(std::int8_t value) noexcept
            	{
            		lot_type_ = value;
            		return *this;
            	}
            
            
            private:
            	DecimalQty min_lot_size_{};
            
            public:
            	static constexpr std::size_t min_lot_size_size() noexcept
            	{
            		return sizeof(DecimalQty);
            	}
            
            	static constexpr std::size_t min_lot_size_offset() noexcept
            	{
            		return 1;
            	}
            
            	static constexpr std::size_t min_lot_size_id() noexcept
            	{
            		return 1231;
            	}
            
            	static constexpr const char *min_lot_size_name() noexcept
            	{
            		return "MinLotSize";
            	}
            
            	constexpr const DecimalQty &min_lot_size() const noexcept
            	{
            		return min_lot_size_;
            	}
            
            	constexpr DecimalQty &min_lot_size() noexcept
            	{
            		return min_lot_size_;
            	}
            	constexpr auto &set_min_lot_size(DecimalQty &value) noexcept
            	{
            		min_lot_size_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoLotTypeRules() = default;
    	NoLotTypeRules(std::uint8_t count)
    		:header_(sizeof(NoLotTypeRules::Entry), count) {}
    
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
    	NoLotTypeRules no_lot_type_rules_{};
    
    public:
    	static constexpr std::size_t no_lot_type_rules_size() noexcept
    	{
    		return sizeof(NoLotTypeRules::Entry);
    	}
    
    	static constexpr std::size_t no_lot_type_rules_id() noexcept
    	{ 
    		return 1234; 
    	}
    	
    	static constexpr const char* no_lot_type_rules_name() noexcept
    	{ 
    		return "NoLotTypeRules"; 
    	}
    
    	std::size_t no_lot_type_rules_offset() const noexcept
    	{
    		return no_inst_attrib_offset() + sizeof(NoInstAttrib::header_) + no_inst_attrib_data_length();
    	}
    
    	std::size_t no_lot_type_rules_data_length() const noexcept
    	{
    		auto& group = no_lot_type_rules();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoLotTypeRules& no_lot_type_rules() const noexcept
    	{ 
    		const auto* buf = buffer() + no_lot_type_rules_offset();
    		return *reinterpret_cast<const NoLotTypeRules*>(buf);
    	}
    	
    	NoLotTypeRules& no_lot_type_rules() noexcept
    	{
    		auto* buf = buffer() + no_lot_type_rules_offset();
    		return *reinterpret_cast<NoLotTypeRules*>(buf);
    	}
    
    	NoLotTypeRules& AppendNoLotTypeRules(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_lot_type_rules_offset();
    		auto& group = *reinterpret_cast<NoLotTypeRules*>(buf);
    		group.header_.set_block_length(sizeof(NoLotTypeRules::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    #pragma pack(push, 1)
    class NoLegs
    {
    	friend MDInstrumentDefinitionSpread56;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	std::int32_t leg_security_id_{};
            
            public:
            	static constexpr std::size_t leg_security_id_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t leg_security_id_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t leg_security_id_id() noexcept
            	{ 
            		return 602; 
            	}
            	
            	static constexpr const char* leg_security_id_name() noexcept
            	{ 
            		return "LegSecurityID"; 
            	}
            	
            	static constexpr std::int32_t leg_security_id_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t leg_security_id_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t leg_security_id_null_value() noexcept
            	{
            		return INT32_MIN;
            	}
            
            	constexpr std::int32_t leg_security_id() const noexcept
            	{ 
            		return leg_security_id_;
            	}
            	
            	constexpr auto& set_leg_security_id(std::int32_t value) noexcept
            	{
            		leg_security_id_ = value;
            		return *this;
            	}
            
            
            public:
            	static constexpr std::size_t leg_security_id_source_size() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t leg_security_id_source_offset() noexcept
            	{ 
            		return 4; 
            	}
            
            	static constexpr std::size_t leg_security_id_source_id() noexcept
            	{ 
            		return 603; 
            	}
            	
            	static constexpr const char* leg_security_id_source_name() noexcept
            	{ 
            		return "LegSecurityIDSource"; 
            	}
            
            	constexpr char leg_security_id_source() const noexcept
            	{ 
            		return '8';
            	}
            
            
            private:
            	LegSide::Value leg_side_{};
            
            public:
            	static constexpr std::size_t leg_side_size() noexcept
            	{
            		return sizeof(LegSide);
            	}
            
            	static constexpr std::size_t leg_side_offset() noexcept
            	{ 
            		return 4; 
            	}
            
            	static constexpr std::size_t leg_side_id() noexcept
            	{ 
            		return 624; 
            	}
            
            	static constexpr const char* leg_side_name() noexcept
            	{ 
            		return "LegSide"; 
            	}
            
            	static constexpr LegSide::Value leg_side_null_value() noexcept
            	{
            		return LegSide::Value::nullValue;
            	}
            
            	constexpr LegSide::Value leg_side() const noexcept
            	{ 
            		return leg_side_;
            	}
            	
            	constexpr auto& set_leg_side(LegSide::Value value) noexcept
            	{
            		leg_side_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int8_t leg_ratio_qty_{};
            
            public:
            	static constexpr std::size_t leg_ratio_qty_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t leg_ratio_qty_offset() noexcept
            	{ 
            		return 5; 
            	}
            
            	static constexpr std::size_t leg_ratio_qty_id() noexcept
            	{ 
            		return 623; 
            	}
            	
            	static constexpr const char* leg_ratio_qty_name() noexcept
            	{ 
            		return "LegRatioQty"; 
            	}
            	
            	static constexpr std::int8_t leg_ratio_qty_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t leg_ratio_qty_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t leg_ratio_qty_null_value() noexcept
            	{
            		return INT8_MIN;
            	}
            
            	constexpr std::int8_t leg_ratio_qty() const noexcept
            	{ 
            		return leg_ratio_qty_;
            	}
            	
            	constexpr auto& set_leg_ratio_qty(std::int8_t value) noexcept
            	{
            		leg_ratio_qty_ = value;
            		return *this;
            	}
            
            
            private:
            	Pricenull9 leg_price_{};
            
            public:
            	static constexpr std::size_t leg_price_size() noexcept
            	{
            		return sizeof(Pricenull9);
            	}
            
            	static constexpr std::size_t leg_price_offset() noexcept
            	{
            		return 6;
            	}
            
            	static constexpr std::size_t leg_price_id() noexcept
            	{
            		return 566;
            	}
            
            	static constexpr const char *leg_price_name() noexcept
            	{
            		return "LegPrice";
            	}
            
            	constexpr const Pricenull9 &leg_price() const noexcept
            	{
            		return leg_price_;
            	}
            
            	constexpr Pricenull9 &leg_price() noexcept
            	{
            		return leg_price_;
            	}
            	constexpr auto &set_leg_price(Pricenull9 &value) noexcept
            	{
            		leg_price_ = value;
            		return *this;
            	}
            
            
            private:
            	DecimalQty leg_option_delta_{};
            
            public:
            	static constexpr std::size_t leg_option_delta_size() noexcept
            	{
            		return sizeof(DecimalQty);
            	}
            
            	static constexpr std::size_t leg_option_delta_offset() noexcept
            	{
            		return 14;
            	}
            
            	static constexpr std::size_t leg_option_delta_id() noexcept
            	{
            		return 1017;
            	}
            
            	static constexpr const char *leg_option_delta_name() noexcept
            	{
            		return "LegOptionDelta";
            	}
            
            	constexpr const DecimalQty &leg_option_delta() const noexcept
            	{
            		return leg_option_delta_;
            	}
            
            	constexpr DecimalQty &leg_option_delta() noexcept
            	{
            		return leg_option_delta_;
            	}
            	constexpr auto &set_leg_option_delta(DecimalQty &value) noexcept
            	{
            		leg_option_delta_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoLegs() = default;
    	NoLegs(std::uint8_t count)
    		:header_(sizeof(NoLegs::Entry), count) {}
    
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
    	NoLegs no_legs_{};
    
    public:
    	static constexpr std::size_t no_legs_size() noexcept
    	{
    		return sizeof(NoLegs::Entry);
    	}
    
    	static constexpr std::size_t no_legs_id() noexcept
    	{ 
    		return 555; 
    	}
    	
    	static constexpr const char* no_legs_name() noexcept
    	{ 
    		return "NoLegs"; 
    	}
    
    	std::size_t no_legs_offset() const noexcept
    	{
    		return no_lot_type_rules_offset() + sizeof(NoLotTypeRules::header_) + no_lot_type_rules_data_length();
    	}
    
    	std::size_t no_legs_data_length() const noexcept
    	{
    		auto& group = no_legs();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoLegs& no_legs() const noexcept
    	{ 
    		const auto* buf = buffer() + no_legs_offset();
    		return *reinterpret_cast<const NoLegs*>(buf);
    	}
    	
    	NoLegs& no_legs() noexcept
    	{
    		auto* buf = buffer() + no_legs_offset();
    		return *reinterpret_cast<NoLegs*>(buf);
    	}
    
    	NoLegs& AppendNoLegs(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_legs_offset();
    		auto& group = *reinterpret_cast<NoLegs*>(buf);
    		group.header_.set_block_length(sizeof(NoLegs::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56::NoEvents &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.event_type_name() << ": " << g.event_type() << " ";
		os << g.event_time_name() << ": " << g.event_time() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56::NoMDFeedTypes &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.md_feed_type_name() << ": " << g.md_feed_type() << " ";
		os << g.market_depth_name() << ": " << g.market_depth() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56::NoInstAttrib &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.inst_attrib_type_name() << ": " << g.inst_attrib_type() << " ";
		os << g.inst_attrib_value_name() << ": " << g.inst_attrib_value() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56::NoLotTypeRules &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.lot_type_name() << ": " << g.lot_type() << " ";
		os << g.min_lot_size_name() << ": " << g.min_lot_size() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56::NoLegs &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.leg_security_id_name() << ": " << g.leg_security_id() << " ";
		os << g.leg_security_id_source_name() << ": " << g.leg_security_id_source() << " ";
		os << g.leg_side_name() << ": " << g.leg_side() << " ";
		os << g.leg_ratio_qty_name() << ": " << g.leg_ratio_qty() << " ";
		os << g.leg_price_name() << ": " << g.leg_price() << " ";
		os << g.leg_option_delta_name() << ": " << g.leg_option_delta() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDInstrumentDefinitionSpread56 &msg)
{
	os << msg.match_event_indicator_name() << ": " << msg.match_event_indicator() << " ";
	os << msg.tot_num_reports_name() << ": " << msg.tot_num_reports() << " ";
	os << msg.security_update_action_name() << ": " << msg.security_update_action() << " ";
	os << msg.last_update_time_name() << ": " << msg.last_update_time() << " ";
	os << msg.md_security_trading_status_name() << ": " << msg.md_security_trading_status() << " ";
	os << msg.appl_id_name() << ": " << msg.appl_id() << " ";
	os << msg.market_segment_id_name() << ": " << msg.market_segment_id() << " ";
	os << msg.underlying_product_name() << ": " << msg.underlying_product() << " ";
	os << msg.security_exchange_name() << ": " << msg.security_exchange() << " ";
	os << msg.security_group_name() << ": " << msg.security_group() << " ";
	os << msg.asset_name() << ": " << msg.asset() << " ";
	os << msg.symbol_name() << ": " << msg.symbol() << " ";
	os << msg.security_id_name() << ": " << msg.security_id() << " ";
	os << msg.security_id_source_name() << ": " << msg.security_id_source() << " ";
	os << msg.security_type_name() << ": " << msg.security_type() << " ";
	os << msg.cfi_code_name() << ": " << msg.cfi_code() << " ";
	os << msg.maturity_month_year_name() << ": " << msg.maturity_month_year() << " ";
	os << msg.currency_name() << ": " << msg.currency() << " ";
	os << msg.security_sub_type_name() << ": " << msg.security_sub_type() << " ";
	os << msg.user_defined_instrument_name() << ": " << msg.user_defined_instrument() << " ";
	os << msg.match_algorithm_name() << ": " << msg.match_algorithm() << " ";
	os << msg.min_trade_vol_name() << ": " << msg.min_trade_vol() << " ";
	os << msg.max_trade_vol_name() << ": " << msg.max_trade_vol() << " ";
	os << msg.min_price_increment_name() << ": " << msg.min_price_increment() << " ";
	os << msg.display_factor_name() << ": " << msg.display_factor() << " ";
	os << msg.price_display_format_name() << ": " << msg.price_display_format() << " ";
	os << msg.price_ratio_name() << ": " << msg.price_ratio() << " ";
	os << msg.tick_rule_name() << ": " << msg.tick_rule() << " ";
	os << msg.unit_of_measure_name() << ": " << msg.unit_of_measure() << " ";
	os << msg.trading_reference_price_name() << ": " << msg.trading_reference_price() << " ";
	os << msg.settl_price_type_name() << ": " << msg.settl_price_type() << " ";
	os << msg.open_interest_qty_name() << ": " << msg.open_interest_qty() << " ";
	os << msg.cleared_volume_name() << ": " << msg.cleared_volume() << " ";
	os << msg.high_limit_price_name() << ": " << msg.high_limit_price() << " ";
	os << msg.low_limit_price_name() << ": " << msg.low_limit_price() << " ";
	os << msg.max_price_variation_name() << ": " << msg.max_price_variation() << " ";
	os << msg.main_fraction_name() << ": " << msg.main_fraction() << " ";
	os << msg.sub_fraction_name() << ": " << msg.sub_fraction() << " ";
	os << msg.trading_reference_date_name() << ": " << msg.trading_reference_date() << " ";
	os << msg.price_quote_method_name() << ": " << msg.price_quote_method() << " ";
	os << msg.risk_set_name() << ": " << msg.risk_set() << " ";
	os << msg.market_set_name() << ": " << msg.market_set() << " ";
	os << msg.instrument_guid_name() << ": " << msg.instrument_guid() << " ";
	os << msg.financial_instrument_full_name_name() << ": " << msg.financial_instrument_full_name() << " ";
	os << msg.no_events_name() << ": " << msg.no_events() << " ";
	os << msg.no_md_feed_types_name() << ": " << msg.no_md_feed_types() << " ";
	os << msg.no_inst_attrib_name() << ": " << msg.no_inst_attrib() << " ";
	os << msg.no_lot_type_rules_name() << ": " << msg.no_lot_type_rules() << " ";
	os << msg.no_legs_name() << ": " << msg.no_legs() << " ";
	return os;
}
}
