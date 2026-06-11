
	[[nodiscard]] std::size_t encoded_size() const noexcept
	{
		return block_length() + S_ENCODED_SIZE_EXPR;
	}

