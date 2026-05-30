#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>
#include<ExecTypeEnum.h>
#include<OrdStatusEnum.h>
#include<MonthYear.h>
#include<SideEnum.h>
#include<QtyEncoding.h>
#include<QtyEncoding.h>
#include<OptionalDecimalEncoding.h>
#include<QtyEncoding.h>
#include<GroupSizeEncoding.h>

namespace fastsbe
{

class ExecutionReport
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "ExecutionReport"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 98; 
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
    	char order_id_[8]{};
    	#pragma pack(pop)
    
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
    	#pragma pack(push, 1)
    	char exec_id_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t exec_id_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t exec_id_offset() noexcept
    	{
    		return order_id_offset() + order_id_size();
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
    	#pragma pack(push, 1)
    	ExecTypeEnum::Value exec_type_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t exec_type_size() noexcept
    	{
    		return sizeof(ExecTypeEnum);
    	}
    
    	static constexpr std::size_t exec_type_offset() noexcept
    	{ 
    		return exec_id_offset() + exec_id_size(); 
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
    	#pragma pack(push, 1)
    	OrdStatusEnum::Value ord_status_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ord_status_size() noexcept
    	{
    		return sizeof(OrdStatusEnum);
    	}
    
    	static constexpr std::size_t ord_status_offset() noexcept
    	{ 
    		return exec_type_offset() + exec_type_size(); 
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
    	#pragma pack(push, 1)
    	char symbol_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t symbol_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t symbol_offset() noexcept
    	{
    		return ord_status_offset() + ord_status_size();
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
    	#pragma pack(push, 1)
    	MonthYear maturity_month_year_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t maturity_month_year_size() noexcept
    	{
    		return sizeof(MonthYear);
    	}
    
    	static constexpr std::size_t maturity_month_year_offset() noexcept
    	{
    		return symbol_offset() + symbol_size();
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
    	#pragma pack(push, 1)
    	SideEnum::Value side_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t side_size() noexcept
    	{
    		return sizeof(SideEnum);
    	}
    
    	static constexpr std::size_t side_offset() noexcept
    	{ 
    		return maturity_month_year_offset() + maturity_month_year_size(); 
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
    	#pragma pack(push, 1)
    	QtyEncoding leaves_qty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t leaves_qty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t leaves_qty_offset() noexcept
    	{
    		return side_offset() + side_size();
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
    	#pragma pack(push, 1)
    	QtyEncoding cum_qty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t cum_qty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t cum_qty_offset() noexcept
    	{
    		return leaves_qty_offset() + leaves_qty_size();
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
    	#pragma pack(push, 1)
    	std::uint16_t trade_date_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t trade_date_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t trade_date_offset() noexcept
    	{ 
    		return cum_qty_offset() + cum_qty_size(); 
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
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t trade_date_null_value() noexcept
    	{ 
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wtype-limits"
    	#endif
    		return 65535;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    
    class FillsGrp
    {
    	friend ExecutionReport;
        
        class Entry
        {
            
            private:
            	#pragma pack(push, 1)
            	OptionalDecimalEncoding fill_px_{};
            	#pragma pack(pop)
            
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
            	#pragma pack(push, 1)
            	QtyEncoding fill_qty_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t fill_qty_size() noexcept
            	{
            		return sizeof(QtyEncoding);
            	}
            
            	static constexpr std::size_t fill_qty_offset() noexcept
            	{
            		return fill_px_offset() + fill_px_size();
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
    
    private:
    #pragma pack(push, 1)
    	GroupSizeEncoding header_{};
    #pragma pack(pop)
    
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
    
    private:
    	#pragma pack(push, 1)
    	FillsGrp fills_grp_{};
    	#pragma pack(pop)
    
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

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport::FillsGrp &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.fill_px_name() << ": " << g.fill_px() << " ";
		os << g.fill_qty_name() << ": " << g.fill_qty() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport &msg)
{
	os << msg.order_id_name() << ": " << msg.order_id() << " ";
	os << msg.exec_id_name() << ": " << msg.exec_id() << " ";
	os << msg.exec_type_name() << ": " << msg.exec_type() << " ";
	os << msg.ord_status_name() << ": " << msg.ord_status() << " ";
	os << msg.symbol_name() << ": " << msg.symbol() << " ";
	os << msg.maturity_month_year_name() << ": " << msg.maturity_month_year() << " ";
	os << msg.side_name() << ": " << msg.side() << " ";
	os << msg.leaves_qty_name() << ": " << msg.leaves_qty() << " ";
	os << msg.cum_qty_name() << ": " << msg.cum_qty() << " ";
	os << msg.trade_date_name() << ": " << msg.trade_date() << " ";
	os << msg.fills_grp_name() << ": " << msg.fills_grp() << " ";
	return os;
}
}
