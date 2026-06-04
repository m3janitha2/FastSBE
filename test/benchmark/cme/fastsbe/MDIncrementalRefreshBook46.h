#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "Pricenull9.h"
#include "MDUpdateAction.h"
#include "MDEntryTypeBook.h"
#include "GroupSize.h"
#include "OrderUpdateAction.h"
#include "GroupSize8Byte.h"

namespace fastsbe
{

#pragma pack(push, 1)
class MDIncrementalRefreshBook46
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "MDIncrementalRefreshBook46"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 46; 
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
    		return 11;
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
    	MatchEventIndicator::value_type match_event_indicator_{};
    
    public:
    	static constexpr std::size_t match_event_indicator_size() noexcept
    	{
    		return sizeof(MatchEventIndicator::value_type);
    	}
    
    	static constexpr std::size_t match_event_indicator_offset() noexcept
    	{
    		return 8;
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
    	char block_trailing_padding_[2]{};
    
    
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
    	friend MDIncrementalRefreshBook46;
        
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
            	std::int32_t security_id_{};
            
            public:
            	static constexpr std::size_t security_id_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t security_id_offset() noexcept
            	{ 
            		return 12; 
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
            		return 16; 
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
            	std::int32_t number_of_orders_{};
            
            public:
            	static constexpr std::size_t number_of_orders_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t number_of_orders_offset() noexcept
            	{ 
            		return 20; 
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
            	std::uint8_t md_price_level_{};
            
            public:
            	static constexpr std::size_t md_price_level_size() noexcept
            	{
            		return sizeof(std::uint8_t);
            	}
            
            	static constexpr std::size_t md_price_level_offset() noexcept
            	{ 
            		return 24; 
            	}
            
            	static constexpr std::size_t md_price_level_id() noexcept
            	{ 
            		return 1023; 
            	}
            	
            	static constexpr const char* md_price_level_name() noexcept
            	{ 
            		return "MDPriceLevel"; 
            	}
            	
            	static constexpr std::uint8_t md_price_level_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint8_t md_price_level_max_value() noexcept
            	{
            		return (UINT8_MAX - 1);
            	}
            	
            	static constexpr std::uint8_t md_price_level_null_value() noexcept
            	{
            		return UINT8_MAX;
            	}
            
            	constexpr std::uint8_t md_price_level() const noexcept
            	{ 
            		return md_price_level_;
            	}
            	
            	constexpr auto& set_md_price_level(std::uint8_t value) noexcept
            	{
            		md_price_level_ = value;
            		return *this;
            	}
            
            
            private:
            	MDUpdateAction::Value md_update_action_{};
            
            public:
            	static constexpr std::size_t md_update_action_size() noexcept
            	{
            		return sizeof(MDUpdateAction);
            	}
            
            	static constexpr std::size_t md_update_action_offset() noexcept
            	{ 
            		return 25; 
            	}
            
            	static constexpr std::size_t md_update_action_id() noexcept
            	{ 
            		return 279; 
            	}
            
            	static constexpr const char* md_update_action_name() noexcept
            	{ 
            		return "MDUpdateAction"; 
            	}
            
            	static constexpr MDUpdateAction::Value md_update_action_null_value() noexcept
            	{
            		return MDUpdateAction::Value::nullValue;
            	}
            
            	constexpr MDUpdateAction::Value md_update_action() const noexcept
            	{ 
            		return md_update_action_;
            	}
            	
            	constexpr auto& set_md_update_action(MDUpdateAction::Value value) noexcept
            	{
            		md_update_action_ = value;
            		return *this;
            	}
            
            
            private:
            	MDEntryTypeBook::Value md_entry_type_{};
            
            public:
            	static constexpr std::size_t md_entry_type_size() noexcept
            	{
            		return sizeof(MDEntryTypeBook);
            	}
            
            	static constexpr std::size_t md_entry_type_offset() noexcept
            	{ 
            		return 26; 
            	}
            
            	static constexpr std::size_t md_entry_type_id() noexcept
            	{ 
            		return 269; 
            	}
            
            	static constexpr const char* md_entry_type_name() noexcept
            	{ 
            		return "MDEntryType"; 
            	}
            
            	static constexpr MDEntryTypeBook::Value md_entry_type_null_value() noexcept
            	{
            		return MDEntryTypeBook::Value::nullValue;
            	}
            
            	constexpr MDEntryTypeBook::Value md_entry_type() const noexcept
            	{ 
            		return md_entry_type_;
            	}
            	
            	constexpr auto& set_md_entry_type(MDEntryTypeBook::Value value) noexcept
            	{
            		md_entry_type_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int32_t tradeable_size_{};
            
            public:
            	static constexpr std::size_t tradeable_size_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t tradeable_size_offset() noexcept
            	{ 
            		return 27; 
            	}
            
            	static constexpr std::size_t tradeable_size_id() noexcept
            	{ 
            		return 37719; 
            	}
            	
            	static constexpr const char* tradeable_size_name() noexcept
            	{ 
            		return "TradeableSize"; 
            	}
            	
            	static constexpr std::int32_t tradeable_size_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t tradeable_size_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t tradeable_size_null_value() noexcept
            	{
            		return INT32_MAX;
            	}
            
            	constexpr std::int32_t tradeable_size() const noexcept
            	{ 
            		return tradeable_size_;
            	}
            	
            	constexpr auto& set_tradeable_size(std::int32_t value) noexcept
            	{
            		tradeable_size_ = value;
            		return *this;
            	}
            
            
            private:
            	char block_trailing_padding_[1]{};
            
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
    
    public:
    
    #pragma pack(push, 1)
    class NoOrderIDEntries
    {
    	friend MDIncrementalRefreshBook46;
        
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
            	std::uint64_t md_order_priority_{};
            
            public:
            	static constexpr std::size_t md_order_priority_size() noexcept
            	{
            		return sizeof(std::uint64_t);
            	}
            
            	static constexpr std::size_t md_order_priority_offset() noexcept
            	{ 
            		return 8; 
            	}
            
            	static constexpr std::size_t md_order_priority_id() noexcept
            	{ 
            		return 37707; 
            	}
            	
            	static constexpr const char* md_order_priority_name() noexcept
            	{ 
            		return "MDOrderPriority"; 
            	}
            	
            	static constexpr std::uint64_t md_order_priority_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint64_t md_order_priority_max_value() noexcept
            	{
            		return (UINT64_MAX - 1);
            	}
            	
            	static constexpr std::uint64_t md_order_priority_null_value() noexcept
            	{
            		return UINT64_MAX;
            	}
            
            	constexpr std::uint64_t md_order_priority() const noexcept
            	{ 
            		return md_order_priority_;
            	}
            	
            	constexpr auto& set_md_order_priority(std::uint64_t value) noexcept
            	{
            		md_order_priority_ = value;
            		return *this;
            	}
            
            
            private:
            	std::int32_t md_display_qty_{};
            
            public:
            	static constexpr std::size_t md_display_qty_size() noexcept
            	{
            		return sizeof(std::int32_t);
            	}
            
            	static constexpr std::size_t md_display_qty_offset() noexcept
            	{ 
            		return 16; 
            	}
            
            	static constexpr std::size_t md_display_qty_id() noexcept
            	{ 
            		return 37706; 
            	}
            	
            	static constexpr const char* md_display_qty_name() noexcept
            	{ 
            		return "MDDisplayQty"; 
            	}
            	
            	static constexpr std::int32_t md_display_qty_min_value() noexcept
            	{ 
            		return (INT32_MIN + 1); 
            	}
            	
            	static constexpr std::int32_t md_display_qty_max_value() noexcept
            	{
            		return INT32_MAX;
            	}
            	
            	static constexpr std::int32_t md_display_qty_null_value() noexcept
            	{
            		return INT32_MAX;
            	}
            
            	constexpr std::int32_t md_display_qty() const noexcept
            	{ 
            		return md_display_qty_;
            	}
            	
            	constexpr auto& set_md_display_qty(std::int32_t value) noexcept
            	{
            		md_display_qty_ = value;
            		return *this;
            	}
            
            
            private:
            	std::uint8_t reference_id_{};
            
            public:
            	static constexpr std::size_t reference_id_size() noexcept
            	{
            		return sizeof(std::uint8_t);
            	}
            
            	static constexpr std::size_t reference_id_offset() noexcept
            	{ 
            		return 20; 
            	}
            
            	static constexpr std::size_t reference_id_id() noexcept
            	{ 
            		return 9633; 
            	}
            	
            	static constexpr const char* reference_id_name() noexcept
            	{ 
            		return "ReferenceID"; 
            	}
            	
            	static constexpr std::uint8_t reference_id_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint8_t reference_id_max_value() noexcept
            	{
            		return (UINT8_MAX - 1);
            	}
            	
            	static constexpr std::uint8_t reference_id_null_value() noexcept
            	{
            		return UINT8_MAX;
            	}
            
            	constexpr std::uint8_t reference_id() const noexcept
            	{ 
            		return reference_id_;
            	}
            	
            	constexpr auto& set_reference_id(std::uint8_t value) noexcept
            	{
            		reference_id_ = value;
            		return *this;
            	}
            
            
            private:
            	OrderUpdateAction::Value order_update_action_{};
            
            public:
            	static constexpr std::size_t order_update_action_size() noexcept
            	{
            		return sizeof(OrderUpdateAction);
            	}
            
            	static constexpr std::size_t order_update_action_offset() noexcept
            	{ 
            		return 21; 
            	}
            
            	static constexpr std::size_t order_update_action_id() noexcept
            	{ 
            		return 37708; 
            	}
            
            	static constexpr const char* order_update_action_name() noexcept
            	{ 
            		return "OrderUpdateAction"; 
            	}
            
            	static constexpr OrderUpdateAction::Value order_update_action_null_value() noexcept
            	{
            		return OrderUpdateAction::Value::nullValue;
            	}
            
            	constexpr OrderUpdateAction::Value order_update_action() const noexcept
            	{ 
            		return order_update_action_;
            	}
            	
            	constexpr auto& set_order_update_action(OrderUpdateAction::Value value) noexcept
            	{
            		order_update_action_ = value;
            		return *this;
            	}
            
            
            private:
            	char block_trailing_padding_[2]{};
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSize8Byte header_{};
    
    public:
    	NoOrderIDEntries() = default;
    	NoOrderIDEntries(std::uint8_t count)
    		:header_(sizeof(NoOrderIDEntries::Entry), count) {}
    
    	Entry& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(GroupSize8Byte)
    			+ (this->header_.block_length() * group_id);
    		return *reinterpret_cast<Entry*>(buffer);
    	}
    
    	const Entry& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(GroupSize8Byte)
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
    		return no_md_entries_offset() + sizeof(NoMDEntries::header_) + no_md_entries_data_length();
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
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDIncrementalRefreshBook46::NoMDEntries &group)
{
	os << "[";
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		if (i) { os << ", "; }
		auto &g = group.get(i);
		os << "{";
		bool comma = false;
		if(comma) { os << ", "; } os << "\"MDEntryPx\": " << g.md_entry_px(); comma = true;
		if(comma) { os << ", "; } os << "\"MDEntrySize\": " << g.md_entry_size(); comma = true;
		if(comma) { os << ", "; } os << "\"SecurityID\": " << g.security_id(); comma = true;
		if(comma) { os << ", "; } os << "\"RptSeq\": " << g.rpt_seq(); comma = true;
		if(comma) { os << ", "; } os << "\"NumberOfOrders\": " << g.number_of_orders(); comma = true;
		if(comma) { os << ", "; } os << "\"MDPriceLevel\": " << +g.md_price_level(); comma = true;
		if(comma) { os << ", "; } os << "\"MDUpdateAction\": " << "\"" << g.md_update_action() << "\""; comma = true;
		if(comma) { os << ", "; } os << "\"MDEntryType\": " << "\"" << g.md_entry_type() << "\""; comma = true;
		if(comma) { os << ", "; } os << "\"TradeableSize\": " << g.tradeable_size(); comma = true;
		os << "}";
	}
	os << "]";
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDIncrementalRefreshBook46::NoOrderIDEntries &group)
{
	os << "[";
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		if (i) { os << ", "; }
		auto &g = group.get(i);
		os << "{";
		bool comma = false;
		if(comma) { os << ", "; } os << "\"OrderID\": " << g.order_id(); comma = true;
		if(comma) { os << ", "; } os << "\"MDOrderPriority\": " << g.md_order_priority(); comma = true;
		if(comma) { os << ", "; } os << "\"MDDisplayQty\": " << g.md_display_qty(); comma = true;
		if(comma) { os << ", "; } os << "\"ReferenceID\": " << +g.reference_id(); comma = true;
		if(comma) { os << ", "; } os << "\"OrderUpdateAction\": " << "\"" << g.order_update_action() << "\""; comma = true;
		os << "}";
	}
	os << "]";
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDIncrementalRefreshBook46 &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"TransactTime\": " << msg.transact_time(); comma = true;
	if(comma) { os << ", "; } os << "\"MatchEventIndicator\": " << MatchEventIndicator::to_string(msg.match_event_indicator()); comma = true;
	if(comma) { os << ", "; } os << "\"NoMDEntries\": " << msg.no_md_entries(); comma = true;
	if(comma) { os << ", "; } os << "\"NoOrderIDEntries\": " << msg.no_order_id_entries(); comma = true;
	os << "}";
	return os;
}
}
