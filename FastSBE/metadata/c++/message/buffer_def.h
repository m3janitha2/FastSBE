
private:
	char buffer_[S_FIELD_SIZE]{};

	const char *buffer() const
	{
		return buffer_;
	}

	char *buffer()
	{
		return buffer_;
	}

