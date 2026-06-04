#pragma once

#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>

#include "ExecTypeEnum.h"
#include "OrdStatusEnum.h"
#include "MonthYear.h"
#include "SideEnum.h"
#include "QtyEncoding.h"
#include "QtyEncoding.h"
#include "OptionalDecimalEncoding.h"
#include "QtyEncoding.h"
#include "GroupSizeEncoding.h"

namespace fastsbe
{

#pragma pack(push, 1)
class ExecutionReport
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "ExecutionReport"; 
    	}
    
    	static constexpr std::uint16_t template_id() noexcept
    	{ 
    		return 98; 
    	}
    
    	static constexpr std::uint16_t schema() noexcept
    	{  
    		return 91; 
    	}
    
    	static constexpr std::uint16_t version() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::uint16_t block_length() noexcept
    	{
    		return 42;
    	}
    
    	static constexpr const char* semantic_type() noexcept
    	{ 
    		return ""; 	
    	}
    
    
    private:
    	char order_id_[8]{};
    
    public:
    	static constexpr std::size_t order_id_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t order_id_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t order_id_id() noexcept
    	{
    		return 37;
    	}
    
    	static constexpr const char *order_id_name() noexcept
    	{
    		return "OrderID";
    	}
    
    	constexpr char *order_id() noexcept
    	{
    		return order_id_;
    	}
    
    	constexpr const char *order_id() const noexcept
    	{
    		return order_id_;
    	}
    
    	constexpr std::string_view order_id_view() noexcept
    	{
    		return std::string_view(order_id_, 8);
    	}
    
    	constexpr const std::string_view order_id_view() const noexcept
    	{
    		return std::string_view(order_id_, 8);
    	}
    
    	const std::string order_id_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(order_id_ + length) != '\0'; ++length);
    		return std::string(order_id_, length);
    	}
    
    	constexpr auto &set_order_id(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(order_id_, value, order_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_order_id(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(order_id_size(), value.size());
    		std::memcpy(order_id_, value.data(), order_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	char exec_id_[8]{};
    
    public:
    	static constexpr std::size_t exec_id_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t exec_id_offset() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t exec_id_id() noexcept
    	{
    		return 17;
    	}
    
    	static constexpr const char *exec_id_name() noexcept
    	{
    		return "ExecID";
    	}
    
    	constexpr char *exec_id() noexcept
    	{
    		return exec_id_;
    	}
    
    	constexpr const char *exec_id() const noexcept
    	{
    		return exec_id_;
    	}
    
    	constexpr std::string_view exec_id_view() noexcept
    	{
    		return std::string_view(exec_id_, 8);
    	}
    
    	constexpr const std::string_view exec_id_view() const noexcept
    	{
    		return std::string_view(exec_id_, 8);
    	}
    
    	const std::string exec_id_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(exec_id_ + length) != '\0'; ++length);
    		return std::string(exec_id_, length);
    	}
    
    	constexpr auto &set_exec_id(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(exec_id_, value, exec_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_exec_id(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(exec_id_size(), value.size());
    		std::memcpy(exec_id_, value.data(), exec_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	ExecTypeEnum::Value exec_type_{};
    
    public:
    	static constexpr std::size_t exec_type_size() noexcept
    	{
    		return sizeof(ExecTypeEnum);
    	}
    
    	static constexpr std::size_t exec_type_offset() noexcept
    	{ 
    		return 16; 
    	}
    
    	static constexpr std::size_t exec_type_id() noexcept
    	{ 
    		return 150; 
    	}
    
    	static constexpr const char* exec_type_name() noexcept
    	{ 
    		return "ExecType"; 
    	}
    
    	static constexpr ExecTypeEnum::Value exec_type_null_value() noexcept
    	{
    		return ExecTypeEnum::Value::nullValue;
    	}
    
    	constexpr ExecTypeEnum::Value exec_type() const noexcept
    	{ 
    		return exec_type_;
    	}
    	
    	constexpr auto& set_exec_type(ExecTypeEnum::Value value) noexcept
    	{
    		exec_type_ = value;
    		return *this;
    	}
    
    
    private:
    	OrdStatusEnum::Value ord_status_{};
    
    public:
    	static constexpr std::size_t ord_status_size() noexcept
    	{
    		return sizeof(OrdStatusEnum);
    	}
    
    	static constexpr std::size_t ord_status_offset() noexcept
    	{ 
    		return 17; 
    	}
    
    	static constexpr std::size_t ord_status_id() noexcept
    	{ 
    		return 39; 
    	}
    
    	static constexpr const char* ord_status_name() noexcept
    	{ 
    		return "OrdStatus"; 
    	}
    
    	static constexpr OrdStatusEnum::Value ord_status_null_value() noexcept
    	{
    		return OrdStatusEnum::Value::nullValue;
    	}
    
    	constexpr OrdStatusEnum::Value ord_status() const noexcept
    	{ 
    		return ord_status_;
    	}
    	
    	constexpr auto& set_ord_status(OrdStatusEnum::Value value) noexcept
    	{
    		ord_status_ = value;
    		return *this;
    	}
    
    
    private:
    	char symbol_[8]{};
    
    public:
    	static constexpr std::size_t symbol_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t symbol_offset() noexcept
    	{
    		return 18;
    	}
    
    	static constexpr std::size_t symbol_id() noexcept
    	{
    		return 55;
    	}
    
    	static constexpr const char *symbol_name() noexcept
    	{
    		return "Symbol";
    	}
    
    	constexpr char *symbol() noexcept
    	{
    		return symbol_;
    	}
    
    	constexpr const char *symbol() const noexcept
    	{
    		return symbol_;
    	}
    
    	constexpr std::string_view symbol_view() noexcept
    	{
    		return std::string_view(symbol_, 8);
    	}
    
    	constexpr const std::string_view symbol_view() const noexcept
    	{
    		return std::string_view(symbol_, 8);
    	}
    
    	const std::string symbol_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(symbol_ + length) != '\0'; ++length);
    		return std::string(symbol_, length);
    	}
    
    	constexpr auto &set_symbol(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(symbol_, value, symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_symbol(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(symbol_size(), value.size());
    		std::memcpy(symbol_, value.data(), symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	MonthYear maturity_month_year_{};
    
    public:
    	static constexpr std::size_t maturity_month_year_size() noexcept
    	{
    		return sizeof(MonthYear);
    	}
    
    	static constexpr std::size_t maturity_month_year_offset() noexcept
    	{
    		return 26;
    	}
    
    	static constexpr std::size_t maturity_month_year_id() noexcept
    	{
    		return 200;
    	}
    
    	static constexpr const char *maturity_month_year_name() noexcept
    	{
    		return "MaturityMonthYear";
    	}
    
    	constexpr const MonthYear &maturity_month_year() const noexcept
    	{
    		return maturity_month_year_;
    	}
    
    	constexpr MonthYear &maturity_month_year() noexcept
    	{
    		return maturity_month_year_;
    	}
    	constexpr auto &set_maturity_month_year(MonthYear &value) noexcept
    	{
    		maturity_month_year_ = value;
    		return *this;
    	}
    
    
    private:
    	SideEnum::Value side_{};
    
    public:
    	static constexpr std::size_t side_size() noexcept
    	{
    		return sizeof(SideEnum);
    	}
    
    	static constexpr std::size_t side_offset() noexcept
    	{ 
    		return 31; 
    	}
    
    	static constexpr std::size_t side_id() noexcept
    	{ 
    		return 54; 
    	}
    
    	static constexpr const char* side_name() noexcept
    	{ 
    		return "Side"; 
    	}
    
    	static constexpr SideEnum::Value side_null_value() noexcept
    	{
    		return SideEnum::Value::nullValue;
    	}
    
    	constexpr SideEnum::Value side() const noexcept
    	{ 
    		return side_;
    	}
    	
    	constexpr auto& set_side(SideEnum::Value value) noexcept
    	{
    		side_ = value;
    		return *this;
    	}
    
    
    private:
    	QtyEncoding leaves_qty_{};
    
    public:
    	static constexpr std::size_t leaves_qty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t leaves_qty_offset() noexcept
    	{
    		return 32;
    	}
    
    	static constexpr std::size_t leaves_qty_id() noexcept
    	{
    		return 151;
    	}
    
    	static constexpr const char *leaves_qty_name() noexcept
    	{
    		return "LeavesQty";
    	}
    
    	constexpr const QtyEncoding &leaves_qty() const noexcept
    	{
    		return leaves_qty_;
    	}
    
    	constexpr QtyEncoding &leaves_qty() noexcept
    	{
    		return leaves_qty_;
    	}
    	constexpr auto &set_leaves_qty(QtyEncoding &value) noexcept
    	{
    		leaves_qty_ = value;
    		return *this;
    	}
    
    
    private:
    	QtyEncoding cum_qty_{};
    
    public:
    	static constexpr std::size_t cum_qty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t cum_qty_offset() noexcept
    	{
    		return 36;
    	}
    
    	static constexpr std::size_t cum_qty_id() noexcept
    	{
    		return 14;
    	}
    
    	static constexpr const char *cum_qty_name() noexcept
    	{
    		return "CumQty";
    	}
    
    	constexpr const QtyEncoding &cum_qty() const noexcept
    	{
    		return cum_qty_;
    	}
    
    	constexpr QtyEncoding &cum_qty() noexcept
    	{
    		return cum_qty_;
    	}
    	constexpr auto &set_cum_qty(QtyEncoding &value) noexcept
    	{
    		cum_qty_ = value;
    		return *this;
    	}
    
    
    private:
    	std::uint16_t trade_date_{};
    
    public:
    	static constexpr std::size_t trade_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trade_date_offset() noexcept
    	{ 
    		return 40; 
    	}
    
    	static constexpr std::size_t trade_date_id() noexcept
    	{ 
    		return 75; 
    	}
    	
    	static constexpr const char* trade_date_name() noexcept
    	{ 
    		return "TradeDate"; 
    	}
    	
    	static constexpr std::uint16_t trade_date_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t trade_date_max_value() noexcept
    	{
    		return (UINT16_MAX - 1);
    	}
    	
    	static constexpr std::uint16_t trade_date_null_value() noexcept
    	{
    		return UINT16_MAX;
    	}
    
    	constexpr std::uint16_t trade_date() const noexcept
    	{ 
    		return trade_date_;
    	}
    	
    	constexpr auto& set_trade_date(std::uint16_t value) noexcept
    	{
    		trade_date_ = value;
    		return *this;
    	}
    
    
    private:
    	char buffer_[1024]{};
    
    	const char *buffer() const
    	{
    		return buffer_;
    	}
    
    	char *buffer()
    	{
    		return buffer_;
    	}
    
    public:
    
    #pragma pack(push, 1)
    class FillsGrp
    {
    	friend ExecutionReport;
        
        #pragma pack(push, 1)
        class Entry
        {
            
            private:
            	OptionalDecimalEncoding fill_px_{};
            
            public:
            	static constexpr std::size_t fill_px_size() noexcept
            	{
            		return sizeof(OptionalDecimalEncoding);
            	}
            
            	static constexpr std::size_t fill_px_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t fill_px_id() noexcept
            	{
            		return 1364;
            	}
            
            	static constexpr const char *fill_px_name() noexcept
            	{
            		return "FillPx";
            	}
            
            	constexpr const OptionalDecimalEncoding &fill_px() const noexcept
            	{
            		return fill_px_;
            	}
            
            	constexpr OptionalDecimalEncoding &fill_px() noexcept
            	{
            		return fill_px_;
            	}
            	constexpr auto &set_fill_px(OptionalDecimalEncoding &value) noexcept
            	{
            		fill_px_ = value;
            		return *this;
            	}
            
            
            private:
            	QtyEncoding fill_qty_{};
            
            public:
            	static constexpr std::size_t fill_qty_size() noexcept
            	{
            		return sizeof(QtyEncoding);
            	}
            
            	static constexpr std::size_t fill_qty_offset() noexcept
            	{
            		return 8;
            	}
            
            	static constexpr std::size_t fill_qty_id() noexcept
            	{
            		return 1365;
            	}
            
            	static constexpr const char *fill_qty_name() noexcept
            	{
            		return "FillQty";
            	}
            
            	constexpr const QtyEncoding &fill_qty() const noexcept
            	{
            		return fill_qty_;
            	}
            
            	constexpr QtyEncoding &fill_qty() noexcept
            	{
            		return fill_qty_;
            	}
            	constexpr auto &set_fill_qty(QtyEncoding &value) noexcept
            	{
            		fill_qty_ = value;
            		return *this;
            	}
            
    };
    #pragma pack(pop)
    
    private:
    	GroupSizeEncoding header_{};
    
    public:
    	FillsGrp() = default;
    	FillsGrp(std::uint16_t count)
    		:header_(sizeof(FillsGrp::Entry), count) {}
    
    	Entry& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(GroupSizeEncoding)
    			+ (this->header_.block_length() * group_id);
    		return *reinterpret_cast<Entry*>(buffer);
    	}
    
    	const Entry& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(GroupSizeEncoding)
    			+ (this->header_.block_length() * group_id);
    		return *reinterpret_cast<const Entry*>(buffer);
    	}
    
    	const auto block_length() const noexcept
    	{
    		return header_.block_length();
    	}
    
    	const auto num_in_group() const noexcept
    	{
    		return header_.num_in_group();
    	}
    
    };
    #pragma pack(pop)
    
    private:
    	FillsGrp fills_grp_{};
    
    public:
    	static constexpr std::size_t fills_grp_size() noexcept
    	{
    		return sizeof(FillsGrp::Entry);
    	}
    
    	static constexpr std::size_t fills_grp_id() noexcept
    	{ 
    		return 2112; 
    	}
    	
    	static constexpr const char* fills_grp_name() noexcept
    	{ 
    		return "FillsGrp"; 
    	}
    
    	std::size_t fills_grp_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t fills_grp_data_length() const noexcept
    	{
    		auto& group = fills_grp();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const FillsGrp& fills_grp() const noexcept
    	{ 
    		const auto* buf = buffer() + fills_grp_offset();
    		return *reinterpret_cast<const FillsGrp*>(buf);
    	}
    	
    	FillsGrp& fills_grp() noexcept
    	{
    		auto* buf = buffer() + fills_grp_offset();
    		return *reinterpret_cast<FillsGrp*>(buf);
    	}
    
    	FillsGrp& AppendFillsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + fills_grp_offset();
    		auto& group = *reinterpret_cast<FillsGrp*>(buf);
    		group.header_.set_block_length(sizeof(FillsGrp::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
};
#pragma pack(pop)

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport::FillsGrp &group)
{
	os << "[";
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		if (i) { os << ", "; }
		auto &g = group.get(i);
		os << "{";
		bool comma = false;
		if(comma) { os << ", "; } os << "\"FillPx\": " << g.fill_px(); comma = true;
		if(comma) { os << ", "; } os << "\"FillQty\": " << g.fill_qty(); comma = true;
		os << "}";
	}
	os << "]";
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport &msg)
{
	os << "{";
	bool comma = false;
	if(comma) { os << ", "; } os << "\"OrderID\": " << "\"" << msg.order_id() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"ExecID\": " << "\"" << msg.exec_id() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"ExecType\": " << "\"" << msg.exec_type() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"OrdStatus\": " << "\"" << msg.ord_status() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"Symbol\": " << "\"" << msg.symbol() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"MaturityMonthYear\": " << msg.maturity_month_year(); comma = true;
	if(comma) { os << ", "; } os << "\"Side\": " << "\"" << msg.side() << "\""; comma = true;
	if(comma) { os << ", "; } os << "\"LeavesQty\": " << msg.leaves_qty(); comma = true;
	if(comma) { os << ", "; } os << "\"CumQty\": " << msg.cum_qty(); comma = true;
	if(comma) { os << ", "; } os << "\"TradeDate\": " << msg.trade_date(); comma = true;
	if(comma) { os << ", "; } os << "\"FillsGrp\": " << msg.fills_grp(); comma = true;
	os << "}";
	return os;
}
}
