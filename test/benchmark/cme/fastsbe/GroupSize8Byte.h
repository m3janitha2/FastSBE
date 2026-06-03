#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class GroupSize8Byte
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
    	
    	constexpr GroupSize8Byte& set_block_length(std::uint16_t value) noexcept
    	{
    		block_length_ = value;
    		return *this;
    	}
    
    
    private:
    	char num_in_group_pre_padding_[5]{};
    
    
    private:
    	std::uint8_t num_in_group_{};
    
    public:
    	static constexpr std::size_t num_in_group_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t num_in_group_offset() noexcept
    	{ 
    		return 7; 
    	}
    	
    	static constexpr const char* num_in_group_name() noexcept
    	{ 
    		return "numInGroup"; 
    	}
    	
    	static constexpr std::uint8_t num_in_group_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t num_in_group_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t num_in_group_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t num_in_group() const noexcept
    	{ 
    		return num_in_group_;
    	}
    	
    	constexpr GroupSize8Byte& set_num_in_group(std::uint8_t value) noexcept
    	{
    		num_in_group_ = value;
    		return *this;
    	}
    
    
    public:
    	GroupSize8Byte() = default;
    
    	/*constexpr */
    	GroupSize8Byte(std::uint16_t block_length, std::uint8_t num_in_group) noexcept
    		:block_length_(block_length), num_in_group_(num_in_group)
    	{
    		
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::GroupSize8Byte &msg)
{
	os << msg.block_length_name() << ": " << msg.block_length() << " ";
	os << msg.num_in_group_name() << ": " << msg.num_in_group() << " ";
	return os;
}
}
