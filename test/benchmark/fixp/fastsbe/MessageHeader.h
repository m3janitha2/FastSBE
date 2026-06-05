#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MessageHeader
{
    
    private:
    	std::uint16_t block_length_{};
    
    public:
    	static constexpr std::size_t block_length_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t block_length_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* block_length_name() noexcept
    	{ 
    		return "blockLength"; 
    	}
    	
    	static constexpr std::uint16_t block_length_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t block_length_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t block_length_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t block_length() const noexcept
    	{ 
    		return block_length_;
    	}
    	
    	constexpr MessageHeader& set_block_length(std::uint16_t value) noexcept
    	{
    		block_length_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint16_t template_id_{};
    
    public:
    	static constexpr std::size_t template_id_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t template_id_offset() noexcept
    	{ 
    		return 2; 
    	}
    	
    	static constexpr const char* template_id_name() noexcept
    	{ 
    		return "templateId"; 
    	}
    	
    	static constexpr std::uint16_t template_id_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t template_id_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t template_id_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t template_id() const noexcept
    	{ 
    		return template_id_;
    	}
    	
    	constexpr MessageHeader& set_template_id(std::uint16_t value) noexcept
    	{
    		template_id_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint16_t schema_id_{};
    
    public:
    	static constexpr std::size_t schema_id_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t schema_id_offset() noexcept
    	{ 
    		return 4; 
    	}
    	
    	static constexpr const char* schema_id_name() noexcept
    	{ 
    		return "schemaId"; 
    	}
    	
    	static constexpr std::uint16_t schema_id_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t schema_id_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t schema_id_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t schema_id() const noexcept
    	{ 
    		return schema_id_;
    	}
    	
    	constexpr MessageHeader& set_schema_id(std::uint16_t value) noexcept
    	{
    		schema_id_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint16_t version_{};
    
    public:
    	static constexpr std::size_t version_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t version_offset() noexcept
    	{ 
    		return 6; 
    	}
    	
    	static constexpr const char* version_name() noexcept
    	{ 
    		return "version"; 
    	}
    	
    	static constexpr std::uint16_t version_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t version_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t version_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t version() const noexcept
    	{ 
    		return version_;
    	}
    	
    	constexpr MessageHeader& set_version(std::uint16_t value) noexcept
    	{
    		version_ = value;
    		return *this;
    	}
    
    
    public:
    	constexpr MessageHeader() = default;
    
    	constexpr MessageHeader(std::uint16_t block_length, std::uint16_t template_id, std::uint16_t schema_id, std::uint16_t version) noexcept
    		:block_length_(block_length), template_id_(template_id), schema_id_(schema_id), version_(version)
    	{
    		
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MessageHeader &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"blockLength\": " << msg.block_length(); comma = true;
	if(comma) { os << ", "; } os << "\"templateId\": " << msg.template_id(); comma = true;
	if(comma) { os << ", "; } os << "\"schemaId\": " << msg.schema_id(); comma = true;
	if(comma) { os << ", "; } os << "\"version\": " << msg.version(); comma = true;
	os << "}";
	return os;
}
}
