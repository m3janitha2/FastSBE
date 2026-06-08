
template <std::size_t N, class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os, [[maybe_unused]] const S_NAMESPACE::S_MESSAGE_NAME<N> &msg)
{
	os << "{";
