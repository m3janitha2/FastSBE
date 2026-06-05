#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "Price9.h"
#include "MDEntryTypeBook.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
template <std::size_t N = 1>
class SnapshotRefreshTopOrders59
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "SnapshotRefreshTopOrders59"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 59; 
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
    	std::int32_t security_id_{};
    
    public:
    	static constexpr std::size_t security_id_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t security_id_offset() noexcept
    	{ 
    		return 9; 
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
    class NoMDEntries
    {
    	template <std::size_t> friend class SnapshotRefreshTopOrders59;
        
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
            	Price9 md_entry_px_{};
            
            public:
            	static constexpr std::size_t md_entry_px_size() noexcept
            	{
            		return sizeof(Price9);
            	}
            
            	static constexpr std::size_t md_entry_px_offset() noexcept
            	{
            		return 16;
            	}
            
            	static constexpr std::size_t md_entry_px_id() noexcept
            	{
            		return 270;
            	}
            
            	static constexpr const char *md_entry_px_name() noexcept
            	{
            		return "MDEntryPx";
            	}
            
            	constexpr const Price9 &md_entry_px() const noexcept
            	{
            		return md_entry_px_;
            	}
            
            	constexpr Price9 &md_entry_px() noexcept
            	{
            		return md_entry_px_;
            	}
            	constexpr auto &set_md_entry_px(Price9 &value) noexcept
            	{
            		md_entry_px_ = value;
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
            		return 24; 
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
            		return INT32_MIN;
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
            	MDEntryTypeBook::Value md_entry_type_{};
            
            public:
            	static constexpr std::size_t md_entry_type_size() noexcept
            	{
            		return sizeof(MDEntryTypeBook);
            	}
            
            	static constexpr std::size_t md_entry_type_offset() noexcept
            	{ 
            		return 28; 
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
    
    
    	template <class CharT, class Traits = std::char_traits<CharT>>
    	friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const NoMDEntries &group)
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
    			if(comma) { os << ", "; } os << "\"MDEntryPx\": " << g.md_entry_px(); comma = true;
    			if(comma) { os << ", "; } os << "\"MDDisplayQty\": " << g.md_display_qty(); comma = true;
    			if(comma) { os << ", "; } os << "\"MDEntryType\": " << "\"" << g.md_entry_type() << "\""; comma = true;
    			os << "}";
    		}
    		os << "]";
    		return os;
    	}
    };
    #pragma pack(pop)
    
    private:
    	NoMDEntries no_md_entries_{};
    
    public:
    	static constexpr std::size_t no_md_entries_size() noexcept
    	{
    		return sizeof(typename NoMDEntries::Entry);
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
    		group.header_.set_block_length(sizeof(typename NoMDEntries::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <std::size_t N, class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::SnapshotRefreshTopOrders59<N> &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"TransactTime\": " << msg.transact_time(); comma = true;
	if(comma) { os << ", "; } os << "\"MatchEventIndicator\": " << MatchEventIndicator::to_string(msg.match_event_indicator()); comma = true;
	if(comma) { os << ", "; } os << "\"SecurityID\": " << msg.security_id(); comma = true;
	if(comma) { os << ", "; } os << "\"NoMDEntries\": " << msg.no_md_entries(); comma = true;
	os << "}";
	return os;
}
}
