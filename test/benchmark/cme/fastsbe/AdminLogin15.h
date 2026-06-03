#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class AdminLogin15
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "AdminLogin15"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 15; 
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
    	std::int8_t heart_bt_int_{};
    
    public:
    	static constexpr std::size_t heart_bt_int_size() noexcept
    	{
    		return sizeof(std::int8_t);
    	}
    
    	static constexpr std::size_t heart_bt_int_offset() noexcept
    	{ 
    		return 0; 
    	}
    
    	static constexpr std::size_t heart_bt_int_id() noexcept
    	{ 
    		return 108; 
    	}
    	
    	static constexpr const char* heart_bt_int_name() noexcept
    	{ 
    		return "HeartBtInt"; 
    	}
    	
    	static constexpr std::int8_t heart_bt_int_min_value() noexcept
    	{ 
    		return (INT8_MIN + 1); 
    	}
    	
    	static constexpr std::int8_t heart_bt_int_max_value() noexcept
    	{
    		return INT8_MAX;
    	}
    	
    	static constexpr std::int8_t heart_bt_int_null_value() noexcept
    	{
    		return INT8_MIN;
    	}
    
    	constexpr std::int8_t heart_bt_int() const noexcept
    	{ 
    		return heart_bt_int_;
    	}
    	
    	constexpr auto& set_heart_bt_int(std::int8_t value) noexcept
    	{
    		heart_bt_int_ = value;
    		return *this;
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::AdminLogin15 &msg)
{
	os << msg.heart_bt_int_name() << ": " << +msg.heart_bt_int() << " ";
	return os;
}
}
