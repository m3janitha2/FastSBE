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
class ChannelReset4
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "ChannelReset4"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 4; 
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
    		return 9;
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
    	friend ChannelReset4;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            public:
            	static constexpr std::size_t md_update_action_size() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t md_update_action_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t md_update_action_id() noexcept
            	{ 
            		return 279; 
            	}
            	
            	static constexpr const char* md_update_action_name() noexcept
            	{ 
            		return "MDUpdateAction"; 
            	}
            
            	constexpr std::int8_t md_update_action() const noexcept
            	{ 
            		return 0;
            	}
            
            
            public:
            	static constexpr std::size_t md_entry_type_size() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t md_entry_type_offset() noexcept
            	{ 
            		return 0; 
            	}
            
            	static constexpr std::size_t md_entry_type_id() noexcept
            	{ 
            		return 269; 
            	}
            	
            	static constexpr const char* md_entry_type_name() noexcept
            	{ 
            		return "MDEntryType"; 
            	}
            
            	constexpr char md_entry_type() const noexcept
            	{ 
            		return 'J';
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
            		return 0; 
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
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ChannelReset4::NoMDEntries &group)
{
	os << "[";
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		if (i) { os << ", "; }
		auto &g = group.get(i);
		os << "{";
		bool comma = false;
		if(comma) { os << ", "; } os << "\"MDUpdateAction\": " << +g.md_update_action(); comma = true;
		if(comma) { os << ", "; } os << "\"MDEntryType\": " << g.md_entry_type(); comma = true;
		if(comma) { os << ", "; } os << "\"ApplID\": " << g.appl_id(); comma = true;
		os << "}";
	}
	os << "]";
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ChannelReset4 &msg)
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
