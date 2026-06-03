#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "SecurityTradingStatus.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "Pricenull9.h"
#include "OpenCloseSettlFlag.h"
#include "SettlPriceType.h"
#include "MDEntryType.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
class SnapshotFullRefresh52
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "SnapshotFullRefresh52"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 52; 
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
    	std::uint32_t last_msg_seq_num_processed_{};
    
    public:
    	static constexpr std::size_t last_msg_seq_num_processed_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t last_msg_seq_num_processed_offset() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr std::size_t last_msg_seq_num_processed_id() noexcept
    	{ 
    		return 369; 
    	}
    	
    	static constexpr const char* last_msg_seq_num_processed_name() noexcept
    	{ 
    		return "LastMsgSeqNumProcessed"; 
    	}
    	
    	static constexpr std::uint32_t last_msg_seq_num_processed_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t last_msg_seq_num_processed_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t last_msg_seq_num_processed_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t last_msg_seq_num_processed() const noexcept
    	{ 
    		return last_msg_seq_num_processed_;
    	}
    	
    	constexpr auto& set_last_msg_seq_num_processed(std::uint32_t value) noexcept
    	{
    		last_msg_seq_num_processed_ = value;
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
    		return 4; 
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
    	std::int32_t security_id_{};
    
    public:
    	static constexpr std::size_t security_id_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t security_id_offset() noexcept
    	{ 
    		return 8; 
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
    	std::uint32_t rpt_seq_{};
    
    public:
    	static constexpr std::size_t rpt_seq_size() noexcept
    	{
    		return sizeof(std::uint32_t);
    	}
    
    	static constexpr std::size_t rpt_seq_offset() noexcept
    	{ 
    		return 12; 
    	}
    
    	static constexpr std::size_t rpt_seq_id() noexcept
    	{ 
    		return 83; 
    	}
    	
    	static constexpr const char* rpt_seq_name() noexcept
    	{ 
    		return "RptSeq"; 
    	}
    	
    	static constexpr std::uint32_t rpt_seq_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint32_t rpt_seq_max_value() noexcept
    	{
    		return (UINT32_MAX - 1);
    	}
    	
    	static constexpr std::uint32_t rpt_seq_null_value() noexcept
    	{
    		return UINT32_MAX;
    	}
    
    	constexpr std::uint32_t rpt_seq() const noexcept
    	{ 
    		return rpt_seq_;
    	}
    	
    	constexpr auto& set_rpt_seq(std::uint32_t value) noexcept
    	{
    		rpt_seq_ = value;
    		return *this;
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
    		return 16; 
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
    	std::uint64_t last_update_time_{};
    
    public:
    	static constexpr std::size_t last_update_time_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t last_update_time_offset() noexcept
    	{ 
    		return 24; 
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
    	std::uint16_t trade_date_{};
    
    public:
    	static constexpr std::size_t trade_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trade_date_offset() noexcept
    	{ 
    		return 32; 
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
    	SecurityTradingStatus::Value md_security_trading_status_{};
    
    public:
    	static constexpr std::size_t md_security_trading_status_size() noexcept
    	{
    		return sizeof(SecurityTradingStatus);
    	}
    
    	static constexpr std::size_t md_security_trading_status_offset() noexcept
    	{ 
    		return 34; 
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
    	Pricenull9 high_limit_price_{};
    
    public:
    	static constexpr std::size_t high_limit_price_size() noexcept
    	{
    		return sizeof(Pricenull9);
    	}
    
    	static constexpr std::size_t high_limit_price_offset() noexcept
    	{
    		return 35;
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
    		return 43;
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
    		return 51;
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
    class NoMDEntries
    {
    	friend SnapshotFullRefresh52;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	Pricenull9 md_entry_px_{};
            
            public:
            	static constexpr std::size_t md_entry_px_size() noexcept
            	{
            		return sizeof(Pricenull9);
            	}
            
            	static constexpr std::size_t md_entry_px_offset() noexcept
            	{
            		return 0;
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
            	std::int32_t md_entry_size_{};
            
            public:
            	static constexpr std::size_t md_entry_size_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t md_entry_size_offset() noexcept
            	{ 
            		return 8; 
            	}
            
            	static constexpr std::size_t md_entry_size_id() noexcept
            	{ 
            		return 271; 
            	}
            	
            	static constexpr const char* md_entry_size_name() noexcept
            	{ 
            		return "MDEntrySize"; 
            	}
            	
            	static constexpr std::int32_t md_entry_size_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t md_entry_size_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t md_entry_size_null_value() noexcept
            	{
            		return INT32_MAX;
            	}
            
            	constexpr std::int32_t md_entry_size() const noexcept
            	{ 
            		return md_entry_size_;
            	}
            	
            	constexpr auto& set_md_entry_size(std::int32_t value) noexcept
            	{
            		md_entry_size_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int32_t number_of_orders_{};
            
            public:
            	static constexpr std::size_t number_of_orders_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t number_of_orders_offset() noexcept
            	{ 
            		return 12; 
            	}
            
            	static constexpr std::size_t number_of_orders_id() noexcept
            	{ 
            		return 346; 
            	}
            	
            	static constexpr const char* number_of_orders_name() noexcept
            	{ 
            		return "NumberOfOrders"; 
            	}
            	
            	static constexpr std::int32_t number_of_orders_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t number_of_orders_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t number_of_orders_null_value() noexcept
            	{
            		return INT32_MAX;
            	}
            
            	constexpr std::int32_t number_of_orders() const noexcept
            	{ 
            		return number_of_orders_;
            	}
            	
            	constexpr auto& set_number_of_orders(std::int32_t value) noexcept
            	{
            		number_of_orders_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int8_t md_price_level_{};
            
            public:
            	static constexpr std::size_t md_price_level_size() noexcept
            	{
            		return sizeof(std::int8_t);
            	}
            
            	static constexpr std::size_t md_price_level_offset() noexcept
            	{ 
            		return 16; 
            	}
            
            	static constexpr std::size_t md_price_level_id() noexcept
            	{ 
            		return 1023; 
            	}
            	
            	static constexpr const char* md_price_level_name() noexcept
            	{ 
            		return "MDPriceLevel"; 
            	}
            	
            	static constexpr std::int8_t md_price_level_min_value() noexcept
            	{ 
            		return (INT8_MIN + 1); 
            	}
            	
            	static constexpr std::int8_t md_price_level_max_value() noexcept
            	{
            		return INT8_MAX;
            	}
            	
            	static constexpr std::int8_t md_price_level_null_value() noexcept
            	{
            		return INT8_MAX;
            	}
            
            	constexpr std::int8_t md_price_level() const noexcept
            	{ 
            		return md_price_level_;
            	}
            	
            	constexpr auto& set_md_price_level(std::int8_t value) noexcept
            	{
            		md_price_level_ = value;
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
            		return 17; 
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
            	OpenCloseSettlFlag::Value open_close_settl_flag_{};
            
            public:
            	static constexpr std::size_t open_close_settl_flag_size() noexcept
            	{
            		return sizeof(OpenCloseSettlFlag);
            	}
            
            	static constexpr std::size_t open_close_settl_flag_offset() noexcept
            	{ 
            		return 19; 
            	}
            
            	static constexpr std::size_t open_close_settl_flag_id() noexcept
            	{ 
            		return 286; 
            	}
            
            	static constexpr const char* open_close_settl_flag_name() noexcept
            	{ 
            		return "OpenCloseSettlFlag"; 
            	}
            
            	static constexpr OpenCloseSettlFlag::Value open_close_settl_flag_null_value() noexcept
            	{
            		return OpenCloseSettlFlag::Value::nullValue;
            	}
            
            	constexpr OpenCloseSettlFlag::Value open_close_settl_flag() const noexcept
            	{ 
            		return open_close_settl_flag_;
            	}
            	
            	constexpr auto& set_open_close_settl_flag(OpenCloseSettlFlag::Value value) noexcept
            	{
            		open_close_settl_flag_ = value;
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
            		return 20;
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
            	MDEntryType::Value md_entry_type_{};
            
            public:
            	static constexpr std::size_t md_entry_type_size() noexcept
            	{
            		return sizeof(MDEntryType);
            	}
            
            	static constexpr std::size_t md_entry_type_offset() noexcept
            	{ 
            		return 21; 
            	}
            
            	static constexpr std::size_t md_entry_type_id() noexcept
            	{ 
            		return 269; 
            	}
            
            	static constexpr const char* md_entry_type_name() noexcept
            	{ 
            		return "MDEntryType"; 
            	}
            
            	static constexpr MDEntryType::Value md_entry_type_null_value() noexcept
            	{
            		return MDEntryType::Value::nullValue;
            	}
            
            	constexpr MDEntryType::Value md_entry_type() const noexcept
            	{ 
            		return md_entry_type_;
            	}
            	
            	constexpr auto& set_md_entry_type(MDEntryType::Value value) noexcept
            	{
            		md_entry_type_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize header_{};
    
    public:
    	NoMDEntries() = default;
    	NoMDEntries(std::uint8_t count)
    		:header_(sizeof(NoMDEntries::Entry), count) {}
    
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
    	NoMDEntries no_md_entries_{};
    
    public:
    	static constexpr std::size_t no_md_entries_size() noexcept
    	{
    		return sizeof(NoMDEntries::Entry);
    	}
    
    	static constexpr std::size_t no_md_entries_id() noexcept
    	{ 
    		return 268; 
    	}
    	
    	static constexpr const char* no_md_entries_name() noexcept
    	{ 
    		return "NoMDEntries"; 
    	}
    
    	std::size_t no_md_entries_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t no_md_entries_data_length() const noexcept
    	{
    		auto& group = no_md_entries();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const NoMDEntries& no_md_entries() const noexcept
    	{ 
    		const auto* buf = buffer() + no_md_entries_offset();
    		return *reinterpret_cast<const NoMDEntries*>(buf);
    	}
    	
    	NoMDEntries& no_md_entries() noexcept
    	{
    		auto* buf = buffer() + no_md_entries_offset();
    		return *reinterpret_cast<NoMDEntries*>(buf);
    	}
    
    	NoMDEntries& AppendNoMDEntries(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + no_md_entries_offset();
    		auto& group = *reinterpret_cast<NoMDEntries*>(buf);
    		group.header_.set_block_length(sizeof(NoMDEntries::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SnapshotFullRefresh52::NoMDEntries &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.md_entry_px_name() << ": " << g.md_entry_px() << " ";
		os << g.md_entry_size_name() << ": " << g.md_entry_size() << " ";
		os << g.number_of_orders_name() << ": " << g.number_of_orders() << " ";
		os << g.md_price_level_name() << ": " << +g.md_price_level() << " ";
		os << g.trading_reference_date_name() << ": " << g.trading_reference_date() << " ";
		os << g.open_close_settl_flag_name() << ": " << g.open_close_settl_flag() << " ";
		os << g.settl_price_type_name() << ": " << SettlPriceType::to_string(g.settl_price_type()) << " ";
		os << g.md_entry_type_name() << ": " << g.md_entry_type() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SnapshotFullRefresh52 &msg)
{
	os << msg.last_msg_seq_num_processed_name() << ": " << msg.last_msg_seq_num_processed() << " ";
	os << msg.tot_num_reports_name() << ": " << msg.tot_num_reports() << " ";
	os << msg.security_id_name() << ": " << msg.security_id() << " ";
	os << msg.rpt_seq_name() << ": " << msg.rpt_seq() << " ";
	os << msg.transact_time_name() << ": " << msg.transact_time() << " ";
	os << msg.last_update_time_name() << ": " << msg.last_update_time() << " ";
	os << msg.trade_date_name() << ": " << msg.trade_date() << " ";
	os << msg.md_security_trading_status_name() << ": " << msg.md_security_trading_status() << " ";
	os << msg.high_limit_price_name() << ": " << msg.high_limit_price() << " ";
	os << msg.low_limit_price_name() << ": " << msg.low_limit_price() << " ";
	os << msg.max_price_variation_name() << ": " << msg.max_price_variation() << " ";
	os << msg.no_md_entries_name() << ": " << msg.no_md_entries() << " ";
	return os;
}
}
