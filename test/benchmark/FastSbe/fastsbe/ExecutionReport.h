#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>
#include<ExecTypeEnum.h>
#include<OrdStatusEnum.h>
#include<MONTHYEAR.h>
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
    	char OrderID_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t OrderID_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t OrderID_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t OrderID_id() noexcept
    	{
    		return 37;
    	}
    
    	static constexpr const char *OrderID_name() noexcept
    	{
    		return "OrderID";
    	}
    
    	constexpr char *get_OrderID() noexcept
    	{
    		return OrderID_;
    	}
    
    	constexpr const char *get_OrderID() const noexcept
    	{
    		return OrderID_;
    	}
    
    	constexpr std::string_view get_OrderID_view() noexcept
    	{
    		return std::string_view(OrderID_, 8);
    	}
    
    	constexpr const std::string_view get_OrderID_view() const noexcept
    	{
    		return std::string_view(OrderID_, 8);
    	}
    
    	const std::string get_OrderID_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(OrderID_ + length) != '\0'; ++length);
    		return std::string(OrderID_, length);
    	}
    
    	constexpr auto &set_OrderID(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(OrderID_, value, OrderID_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_OrderID(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(OrderID_size(), value.size());
    		std::memcpy(OrderID_, value.data(), OrderID_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	char ExecID_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ExecID_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t ExecID_offset() noexcept
    	{
    		return OrderID_offset() + OrderID_size();
    	}
    
    	static constexpr std::size_t ExecID_id() noexcept
    	{
    		return 17;
    	}
    
    	static constexpr const char *ExecID_name() noexcept
    	{
    		return "ExecID";
    	}
    
    	constexpr char *get_ExecID() noexcept
    	{
    		return ExecID_;
    	}
    
    	constexpr const char *get_ExecID() const noexcept
    	{
    		return ExecID_;
    	}
    
    	constexpr std::string_view get_ExecID_view() noexcept
    	{
    		return std::string_view(ExecID_, 8);
    	}
    
    	constexpr const std::string_view get_ExecID_view() const noexcept
    	{
    		return std::string_view(ExecID_, 8);
    	}
    
    	const std::string get_ExecID_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(ExecID_ + length) != '\0'; ++length);
    		return std::string(ExecID_, length);
    	}
    
    	constexpr auto &set_ExecID(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(ExecID_, value, ExecID_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_ExecID(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(ExecID_size(), value.size());
    		std::memcpy(ExecID_, value.data(), ExecID_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	ExecTypeEnum::Value ExecType_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ExecType_size() noexcept
    	{
    		return sizeof(ExecTypeEnum);
    	}
    
    	static constexpr std::size_t ExecType_offset() noexcept
    	{ 
    		return ExecID_offset() + ExecID_size(); 
    	}
    
    	static constexpr std::size_t ExecType_id() noexcept
    	{ 
    		return 150; 
    	}
    
    	static constexpr const char* ExecType_name() noexcept
    	{ 
    		return "ExecType"; 
    	}
    
    	static constexpr ExecTypeEnum::Value ExecType_null_value() noexcept
    	{
    		return ExecTypeEnum::Value::nullValue;
    	}
    
    	constexpr ExecTypeEnum::Value get_ExecType() const noexcept
    	{ 
    		return ExecType_;
    	}
    	
    	constexpr auto& set_ExecType(ExecTypeEnum::Value value) noexcept
    	{
    		ExecType_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	OrdStatusEnum::Value OrdStatus_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t OrdStatus_size() noexcept
    	{
    		return sizeof(OrdStatusEnum);
    	}
    
    	static constexpr std::size_t OrdStatus_offset() noexcept
    	{ 
    		return ExecType_offset() + ExecType_size(); 
    	}
    
    	static constexpr std::size_t OrdStatus_id() noexcept
    	{ 
    		return 39; 
    	}
    
    	static constexpr const char* OrdStatus_name() noexcept
    	{ 
    		return "OrdStatus"; 
    	}
    
    	static constexpr OrdStatusEnum::Value OrdStatus_null_value() noexcept
    	{
    		return OrdStatusEnum::Value::nullValue;
    	}
    
    	constexpr OrdStatusEnum::Value get_OrdStatus() const noexcept
    	{ 
    		return OrdStatus_;
    	}
    	
    	constexpr auto& set_OrdStatus(OrdStatusEnum::Value value) noexcept
    	{
    		OrdStatus_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	char Symbol_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Symbol_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t Symbol_offset() noexcept
    	{
    		return OrdStatus_offset() + OrdStatus_size();
    	}
    
    	static constexpr std::size_t Symbol_id() noexcept
    	{
    		return 55;
    	}
    
    	static constexpr const char *Symbol_name() noexcept
    	{
    		return "Symbol";
    	}
    
    	constexpr char *get_Symbol() noexcept
    	{
    		return Symbol_;
    	}
    
    	constexpr const char *get_Symbol() const noexcept
    	{
    		return Symbol_;
    	}
    
    	constexpr std::string_view get_Symbol_view() noexcept
    	{
    		return std::string_view(Symbol_, 8);
    	}
    
    	constexpr const std::string_view get_Symbol_view() const noexcept
    	{
    		return std::string_view(Symbol_, 8);
    	}
    
    	const std::string get_Symbol_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(Symbol_ + length) != '\0'; ++length);
    		return std::string(Symbol_, length);
    	}
    
    	constexpr auto &set_Symbol(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(Symbol_, value, Symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_Symbol(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(Symbol_size(), value.size());
    		std::memcpy(Symbol_, value.data(), Symbol_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	MONTHYEAR MaturityMonthYear_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t MaturityMonthYear_size() noexcept
    	{
    		return sizeof(MONTHYEAR);
    	}
    
    	static constexpr std::size_t MaturityMonthYear_offset() noexcept
    	{
    		return Symbol_offset() + Symbol_size();
    	}
    
    	static constexpr std::size_t MaturityMonthYear_id() noexcept
    	{
    		return 200;
    	}
    
    	static constexpr const char *MaturityMonthYear_name() noexcept
    	{
    		return "MaturityMonthYear";
    	}
    
    	constexpr const MONTHYEAR &get_MaturityMonthYear() const noexcept
    	{
    		return MaturityMonthYear_;
    	}
    
    	constexpr MONTHYEAR &get_MaturityMonthYear() noexcept
    	{
    		return MaturityMonthYear_;
    	}
    	constexpr auto &set_MaturityMonthYear(MONTHYEAR &value) noexcept
    	{
    		MaturityMonthYear_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	SideEnum::Value Side_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t Side_size() noexcept
    	{
    		return sizeof(SideEnum);
    	}
    
    	static constexpr std::size_t Side_offset() noexcept
    	{ 
    		return MaturityMonthYear_offset() + MaturityMonthYear_size(); 
    	}
    
    	static constexpr std::size_t Side_id() noexcept
    	{ 
    		return 54; 
    	}
    
    	static constexpr const char* Side_name() noexcept
    	{ 
    		return "Side"; 
    	}
    
    	static constexpr SideEnum::Value Side_null_value() noexcept
    	{
    		return SideEnum::Value::nullValue;
    	}
    
    	constexpr SideEnum::Value get_Side() const noexcept
    	{ 
    		return Side_;
    	}
    	
    	constexpr auto& set_Side(SideEnum::Value value) noexcept
    	{
    		Side_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	QtyEncoding LeavesQty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t LeavesQty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t LeavesQty_offset() noexcept
    	{
    		return Side_offset() + Side_size();
    	}
    
    	static constexpr std::size_t LeavesQty_id() noexcept
    	{
    		return 151;
    	}
    
    	static constexpr const char *LeavesQty_name() noexcept
    	{
    		return "LeavesQty";
    	}
    
    	constexpr const QtyEncoding &get_LeavesQty() const noexcept
    	{
    		return LeavesQty_;
    	}
    
    	constexpr QtyEncoding &get_LeavesQty() noexcept
    	{
    		return LeavesQty_;
    	}
    	constexpr auto &set_LeavesQty(QtyEncoding &value) noexcept
    	{
    		LeavesQty_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	QtyEncoding CumQty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t CumQty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t CumQty_offset() noexcept
    	{
    		return LeavesQty_offset() + LeavesQty_size();
    	}
    
    	static constexpr std::size_t CumQty_id() noexcept
    	{
    		return 14;
    	}
    
    	static constexpr const char *CumQty_name() noexcept
    	{
    		return "CumQty";
    	}
    
    	constexpr const QtyEncoding &get_CumQty() const noexcept
    	{
    		return CumQty_;
    	}
    
    	constexpr QtyEncoding &get_CumQty() noexcept
    	{
    		return CumQty_;
    	}
    	constexpr auto &set_CumQty(QtyEncoding &value) noexcept
    	{
    		CumQty_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	std::uint16_t TradeDate_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t TradeDate_size() noexcept
    	{
    		return sizeof(std::uint16_t);
    	}
    
    	static constexpr std::size_t TradeDate_offset() noexcept
    	{ 
    		return CumQty_offset() + CumQty_size(); 
    	}
    
    	static constexpr std::size_t TradeDate_id() noexcept
    	{ 
    		return 75; 
    	}
    	
    	static constexpr const char* TradeDate_name() noexcept
    	{ 
    		return "TradeDate"; 
    	}
    	
    	static constexpr std::uint16_t TradeDate_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint16_t TradeDate_max_value() noexcept
    	{
    		return 65534;
    	}
    	
    	static constexpr std::uint16_t TradeDate_null_value() noexcept
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
    
    	constexpr std::uint16_t get_TradeDate() const noexcept
    	{ 
    		return TradeDate_;
    	}
    	
    	constexpr auto& set_TradeDate(std::uint16_t value) noexcept
    	{
    		TradeDate_ = value;
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
        
        class Data
        {
            
            private:
            	#pragma pack(push, 1)
            	OptionalDecimalEncoding FillPx_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t FillPx_size() noexcept
            	{
            		return sizeof(OptionalDecimalEncoding);
            	}
            
            	static constexpr std::size_t FillPx_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t FillPx_id() noexcept
            	{
            		return 1364;
            	}
            
            	static constexpr const char *FillPx_name() noexcept
            	{
            		return "FillPx";
            	}
            
            	constexpr const OptionalDecimalEncoding &get_FillPx() const noexcept
            	{
            		return FillPx_;
            	}
            
            	constexpr OptionalDecimalEncoding &get_FillPx() noexcept
            	{
            		return FillPx_;
            	}
            	constexpr auto &set_FillPx(OptionalDecimalEncoding &value) noexcept
            	{
            		FillPx_ = value;
            		return *this;
            	}
            
            
            private:
            	#pragma pack(push, 1)
            	QtyEncoding FillQty_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t FillQty_size() noexcept
            	{
            		return sizeof(QtyEncoding);
            	}
            
            	static constexpr std::size_t FillQty_offset() noexcept
            	{
            		return FillPx_offset() + FillPx_size();
            	}
            
            	static constexpr std::size_t FillQty_id() noexcept
            	{
            		return 1365;
            	}
            
            	static constexpr const char *FillQty_name() noexcept
            	{
            		return "FillQty";
            	}
            
            	constexpr const QtyEncoding &get_FillQty() const noexcept
            	{
            		return FillQty_;
            	}
            
            	constexpr QtyEncoding &get_FillQty() noexcept
            	{
            		return FillQty_;
            	}
            	constexpr auto &set_FillQty(QtyEncoding &value) noexcept
            	{
            		FillQty_ = value;
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
    		:header_(sizeof(FillsGrp::Data), count) {}
    
    	Data& get(std::size_t group_id) noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(GroupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<Data*>(buffer);
    	}
    
    	const Data& get(std::size_t group_id) const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(GroupSizeEncoding)
    			+ (this->header_.get_blockLength() * group_id);
    		return *reinterpret_cast<const Data*>(buffer);
    	}
    
    	const auto get_blockLength() const noexcept
    	{
    		return header_.get_blockLength();
    	}
    
    	const auto get_numInGroup() const noexcept
    	{
    		return header_.get_numInGroup();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	FillsGrp FillsGrp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t FillsGrp_size() noexcept
    	{
    		return sizeof(FillsGrp::Data);
    	}
    
    	static constexpr std::size_t FillsGrp_id() noexcept
    	{ 
    		return 2112; 
    	}
    	
    	static constexpr const char* FillsGrp_name() noexcept
    	{ 
    		return "FillsGrp"; 
    	}
    
    	std::size_t FillsGrp_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t FillsGrp_data_length() const noexcept
    	{
    		auto& group = get_FillsGrp();
    		return group.header_.get_blockLength() * group.header_.get_numInGroup();
    	}
    	
    	const FillsGrp& get_FillsGrp() const noexcept
    	{ 
    		const auto* buf = buffer() + FillsGrp_offset();
    		return *reinterpret_cast<const FillsGrp*>(buf);
    	}
    	
    	FillsGrp& get_FillsGrp() noexcept
    	{
    		auto* buf = buffer() + FillsGrp_offset();
    		return *reinterpret_cast<FillsGrp*>(buf);
    	}
    
    	FillsGrp& append_FillsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + FillsGrp_offset();
    		auto& group = *reinterpret_cast<FillsGrp*>(buf);
    		group.header_.set_blockLength(sizeof(FillsGrp::Data));
    		group.header_.set_numInGroup(count);
    		return group;	
    	}
    
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport::FillsGrp &group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto &g = group.get(i);
		os << g.FillPx_name() << ": " << g.get_FillPx() << " ";
		os << g.FillQty_name() << ": " << g.get_FillQty() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::ExecutionReport &msg)
{
	os << msg.OrderID_name() << ": " << msg.get_OrderID() << " ";
	os << msg.ExecID_name() << ": " << msg.get_ExecID() << " ";
	os << msg.ExecType_name() << ": " << msg.get_ExecType() << " ";
	os << msg.OrdStatus_name() << ": " << msg.get_OrdStatus() << " ";
	os << msg.Symbol_name() << ": " << msg.get_Symbol() << " ";
	os << msg.MaturityMonthYear_name() << ": " << msg.get_MaturityMonthYear() << " ";
	os << msg.Side_name() << ": " << msg.get_Side() << " ";
	os << msg.LeavesQty_name() << ": " << msg.get_LeavesQty() << " ";
	os << msg.CumQty_name() << ": " << msg.get_CumQty() << " ";
	os << msg.TradeDate_name() << ": " << msg.get_TradeDate() << " ";
	os << msg.FillsGrp_name() << ": " << msg.get_FillsGrp() << " ";
	return os;
}
}
