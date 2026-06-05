#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class Data
{
    
    private:
    	std::uint16_t length_{};
    
    public:
    	static constexpr std::size_t length_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t length_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* length_name() noexcept
    	{ 
    		return "length"; 
    	}
    	
    	static constexpr std::uint16_t length_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t length_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t length_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t length() const noexcept
    	{ 
    		return length_;
    	}
    	
    	constexpr Data& set_length(std::uint16_t value) noexcept
    	{
    		length_ = value;
    		return *this;
    	}
    
    
    private:
    	char var_data_[0]{};
    
    public:
    	static constexpr std::size_t var_data_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t var_data_offset() noexcept
    	{ 
    		return 2; 
    	}
    	
    	static constexpr const char* var_data_name() noexcept
    	{ 
    		return "varData"; 
    	}
    
    	constexpr char* var_data() noexcept
    	{ 
    		return var_data_;
    	}
    
    	constexpr const char* var_data() const noexcept
    	{ 
    		return var_data_;
    	}
    
    	constexpr std::string_view var_data_view() noexcept
    	{ 
    		return std::string_view(var_data_, 0);
    	}
    
    	constexpr const std::string_view var_data_view() const noexcept
    	{ 
    		return std::string_view(var_data_, 0);
    	}
    
    	const std::string var_data_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 0 && *(var_data_ + length) != '\0'; ++length);
    		return std::string(var_data_, length);
    	}	
    
    	auto& set_var_data(const char* value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#pragma GCC diagnostic ignored "-Wstringop-overread"
    	#endif		
    		//auto length = strlen(value);
    		std::memcpy(var_data_, value, var_data_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif			
    	}
    
    	// Safe: copy size bytes (capped at the field width) and NUL-pad the remainder.
    	auto& set_var_data(const char* value, std::size_t size) noexcept
    	{
    		const auto length = size < var_data_size() ? size : var_data_size();
    		std::memcpy(var_data_, value, length);
    		std::memset(var_data_ + length, 0, var_data_size() - length);
    		return *this;
    	}
    
    	auto& set_var_data(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#pragma GCC diagnostic ignored "-Wstringop-overread"
    	#endif		
    		//constexpr auto size = std::min(var_data_size(), value.size());
    		//auto size = std::min(var_data_size(), value.size());
    		std::memcpy(var_data_, value.data(), var_data_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif			
    	}
    
    
    public:
    	Data() = default;
    
    	/*constexpr */
    	Data(std::uint16_t length, std::string_view var_data) noexcept
    		:length_(length)
    	{
    		var_data.copy(var_data_,var_data_size());
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::Data &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"length\": " << msg.length(); comma = true;
	if(comma) { os << ", "; } os << "\"varData\": " << "\"" << msg.var_data() << "\""; comma = true;
	os << "}";
	return os;
}
}
