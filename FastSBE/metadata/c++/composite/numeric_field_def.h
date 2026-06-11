
private:
	S_FIELD_TYPE S_FIELD_NAME_{};

public:
	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return sizeof(S_FIELD_TYPE);
	}

	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}
	
	[[nodiscard]] static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_SCHEMA"; 
	}
	
	[[nodiscard]] static constexpr S_FIELD_TYPE S_FIELD_NAME_min_value() noexcept
	{ 
		return static_cast<S_FIELD_TYPE>(S_FIELD_MIN);
	}
	
	[[nodiscard]] static constexpr S_FIELD_TYPE S_FIELD_NAME_max_value() noexcept
	{
		return static_cast<S_FIELD_TYPE>(S_FIELD_MAX);
	}
	
	[[nodiscard]] static constexpr S_FIELD_TYPE S_FIELD_NAME_null_value() noexcept
	{
		return static_cast<S_FIELD_TYPE>(S_FIELD_NULL);
	}

	[[nodiscard]] constexpr S_FIELD_TYPE S_FIELD_NAME() const noexcept
	{ 
		return S_FIELD_NAME_;
	}
	
	constexpr S_MESSAGE_NAME& set_S_FIELD_NAME(S_FIELD_TYPE value) noexcept
	{
		S_FIELD_NAME_ = value;
		return *this;
	}

