#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

class GroupSizeEncoding
{
    
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
    	
    	constexpr GroupSizeEncoding& set_block_length(std::uint16_t value) noexcept
    	{
    		block_length_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t num_in_group_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t num_in_group_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t num_in_group_offset() noexcept
    	{ 
    		return block_length_offset() + block_length_size(); 
    	}
    	
    	static constexpr const char* num_in_group_name() noexcept
    	{ 
    		return "numInGroup"; 
    	}
    	
    	static constexpr std::uint16_t num_in_group_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t num_in_group_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t num_in_group_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t num_in_group() const noexcept
    	{ 
    		return num_in_group_;
    	}
    	
    	constexpr GroupSizeEncoding& set_num_in_group(std::uint16_t value) noexcept
    	{
    		num_in_group_ = value;
    		return *this;
    	}
    
    
    public:
    	GroupSizeEncoding() = default;
    
    	/*constexpr */
    	GroupSizeEncoding(std::uint16_t block_length, std::uint16_t num_in_group) noexcept
    		:block_length_(block_length), num_in_group_(num_in_group)
    	{
    		
    	}
    
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::GroupSizeEncoding &msg)
{
	os << msg.block_length_name() << ": " << msg.block_length() << " ";
	os << msg.num_in_group_name() << ": " << msg.num_in_group() << " ";
	return os;
}
}
