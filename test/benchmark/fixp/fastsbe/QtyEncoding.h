#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class QtyEncoding
{
    
    private:
    	std::int32_t mantissa_{};
    
    public:
    	static constexpr std::size_t mantissa_size() noexcept
    	{
    		return sizeof(std::int32_t);
    	}
    
    	static constexpr std::size_t mantissa_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* mantissa_name() noexcept
    	{ 
    		return "mantissa"; 
    	}
    	
    	static constexpr std::int32_t mantissa_min_value() noexcept
    	{ 
    		return (INT32_MIN + 1); 
    	}
    	
    	static constexpr std::int32_t mantissa_max_value() noexcept
    	{
    		return INT32_MAX;
    	}
    	
    	static constexpr std::int32_t mantissa_null_value() noexcept
    	{
    		return INT32_MIN;
    	}
    
    	constexpr std::int32_t mantissa() const noexcept
    	{ 
    		return mantissa_;
    	}
    	
    	constexpr QtyEncoding& set_mantissa(std::int32_t value) noexcept
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
    		return 4; 
    	}
    	
    	static constexpr const char* exponent_name() noexcept
    	{ 
    		return "exponent"; 
    	}
    
    	constexpr std::int8_t exponent() noexcept
    	{ 
    		return 0;
    	}
    
    	constexpr std::int8_t exponent() const noexcept
    	{ 
    		return 0;
    	}
    
    
    public:
    	constexpr QtyEncoding() = default;
    
    	constexpr QtyEncoding(std::int32_t mantissa) noexcept
    		:mantissa_(mantissa)
    	{
    		
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::QtyEncoding &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"mantissa\": " << msg.mantissa(); comma = true;
	if(comma) { os << ", "; } os << "\"exponent\": " << +msg.exponent(); comma = true;
	os << "}";
	return os;
}
}
