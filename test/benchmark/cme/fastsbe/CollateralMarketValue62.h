#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "MatchEventIndicator.h"
#include "SecurityAltIDSource.h"
#include "Price9.h"
#include "Price9.h"
#include "PriceSource.h"
#include "GroupSize.h"

namespace fastsbe
{

#pragma pack(push, 1)
class CollateralMarketValue62
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "CollateralMarketValue62"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 62; 
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
    	friend CollateralMarketValue62;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	char underlying_security_alt_id_[12]{};
            
            public:
            	static constexpr std::size_t underlying_security_alt_id_size() noexcept
            	{
            		return 12;
            	}
            
            	static constexpr std::size_t underlying_security_alt_id_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t underlying_security_alt_id_id() noexcept
            	{
            		return 458;
            	}
            
            	static constexpr const char *underlying_security_alt_id_name() noexcept
            	{
            		return "UnderlyingSecurityAltID";
            	}
            
            	constexpr char *underlying_security_alt_id() noexcept
            	{
            		return underlying_security_alt_id_;
            	}
            
            	constexpr const char *underlying_security_alt_id() const noexcept
            	{
            		return underlying_security_alt_id_;
            	}
            
            	constexpr std::string_view underlying_security_alt_id_view() noexcept
            	{
            		return std::string_view(underlying_security_alt_id_, 12);
            	}
            
            	constexpr const std::string_view underlying_security_alt_id_view() const noexcept
            	{
            		return std::string_view(underlying_security_alt_id_, 12);
            	}
            
            	const std::string underlying_security_alt_id_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 12 && *(underlying_security_alt_id_ + length) != '\0'; ++length);
            		return std::string(underlying_security_alt_id_, length);
            	}
            
            	constexpr auto &set_underlying_security_alt_id(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(underlying_security_alt_id_, value, underlying_security_alt_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_underlying_security_alt_id(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(underlying_security_alt_id_size(), value.size());
            		std::memcpy(underlying_security_alt_id_, value.data(), underlying_security_alt_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	SecurityAltIDSource::Value underlying_security_alt_id_source_{};
            
            public:
            	static constexpr std::size_t underlying_security_alt_id_source_size() noexcept
            	{
            		return sizeof(SecurityAltIDSource);
            	}
            
            	static constexpr std::size_t underlying_security_alt_id_source_offset() noexcept
            	{ 
            		return 12; 
            	}
            
            	static constexpr std::size_t underlying_security_alt_id_source_id() noexcept
            	{ 
            		return 459; 
            	}
            
            	static constexpr const char* underlying_security_alt_id_source_name() noexcept
            	{ 
            		return "UnderlyingSecurityAltIDSource"; 
            	}
            
            	static constexpr SecurityAltIDSource::Value underlying_security_alt_id_source_null_value() noexcept
            	{
            		return SecurityAltIDSource::Value::nullValue;
            	}
            
            	constexpr SecurityAltIDSource::Value underlying_security_alt_id_source() const noexcept
            	{ 
            		return underlying_security_alt_id_source_;
            	}
            	
            	constexpr auto& set_underlying_security_alt_id_source(SecurityAltIDSource::Value value) noexcept
            	{
            		underlying_security_alt_id_source_ = value;
            		return *this;
            	}
            
            
            private:
            	Price9 collateral_market_price_{};
            
            public:
            	static constexpr std::size_t collateral_market_price_size() noexcept
            	{
            		return sizeof(Price9);
            	}
            
            	static constexpr std::size_t collateral_market_price_offset() noexcept
            	{
            		return 13;
            	}
            
            	static constexpr std::size_t collateral_market_price_id() noexcept
            	{
            		return 2689;
            	}
            
            	static constexpr const char *collateral_market_price_name() noexcept
            	{
            		return "CollateralMarketPrice";
            	}
            
            	constexpr const Price9 &collateral_market_price() const noexcept
            	{
            		return collateral_market_price_;
            	}
            
            	constexpr Price9 &collateral_market_price() noexcept
            	{
            		return collateral_market_price_;
            	}
            	constexpr auto &set_collateral_market_price(Price9 &value) noexcept
            	{
            		collateral_market_price_ = value;
            		return *this;
            	}
            
            
            private:
            	Price9 dirty_price_{};
            
            public:
            	static constexpr std::size_t dirty_price_size() noexcept
            	{
            		return sizeof(Price9);
            	}
            
            	static constexpr std::size_t dirty_price_offset() noexcept
            	{
            		return 21;
            	}
            
            	static constexpr std::size_t dirty_price_id() noexcept
            	{
            		return 37001;
            	}
            
            	static constexpr const char *dirty_price_name() noexcept
            	{
            		return "DirtyPrice";
            	}
            
            	constexpr const Price9 &dirty_price() const noexcept
            	{
            		return dirty_price_;
            	}
            
            	constexpr Price9 &dirty_price() noexcept
            	{
            		return dirty_price_;
            	}
            	constexpr auto &set_dirty_price(Price9 &value) noexcept
            	{
            		dirty_price_ = value;
            		return *this;
            	}
            
            
            private:
            	std::uint64_t underlying_instrument_guid_{};
            
            public:
            	static constexpr std::size_t underlying_instrument_guid_size() noexcept
            	{
            		return sizeof(std::uint64_t);
            	}
            
            	static constexpr std::size_t underlying_instrument_guid_offset() noexcept
            	{ 
            		return 29; 
            	}
            
            	static constexpr std::size_t underlying_instrument_guid_id() noexcept
            	{ 
            		return 37519; 
            	}
            	
            	static constexpr const char* underlying_instrument_guid_name() noexcept
            	{ 
            		return "UnderlyingInstrumentGUID"; 
            	}
            	
            	static constexpr std::uint64_t underlying_instrument_guid_min_value() noexcept
            	{ 
            		return 0; 
            	}
            	
            	static constexpr std::uint64_t underlying_instrument_guid_max_value() noexcept
            	{
            		return (UINT64_MAX - 1);
            	}
            	
            	static constexpr std::uint64_t underlying_instrument_guid_null_value() noexcept
            	{
            		return UINT64_MAX;
            	}
            
            	constexpr std::uint64_t underlying_instrument_guid() const noexcept
            	{ 
            		return underlying_instrument_guid_;
            	}
            	
            	constexpr auto& set_underlying_instrument_guid(std::uint64_t value) noexcept
            	{
            		underlying_instrument_guid_ = value;
            		return *this;
            	}
            
            
            private:
            	PriceSource::Value md_stream_id_{};
            
            public:
            	static constexpr std::size_t md_stream_id_size() noexcept
            	{
            		return sizeof(PriceSource);
            	}
            
            	static constexpr std::size_t md_stream_id_offset() noexcept
            	{ 
            		return 37; 
            	}
            
            	static constexpr std::size_t md_stream_id_id() noexcept
            	{ 
            		return 1500; 
            	}
            
            	static constexpr const char* md_stream_id_name() noexcept
            	{ 
            		return "MDStreamID"; 
            	}
            
            	static constexpr PriceSource::Value md_stream_id_null_value() noexcept
            	{
            		return PriceSource::Value::nullValue;
            	}
            
            	constexpr PriceSource::Value md_stream_id() const noexcept
            	{ 
            		return md_stream_id_;
            	}
            	
            	constexpr auto& set_md_stream_id(PriceSource::Value value) noexcept
            	{
            		md_stream_id_ = value;
            		return *this;
            	}
            
            
            private:
            	char block_trailing_padding_[2]{};
            
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
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::CollateralMarketValue62::NoMDEntries &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.underlying_security_alt_id_name() << ": " << g.underlying_security_alt_id() << " ";
		os << g.underlying_security_alt_id_source_name() << ": " << g.underlying_security_alt_id_source() << " ";
		os << g.collateral_market_price_name() << ": " << g.collateral_market_price() << " ";
		os << g.dirty_price_name() << ": " << g.dirty_price() << " ";
		os << g.underlying_instrument_guid_name() << ": " << g.underlying_instrument_guid() << " ";
		os << g.md_stream_id_name() << ": " << g.md_stream_id() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::CollateralMarketValue62 &msg)
{
	os << msg.transact_time_name() << ": " << msg.transact_time() << " ";
	os << msg.match_event_indicator_name() << ": " << msg.match_event_indicator() << " ";
	os << msg.no_md_entries_name() << ": " << msg.no_md_entries() << " ";
	return os;
}
}
