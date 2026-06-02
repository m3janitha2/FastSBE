#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

namespace fastsbe
{

#pragma pack(push, 1)
class MonthYear
{
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t year_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t year_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t year_offset() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr const char* year_name() noexcept
    	{ 
    		return "year"; 
    	}
    	
    	static constexpr std::uint16_t year_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t year_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t year_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t year() const noexcept
    	{ 
    		return year_;
    	}
    	
    	constexpr MonthYear& set_year(std::uint16_t value) noexcept
    	{
    		year_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t month_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t month_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t month_offset() noexcept
    	{ 
    		return 2; 
    	}
    	
    	static constexpr const char* month_name() noexcept
    	{ 
    		return "month"; 
    	}
    	
    	static constexpr std::uint8_t month_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t month_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t month_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t month() const noexcept
    	{ 
    		return month_;
    	}
    	
    	constexpr MonthYear& set_month(std::uint8_t value) noexcept
    	{
    		month_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t day_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t day_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t day_offset() noexcept
    	{ 
    		return 3; 
    	}
    	
    	static constexpr const char* day_name() noexcept
    	{ 
    		return "day"; 
    	}
    	
    	static constexpr std::uint8_t day_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t day_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t day_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t day() const noexcept
    	{ 
    		return day_;
    	}
    	
    	constexpr MonthYear& set_day(std::uint8_t value) noexcept
    	{
    		day_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint8_t week_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t week_size() noexcept
    	{
    		return sizeof(std::uint8_t);
    	}
    
    	static constexpr std::size_t week_offset() noexcept
    	{ 
    		return 4; 
    	}
    	
    	static constexpr const char* week_name() noexcept
    	{ 
    		return "week"; 
    	}
    	
    	static constexpr std::uint8_t week_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint8_t week_max_value() noexcept
    	{
    		return (UINT8_MAX - 1);
    	}
    	
    	static constexpr std::uint8_t week_null_value() noexcept
    	{
    		return UINT8_MAX;
    	}
    
    	constexpr std::uint8_t week() const noexcept
    	{ 
    		return week_;
    	}
    	
    	constexpr MonthYear& set_week(std::uint8_t value) noexcept
    	{
    		week_ = value;
    		return *this;
    	}
    
    
    public:
    	MonthYear() = default;
    
    	/*constexpr */
    	MonthYear(std::uint16_t year, std::uint8_t month, std::uint8_t day, std::uint8_t week) noexcept
    		:year_(year), month_(month), day_(day), week_(week)
    	{
    		
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::MonthYear &msg)
{
	os << msg.year_name() << ": " << msg.year() << " ";
	os << msg.month_name() << ": " << msg.month() << " ";
	os << msg.day_name() << ": " << msg.day() << " ";
	os << msg.week_name() << ": " << msg.week() << " ";
	return os;
}
}
