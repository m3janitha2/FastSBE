
	template <class CharT, class Traits = std::char_traits<CharT>>
	friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, const S_GROUP_NAME &group)
	{
		os << "[";
		for (auto i = 0; i < group.num_in_group(); i++)
		{
			if (i) { os << ", "; }
			auto &g = group.get(i);
			os << "{";
			bool comma = false;
