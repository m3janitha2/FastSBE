"""Generate C++ accessors for SBE variable-length data fields."""

import logging

from FileGen import Indentation
from FileGen import ClassGen
from FileGen import read_template
from MessageGen import FieldGen

class VariableLengthDataGen:
	"""Emit the class for a variable-length data field (a length + varData pair)."""

	group_qualifier_def_ct = read_template('metadata/c++/message/group_qualifier_def.h')
	group_class_qualifier_def_ct = 'public:'

	def gen_qualifier_def(self, message_name):
			field_def = self.group_qualifier_def_ct\
				.replace('S_MESSAGE_NAME', message_name)
			self.handler.content += self.indentation.get_indented_str(field_def)
			

	def __init__(self, handler, indentation, name, id, message_name, namespace, dimension_type):
		self.handler = handler
		self.indentation = indentation
		self.name = name
		self.id = id
		self.dimension_type = dimension_type

		logging.debug('create VariableLengthDataGen: %s', self.name)
		self.handler.content += self.indentation.get_indented_str(self.group_class_qualifier_def_ct)
		self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = self.name)

		self.gen_qualifier_def(message_name)


	def __del__(self):
		logging.debug('delete GroupGen: %s', self.name)


