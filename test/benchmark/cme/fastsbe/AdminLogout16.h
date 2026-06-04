#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class AdminLogout16
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "AdminLogout16"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 16; 
    	}
    
    	static constexpr std::uint16_t schema() noexcept
    	{  
    		return 1; 
    	}
    
    	static constexpr std::uint16_t version() noexcept
    	{
    		return 13;
    	}
    
    	static constexpr std::uint16_t block_length() noexcept
    	{
    		return 180;
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	char text_[180]{};
    
    public:
    	static constexpr std::size_t text_size() noexcept
    	{
    		return 180;
    	}
    
    	static constexpr std::size_t text_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t text_id() noexcept
    	{
    		return 58;
    	}
    
    	static constexpr const char *text_name() noexcept
    	{
    		return "Text";
    	}
    
    	constexpr char *text() noexcept
    	{
    		return text_;
    	}
    
    	constexpr const char *text() const noexcept
    	{
    		return text_;
    	}
    
    	constexpr std::string_view text_view() noexcept
    	{
    		return std::string_view(text_, 180);
    	}
    
    	constexpr const std::string_view text_view() const noexcept
    	{
    		return std::string_view(text_, 180);
    	}
    
    	const std::string text_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 180 && *(text_ + length) != '\0'; ++length);
    		return std::string(text_, length);
    	}
    
    	constexpr auto &set_text(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(text_, value, text_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_text(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(text_size(), value.size());
    		std::memcpy(text_, value.data(), text_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::AdminLogout16 &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"Text\": " << "\"" << msg.text() << "\""; comma = true;
	os << "}";
	return os;
}
}
