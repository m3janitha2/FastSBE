#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class MessageHeader
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "MessageHeader"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr std::size_t schema() noexcept
    	{  
    		return 91; 
    	}
    
    	static constexpr std::size_t version() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t block_length_{};
    	#pragma pack(pop)
    
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
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t block_length_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    	#pragma pack(push, 1)
    	std::uint16_t template_id_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t template_id_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t template_id_offset() noexcept
    	{ 
    		return block_length_offset() + block_length_size(); 
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
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t template_id_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    	#pragma pack(push, 1)
    	std::uint16_t schema_id_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t schema_id_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t schema_id_offset() noexcept
    	{ 
    		return template_id_offset() + template_id_size(); 
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
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t schema_id_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    	#pragma pack(push, 1)
    	std::uint16_t version_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t version_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t version_offset() noexcept
    	{ 
    		return schema_id_offset() + schema_id_size(); 
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
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t version_null_value() noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    	MessageHeader() = default;
    
    	/*constexpr */
    	MessageHeader(std::uint16_t block_length, std::uint16_t template_id, std::uint16_t schema_id, std::uint16_t version) noexcept
    		:block_length_(block_length), template_id_(template_id), schema_id_(schema_id), version_(version)
    	{
    		
    	}
    
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MessageHeader &msg)
{
	os << msg.block_length_name() << ": " << msg.block_length() << " ";
	os << msg.template_id_name() << ": " << msg.template_id() << " ";
	os << msg.schema_id_name() << ": " << msg.schema_id() << " ";
	os << msg.version_name() << ": " << msg.version() << " ";
	return os;
}
}
