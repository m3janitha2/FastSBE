
private:
	S_GROUP_NAME S_GROUP_SNAKE_{};

public:
	[[nodiscard]] static constexpr std::size_t S_GROUP_SNAKE_size() noexcept
	{
		return sizeof(typename S_GROUP_NAME::Entry);
	}

	[[nodiscard]] static constexpr std::size_t S_GROUP_SNAKE_id() noexcept
	{ 
		return S_GROUP_ID; 
	}
	
	[[nodiscard]] static constexpr const char* S_GROUP_SNAKE_name() noexcept
	{ 
		return "S_GROUP_NAME"; 
	}

	[[nodiscard]] std::size_t S_GROUP_SNAKE_offset() const noexcept
	{
		return S_GROUP_OFFSET;
	}

	[[nodiscard]] std::size_t S_GROUP_SNAKE_data_length() const noexcept
	{
		auto& group = S_GROUP_SNAKE();
		return group.header_.S_BLOCK_LENGTH_NAME() * group.header_.S_NUM_IN_GROUP_NAME();
	}
	
	[[nodiscard]] const S_GROUP_NAME& S_GROUP_SNAKE() const noexcept
	{ 
		const auto* buf = buffer() + S_GROUP_SNAKE_offset();
		return *reinterpret_cast<const S_GROUP_NAME*>(buf);
	}
	
	[[nodiscard]] S_GROUP_NAME& S_GROUP_SNAKE() noexcept
	{
		auto* buf = buffer() + S_GROUP_SNAKE_offset();
		return *reinterpret_cast<S_GROUP_NAME*>(buf);
	}

	S_GROUP_NAME& AppendS_GROUP_NAME(S_NUM_IN_GROUP_TYPE count) noexcept
	{
		auto* buf = buffer() + S_GROUP_SNAKE_offset();
		auto& group = *reinterpret_cast<S_GROUP_NAME*>(buf);
		group.header_.set_S_BLOCK_LENGTH_NAME(sizeof(typename S_GROUP_NAME::Entry));
		group.header_.set_S_NUM_IN_GROUP_NAME(count);
		return group;	
	}

