
private:
	#pragma pack(push, 1)
	S_GROUP_NAME S_GROUP_SNAKE_{};
	#pragma pack(pop)

public:
	static constexpr std::size_t S_GROUP_SNAKE_size() noexcept
	{
		return sizeof(S_GROUP_NAME::Data);
	}

	static constexpr std::size_t S_GROUP_SNAKE_id() noexcept
	{ 
		return S_GROUP_ID; 
	}
	
	static constexpr const char* S_GROUP_SNAKE_name() noexcept
	{ 
		return "S_GROUP_NAME"; 
	}

	std::size_t S_GROUP_SNAKE_offset() const noexcept
	{
		return S_GROUP_OFFSET;
	}

	std::size_t S_GROUP_SNAKE_data_length() const noexcept
	{
		auto& group = S_GROUP_SNAKE();
		return group.header_.block_length() * group.header_.S_NUM_IN_GROUP_NAME();
	}
	
	const S_GROUP_NAME& S_GROUP_SNAKE() const noexcept
	{ 
		const auto* buf = buffer() + S_GROUP_SNAKE_offset();
		return *reinterpret_cast<const S_GROUP_NAME*>(buf);
	}
	
	S_GROUP_NAME& S_GROUP_SNAKE() noexcept
	{
		auto* buf = buffer() + S_GROUP_SNAKE_offset();
		return *reinterpret_cast<S_GROUP_NAME*>(buf);
	}

	S_GROUP_NAME& AppendS_GROUP_NAME(S_NUM_IN_GROUP_TYPE count) noexcept
	{
		auto* buf = buffer() + S_GROUP_SNAKE_offset();
		auto& group = *reinterpret_cast<S_GROUP_NAME*>(buf);
		group.header_.set_S_BLOCK_LENGTH_NAME(sizeof(S_GROUP_NAME::Data));
		group.header_.set_S_NUM_IN_GROUP_NAME(count);
		group.header_.set_S_NUM_GROUPS_NAME(0);	// TODO
		group.header_.set_S_NUM_VAR_DATA_FIELDS_NAME(0);	// TODO
		return group;	
	}

