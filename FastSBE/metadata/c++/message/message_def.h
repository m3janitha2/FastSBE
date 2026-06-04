
public:
	static constexpr const char* name() noexcept
	{ 
		return "S_MESSAGE_NAME"; 
	}

	static constexpr S_TEMPLATE_ID_TYPE template_id() noexcept
	{ 
		return S_MESSAGE_ID; 
	}

	static constexpr S_SCHEMA_TYPE schema() noexcept
	{  
		return S_SCHEMA_ID; 
	}

	static constexpr S_VERSION_TYPE version() noexcept
	{
		return S_VERSION_ID;
	}

	static constexpr S_BLOCK_LENGTH_TYPE block_length() noexcept
	{
		return S_BLOCK_LENGTH;
	}

	static constexpr const char* semantic_type() noexcept
	{ 
		return ""; 	
	}

