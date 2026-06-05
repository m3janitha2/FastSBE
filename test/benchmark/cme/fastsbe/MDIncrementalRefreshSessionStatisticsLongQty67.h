#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "Price9.h"
#include "OpenCloseSettlFlag.h"
#include "MDUpdateAction.h"
#include "MDEntryTypeStatistics.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
template <std::size_t N = 1>
class MDIncrementalRefreshSessionStatisticsLongQty67
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "MDIncrementalRefreshSessionStatisticsLongQty67"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 67; 
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
    	template <std::size_t> friend class MDIncrementalRefreshSessionStatisticsLongQty67;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	Price9 md_entry_px_{};
            
            public:
            	static constexpr std::size_t md_entry_px_size() noexcept
            	{
            		return sizeof(Price9);
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
            	std::uint64_t md_entry_size_{};
            
            public:
            	static constexpr std::size_t md_entry_size_size() noexcept
            	{
            		return sizeof(std::uint64_t);
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
            	
            	static constexpr std::uint64_t md_entry_size_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint64_t md_entry_size_max_value() noexcept
            	{
            		return (UINT64_MAX - 1);
            	}
            	
            	static constexpr std::uint64_t md_entry_size_null_value() noexcept
            	{
            		return UINT64_MAX;
            	}
            
            	constexpr std::uint64_t md_entry_size() const noexcept
            	{ 
            		return md_entry_size_;
            	}
            	
            	constexpr auto& set_md_entry_size(std::uint64_t value) noexcept
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
            	std::uint32_t rpt_seq_{};
            
            public:
            	static constexpr std::size_t rpt_seq_size() noexcept
            	{
            		return sizeof(std::uint32_t);
            	}
            
            	static constexpr std::size_t rpt_seq_offset() noexcept
            	{ 
            		return 20; 
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
            	OpenCloseSettlFlag::Value open_close_settl_flag_{};
            
            public:
            	static constexpr std::size_t open_close_settl_flag_size() noexcept
            	{
            		return sizeof(OpenCloseSettlFlag);
            	}
            
            	static constexpr std::size_t open_close_settl_flag_offset() noexcept
            	{ 
            		return 24; 
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
            	MDEntryTypeStatistics::Value md_entry_type_{};
            
            public:
            	static constexpr std::size_t md_entry_type_size() noexcept
            	{
            		return sizeof(MDEntryTypeStatistics);
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
            
            	static constexpr MDEntryTypeStatistics::Value md_entry_type_null_value() noexcept
            	{
            		return MDEntryTypeStatistics::Value::nullValue;
            	}
            
            	constexpr MDEntryTypeStatistics::Value md_entry_type() const noexcept
            	{ 
            		return md_entry_type_;
            	}
            	
            	constexpr auto& set_md_entry_type(MDEntryTypeStatistics::Value value) noexcept
            	{
            		md_entry_type_ = value;
            		return *this;
            	}
            
            
            private:
            	char block_trailing_padding_[5]{};
            
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
    		if(comma) { os << ", "; } os << "\"MDEntryPx\": " << g.md_entry_px(); comma = true;
    		if(comma) { os << ", "; } os << "\"MDEntrySize\": " << g.md_entry_size(); comma = true;
    		if(comma) { os << ", "; } os << "\"SecurityID\": " << g.security_id(); comma = true;
    		if(comma) { os << ", "; } os << "\"RptSeq\": " << g.rpt_seq(); comma = true;
    		if(comma) { os << ", "; } os << "\"OpenCloseSettlFlag\": " << "\"" << g.open_close_settl_flag() << "\""; comma = true;
    		if(comma) { os << ", "; } os << "\"MDUpdateAction\": " << "\"" << g.md_update_action() << "\""; comma = true;
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
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MDIncrementalRefreshSessionStatisticsLongQty67<N> &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"TransactTime\": " << msg.transact_time(); comma = true;
	if(comma) { os << ", "; } os << "\"MatchEventIndicator\": " << MatchEventIndicator::to_string(msg.match_event_indicator()); comma = true;
	if(comma) { os << ", "; } os << "\"NoMDEntries\": " << msg.no_md_entries(); comma = true;
	os << "}";
	return os;
}
}
