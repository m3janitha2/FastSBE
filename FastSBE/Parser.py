"""Parse an SBE XML schema and drive C++ codec generation.

This is the orchestrator: it reads the schema's types, enums, sets, composites
and messages and dispatches each to the matching generator.
"""

import xml.etree.ElementTree as ET
import logging

from MessageGen import MessageGen
from Metadata import Metadata
from EnumGen import EnumGen
from SetGen import SetGen
from GroupGen import GroupGen
from VariableLengthDataGen import VariableLengthDataGen
from FileGen import ContentHandler
from FileGen import Indentation
from FileGen import FileGen


def to_pascal_case(name):
	out = []
	for part in name.split('_'):
		if not part:
			continue
		if part.isupper():
			out.append(part[:1] + part[1:].lower())
		else:
			out.append(part[:1].upper() + part[1:])
	return ''.join(out)


class Parser:
	"""Walk a parsed SBE schema and generate a C++ header per type, enum, set,
	composite and message. Computes field byte sizes and offsets so the
	generated struct layout matches the SBE wire format.
	"""

	def get_null_value_of_primitive(self, type_node):
		null_value = Metadata.default_null[type_node]
		if('nullValue' in type_node):
			null_value = type_node['nullValue']
		return null_value


	def get_numeric_attrib_of_primitive(self, type_node, attrib = None):
		min_value = Metadata.default_minimum[type_node]
		max_value = Metadata.default_maximum[type_node]
		null_value = Metadata.default_null[type_node]
		# attrib is the combined field+type dict; schema values override the defaults.
		if(attrib is not None):
			if('minValue' in attrib):
				min_value = attrib['minValue']
			if('maxValue' in attrib):
				max_value = attrib['maxValue']
			if('nullValue' in attrib):
				null_value = attrib['nullValue']
		return (Metadata.to_cpp_int_literal(min_value, type_node),
			Metadata.to_cpp_int_literal(max_value, type_node),
			Metadata.to_cpp_int_literal(null_value, type_node))


	def get_encoding_primitive(self, encoding_type):
		# encoding_type may be a primitive name (int8, ...) or a named simple type
		if(encoding_type in Metadata.primitive_sizes):
			return encoding_type
		type_elem = self.root.find(".//*[@name='" + encoding_type + "']")
		if(type_elem is not None and 'primitiveType' in type_elem.attrib):
			return type_elem.attrib['primitiveType']
		logging.error("cannot resolve encoding primitive for '%s'", encoding_type)
		raise SystemExit("FastSBE: cannot resolve encoding type '%s'" % encoding_type)

	def get_named_type_size(self, name):
		if(name in self.user_defined_enums or name in self.user_defined_sets):
			elem = self.root.find(".//*[@name='" + name + "']")
			return Metadata.primitive_sizes[self.get_encoding_primitive(self.get_primitive_encoding_type(elem.attrib))]
		if(name in self.user_defined_composites):
			return self.get_composite_size(name)
		elem = self.root.find(".//*[@name='" + name + "']")
		if(elem is not None and 'primitiveType' in elem.attrib):
			primitive = elem.attrib['primitiveType']
			if(primitive == 'char'):
				return int(elem.attrib.get('length', 1))
			return Metadata.primitive_sizes[primitive]
		logging.error("cannot size named type '%s'", name)
		raise SystemExit("FastSBE: cannot size named type '%s'" % name)

	def get_member_size(self, member):
		if(member.attrib.get('presence') == 'constant'):
			return 0
		tag = member.tag.split('}')[-1]
		if(tag == 'enum' or tag == 'set'):
			return Metadata.primitive_sizes[self.get_encoding_primitive(self.get_primitive_encoding_type(member.attrib))]
		if(tag == 'composite'):
			return self.get_composite_size(member.attrib['name'])
		if(tag == 'type'):
			if('primitiveType' in member.attrib):
				primitive = member.attrib['primitiveType']
				if(primitive == 'char'):
					return int(member.attrib.get('length', 1))
				return Metadata.primitive_sizes[primitive]
			# a <type> with no primitiveType references an enum/set/composite/simple type
			return self.get_named_type_size(member.attrib['type'])
		logging.error("unsupported composite member tag '%s' in size computation", tag)
		raise SystemExit("FastSBE: unsupported composite member tag '%s'" % tag)

	def get_composite_size(self, composite_name):
		# total byte width of a composite, honoring explicit member offsets
		composite = self.root.find(".//*[@name='" + composite_name + "']")
		accumulated = 0
		total = 0
		for member in composite:
			member_size = self.get_member_size(member)
			declared = member.attrib.get('offset')
			offset = int(declared) if declared is not None else accumulated
			total = max(total, offset + member_size)
			accumulated = offset + member_size
		return total

	def get_type_size(self, field):
		# byte width a message/group field occupies in the fixed block (0 for constants)
		if(self.is_const_type(field.attrib)):
			return 0
		field_type = field.attrib['type']
		if(field_type in self.user_defined_enums or field_type in self.user_defined_sets):
			elem = self.root.find(".//*[@name='" + field_type + "']")
			return Metadata.primitive_sizes[self.get_encoding_primitive(self.get_primitive_encoding_type(elem.attrib))]
		if(field_type in self.user_defined_composites):
			return self.get_composite_size(field_type)
		attrib = self.update_field_attrib(field)
		# a constant may be declared on the referenced type rather than the field
		if(self.is_const_type(attrib)):
			return 0
		primitive = self.get_primitive_type(attrib)
		if(primitive == 'char'):
			return int(attrib.get('length', 1))
		return Metadata.primitive_sizes[primitive]


	def is_numeric(self, primitive_type, attrib):
		if (primitive_type in Metadata.primitive_types):
			return True
		else:
			return False


	# char length 1 is a single character; length > 1 a fixed array; length 0
	# the variable-length-data sentinel (varData, needs char* access).
	def is_string_field(self, primitive_type, attrib):
		if ((primitive_type == 'char') and ('length' in attrib) and (int(attrib['length']) != 1)):
			return True
		else:
			return False


	def is_const_type(self, field_attrib):
		if(('presence' in field_attrib) and (field_attrib['presence'] == 'constant')):
			return True
		else:
			return False


	def parse_all_types(self, types):
		for type_node in types.iter('type'):
			type_name = type_node.attrib['name']
			self.user_defined_types.update({type_name : type_node.attrib})


	def update_enum_attrib(self, type_node):
		items = type_node.items()
		enum_attrib = {}
		for (key, value) in items:
			enum_attrib[key] = value
		
		encoding_type = type_node.attrib['encodingType']
		if encoding_type in Metadata.primitive_types:
			return enum_attrib
		else:
			if (encoding_type in self.user_defined_types):
				type_attrib = self.user_defined_types[encoding_type]
				enum_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', encoding_type)
				exit()

		logging.debug('enum_attrib %s', enum_attrib)
		return enum_attrib


	def update_field_attrib(self, field):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		field_type = field.attrib['type']

		if (field_type in Metadata.primitive_types):
			return field_attrib
		else:
			if (field_type in self.user_defined_types):
				type_attrib = self.user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', field_type)
				exit()

		logging.debug('field_attrib %s', field_attrib)
		return field_attrib


	def update_type_attrib(self, field):
		items = field.items()
		field_attrib = {}
		for (key, value) in items:
			field_attrib[key] = value

		l = lambda attrib: attrib['type'] if('type' in attrib)\
		   else ( attrib['primitiveType'] if 'primitiveType' in attrib else None)
		field_type = l(field.attrib)

		if (field_type in Metadata.primitive_types):
			return field_attrib
		else:
			if (field_type in self.user_defined_types):
				type_attrib = self.user_defined_types[field_type]
				field_attrib.update(type_attrib)
			else:
				logging.error('%s is not defined in types', field_type)
				exit()

		logging.debug('field_attrib %s', field_attrib)
		return field_attrib


	def get_primitive_encoding_type(self, enum_attrib):
		if 'primitiveType' in enum_attrib:
			return enum_attrib['primitiveType']
		elif 'encodingType' in enum_attrib:
			return enum_attrib['encodingType']
		else:
			logging.error('type or primitiveType is not defined in %s', enum_attrib['name']) 
			exit()


	def get_primitive_type(self, field_attrib):
		if 'primitiveType' in field_attrib:
			return field_attrib['primitiveType']
		elif 'type' in field_attrib:
			return field_attrib['type']
		else:
			logging.error('type or primitiveType is not defined in %s', field_attrib['name'])
			exit()

	# a constant's value may live on the field's text or the referenced type's
	# text (CME uses the latter); missing in both is a malformed schema -> fail.
	def get_const_value(self, field):
		value = field.text
		if value is None and 'type' in field.attrib:
			type_elem = self.root.find(".//*[@name='" + field.attrib['type'] + "']")
			if type_elem is not None:
				value = type_elem.text
		if value is None:
			name = field.attrib.get('name', '?')
			logging.error("constant field '%s' has no value", name)
			raise SystemExit("FastSBE: constant field '%s' (type '%s') has no value"
				% (name, field.attrib.get('type', '?')))
		return value.strip()

	def get_enum_null_value(self, enum_attrib):
		enum_name = enum_attrib['name']
		xpath = ".//*[@name='" + enum_name + "']"
		field = self.root.find(xpath)

		primitive_encoding_type = self.get_primitive_encoding_type(enum_attrib)
		(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_encoding_type)
		if 'nullValue' in field:
			null_value = field['nullValue']

		return 'nullValue', null_value

	def generate_enum(self, type_node):
		enum_values = []
		for field in type_node:
			enum_values.append((field.attrib['name'], field.text))		

		enum_name = type_node.attrib['name']
		encoding_type = type_node.attrib['encodingType']
		enum_attrib = self.update_enum_attrib(type_node = type_node)
		primitive_encoding_type = self.get_primitive_encoding_type(enum_attrib)
		enum_values.append(self.get_enum_null_value(enum_attrib))
		handler = ContentHandler()
		enum_file = EnumGen(handler, to_pascal_case(enum_name), Metadata.c_field_types[primitive_encoding_type]\
			, enum_values, self.namespace)
		self.user_defined_enums.append(enum_name)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		handler.user_includes = []
		indentation = Indentation(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = to_pascal_case(enum_name), namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_enums(self, types):
		for type_node in types.iter('enum'):
			self.generate_enum(type_node)


	def generate_set(self, type_node):
		set_name = type_node.attrib['name']
		# resolve encodingType (may be a user-defined alias) to a primitive, like enums
		set_attrib = self.update_enum_attrib(type_node = type_node)
		primitive_encoding_type = self.get_primitive_encoding_type(set_attrib)
		# choices: (name, bit index) - SetGen turns the index into a 1u<<index mask
		choices = [(choice.attrib['name'], choice.text.strip()) for choice in type_node]

		handler = ContentHandler()
		SetGen(handler, to_pascal_case(set_name)\
			, Metadata.c_field_types[primitive_encoding_type], choices, self.namespace)
		self.user_defined_sets.append(set_name)

		system_includes = ["cstdint", "string", "ostream"]
		handler.user_includes = []
		indentation = Indentation(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = to_pascal_case(set_name), namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_sets(self, types):
		for type_node in types.iter('set'):
			self.generate_set(type_node)


	def get_composite_type(self, type_node):
		if('type' in type_node.attrib):
			return type_node.attrib['type']
		elif('primitiveType' in type_node.attrib):
			return type_node.attrib['primitiveType']


	def get_enum_const_value(field):
		if 'valueRef' in field.attrib:
			return field.attrib['valueRef'].split('.')[1]
		else:
			return field.text

	def get_enum_type(field):
		if 'valueRef' in field.attrib:
			return field.attrib['valueRef'].split('.')[0]
		else:
			return field.attrib['type']


	def generate_composite_type(self, field_gen, composite_name, type_node, previous_type_name):
		type_name = type_node.attrib['name']
		composite_type = self.get_composite_type(type_node)
		includes = []

		# honor the schema offset of this composite member (emit padding for gaps)
		field_gen.layout_field(type_name, type_node.attrib.get('offset'), self.get_member_size(type_node))

		if('valueRef' in type_node.attrib.keys()):
			composite_type = Parser.get_enum_type(type_node)

		if(composite_type in self.user_defined_enums):
			includes.append(composite_type)
			if(self.is_const_type(type_node.attrib)):
				logging.debug('const enum field: %s', type_name)
				field_gen.gen_composite_const_enum_field_def(message_name = composite_name, field_type = to_pascal_case(composite_type)\
					, field_name = type_name, previous_field_name = previous_type_name\
					, value = Parser.get_enum_const_value(type_node))
				return type_name, includes
			else:
				logging.debug('enum field: %s', type_name)
				null_value = 0
				field_gen.gen_composite_enum_field_def(message_name = composite_name, field_type = to_pascal_case(composite_type)\
					, field_name = type_name, previous_field_name = previous_type_name\
					, null = null_value)
				return type_name, includes

		if(composite_type in self.user_defined_sets):
			logging.debug('set field: %s', type_name)
			field_gen.gen_composite_set_field_def(message_name = composite_name, field_type = to_pascal_case(composite_type)\
				, field_name = type_name, previous_field_name = previous_type_name)
			return type_name, includes

		field_attrib =  self.update_type_attrib(field = type_node)
		primitive_type = self.get_primitive_type(type_node.attrib)
		field_type = Metadata.c_field_types[primitive_type]

		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(type_node.attrib)):
				logging.debug('const string field: %s', type_name)
				field_gen.gen_composite_const_string_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, previous_field_name = previous_type_name, field_size = type_node.attrib['length']\
					, value = type_node.text)
				return type_name, includes
			else:
				logging.debug('const string field: %s', type_name)
				field_gen.gen_composite_string_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, previous_field_name = previous_type_name, field_size = type_node.attrib['length'])
				return type_name, includes
		
		if(self.is_numeric(primitive_type, type_node.attrib)):
			if(('presence' in type_node.attrib) and (type_node.attrib['presence'] == 'constant')):
				field_gen.gen_composite_const_numeric_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, previous_field_name = previous_type_name\
					, value = type_node.text)
				return type_name, includes
			else:
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type, field_attrib)
				field_gen.gen_composite_numeric_field_def(message_name = composite_name\
					, field_type = field_type\
					, field_name = type_name, previous_field_name = previous_type_name\
					, min = min_value, max = max_value, null = null_value)
				return type_name, includes
		else:
			logging.error('field type or primitive type is not defined in: %s', type_name)
			exit()


	def get_description(message):
		if 'description' in message.attrib:
			return message.attrib['description']
		else:
			return ""

	def generate_composite_class(self, composite, handler):
		composite_name = composite.attrib['name']
		description = Parser.get_description(composite)
		msg_gen = MessageGen(handler = handler, message_name = to_pascal_case(composite_name), message_id = 0\
			, schema = self.schema_id, version = self.schema_version, description = description, namespace = self.namespace\
			, descriptor = False)

		msg_gen.field_gen.gen_ostream_begin()
		msg_gen.field_gen.reset_layout()
		previous_type_name = ""
		for type_node in composite.iter('type'):
			previous_type_name, includes = self.generate_composite_type(msg_gen.field_gen, to_pascal_case(composite_name), type_node\
				, previous_type_name)
		msg_gen.field_gen.gen_ostream_end()
		msg_gen.field_gen.gen_trailing_padding(composite.attrib.get('blockLength'))
		msg_gen.field_gen.gen_constructor()

	def generate_composite(self, composite):
		composite_name = composite.attrib['name']
		logging.debug('generate_composite: %s ' , composite_name)

		handler = ContentHandler()
		self.generate_composite_class(composite, handler)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		indentation = Indentation(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = to_pascal_case(composite_name), namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_composites(self, types):
		for composite in types.iter('composite'):
			composite_name = composite.attrib['name']
			self.user_defined_composites.append(composite_name)
			self.generate_composite(composite)


	def generate_message_field(self, field_gen, message_name, field, previous_field_name, is_group, group_name):
		field_name = field.attrib['name']
		field_id = field.attrib['id']
		field_type = field.attrib['type']

		# honor the schema offset: pad any gap so the member lands at its position
		field_gen.layout_field(field_name, field.attrib.get('offset'), self.get_type_size(field))

		if(field_type in self.user_defined_enums):
			if(self.is_const_type(field.attrib)):
				logging.debug('const enum field: %s', field_name)
				field_gen.gen_message_const_enum_field_def(message_name = message_name, field_type = to_pascal_case(field_type)\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, value = Parser.get_enum_const_value(field), is_group = is_group, group_name = group_name)
				return field_name
			else:
				logging.debug('enum field: %s', field_name)
				null_value = 0
				field_gen.gen_message_enum_field_def(message_name = message_name, field_type = to_pascal_case(field_type)\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, null = null_value, is_group = is_group, group_name = group_name)
				return field_name

		if(field_type in self.user_defined_sets):
			logging.debug('set field: %s', field_name)
			field_gen.gen_message_set_field_def(message_name = message_name, field_type = to_pascal_case(field_type)\
				, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
				, is_group = is_group, group_name = group_name)
			return field_name

		if(field_type in self.user_defined_composites):
			logging.debug('composite field: %s', field_name)
			field_gen.gen_message_composite_field_def(message_name = message_name, field_type = to_pascal_case(field_type)\
				, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
				, is_group = is_group, group_name = group_name)
			return field_name

		field_attrib = self.update_field_attrib(field)
		primitive_type = self.get_primitive_type(field_attrib)

		if(self.is_string_field(primitive_type, field_attrib)):
			if(self.is_const_type(field_attrib)):
				logging.debug('const string field: %s', field_name)
				field_gen.gen_message_const_string_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, field_size = field_attrib['length']\
					, value = self.get_const_value(field), is_group = is_group, group_name = group_name)
				return field_name

			else:
				logging.debug('const string field: %s', field_name)
				field_gen.gen_message_string_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, field_size = field_attrib['length'], is_group = is_group, group_name = group_name)
				return field_name

		if(self.is_numeric(primitive_type, field_attrib)):
			logging.debug('const numeric field: %s', field_name)
			if(('presence' in field_attrib) and (field_attrib['presence'] == 'constant')):
				const_value = self.get_const_value(field)
				if(primitive_type == 'char'):
					const_value = "'" + const_value + "'"
				field_gen.gen_message_const_numeric_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, value = const_value, is_group = is_group, group_name = group_name)
				return field_name
			else:
				logging.debug('numeric field: %s', field_name)
				(min_value, max_value, null_value) = self.get_numeric_attrib_of_primitive(primitive_type, field_attrib)
				field_gen.gen_message_numeric_field_def(message_name = message_name\
					, field_type = Metadata.c_field_types[primitive_type]\
					, field_id = field_id, field_name = field_name, previous_field_name = previous_field_name\
					, min = min_value, max = max_value, null = null_value, is_group = is_group, group_name = group_name)
				return field_name

		logging.error('field type or primitive type is not defined in: %s', field_name)
		exit()

		return field_name


	def generate_group_fields(self, msg_gen, handler, group_gen, group, message_name):

		entry_gen = group_gen.GroupEntryGen(handler = handler, indentation = msg_gen.indentation
									, namespace = self.namespace)
		group_name = group.attrib['name']

		entry_gen.field_gen.gen_ostream_group_begin(group_name, message_name)
		entry_gen.field_gen.reset_layout()
		previous_field_name = ""
		for field in group:
			if (field.tag == 'field'):
				previous_field_name = self.generate_message_field(entry_gen.field_gen\
					, group_name, field, previous_field_name, is_group = True, group_name = group_name)
		entry_gen.field_gen.gen_trailing_padding(group.attrib.get('blockLength'))
		entry_gen.field_gen.gen_ostream_group_end()


	def update_group_size_encoding_types(group_size_encoding_type_entry, composite, index):
		type_node = composite[index]
		default_type_name = Metadata.default_group_size_encoding_names[index].lower()
		if (type_node.attrib['name'].lower() != default_type_name):
			logging.error('invalid group size encoding. expected %s confiured %s'\
				, default_type_name.lower(), type_node.attrib['name'].lower())
			exit()
		else:
			group_size_encoding_type = { 
				"name": type_node.attrib['name'], 
				"type" : Metadata.c_field_types[type_node.attrib['primitiveType']]  
			}
			group_size_encoding_type_entry.append(group_size_encoding_type)


	def parse_group_size_encoding_header(self, dimension_type):
		if(dimension_type in self.group_size_encoding_types.keys()):
			return self.group_size_encoding_types[dimension_type]
		else:
			xpath = ".//*[@name='" + dimension_type + "']"
			composite = self.root.find(xpath)
			group_size_encoding_type = []
			field_count = len(composite)
			if(field_count < 2):
				logging.error('invalid group size encoding. expected at least 2 field')
				exit()
			elif(field_count == 2):
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 0)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 1)
			elif(field_count == 4):
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 0)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 1)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 2)
				Parser.update_group_size_encoding_types(group_size_encoding_type, composite, 3)
		
			self.group_size_encoding_types.update({dimension_type : group_size_encoding_type})
			logging.debug('update group size encoding. %s', group_size_encoding_type)
			return group_size_encoding_type


	def update_variable_data_encoding_types(variable_data_encoding_type_entry, composite, index):
		type_node = composite[index]
		default_type_name = Metadata.default_variable_data_encoding_names[index].lower()
		if (type_node.attrib['name'].lower() != default_type_name):
			logging.error('invalid variable data encoding. expected %s confiured %s'\
				, default_type_name.lower(), type_node.attrib['name'].lower())
			exit()
		else:
			variable_data_encoding_type = { 
				"name": type_node.attrib['name'], 
				"type" : Metadata.c_field_types[type_node.attrib['primitiveType']]  
			}
			variable_data_encoding_type_entry.append(variable_data_encoding_type)


	def parse_variable_data_encoding_header(self, type_node):
		if(type_node in self.variable_data_encoding_types.keys()):
			return self.variable_data_encoding_types[type_node]
		else:
			xpath = ".//*[@name='" + type_node + "']"
			composite = self.root.find(xpath)
			variable_data_encoding_type = []
			field_count = len(composite)
			if(field_count < 2):
				logging.error('invalid variable data encoding. expected at least 2 field')
				exit()
			elif(field_count == 2):
				Parser.update_variable_data_encoding_types(variable_data_encoding_type, composite, 0)
				Parser.update_variable_data_encoding_types(variable_data_encoding_type, composite, 1)		

			self.variable_data_encoding_types.update({type_node : variable_data_encoding_type})
			logging.debug('variable data encoding. %s', variable_data_encoding_type)
			return variable_data_encoding_type


	def generate_nested_group(self, msg_gen, handler, group, message_name, dimension):
		group_name = group.attrib['name']
		group_id = group.attrib['id']
		dimension_type = group.attrib['dimensionType']
		
		group_gen = GroupGen(handler = handler, indentation = msg_gen.indentation\
			, name = group_name, field_id = group_id, message_name = message_name, namespace = self.namespace\
			, dimension_type = dimension_type)

		self.generate_group_fields(msg_gen, handler, group_gen, group, message_name)

		dimension_type_count = len(dimension)
		if(dimension_type_count == 2):
			msg_gen.field_gen.gen_nested_group_def(group_name = group_name, dimension_type = to_pascal_case(dimension_type)\
				, block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type'])

		elif(dimension_type_count == 4):
			msg_gen.field_gen.gen_nested_group_def_4(group_name = group_name, dimension_type = to_pascal_case(dimension_type)\
				, block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type']\
				, num_groups_type = dimension[2]['type']\
				, num_var_data_field_type = dimension[3]['type'])


	def parse_group(self, msg_gen, handler, message_name, group, previous_field_name):
		group_name = group.attrib['name']
		group_id = group.attrib['id']
		dimension_type = group.attrib['dimensionType']

		dimension = self.parse_group_size_encoding_header(dimension_type)

		self.generate_nested_group(msg_gen, handler, group, message_name, dimension)

		dimension_type_count = len(dimension)
		if(dimension_type_count == 2):
			msg_gen.field_gen.gen_group_def(group_name = group_name\
				, previous_group_name = previous_field_name, group_id = group_id\
				, dimension_type = to_pascal_case(dimension_type), block_length_name = 'blockLength'\
				, num_in_group_name = 'numInGroup', num_in_group_type = 'std::uint16_t')
		elif(dimension_type_count == 4):
			msg_gen.field_gen.gen_group_def_4(group_name = group_name
				, previous_group_name = previous_field_name, group_id = group_id\
				, dimension_type = to_pascal_case(dimension_type), block_length_name = dimension[0]['name']\
				, num_in_group_name = dimension[1]['name'], num_in_group_type = dimension[1]['type']\
				, num_groups_name = dimension[2]['name'], num_groups_type = dimension[2]['type']\
				, num_var_data_fields_name = dimension[3]['name'], num_var_data_fields_type = dimension[3]['type'])

		return group_name


	def generate_nested_variable_length_data(self, msg_gen, handler, variable_length_data, message_name, dimension):
		name = variable_length_data.attrib['name']
		field_id = variable_length_data.attrib['id']
		dimension_type = variable_length_data.attrib['type']
		
		group_gen = VariableLengthDataGen(handler = handler, indentation = msg_gen.indentation\
			, name = name, field_id = field_id, message_name = message_name, namespace = self.namespace\
			, dimension_type = dimension_type)

		msg_gen.field_gen.gen_nested_variable_length_data_def(variable_length_data_name = name, dimension_type = to_pascal_case(dimension_type)\
			, dimension = dimension)		


	def parse_data(self, msg_gen, handler, message_name, variable_length_data, previous_variable_length_data_name):
		name = variable_length_data.attrib['name']
		field_id = variable_length_data.attrib['id']
		dimension_type = variable_length_data.attrib['type']

		dimension = self.parse_variable_data_encoding_header(dimension_type)
		self.generate_nested_variable_length_data(msg_gen, handler, variable_length_data, message_name, dimension)

		msg_gen.field_gen.gen_variable_length_data_def(variable_length_data_name = name\
			, previous_variable_length_data_name = previous_variable_length_data_name, variable_length_data_id = field_id\
			, dimension_type = to_pascal_case(dimension_type), dimension = dimension)

		return name
		

	def generate_message(self, message, handler):
		message_name = message.attrib['name']
		message_id = message.attrib['id']		
		description = Parser.get_description(message)

		msg_gen = MessageGen(handler = handler, message_name = message_name, message_id = message_id\
			, schema = self.schema_id, version = self.schema_version, description = description, namespace = self.namespace)

		msg_gen.field_gen.gen_ostream_begin()
		msg_gen.field_gen.reset_layout()
		is_group_section = False
		is_var_data_section = False
		previous_field_name = ""
		for element in message:
			if (element.tag == 'field'):
				previous_field_name = self.generate_message_field(msg_gen.field_gen, message_name, element\
					, previous_field_name, is_group = False, group_name = '')
			elif(element.tag == 'group'):
				if(not is_group_section):
					is_group_section = True
					previous_field_name = ""
					msg_gen.field_gen.gen_trailing_padding(message.attrib.get('blockLength'))
					msg_gen.field_gen.gen_buffer_def(1024)					
					
				previous_field_name = self.parse_group(msg_gen, handler, message_name, element\
					, previous_field_name)

			elif(element.tag == 'data'):
				if(not is_var_data_section):
					is_var_data_section = True
					if(is_group_section):
						# buffer already emitted by the group section
						pass
					else:					
						previous_field_name = ""
						msg_gen.field_gen.gen_trailing_padding(message.attrib.get('blockLength'))
						msg_gen.field_gen.gen_buffer_def(1024)
						is_fixed_length_section = False

				previous_field_name = self.parse_data(msg_gen, handler, message_name, element\
					, previous_field_name)

		msg_gen.field_gen.gen_ostream_end()


	def parse_message(self, message):
		message_name = message.attrib['name']
		logging.debug('message_name: %s', message_name)

		handler = ContentHandler()
		self.generate_message(message, handler)

		system_includes = ["cstdint", "string", "string_view", "ostream", "cstring"]
		indentation = Indentation(0)
		FileGen(indentation = indentation, out_folder = self.out_folder\
			, file_name = message_name, namespace = self.namespace\
			, system_includes = system_includes, handler = handler)


	def parse_all_messages(self, root):
		messages = root.find('messages')
		if not messages:
			namespaces = {'sbe' : root.tag.split('}')[0].strip('{')}
			for message in root.iterfind('sbe:message', namespaces):
				self.parse_message(message)
		else:
			namespaces = {'sbe' : root.tag.split('}')[0].strip('{')}
			for message in messages.iterfind('sbe:message', namespaces):
				self.parse_message(message)

	def run(self):
		tree = ET.parse(self.schema_file)
		self.root = tree.getroot()
		self.schema_id = self.root.attrib['id']
		self.schema_version = self.root.attrib['version']
		logging.debug('schema_id: %s schema_version: %s', self.schema_id, self.schema_version)

		types = self.root.find('types')
		self.parse_all_types(types = types)
		self.parse_all_enums(types = types)
		self.parse_all_sets(types = types)
		self.parse_all_composites(types = types)
		self.parse_all_messages(root = self.root)



	def __init__(self, schema_file, out_folder, override_namespace):
		self.schema_file = schema_file
		self.out_folder = out_folder
		self.namespace = override_namespace

		self.user_defined_types = {}
		self.user_defined_enums = []
		self.user_defined_sets = []
		self.user_defined_composites = []
		self.group_size_encoding_types = {}
		self.variable_data_encoding_types = {}

		self.run()

		logging.debug('end')