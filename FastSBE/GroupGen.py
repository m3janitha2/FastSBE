"""Generate C++ classes for SBE repeating groups."""

import logging

from FileGen import Indentation
from FileGen import ClassGen
from FileGen import read_template
from MessageGen import FieldGen

class GroupGen:
	"""Emit the C++ class for a repeating group: its dimension header and the
	Append accessor that adds entries.
	"""

	group_qualifier_def_ct = read_template('metadata/c++/message/group_qualifier_def.h')
	group_class_qualifier_def_ct = 'public:'

	class GroupEntryGen:
		"""Emit the Entry class - the field layout of one group occurrence."""

		def __init__(self, handler, indentation, namespace):
			self.handler = handler
			self.indentation = indentation
			
			logging.debug('create GroupEntryGen')
			self.indentation.increment()

			self.group_entry_gen = ClassGen(handler = self.handler, indentation = self.indentation\
				, class_name = "Entry")
			self.field_gen = FieldGen(handler = self.handler, indentation = indentation\
				, message_name = "Entry", class_gen = self.group_entry_gen, namespace = namespace)

		def __del__(self):
			self.indentation.decrement()
			logging.debug('delete GroupEntryGen')

	def gen_group_qualifier_def(self, message_name):
			field_def = self.group_qualifier_def_ct\
				.replace('S_MESSAGE_NAME', message_name)
			self.handler.content += self.indentation.indent(field_def)


	def __init__(self, handler, indentation, name, field_id, message_name, namespace, dimension_type):
		self.handler = handler
		self.indentation = indentation
		self.name = name
		self.field_id = field_id
		self.dimension_type = dimension_type

		logging.debug('create GroupGen: %s', self.name)
		self.handler.content += self.indentation.indent(self.group_class_qualifier_def_ct)
		self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = self.name)

		self.gen_group_qualifier_def(message_name)


	def __del__(self):
		logging.debug('delete GroupGen: %s', self.name)


