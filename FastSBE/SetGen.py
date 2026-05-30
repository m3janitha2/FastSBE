import logging

from FileGen import Indentation
from FileGen import ClassGen


class SetClassGen:
	# A <set> is a bitmap: an unsigned integer where each <choice> is a bit.
	# It is generated as a class scoping the choices as bit masks, mirroring
	# how an <enum> is generated as a class scoping enum class Value:
	#
	#   class MatchEventIndicator {
	#    public:
	#     using value_type = std::uint8_t;
	#     enum class Choice : value_type { LastTradeMsg = 1u << 0, ... };
	#   };
	#   constexpr MatchEventIndicator::Choice operator|(...);   // combine: A | B
	#
	# The raw value lives in the owning message/group field, so this type holds
	# no state - it only scopes the choices and the combine operator.

	class ChoiceDefinitionGen:
		choice_begin_ct = 'public:\nusing value_type = {encoding_type};\nenum class Choice : value_type\n{{\n'
		choice_end_ct = '};\n'
		choice_value_ct = '{name} = static_cast<value_type>(1u << {index}),\n'

		def gen_begin(self):
			self.indentation.increment()
			begin = self.choice_begin_ct.format(encoding_type=self.encoding_type)
			self.handler.content += self.indentation.get_indented_str(begin)

		def gen_values(self):
			body = ""
			for (name, index) in self.choices:
				body += self.choice_value_ct.format(name=name, index=index)
			self.indentation.increment()
			self.handler.content += self.indentation.get_indented_str(body)
			self.indentation.decrement()

		def gen_end(self):
			self.handler.content += self.indentation.get_indented_str(self.choice_end_ct)
			self.indentation.decrement()

		def __init__(self, handler, indentation, encoding_type, choices):
			self.handler = handler
			self.indentation = indentation
			self.encoding_type = encoding_type
			self.choices = choices
			self.gen_begin()
			self.gen_values()
			self.gen_end()

	def gen_operator_or(self):
		op = (
			"\nconstexpr S_SET_NAME::Choice operator|("
			"S_SET_NAME::Choice a, S_SET_NAME::Choice b) noexcept\n"
			"{\n"
			"\treturn static_cast<S_SET_NAME::Choice>(\n"
			"\t\tstatic_cast<S_SET_NAME::value_type>(a) | "
			"static_cast<S_SET_NAME::value_type>(b));\n"
			"}\n").replace('S_SET_NAME', self.set_name)
		self.handler.ostream += op

	def __init__(self, handler, set_name, encoding_type, choices, namespace):
		self.handler = handler
		self.set_name = set_name
		self.encoding_type = encoding_type
		self.choices = choices

		self.indentation = Indentation(0)
		class_gen = ClassGen(handler=self.handler, indentation=self.indentation,
			class_name=self.set_name)
		self.ChoiceDefinitionGen(handler=self.handler, indentation=self.indentation,
			encoding_type=encoding_type, choices=choices)
		self.gen_operator_or()

	def __del__(self):
		logging.debug('delete SetClassGen')
