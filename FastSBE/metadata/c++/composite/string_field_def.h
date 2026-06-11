
private:
	char S_FIELD_NAME_[S_FIELD_SIZE]{};

public:
	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return S_FIELD_SIZE;
	}

	[[nodiscard]] static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}
	
	[[nodiscard]] static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_SCHEMA"; 
	}

	// Not NUL-terminated when the value fills the field; use _view()/_string()
	// for a bounded read.
	[[nodiscard]] constexpr char* S_FIELD_NAME() noexcept
	{
		return S_FIELD_NAME_;
	}

	[[nodiscard]] constexpr const char* S_FIELD_NAME() const noexcept
	{
		return S_FIELD_NAME_;
	}

	[[nodiscard]] constexpr std::string_view S_FIELD_NAME_view() noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, S_FIELD_SIZE);
	}

	[[nodiscard]] constexpr const std::string_view S_FIELD_NAME_view() const noexcept
	{ 
		return std::string_view(S_FIELD_NAME_, S_FIELD_SIZE);
	}

	[[nodiscard]] constexpr const std::string S_FIELD_NAME_string() const noexcept
	{
		auto length = 0ULL;
		for (; length < S_FIELD_SIZE && *(S_FIELD_NAME_ + length) != '\0'; ++length);
		return std::string(S_FIELD_NAME_, length);
	}	

	auto& set_S_FIELD_NAME(const char* value) noexcept
	{
	#if defined(__GNUC__) && !defined(__clang__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wstringop-overflow"
	#pragma GCC diagnostic ignored "-Wstringop-overread"
	#endif		
		//auto length = strlen(value);
		std::memcpy(S_FIELD_NAME_, value, S_FIELD_NAME_size());
		return *this;
	#if defined(__GNUC__) && !defined(__clang__)
	#pragma GCC diagnostic pop
	#endif			
	}

	// Safe: copy size bytes (capped at the field width) and NUL-pad the remainder.
	auto& set_S_FIELD_NAME(const char* value, std::size_t size) noexcept
	{
		const auto length = size < S_FIELD_NAME_size() ? size : S_FIELD_NAME_size();
		std::memcpy(S_FIELD_NAME_, value, length);
		std::memset(S_FIELD_NAME_ + length, 0, S_FIELD_NAME_size() - length);
		return *this;
	}

	auto& set_S_FIELD_NAME(std::string_view value) noexcept
	{
	#if defined(__GNUC__) && !defined(__clang__)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wstringop-overflow"
	#pragma GCC diagnostic ignored "-Wstringop-overread"
	#endif		
		//constexpr auto size = std::min(S_FIELD_NAME_size(), value.size());
		//auto size = std::min(S_FIELD_NAME_size(), value.size());
		std::memcpy(S_FIELD_NAME_, value.data(), S_FIELD_NAME_size());
		return *this;
	#if defined(__GNUC__) && !defined(__clang__)
	#pragma GCC diagnostic pop
	#endif			
	}

