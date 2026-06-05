
// A complete SBE message: the message header paired with a message body. The
// header is initialized from the body's compile-time descriptor, and the pair
// is packed so its layout matches the wire (header bytes followed by the body).
#pragma pack(push, 1)
template <typename Body>
class SbeMessage
{
private:
	MessageHeader header_;
	Body body_;

public:
	constexpr SbeMessage() noexcept
		: header_{}
	{
		// Set the identity fields by name; any extra header fields (e.g. the SBE
		// 2.0 numGroups / numVarDataFields) keep their zero default.
		header_.set_block_length(Body::block_length())
			.set_template_id(Body::template_id())
			.set_schema_id(Body::schema())
			.set_version(Body::version());
	}

	constexpr MessageHeader& header() noexcept
	{
		return header_;
	}

	constexpr const MessageHeader& header() const noexcept
	{
		return header_;
	}

	constexpr Body& body() noexcept
	{
		return body_;
	}

	constexpr const Body& body() const noexcept
	{
		return body_;
	}
};
#pragma pack(pop)

template <typename Body, class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& os, const SbeMessage<Body>& msg)
{
	os << "{";
	os << "\"header\": " << msg.header() << ", ";
	os << "\"body\": " << msg.body();
	os << "}";
	return os;
}
