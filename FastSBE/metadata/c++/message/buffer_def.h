
private:
	char buffer_[N]{};

	constexpr const char *buffer() const noexcept
	{
		return buffer_;
	}

	constexpr char *buffer() noexcept
	{
		return buffer_;
	}

