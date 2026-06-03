#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class Price9
{
    
    private:
    	std::int64_t mantissa_{};
    
    public:
    	static constexpr std::size_t mantissa_size() noexcept
    	{
    		return sizeof(std::int64_t);
    	}
    
    	static constexpr std::size_t mantissa_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* mantissa_name() noexcept
    	{ 
    		return "mantissa"; 
    	}
    	
    	static constexpr std::int64_t mantissa_min_value() noexcept
    	{ 
    		return (INT64_MIN + 1); 
    	}
    	
    	static constexpr std::int64_t mantissa_max_value() noexcept
    	{
    		return INT64_MAX;
    	}
    	
    	static constexpr std::int64_t mantissa_null_value() noexcept
    	{
    		return INT64_MIN;
    	}
    
    	constexpr std::int64_t mantissa() const noexcept
    	{ 
    		return mantissa_;
    	}
    	
    	constexpr Price9& set_mantissa(std::int64_t value) noexcept
    	{
    		mantissa_ = value;
    		return *this;
    	}
    
    
    public:
    	static constexpr std::size_t exponent_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t exponent_offset() noexcept
    	{ 
    		return 8; 
    	}
    	
    	static constexpr const char* exponent_name() noexcept
    	{ 
    		return "exponent"; 
    	}
    
    	constexpr std::int8_t exponent() noexcept
    	{ 
    		return -9;
    	}
    
    	constexpr std::int8_t exponent() const noexcept
    	{ 
    		return -9;
    	}
    
    
    public:
    	Price9() = default;
    
    	/*constexpr */
    	Price9(std::int64_t mantissa) noexcept
    		:mantissa_(mantissa)
    	{
    		
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::Price9 &msg)
{
	os << msg.mantissa_name() << ": " << msg.mantissa() << " ";
	os << msg.exponent_name() << ": " << +msg.exponent() << " ";
	return os;
}
}
