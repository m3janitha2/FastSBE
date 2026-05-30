
public:
	static constexpr std::size_t S_FIELD_NAME_size() noexcept
	{
		return 0;
	}

	static constexpr std::size_t S_FIELD_NAME_offset() noexcept
	{ 
		return S_FIELD_OFFSET; 
	}
	
	static constexpr const char* S_FIELD_NAME_name() noexcept
	{ 
		return "S_FIELD_SCHEMA"; 
	}

	constexpr S_FIELD_TYPE S_FIELD_NAME() noexcept
	{ 
		return S_CONST_FIELD_VALUE;
	}

	constexpr S_FIELD_TYPE S_FIELD_NAME() const noexcept
	{ 
		return S_CONST_FIELD_VALUE;
	}

