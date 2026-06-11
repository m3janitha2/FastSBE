
private:
	char buffer_[N]{};

	[[nodiscard]] constexpr const char *buffer() const noexcept
	{
		return buffer_;
	}

	[[nodiscard]] constexpr char *buffer() noexcept
	{
		return buffer_;
	}

