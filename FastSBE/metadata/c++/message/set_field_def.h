
private:
	S_FIELD_TYPE::value_type S_FIELD_NAME_{};

public:
	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return sizeof(S_FIELD_TYPE::value_type);
	}

	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{
		return S_FIELD_OFFSET;
	}

	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_id() noexcept
	{
		return S_FIELD_ID;
	}

	[[nodiscard]] static constexpr const char* S_FIELD_NAME_name() noexcept
	{
		return "S_FIELD_SCHEMA";
	}

	// raw whole-field access (low-latency path)
	[[nodiscard]] constexpr S_FIELD_TYPE::value_type S_FIELD_NAME() const noexcept
	{
		return S_FIELD_NAME_;
	}

	constexpr auto& set_S_FIELD_NAME(S_FIELD_TYPE::value_type value) noexcept
	{
		S_FIELD_NAME_ = value;
		return *this;
	}

	// per-choice access; choices combine with operator| (A | B | C)
	[[nodiscard]] constexpr bool S_FIELD_NAME(S_FIELD_TYPE::Choice choice) const noexcept
	{
		return (S_FIELD_NAME_ & static_cast<S_FIELD_TYPE::value_type>(choice))
			== static_cast<S_FIELD_TYPE::value_type>(choice);
	}

	constexpr auto& set_S_FIELD_NAME(S_FIELD_TYPE::Choice choice) noexcept
	{
		S_FIELD_NAME_ = static_cast<S_FIELD_TYPE::value_type>(
			S_FIELD_NAME_ | static_cast<S_FIELD_TYPE::value_type>(choice));
		return *this;
	}

	constexpr auto& clear_S_FIELD_NAME(S_FIELD_TYPE::Choice choice) noexcept
	{
		S_FIELD_NAME_ = static_cast<S_FIELD_TYPE::value_type>(
			S_FIELD_NAME_ & ~static_cast<S_FIELD_TYPE::value_type>(choice));
		return *this;
	}
