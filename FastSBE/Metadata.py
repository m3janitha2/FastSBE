
class Metadata:
	primitive_types = {
		"int8",	
		"uint8",	
		"int16",
		"uint16",
		"int32",	
		"uint32",
		"int64",	
		"uint64",
		"char",
		}

	c_field_types = {
		"int8"	: "std::int8_t",
		"uint8"	: "std::uint8_t",
		"int16"	: "std::int16_t",
		"uint16": "std::uint16_t",
		"int32"	: "std::int32_t",
		"uint32": "std::uint32_t",
		"int64"	: "std::int64_t",
		"uint64": "std::uint64_t",
		"char"	: "char"
		}

	defult_minimum = {
		"int8"	: -127,
		"uint8"	: 0,
		"int16"	: -32767,
		"uint16": 0,
		"int32"	: -2147483647,
		"uint32": 0,
		"int64"	: -9223372036854775807,
		"uint64": 0,
		"char"	: 32,
	}

	defult_maximum = {
		"int8"	: 127,
		"uint8"	: 254,
		"int16"	: 32767,
		"uint16": 65534,
		"int32"	: 2147483647,
		"uint32": 4294967294,
		"int64"	: 9223372036854775807,
		"uint64": 18446744073709551614,
		"char"	: 255,
	}

	defult_null = {
		"int8"	: -128,
		"uint8"	: 255,
		"int16"	: -32768,
		"uint16": 65535,
		"int32"	: -2147483648,
		"uint32": 4294967295,
		"int64"	: -9223372036854775808,
		"uint64": 18446744073709551615,
		"char"	: 0,
	}

	default_group_size_encoding_names = [
		"blockLength",
		"numInGroup",
		"numGroups",
		"numVarDataFields"
	]

	default_variable_data_encoding_names = [
		"length",
		"varData",
	]

	@staticmethod
	def to_cpp_int_literal(value, primitive_type):
		# Render an SBE limit/null value as a C++ literal.
		#
		# A type's extreme sentinels (min, max, and one step inside) are emitted
		# as the matching <cstdint> macro (INT8_MIN, UINT64_MAX, ...). Generated
		# headers already include <cstdint>, so this needs no extra include, and
		# the macro is:
		#   - self-documenting,
		#   - warning-free (a bare 64-bit extreme is otherwise flagged "integer
		#     constant is so large that it is unsigned", and INT*_MIN has no
		#     negative-literal form in C++),
		#   - zero runtime cost (a constant expression folded by the compiler).
		# Any other value falls back to a correctly-suffixed literal.
		spec = {
			"int8"  : (8,  True),  "uint8"  : (8,  False),
			"int16" : (16, True),  "uint16" : (16, False),
			"int32" : (32, True),  "uint32" : (32, False),
			"int64" : (64, True),  "uint64" : (64, False),
		}
		if primitive_type not in spec:
			return str(value)
		v = int(value)
		(bits, signed) = spec[primitive_type]
		base = ("" if signed else "U") + "INT" + str(bits)
		if signed:
			type_min = -(1 << (bits - 1))
			type_max = (1 << (bits - 1)) - 1
			if v == type_min:     return base + "_MIN"
			if v == type_min + 1: return "(" + base + "_MIN + 1)"
			if v == type_max:     return base + "_MAX"
			if v == type_max - 1: return "(" + base + "_MAX - 1)"
			suffix = "LL" if bits == 64 else ""
		else:
			type_max = (1 << bits) - 1
			if v == 0:            return "0"
			if v == type_max:     return base + "_MAX"
			if v == type_max - 1: return "(" + base + "_MAX - 1)"
			suffix = "ULL" if bits == 64 else "U"
		return str(v) + suffix
