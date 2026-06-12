
public:
	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return 0;
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

	[[nodiscard]] constexpr S_FIELD_TYPE::Value S_FIELD_NAME() const noexcept
	{
		return S_FIELD_TYPE::Value::S_CONST_FIELD_VALUE;
	}
