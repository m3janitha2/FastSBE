
private:
	S_DIAMENTION_TYPE header_{};

public:
	constexpr S_GROUP_NAME() = default;
	S_GROUP_NAME(S_NUM_IN_GROUP_TYPE count, S_NUM_GROUPS_TYPE groups_count, S_NUM_VAR_DATA_FIELDS_TYPE var_data_fields_count) noexcept
		:header_(sizeof(S_GROUP_NAME::Entry), count, groups_count, var_data_fields_count) {}

	[[nodiscard]] Entry& get(std::size_t group_id) noexcept
	{
		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE)
			+ (this->header_.S_BLOCK_LENGTH_NAME() * group_id);
		return *reinterpret_cast<Entry*>(buffer);
	}
	
	[[nodiscard]] const Entry& get(std::size_t group_id) const noexcept
	{
		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE)
			+ (this->header_.S_BLOCK_LENGTH_NAME() * group_id);
		return *reinterpret_cast<const Entry*>(buffer);
	}

	[[nodiscard]] constexpr auto S_BLOCK_LENGTH_NAME() const noexcept
	{
		return header_.S_BLOCK_LENGTH_NAME();
	}

	[[nodiscard]] constexpr auto S_NUM_IN_GROUP_NAME() const noexcept
	{
		return header_.S_NUM_IN_GROUP_NAME();
	}

