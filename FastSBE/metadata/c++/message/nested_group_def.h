
private:
#pragma pack(push, 1)
	S_DIAMENTION_TYPE header_{};
#pragma pack(pop)

public:
	S_GROUP_NAME() = default;
	S_GROUP_NAME(S_NUM_IN_GROUP_TYPE count)
		:header_(sizeof(S_GROUP_NAME::Entry), count) {}

	Entry& get(std::size_t group_id) noexcept
	{
		auto* buffer = reinterpret_cast<char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE)
			+ (this->header_.S_BLOCK_LENGTH_NAME() * group_id);
		return *reinterpret_cast<Entry*>(buffer);
	}

	const Entry& get(std::size_t group_id) const noexcept
	{
		auto* buffer = reinterpret_cast<const char*>(&this->header_) + sizeof(S_DIAMENTION_TYPE)
			+ (this->header_.S_BLOCK_LENGTH_NAME() * group_id);
		return *reinterpret_cast<const Entry*>(buffer);
	}

	const auto S_BLOCK_LENGTH_NAME() const noexcept
	{
		return header_.S_BLOCK_LENGTH_NAME();
	}

	const auto S_NUM_IN_GROUP_NAME() const noexcept
	{
		return header_.S_NUM_IN_GROUP_NAME();
	}

