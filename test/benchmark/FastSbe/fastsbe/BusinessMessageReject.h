#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>
#include<BusinessRejectReasonEnum.h>
#include<DATA.h>

namespace fastsbe
{

class BusinessMessageReject
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "BusinessMessageReject"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 97; 
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
    	char busines_reject_ref_id_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t busines_reject_ref_id_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t busines_reject_ref_id_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t busines_reject_ref_id_id() noexcept
    	{
    		return 379;
    	}
    
    	static constexpr const char *busines_reject_ref_id_name() noexcept
    	{
    		return "BusinesRejectRefId";
    	}
    
    	constexpr char *busines_reject_ref_id() noexcept
    	{
    		return busines_reject_ref_id_;
    	}
    
    	constexpr const char *busines_reject_ref_id() const noexcept
    	{
    		return busines_reject_ref_id_;
    	}
    
    	constexpr std::string_view busines_reject_ref_id_view() noexcept
    	{
    		return std::string_view(busines_reject_ref_id_, 8);
    	}
    
    	constexpr const std::string_view busines_reject_ref_id_view() const noexcept
    	{
    		return std::string_view(busines_reject_ref_id_, 8);
    	}
    
    	const std::string busines_reject_ref_id_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(busines_reject_ref_id_ + length) != '\0'; ++length);
    		return std::string(busines_reject_ref_id_, length);
    	}
    
    	constexpr auto &set_busines_reject_ref_id(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(busines_reject_ref_id_, value, busines_reject_ref_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_busines_reject_ref_id(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(busines_reject_ref_id_size(), value.size());
    		std::memcpy(busines_reject_ref_id_, value.data(), busines_reject_ref_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	BusinessRejectReasonEnum::Value business_reject_reason_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t business_reject_reason_size() noexcept
    	{
    		return sizeof(BusinessRejectReasonEnum);
    	}
    
    	static constexpr std::size_t business_reject_reason_offset() noexcept
    	{ 
    		return busines_reject_ref_id_offset() + busines_reject_ref_id_size(); 
    	}
    
    	static constexpr std::size_t business_reject_reason_id() noexcept
    	{ 
    		return 380; 
    	}
    
    	static constexpr const char* business_reject_reason_name() noexcept
    	{ 
    		return "BusinessRejectReason"; 
    	}
    
    	static constexpr BusinessRejectReasonEnum::Value business_reject_reason_null_value() noexcept
    	{
    		return BusinessRejectReasonEnum::Value::nullValue;
    	}
    
    	constexpr BusinessRejectReasonEnum::Value business_reject_reason() const noexcept
    	{ 
    		return business_reject_reason_;
    	}
    	
    	constexpr auto& set_business_reject_reason(BusinessRejectReasonEnum::Value value) noexcept
    	{
    		business_reject_reason_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char buffer_[1024]{};
    	#pragma pack(pop)
    
    	const char *buffer() const
    	{
    		return buffer_;
    	}
    
    	char *buffer()
    	{
    		return buffer_;
    	}
    
    public:
    
    class Text
    {
    	friend BusinessMessageReject;
    
    private:
    #pragma pack(push, 1)
    	DATA header_{};
    #pragma pack(pop)
    
    public:
    	Text() = default;
    
    	std::basic_string_view<char> get_str() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<char*>(buffer), this->header_.length()};
    	}
    
    	const std::basic_string_view<char> get_str() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return {reinterpret_cast<const char*>(buffer), this->header_.length()};
    	}
    
    	char* get() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<char*>(buffer);
    	}
    
    	const char* get() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(DATA);
    		return reinterpret_cast<const char*>(buffer);
    	}
    
    	const auto length() const noexcept
    	{
    		return header_.length();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	Text text_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t text_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t text_id() noexcept
    	{ 
    		return 58; 
    	}
    	
    	static constexpr const char* text_name() noexcept
    	{ 
    		return "Text"; 
    	}
    
    	std::size_t text_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t text_data_length() const noexcept
    	{
    		auto& data = text();
    		return data.header_.length();
    	}
    	
    	const Text& text() const noexcept
    	{ 
    		const auto* buf = buffer() + text_offset();
    		return *reinterpret_cast<const Text*>(buf);
    	}
    	
    	Text& text() noexcept
    	{
    		auto* buf = buffer() + text_offset();
    		return *reinterpret_cast<Text*>(buf);
    	}
    
    	Text& AppendText(const char* value, std::uint16_t length) noexcept
    	{
    		auto* buf = buffer() + text_offset();
    		auto& data = *reinterpret_cast<Text*>(buf);
    		data.header_.set_length(length);
    		std::memcpy(data.get(), value, length);
    		return data;
    	}
    
    	Text& AppendText(std::basic_string_view<char> value) noexcept
    	{
    		auto* buf = buffer() + text_offset();
    		auto& data = *reinterpret_cast<Text*>(buf);
    		data.header_.set_length(value.size());
    		std::memcpy(data.get(), value.data(), value.size());
    		return data;	
    	}
    	
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::BusinessMessageReject &msg)
{
	os << msg.busines_reject_ref_id_name() << ": " << msg.busines_reject_ref_id() << " ";
	os << msg.business_reject_reason_name() << ": " << msg.business_reject_reason() << " ";
	os << msg.text_name() << ": " << msg.text().get_str() << " ";
	return os;
}
}
