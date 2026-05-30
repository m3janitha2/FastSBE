import logging

from FileGen import Indentation
from FileGen import ClassGen
from MessageGen import FieldGen

class GroupGen:
	group_qulifiyer_def_ct = open('metadata/c++/message/group_qulifiyer_def.h', 'r').read()
	group_class_qulifiyer_def_ct = 'public:'

	class GroupEntryGen:
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

	def gen_group_qulifiyer_def(self, message_name):
			field_def = self.group_qulifiyer_def_ct\
				.replace('S_MESSAGE_NAME', message_name)
			self.handler.content += self.indentation.get_indented_str(field_def)


	def __init__(self, handler, indentation, name, id, message_name, namespace, dimension_type):
		self.handler = handler
		self.indentation = indentation
		self.name = name
		self.id = id
		self.dimension_type = dimension_type

		logging.debug('create GroupGen: %s', self.name)
		self.handler.content += self.indentation.get_indented_str(self.group_class_qulifiyer_def_ct)
		self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = self.name)

		self.gen_group_qulifiyer_def(message_name)


	def __del__(self):
		logging.debug('delete GroupGen: %s', self.name)


