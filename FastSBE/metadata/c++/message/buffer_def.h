
private:
	char buffer_[N]{};

	const char *buffer() const
	{
		return buffer_;
	}

	char *buffer()
	{
		return buffer_;
	}

