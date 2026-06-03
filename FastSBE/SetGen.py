"""Generate C++ classes for SBE <set> (bitset) types."""

import logging

from FileGen import Indentation
from FileGen import ClassGen


class SetGen:
	"""Emit a C++ class for an SBE set. A set is a bitmap where each <choice> is
	one bit, generated as a Choice enum of bit masks plus an operator| to
	combine them. The set holds no state - the raw value lives in the owning
	field.
	"""

	class ChoiceDefinitionGen:
		"""Emit the nested Choice enum, one bit-mask value per choice."""

		choice_begin_ct = 'public:\nusing value_type = {encoding_type};\nenum class Choice : value_type\n{{\n'
		choice_end_ct = '};\n'
		choice_value_ct = '{name} = static_cast<value_type>(1u << {index}),\n'

		def gen_begin(self):
			self.indentation.increment()
			begin = self.choice_begin_ct.format(encoding_type=self.encoding_type)
			self.handler.content += self.indentation.indent(begin)

		def gen_values(self):
			body = ""
			for (name, index) in self.choices:
				body += self.choice_value_ct.format(name=name, index=index)
			self.indentation.increment()
			self.handler.content += self.indentation.indent(body)
			self.indentation.decrement()

		def gen_end(self):
			self.handler.content += self.indentation.indent(self.choice_end_ct)
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
		logging.debug('delete SetGen')
