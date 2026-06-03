#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class AdminHeartbeat12
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "AdminHeartbeat12"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 12; 
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
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::AdminHeartbeat12 &msg)
{
	return os;
}
}
