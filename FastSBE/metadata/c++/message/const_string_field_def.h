
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

	[[nodiscard]] static constexpr const char *S_FIELD_NAME_name() noexcept
	{
		return "S_FIELD_SCHEMA";
	}

	[[nodiscard]] constexpr const char *S_FIELD_NAME() const noexcept
	{
		return "S_CONST_FIELD_VALUE";
	}

	[[nodiscard]] constexpr const std::string_view S_FIELD_NAME_view() const noexcept
	{
		return std::string_view("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}

	[[nodiscard]] constexpr const std::string S_FIELD_NAME_string() const noexcept
	{
		return std::string("S_CONST_FIELD_VALUE", S_FIELD_SIZE);
	}
