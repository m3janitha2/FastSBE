#pragma once
#include<cstdint>
#include<string>
#include<string_view>
#include<ostream>
#include<cstring>
#include<SideEnum.h>
#include<QtyEncoding.h>
#include<OrdTypeEnum.h>
#include<OptionalDecimalEncoding.h>
#include<OptionalDecimalEncoding.h>
#include<PartyIDSourceEnum.h>
#include<PartyRoleEnum.h>
#include<GroupSizeEncoding.h>
#include<QtyEncoding.h>
#include<GroupSizeEncoding.h>
#include<GroupSizeEncoding.h>
#include<Data.h>
#include<Data.h>

namespace fastsbe
{

class NewOrderSingle
{
    
    public:
    	static constexpr const char* name() noexcept
    	{ 
    		return "NewOrderSingle"; 
    	}
    
    	static constexpr std::size_t template_id() noexcept
    	{ 
    		return 99; 
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
    	char cl_ord_id_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t cl_ord_id_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t cl_ord_id_offset() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t cl_ord_id_id() noexcept
    	{
    		return 11;
    	}
    
    	static constexpr const char *cl_ord_id_name() noexcept
    	{
    		return "ClOrdId";
    	}
    
    	constexpr char *cl_ord_id() noexcept
    	{
    		return cl_ord_id_;
    	}
    
    	constexpr const char *cl_ord_id() const noexcept
    	{
    		return cl_ord_id_;
    	}
    
    	constexpr std::string_view cl_ord_id_view() noexcept
    	{
    		return std::string_view(cl_ord_id_, 8);
    	}
    
    	constexpr const std::string_view cl_ord_id_view() const noexcept
    	{
    		return std::string_view(cl_ord_id_, 8);
    	}
    
    	const std::string cl_ord_id_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(cl_ord_id_ + length) != '\0'; ++length);
    		return std::string(cl_ord_id_, length);
    	}
    
    	constexpr auto &set_cl_ord_id(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(cl_ord_id_, value, cl_ord_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_cl_ord_id(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(cl_ord_id_size(), value.size());
    		std::memcpy(cl_ord_id_, value.data(), cl_ord_id_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    private:
    	#pragma pack(push, 1)
    	char account_[8]{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t account_size() noexcept
    	{
    		return 8;
    	}
    
    	static constexpr std::size_t account_offset() noexcept
    	{
    		return cl_ord_id_offset() + cl_ord_id_size();
    	}
    
    	static constexpr std::size_t account_id() noexcept
    	{
    		return 1;
    	}
    
    	static constexpr const char *account_name() noexcept
    	{
    		return "Account";
    	}
    
    	constexpr char *account() noexcept
    	{
    		return account_;
    	}
    
    	constexpr const char *account() const noexcept
    	{
    		return account_;
    	}
    
    	constexpr std::string_view account_view() noexcept
    	{
    		return std::string_view(account_, 8);
    	}
    
    	constexpr const std::string_view account_view() const noexcept
    	{
    		return std::string_view(account_, 8);
    	}
    
    	const std::string account_string() const noexcept
    	{
    		auto length = 0ULL;
    		for (; length < 8 && *(account_ + length) != '\0'; ++length);
    		return std::string(account_, length);
    	}
    
    	constexpr auto &set_account(const char *value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		std::memcpy(account_, value, account_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
    	}
    
    	auto &set_account(std::string_view value) noexcept
    	{
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic push
    	#pragma GCC diagnostic ignored "-Wstringop-overflow"
    	#endif
    		// auto size = std::min(account_size(), value.size());
    		std::memcpy(account_, value.data(), account_size());
    		return *this;
    	#if defined(__GNUG__)
    	#pragma GCC diagnostic pop
    	#endif
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
    		return account_offset() + account_size();
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
    	SideEnum::Value side_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t side_size() noexcept
    	{
    		return sizeof(SideEnum);
    	}
    
    	static constexpr std::size_t side_offset() noexcept
    	{ 
    		return symbol_offset() + symbol_size(); 
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
    	std::uint64_t transact_time_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t transact_time_size() noexcept
    	{
    		return sizeof(std::uint64_t);
    	}
    
    	static constexpr std::size_t transact_time_offset() noexcept
    	{ 
    		return side_offset() + side_size(); 
    	}
    
    	static constexpr std::size_t transact_time_id() noexcept
    	{ 
    		return 60; 
    	}
    	
    	static constexpr const char* transact_time_name() noexcept
    	{ 
    		return "TransactTime"; 
    	}
    	
    	static constexpr std::uint64_t transact_time_min_value() noexcept
    	{ 
    		return 0; 
    	}
    	
    	static constexpr std::uint64_t transact_time_max_value() noexcept
    	{
    		return (UINT64_MAX - 1);
    	}
    	
    	static constexpr std::uint64_t transact_time_null_value() noexcept
    	{
    		return UINT64_MAX;
    	}
    
    	constexpr std::uint64_t transact_time() const noexcept
    	{ 
    		return transact_time_;
    	}
    	
    	constexpr auto& set_transact_time(std::uint64_t value) noexcept
    	{
    		transact_time_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	QtyEncoding order_qty_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t order_qty_size() noexcept
    	{
    		return sizeof(QtyEncoding);
    	}
    
    	static constexpr std::size_t order_qty_offset() noexcept
    	{
    		return transact_time_offset() + transact_time_size();
    	}
    
    	static constexpr std::size_t order_qty_id() noexcept
    	{
    		return 38;
    	}
    
    	static constexpr const char *order_qty_name() noexcept
    	{
    		return "OrderQty";
    	}
    
    	constexpr const QtyEncoding &order_qty() const noexcept
    	{
    		return order_qty_;
    	}
    
    	constexpr QtyEncoding &order_qty() noexcept
    	{
    		return order_qty_;
    	}
    	constexpr auto &set_order_qty(QtyEncoding &value) noexcept
    	{
    		order_qty_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	OrdTypeEnum::Value ord_type_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t ord_type_size() noexcept
    	{
    		return sizeof(OrdTypeEnum);
    	}
    
    	static constexpr std::size_t ord_type_offset() noexcept
    	{ 
    		return order_qty_offset() + order_qty_size(); 
    	}
    
    	static constexpr std::size_t ord_type_id() noexcept
    	{ 
    		return 40; 
    	}
    
    	static constexpr const char* ord_type_name() noexcept
    	{ 
    		return "OrdType"; 
    	}
    
    	static constexpr OrdTypeEnum::Value ord_type_null_value() noexcept
    	{
    		return OrdTypeEnum::Value::nullValue;
    	}
    
    	constexpr OrdTypeEnum::Value ord_type() const noexcept
    	{ 
    		return ord_type_;
    	}
    	
    	constexpr auto& set_ord_type(OrdTypeEnum::Value value) noexcept
    	{
    		ord_type_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	OptionalDecimalEncoding price_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t price_size() noexcept
    	{
    		return sizeof(OptionalDecimalEncoding);
    	}
    
    	static constexpr std::size_t price_offset() noexcept
    	{
    		return ord_type_offset() + ord_type_size();
    	}
    
    	static constexpr std::size_t price_id() noexcept
    	{
    		return 44;
    	}
    
    	static constexpr const char *price_name() noexcept
    	{
    		return "Price";
    	}
    
    	constexpr const OptionalDecimalEncoding &price() const noexcept
    	{
    		return price_;
    	}
    
    	constexpr OptionalDecimalEncoding &price() noexcept
    	{
    		return price_;
    	}
    	constexpr auto &set_price(OptionalDecimalEncoding &value) noexcept
    	{
    		price_ = value;
    		return *this;
    	}
    
    
    private:
    	#pragma pack(push, 1)
    	OptionalDecimalEncoding stop_px_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t stop_px_size() noexcept
    	{
    		return sizeof(OptionalDecimalEncoding);
    	}
    
    	static constexpr std::size_t stop_px_offset() noexcept
    	{
    		return price_offset() + price_size();
    	}
    
    	static constexpr std::size_t stop_px_id() noexcept
    	{
    		return 99;
    	}
    
    	static constexpr const char *stop_px_name() noexcept
    	{
    		return "StopPx";
    	}
    
    	constexpr const OptionalDecimalEncoding &stop_px() const noexcept
    	{
    		return stop_px_;
    	}
    
    	constexpr OptionalDecimalEncoding &stop_px() noexcept
    	{
    		return stop_px_;
    	}
    	constexpr auto &set_stop_px(OptionalDecimalEncoding &value) noexcept
    	{
    		stop_px_ = value;
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
    
    class PartiesGrp
    {
    	friend NewOrderSingle;
        
        class Entry
        {
            
            private:
            	#pragma pack(push, 1)
            	char party_id_[8]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t party_id_size() noexcept
            	{
            		return 8;
            	}
            
            	static constexpr std::size_t party_id_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t party_id_id() noexcept
            	{
            		return 448;
            	}
            
            	static constexpr const char *party_id_name() noexcept
            	{
            		return "PartyID";
            	}
            
            	constexpr char *party_id() noexcept
            	{
            		return party_id_;
            	}
            
            	constexpr const char *party_id() const noexcept
            	{
            		return party_id_;
            	}
            
            	constexpr std::string_view party_id_view() noexcept
            	{
            		return std::string_view(party_id_, 8);
            	}
            
            	constexpr const std::string_view party_id_view() const noexcept
            	{
            		return std::string_view(party_id_, 8);
            	}
            
            	const std::string party_id_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 8 && *(party_id_ + length) != '\0'; ++length);
            		return std::string(party_id_, length);
            	}
            
            	constexpr auto &set_party_id(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(party_id_, value, party_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_party_id(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(party_id_size(), value.size());
            		std::memcpy(party_id_, value.data(), party_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	#pragma pack(push, 1)
            	PartyIDSourceEnum::Value party_id_source_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t party_id_source_size() noexcept
            	{
            		return sizeof(PartyIDSourceEnum);
            	}
            
            	static constexpr std::size_t party_id_source_offset() noexcept
            	{ 
            		return party_id_offset() + party_id_size(); 
            	}
            
            	static constexpr std::size_t party_id_source_id() noexcept
            	{ 
            		return 447; 
            	}
            
            	static constexpr const char* party_id_source_name() noexcept
            	{ 
            		return "PartyIDSource"; 
            	}
            
            	static constexpr PartyIDSourceEnum::Value party_id_source_null_value() noexcept
            	{
            		return PartyIDSourceEnum::Value::nullValue;
            	}
            
            	constexpr PartyIDSourceEnum::Value party_id_source() const noexcept
            	{ 
            		return party_id_source_;
            	}
            	
            	constexpr auto& set_party_id_source(PartyIDSourceEnum::Value value) noexcept
            	{
            		party_id_source_ = value;
            		return *this;
            	}
            
            
            private:
            	#pragma pack(push, 1)
            	PartyRoleEnum::Value party_role_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t party_role_size() noexcept
            	{
            		return sizeof(PartyRoleEnum);
            	}
            
            	static constexpr std::size_t party_role_offset() noexcept
            	{ 
            		return party_id_source_offset() + party_id_source_size(); 
            	}
            
            	static constexpr std::size_t party_role_id() noexcept
            	{ 
            		return 452; 
            	}
            
            	static constexpr const char* party_role_name() noexcept
            	{ 
            		return "PartyRole"; 
            	}
            
            	static constexpr PartyRoleEnum::Value party_role_null_value() noexcept
            	{
            		return PartyRoleEnum::Value::nullValue;
            	}
            
            	constexpr PartyRoleEnum::Value party_role() const noexcept
            	{ 
            		return party_role_;
            	}
            	
            	constexpr auto& set_party_role(PartyRoleEnum::Value value) noexcept
            	{
            		party_role_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	GroupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	PartiesGrp() = default;
    	PartiesGrp(std::uint16_t count)
    		:header_(sizeof(PartiesGrp::Entry), count) {}
    
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
    	PartiesGrp parties_grp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t parties_grp_size() noexcept
    	{
    		return sizeof(PartiesGrp::Entry);
    	}
    
    	static constexpr std::size_t parties_grp_id() noexcept
    	{ 
    		return 583; 
    	}
    	
    	static constexpr const char* parties_grp_name() noexcept
    	{ 
    		return "PartiesGrp"; 
    	}
    
    	std::size_t parties_grp_offset() const noexcept
    	{
    		return 0;
    	}
    
    	std::size_t parties_grp_data_length() const noexcept
    	{
    		auto& group = parties_grp();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const PartiesGrp& parties_grp() const noexcept
    	{ 
    		const auto* buf = buffer() + parties_grp_offset();
    		return *reinterpret_cast<const PartiesGrp*>(buf);
    	}
    	
    	PartiesGrp& parties_grp() noexcept
    	{
    		auto* buf = buffer() + parties_grp_offset();
    		return *reinterpret_cast<PartiesGrp*>(buf);
    	}
    
    	PartiesGrp& AppendPartiesGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + parties_grp_offset();
    		auto& group = *reinterpret_cast<PartiesGrp*>(buf);
    		group.header_.set_block_length(sizeof(PartiesGrp::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    class AllocsGrp
    {
    	friend NewOrderSingle;
        
        class Entry
        {
            
            private:
            	#pragma pack(push, 1)
            	char alloc_account_[16]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t alloc_account_size() noexcept
            	{
            		return 16;
            	}
            
            	static constexpr std::size_t alloc_account_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t alloc_account_id() noexcept
            	{
            		return 79;
            	}
            
            	static constexpr const char *alloc_account_name() noexcept
            	{
            		return "AllocAccount";
            	}
            
            	constexpr char *alloc_account() noexcept
            	{
            		return alloc_account_;
            	}
            
            	constexpr const char *alloc_account() const noexcept
            	{
            		return alloc_account_;
            	}
            
            	constexpr std::string_view alloc_account_view() noexcept
            	{
            		return std::string_view(alloc_account_, 16);
            	}
            
            	constexpr const std::string_view alloc_account_view() const noexcept
            	{
            		return std::string_view(alloc_account_, 16);
            	}
            
            	const std::string alloc_account_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 16 && *(alloc_account_ + length) != '\0'; ++length);
            		return std::string(alloc_account_, length);
            	}
            
            	constexpr auto &set_alloc_account(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(alloc_account_, value, alloc_account_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_alloc_account(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(alloc_account_size(), value.size());
            		std::memcpy(alloc_account_, value.data(), alloc_account_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            private:
            	#pragma pack(push, 1)
            	QtyEncoding alloc_shares_{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t alloc_shares_size() noexcept
            	{
            		return sizeof(QtyEncoding);
            	}
            
            	static constexpr std::size_t alloc_shares_offset() noexcept
            	{
            		return alloc_account_offset() + alloc_account_size();
            	}
            
            	static constexpr std::size_t alloc_shares_id() noexcept
            	{
            		return 80;
            	}
            
            	static constexpr const char *alloc_shares_name() noexcept
            	{
            		return "AllocShares";
            	}
            
            	constexpr const QtyEncoding &alloc_shares() const noexcept
            	{
            		return alloc_shares_;
            	}
            
            	constexpr QtyEncoding &alloc_shares() noexcept
            	{
            		return alloc_shares_;
            	}
            	constexpr auto &set_alloc_shares(QtyEncoding &value) noexcept
            	{
            		alloc_shares_ = value;
            		return *this;
            	}
            
    };
    
    private:
    #pragma pack(push, 1)
    	GroupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	AllocsGrp() = default;
    	AllocsGrp(std::uint16_t count)
    		:header_(sizeof(AllocsGrp::Entry), count) {}
    
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
    	AllocsGrp allocs_grp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t allocs_grp_size() noexcept
    	{
    		return sizeof(AllocsGrp::Entry);
    	}
    
    	static constexpr std::size_t allocs_grp_id() noexcept
    	{ 
    		return 78; 
    	}
    	
    	static constexpr const char* allocs_grp_name() noexcept
    	{ 
    		return "AllocsGrp"; 
    	}
    
    	std::size_t allocs_grp_offset() const noexcept
    	{
    		return parties_grp_offset() + sizeof(PartiesGrp::header_) + parties_grp_data_length();
    	}
    
    	std::size_t allocs_grp_data_length() const noexcept
    	{
    		auto& group = allocs_grp();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const AllocsGrp& allocs_grp() const noexcept
    	{ 
    		const auto* buf = buffer() + allocs_grp_offset();
    		return *reinterpret_cast<const AllocsGrp*>(buf);
    	}
    	
    	AllocsGrp& allocs_grp() noexcept
    	{
    		auto* buf = buffer() + allocs_grp_offset();
    		return *reinterpret_cast<AllocsGrp*>(buf);
    	}
    
    	AllocsGrp& AppendAllocsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + allocs_grp_offset();
    		auto& group = *reinterpret_cast<AllocsGrp*>(buf);
    		group.header_.set_block_length(sizeof(AllocsGrp::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    class TradingSessionsGrp
    {
    	friend NewOrderSingle;
        
        class Entry
        {
            
            private:
            	#pragma pack(push, 1)
            	char trading_session_id_[8]{};
            	#pragma pack(pop)
            
            public:
            	static constexpr std::size_t trading_session_id_size() noexcept
            	{
            		return 8;
            	}
            
            	static constexpr std::size_t trading_session_id_offset() noexcept
            	{
            		return 0;
            	}
            
            	static constexpr std::size_t trading_session_id_id() noexcept
            	{
            		return 336;
            	}
            
            	static constexpr const char *trading_session_id_name() noexcept
            	{
            		return "TradingSessionID";
            	}
            
            	constexpr char *trading_session_id() noexcept
            	{
            		return trading_session_id_;
            	}
            
            	constexpr const char *trading_session_id() const noexcept
            	{
            		return trading_session_id_;
            	}
            
            	constexpr std::string_view trading_session_id_view() noexcept
            	{
            		return std::string_view(trading_session_id_, 8);
            	}
            
            	constexpr const std::string_view trading_session_id_view() const noexcept
            	{
            		return std::string_view(trading_session_id_, 8);
            	}
            
            	const std::string trading_session_id_string() const noexcept
            	{
            		auto length = 0ULL;
            		for (; length < 8 && *(trading_session_id_ + length) != '\0'; ++length);
            		return std::string(trading_session_id_, length);
            	}
            
            	constexpr auto &set_trading_session_id(const char *value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		std::memcpy(trading_session_id_, value, trading_session_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
            
            	auto &set_trading_session_id(std::string_view value) noexcept
            	{
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic push
            	#pragma GCC diagnostic ignored "-Wstringop-overflow"
            	#endif
            		// auto size = std::min(trading_session_id_size(), value.size());
            		std::memcpy(trading_session_id_, value.data(), trading_session_id_size());
            		return *this;
            	#if defined(__GNUG__)
            	#pragma GCC diagnostic pop
            	#endif
            	}
    };
    
    private:
    #pragma pack(push, 1)
    	GroupSizeEncoding header_{};
    #pragma pack(pop)
    
    public:
    	TradingSessionsGrp() = default;
    	TradingSessionsGrp(std::uint16_t count)
    		:header_(sizeof(TradingSessionsGrp::Entry), count) {}
    
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
    	TradingSessionsGrp trading_sessions_grp_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t trading_sessions_grp_size() noexcept
    	{
    		return sizeof(TradingSessionsGrp::Entry);
    	}
    
    	static constexpr std::size_t trading_sessions_grp_id() noexcept
    	{ 
    		return 386; 
    	}
    	
    	static constexpr const char* trading_sessions_grp_name() noexcept
    	{ 
    		return "TradingSessionsGrp"; 
    	}
    
    	std::size_t trading_sessions_grp_offset() const noexcept
    	{
    		return allocs_grp_offset() + sizeof(AllocsGrp::header_) + allocs_grp_data_length();
    	}
    
    	std::size_t trading_sessions_grp_data_length() const noexcept
    	{
    		auto& group = trading_sessions_grp();
    		return group.header_.block_length() * group.header_.num_in_group();
    	}
    	
    	const TradingSessionsGrp& trading_sessions_grp() const noexcept
    	{ 
    		const auto* buf = buffer() + trading_sessions_grp_offset();
    		return *reinterpret_cast<const TradingSessionsGrp*>(buf);
    	}
    	
    	TradingSessionsGrp& trading_sessions_grp() noexcept
    	{
    		auto* buf = buffer() + trading_sessions_grp_offset();
    		return *reinterpret_cast<TradingSessionsGrp*>(buf);
    	}
    
    	TradingSessionsGrp& AppendTradingSessionsGrp(std::uint16_t count) noexcept
    	{
    		auto* buf = buffer() + trading_sessions_grp_offset();
    		auto& group = *reinterpret_cast<TradingSessionsGrp*>(buf);
    		group.header_.set_block_length(sizeof(TradingSessionsGrp::Entry));
    		group.header_.set_num_in_group(count);
    		return group;	
    	}
    
    public:
    
    class Text
    {
    	friend NewOrderSingle;
    
    private:
    #pragma pack(push, 1)
    	Data header_{};
    #pragma pack(pop)
    
    public:
    	Text() = default;
    
    	std::basic_string_view<char> get_str() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(Data);
    		return {reinterpret_cast<char*>(buffer), this->header_.length()};
    	}
    
    	const std::basic_string_view<char> get_str() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(Data);
    		return {reinterpret_cast<const char*>(buffer), this->header_.length()};
    	}
    
    	char* get() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(Data);
    		return reinterpret_cast<char*>(buffer);
    	}
    
    	const char* get() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(Data);
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
    		return trading_sessions_grp_offset() + sizeof(TradingSessionsGrp::header_) + trading_sessions_grp_data_length();
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
    	
    public:
    
    class ClearingFirm
    {
    	friend NewOrderSingle;
    
    private:
    #pragma pack(push, 1)
    	Data header_{};
    #pragma pack(pop)
    
    public:
    	ClearingFirm() = default;
    
    	std::basic_string_view<char> get_str() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(Data);
    		return {reinterpret_cast<char*>(buffer), this->header_.length()};
    	}
    
    	const std::basic_string_view<char> get_str() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(Data);
    		return {reinterpret_cast<const char*>(buffer), this->header_.length()};
    	}
    
    	char* get() noexcept
    	{
    		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(Data);
    		return reinterpret_cast<char*>(buffer);
    	}
    
    	const char* get() const noexcept
    	{
    		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(Data);
    		return reinterpret_cast<const char*>(buffer);
    	}
    
    	const auto length() const noexcept
    	{
    		return header_.length();
    	}
    
    };
    
    private:
    	#pragma pack(push, 1)
    	ClearingFirm clearing_firm_{};
    	#pragma pack(pop)
    
    public:
    	static constexpr std::size_t clearing_firm_size() noexcept
    	{
    		return 0;
    	}
    
    	static constexpr std::size_t clearing_firm_id() noexcept
    	{ 
    		return 439; 
    	}
    	
    	static constexpr const char* clearing_firm_name() noexcept
    	{ 
    		return "ClearingFirm"; 
    	}
    
    	std::size_t clearing_firm_offset() const noexcept
    	{
    		return text_offset() + sizeof(Text::header_) + text_data_length();
    	}
    
    	std::size_t clearing_firm_data_length() const noexcept
    	{
    		auto& data = clearing_firm();
    		return data.header_.length();
    	}
    	
    	const ClearingFirm& clearing_firm() const noexcept
    	{ 
    		const auto* buf = buffer() + clearing_firm_offset();
    		return *reinterpret_cast<const ClearingFirm*>(buf);
    	}
    	
    	ClearingFirm& clearing_firm() noexcept
    	{
    		auto* buf = buffer() + clearing_firm_offset();
    		return *reinterpret_cast<ClearingFirm*>(buf);
    	}
    
    	ClearingFirm& AppendClearingFirm(const char* value, std::uint16_t length) noexcept
    	{
    		auto* buf = buffer() + clearing_firm_offset();
    		auto& data = *reinterpret_cast<ClearingFirm*>(buf);
    		data.header_.set_length(length);
    		std::memcpy(data.get(), value, length);
    		return data;
    	}
    
    	ClearingFirm& AppendClearingFirm(std::basic_string_view<char> value) noexcept
    	{
    		auto* buf = buffer() + clearing_firm_offset();
    		auto& data = *reinterpret_cast<ClearingFirm*>(buf);
    		data.header_.set_length(value.size());
    		std::memcpy(data.get(), value.data(), value.size());
    		return data;	
    	}
    	
};

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::NewOrderSingle::PartiesGrp &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.party_id_name() << ": " << g.party_id() << " ";
		os << g.party_id_source_name() << ": " << g.party_id_source() << " ";
		os << g.party_role_name() << ": " << g.party_role() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::NewOrderSingle::AllocsGrp &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.alloc_account_name() << ": " << g.alloc_account() << " ";
		os << g.alloc_shares_name() << ": " << g.alloc_shares() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::NewOrderSingle::TradingSessionsGrp &group)
{
	for (auto i = 0; i < group.num_in_group(); i++)
	{
		auto &g = group.get(i);
		os << g.trading_session_id_name() << ": " << g.trading_session_id() << " ";
	}
	return os;
}

template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const fastsbe::NewOrderSingle &msg)
{
	os << msg.cl_ord_id_name() << ": " << msg.cl_ord_id() << " ";
	os << msg.account_name() << ": " << msg.account() << " ";
	os << msg.symbol_name() << ": " << msg.symbol() << " ";
	os << msg.side_name() << ": " << msg.side() << " ";
	os << msg.transact_time_name() << ": " << msg.transact_time() << " ";
	os << msg.order_qty_name() << ": " << msg.order_qty() << " ";
	os << msg.ord_type_name() << ": " << msg.ord_type() << " ";
	os << msg.price_name() << ": " << msg.price() << " ";
	os << msg.stop_px_name() << ": " << msg.stop_px() << " ";
	os << msg.parties_grp_name() << ": " << msg.parties_grp() << " ";
	os << msg.allocs_grp_name() << ": " << msg.allocs_grp() << " ";
	os << msg.trading_sessions_grp_name() << ": " << msg.trading_sessions_grp() << " ";
	os << msg.text_name() << ": " << msg.text().get_str() << " ";
	os << msg.clearing_firm_name() << ": " << msg.clearing_firm().get_str() << " ";
	return os;
}
}
