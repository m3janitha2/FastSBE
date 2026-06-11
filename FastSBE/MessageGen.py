"""Generate the C++ classes for SBE messages and composites."""

import logging

from FileGen import Indentation
from FileGen import FileGen
from FileGen import ClassGen
from FileGen import ContentHandler
from FileGen import to_snake_case
from FileGen import read_template
from Metadata import Metadata

class FieldGen:
	"""Emit the members and accessors for the fields of a message, composite or
	group entry - numeric, enum, set, string, composite and constant fields -
	plus the padding that keeps each field at its declared offset and the block
	at its declared blockLength.
	"""

	message_def_ct                  = read_template('metadata/c++/message/message_def.h')
	message_numeric_field_ct        = read_template('metadata/c++/message/numeric_field_def.h')
	message_const_numeric_field_ct  = read_template('metadata/c++/message/const_numeric_field_def.h')
	message_enum_field_ct           = read_template('metadata/c++/message/enum_field_def.h')
	message_const_enum_field_ct     = read_template('metadata/c++/message/const_enum_field_def.h')
	message_set_field_ct            = read_template('metadata/c++/message/set_field_def.h')
	message_string_field_ct         = read_template('metadata/c++/message/string_field_def.h')
	message_const_string_field_ct   = read_template('metadata/c++/message/const_string_field_def.h')
	message_composite_field_ct      = read_template('metadata/c++/message/composite_field_def.h')
	padding_def_ct                  = read_template('metadata/c++/message/padding_def.h')

	composite_numeric_field_ct      = read_template('metadata/c++/composite/numeric_field_def.h')
	composite_const_numeric_field_ct= read_template('metadata/c++/composite/const_numeric_field_def.h')
	composite_enum_field_ct         = read_template('metadata/c++/composite/enum_field_def.h')
	composite_const_enum_field_ct   = read_template('metadata/c++/composite/const_enum_field_def.h')
	composite_set_field_ct          = read_template('metadata/c++/composite/set_field_def.h')
	composite_string_field_ct       = read_template('metadata/c++/composite/string_field_def.h')
	composite_const_string_field_ct = read_template('metadata/c++/composite/const_string_field_def.h')

	constructor_ct                  = read_template('metadata/c++/composite/constructor_def.h')


	nested_group_def_ct             = read_template('metadata/c++/message/nested_group_def.h')
	nested_group_def_ct_extended           = read_template('metadata/c++/message/nested_group_def_extended.h')
	group_def_ct                    = read_template('metadata/c++/message/group_def.h')
	group_def_ct_extended                  = read_template('metadata/c++/message/group_def_extended.h')

	nested_variable_length_data_def_ct      = read_template('metadata/c++/message/nested_variable_length_data_def.h')
	variable_length_data_def_ct             = read_template('metadata/c++/message/variable_length_data_def.h')

	encoded_size_def_ct                     = read_template('metadata/c++/message/encoded_size_def.h')
	encoded_size_fixed_def_ct               = read_template('metadata/c++/message/encoded_size_fixed_def.h')

	buffer_def_ct                   = read_template('metadata/c++/message/buffer_def.h')

	ostream_field_def_begin_ct      = read_template('metadata/c++/message/ostream_field_def_begin.h')
	ostream_message_def_begin_ct    = read_template('metadata/c++/message/ostream_message_def_begin.h')
	ostream_field_def_end_ct        = read_template('metadata/c++/message/ostream_field_def_end.h')
	ostream_field_def_ct            = read_template('metadata/c++/message/ostream_field_def.h')
	ostream_group_def_begin_ct      = read_template('metadata/c++/message/ostream_group_def_begin.h')
	ostream_group_def_end_ct        = read_template('metadata/c++/message/ostream_group_def_end.h')
	ostream_group_field_def_ct      = read_template('metadata/c++/message/ostream_group_field_def.h')
	ostream_variable_length_data_def_ct      = read_template('metadata/c++/message/ostream_variable_length_data_def.h')
	

	def gen_message_descriptor(self, message_name, message_id, schema, version, description, block_length, header_types):
		# Return types come from the message header fields (S_*_TYPE) - replace
		# them before the values so S_BLOCK_LENGTH_TYPE is not clobbered by the
		# S_BLOCK_LENGTH value substitution.
		message_def = self.message_def_ct\
			.replace('S_BLOCK_LENGTH_TYPE', header_types['blockLength'])\
			.replace('S_TEMPLATE_ID_TYPE', header_types['templateId'])\
			.replace('S_SCHEMA_TYPE', header_types['schemaId'])\
			.replace('S_VERSION_TYPE', header_types['version'])\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_MESSAGE_ID', str(message_id))\
			.replace('S_SCHEMA_ID', str(schema))\
			.replace('S_VERSION_ID', str(version))\
			.replace('S_BLOCK_LENGTH', str(block_length))
		self.handler.content += self.indentation.indent(message_def)


	def reset_layout(self):
		self.current_offset = 0
		self.field_offset = 0

	def gen_padding(self, member_name, size):
		# emit a private byte-padding member (no accessor)
		pad = self.padding_def_ct\
			.replace('S_PADDING_MEMBER', member_name)\
			.replace('S_PADDING_SIZE', str(size))
		self.handler.content += self.indentation.indent(pad)

	def gen_trailing_padding(self, block_length):
		# pad the fixed block out to blockLength so the variable part (groups /
		# data) starts at the right offset - the first group sits at buffer()+0.
		if(block_length is None):
			return
		block_length = int(block_length)
		if(block_length < self.current_offset):
			logging.error("blockLength %d is smaller than the fixed block size %d"\
				, block_length, self.current_offset)
			raise SystemExit("FastSBE: blockLength %d < fixed block size %d"\
				% (block_length, self.current_offset))
		if(block_length > self.current_offset):
			self.gen_padding('block_trailing_padding_', block_length - self.current_offset)
			self.current_offset = block_length

	def layout_field(self, field_name, declared_offset, field_size):
		# resolve the field's offset and pad any gap, so the C++ member lands at
		# the schema offset - the generated code does no runtime offset math.
		if(field_size == 0):
			# constants occupy no wire bytes: place at the cursor, do not advance.
			self.field_offset = self.current_offset
			return
		if(declared_offset is not None):
			declared_offset = int(declared_offset)
			if(declared_offset > self.current_offset):
				self.gen_padding(to_snake_case(field_name) + '_pre_padding_', declared_offset - self.current_offset)
				self.current_offset = declared_offset
			elif(declared_offset < self.current_offset):
				logging.error("field '%s' declared offset %d overlaps preceding fields (cursor %d)"\
					, field_name, declared_offset, self.current_offset)
				raise SystemExit("FastSBE: field '%s' declared offset %d < accumulated %d (overlap)"\
					% (field_name, declared_offset, self.current_offset))
		self.field_offset = self.current_offset
		self.current_offset += field_size

	def get_field_offset(self, previous_field_name):
		return str(self.field_offset)

	def get_group_offset(self, previous_field_name):
		if(previous_field_name ==""):
			return '0'
		else:
			return to_snake_case(previous_field_name) + '_offset() + ' + 'sizeof(' + previous_field_name + '::header_) + ' + to_snake_case(previous_field_name) + '_data_length()'

	def gen_encoded_size(self, last_element_name):
		# encoded_size() = the message body's on-wire length: the root block plus
		# every repeating group and variable-length field. A fixed-only message
		# gets a compile-time block_length(); otherwise it is block_length() plus
		# the offset just past the last variable-length element - the same
		# accumulation get_group_offset() uses to place the element after it.
		if(last_element_name == ""):
			method = self.encoded_size_fixed_def_ct
		else:
			method = self.encoded_size_def_ct.replace('S_ENCODED_SIZE_EXPR', self.get_group_offset(last_element_name))
		self.handler.content += self.indentation.indent(method)


	def gen_ostream_field_def_begin(self):
		# a message is a class template, so its operator<< takes Msg<N>; a composite
		# is a plain class and uses the unparameterized signature.
		self.ostream_first = True
		template = self.ostream_message_def_begin_ct if self.is_message else self.ostream_field_def_begin_ct
		field_def = template\
			.replace('S_NAMESPACE', self.namespace)\
			.replace('S_MESSAGE_NAME', self.message_name)
		self.handler.ostream += field_def
		logging.debug('gen_ostream_field_def_begin')

	def gen_ostream_field_def_end(self):
		self.handler.ostream += self.ostream_field_def_end_ct
		logging.debug('gen_ostream_def')

	def gen_ostream_begin(self):
		self.gen_ostream_field_def_begin()

	def gen_ostream_end(self):
		self.gen_ostream_field_def_end()

	@staticmethod
	def gen_ostream_value(accessor, mode, set_type):
		# how a field's value is rendered in the JSON stream operator:
		#   cast   - promote int8/uint8 with unary + so it prints as a number
		#   set    - decode the bitset to a JSON array of choice names
		#   quoted - wrap in double quotes (enum / constant name, NUL-terminated)
		#   string - char-array field, quoted; must go through the _string()
		#            accessor: the raw char* is not NUL-terminated when the
		#            value fills the field, so operator<< would print past it
		#   char   - single-char field, quoted; a NUL value renders as ""
		#            instead of emitting a control byte
		if(mode == 'cast'):
			return '+' + accessor
		if(mode == 'set'):
			return set_type + '::to_string(' + accessor + ')'
		if(mode == 'char'):
			return ('"\\"" << (' + accessor + " == '\\0' ? std::string() : std::string(1, "
				+ accessor + ')) << "\\""')
		if(mode in ('quoted', 'string')):
			return '"\\"" << ' + accessor + ' << "\\""'
		return accessor

	@staticmethod
	def ostream_accessor(prefix, snake, mode):
		# char-array fields print via the bounded, NUL-trimmed _string()
		# accessor; every other mode reads the plain getter.
		suffix = '_string()' if mode == 'string' else '()'
		return prefix + snake + suffix

	@staticmethod
	def numeric_ostream_mode(field_type):
		# int8/uint8 are (un)signed char, so operator<< would print them as a
		# character; promote those to int. A plain char field is a one-char
		# string in JSON terms, so quote it. Wider integers stream as-is.
		if(field_type == Metadata.c_field_types['char']):
			return 'char'
		if(field_type in (Metadata.c_field_types['int8'], Metadata.c_field_types['uint8'])):
			return 'cast'
		return 'plain'

	def gen_ostream_field_def(self, field_name, mode = 'plain', set_type = None):
		snake = to_snake_case(field_name)
		value = self.gen_ostream_value(self.ostream_accessor('msg.', snake, mode), mode, set_type)
		sep = '' if self.ostream_first else ', '
		self.ostream_first = False
		field_def = self.ostream_field_def_ct\
			.replace('S_FIELD_SEP', sep)\
			.replace('S_MESSAGE_NAME', self.message_name)\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_VALUE', value)\
			.replace('S_FIELD_NAME', snake)
		field_def += '\n'
		self.handler.ostream += field_def
		logging.debug('gen_ostream_def')


	def gen_ostream_field(self, field_name, is_group, group_name, mode = 'plain', set_type = None):
		if(not is_group):
			self.gen_ostream_field_def(field_name, mode, set_type)
		else:
			self.gen_ostream_group_field_def(field_name, group_name, mode, set_type)


	def gen_ostream_group_def_begin(self, group_name, message_name):
		self.ostream_var_first = True
		field_def = self.ostream_group_def_begin_ct\
			.replace('S_NAMESPACE', self.namespace)\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_GROUP_NAME', group_name).replace('S_GROUP_SNAKE', to_snake_case(group_name))
		self.handler.ostream_var += field_def
		logging.debug('gen_ostream_field_def_begin')

	def gen_ostream_group_def_end(self):
		self.handler.ostream_var += self.ostream_group_def_end_ct
		logging.debug('gen_ostream_def')

	def gen_ostream_group_begin(self, group_name, message_name):
		self.gen_ostream_group_def_begin(group_name, message_name)

	def gen_ostream_group_end(self):
		self.gen_ostream_group_def_end()

	def gen_ostream_group_field_def(self, field_name, group_name, mode = 'plain', set_type = None):
		snake = to_snake_case(field_name)
		value = self.gen_ostream_value(self.ostream_accessor('g.', snake, mode), mode, set_type)
		sep = '' if self.ostream_var_first else ', '
		self.ostream_var_first = False
		field_def = self.ostream_group_field_def_ct\
			.replace('S_FIELD_SEP', sep)\
			.replace('S_MESSAGE_NAME', self.message_name)\
			.replace('S_GROUP_NAME', self.message_name)\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_VALUE', value)\
			.replace('S_FIELD_NAME', snake)
		field_def += '\n'
		self.handler.ostream_var += field_def
		logging.debug('gen_ostream_def')

	def gen_ostream_variable_length_data_def(self, field_name):
		sep = '' if self.ostream_first else ', '
		self.ostream_first = False
		field_def = self.ostream_variable_length_data_def_ct\
			.replace('S_FIELD_SEP', sep)\
			.replace('S_MESSAGE_NAME', self.message_name)\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))
		field_def += '\n'
		self.handler.ostream += field_def
		logging.debug('gen_ostream_def')        


	def gen_message_numeric_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name\
		, min, max, null, is_group, group_name):
		field_def = self.message_numeric_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_MIN', str(min))\
			.replace('S_FIELD_MAX', str(max))\
			.replace('S_FIELD_NULL', str(null))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, self.numeric_ostream_mode(field_type))
		logging.debug('gen_message_numeric_field_def: %s', field_name)

	def gen_composite_numeric_field_def(self, message_name\
		, field_type, field_name, previous_field_name\
		, min, max, null):
		field_def = self.composite_numeric_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_MIN', str(min))\
			.replace('S_FIELD_MAX', str(max))\
			.replace('S_FIELD_NULL', str(null))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, self.numeric_ostream_mode(field_type))
		self.handler.field_type_and_name.append([field_type, field_name])
		logging.debug('gen_composite_numeric_field_def: %s', field_name)


	def gen_message_const_numeric_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name, value, is_group, group_name):
		field_def = self.message_const_numeric_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, self.numeric_ostream_mode(field_type))
		logging.debug('gen_message_const_numeric_field_def: %s', field_name)

	def gen_composite_const_numeric_field_def(self, message_name\
		, field_type, field_name, previous_field_name, value):
		field_def = self.composite_const_numeric_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, self.numeric_ostream_mode(field_type))
		logging.debug('gen_composite_const_numeric_field_def: %s', field_name)


	def gen_message_enum_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name\
		, null, is_group, group_name):
		field_def = self.message_enum_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_NULL', str(null))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, 'quoted')
		self.handler.user_includes.append(field_type)
		logging.debug('gen_message_enum_field_def: %s', field_name)

	def gen_message_set_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name\
		, is_group, group_name):
		field_def = self.message_set_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, 'set', field_type)
		self.handler.user_includes.append(field_type)
		logging.debug('gen_message_set_field_def: %s', field_name)

	def gen_composite_set_field_def(self, message_name\
		, field_type, field_name, previous_field_name):
		field_def = self.composite_set_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, 'set', field_type)
		self.handler.user_includes.append(field_type)
		logging.debug('gen_composite_set_field_def: %s', field_name)

	def gen_composite_enum_field_def(self, message_name\
		, field_type, field_name, previous_field_name\
		, null):
		field_def = self.composite_enum_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_NULL', str(null))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, 'quoted')
		self.handler.user_includes.append(field_type)
		self.handler.field_type_and_name.append([field_type + '::Value', field_name])
		logging.debug('gen_composite_enum_field_def: %s', field_name)


	def gen_message_const_enum_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name, value, is_group, group_name):
		field_def = self.message_const_enum_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, 'quoted')
		self.handler.user_includes.append(field_type)
		logging.debug('gen_message_const_enum_field_def: %s', field_name)

	def gen_composite_const_enum_field_def(self, message_name\
		, field_type, field_name, previous_field_name, value):
		field_def = self.composite_const_enum_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, 'quoted')
		self.handler.user_includes.append(field_type)
		logging.debug('gen_composite_const_enum_field_def: %s', field_name)


	def gen_message_string_field_def(self, message_name, field_type, field_id, field_name\
		, previous_field_name, field_size, is_group, group_name):
		field_def = self.message_string_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_SIZE', field_size)
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, 'string')
		logging.debug('gen_message_string_field_def: %s', field_name)

	def gen_composite_string_field_def(self, message_name, field_type, field_name\
		, previous_field_name, field_size):
		field_def = self.composite_string_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_SIZE', field_size)
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, 'string')
		# tag 'string': a char-array field needs a string_view ctor arg + copy(),
		# unlike a bare char (single-char numeric), whose C++ type is also 'char'.
		self.handler.field_type_and_name.append([field_type, field_name, 'string'])
		logging.debug('gen_composite_string_field_def: %s', field_name)


	def gen_message_const_string_field_def(self, message_name, field_type, field_id, field_name\
		, previous_field_name, field_size, value, is_group, group_name):
		field_def = self.message_const_string_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_SIZE', field_size)\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name, 'quoted')
		logging.debug('gen_message_const_string_field_def: %s', field_name)

	def gen_composite_const_string_field_def(self, message_name, field_type, field_name\
		, previous_field_name, field_size, value):
		field_def = self.composite_const_string_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))\
			.replace('S_FIELD_SIZE', field_size)\
			.replace('S_CONST_FIELD_VALUE', str(value))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(field_name, 'quoted')
		logging.debug('gen_composite_const_string_field_def: %s', field_name)


	def gen_message_composite_field_def(self, message_name\
		, field_type, field_id, field_name, previous_field_name, is_group, group_name):
		field_def = self.message_composite_field_ct\
			.replace('S_MESSAGE_NAME', message_name)\
			.replace('S_FIELD_ID', str(field_id))\
			.replace('S_FIELD_TYPE', field_type)\
			.replace('S_FIELD_OFFSET', self.get_field_offset(previous_field_name))\
			.replace('S_FIELD_SCHEMA', field_name)\
			.replace('S_FIELD_NAME', to_snake_case(field_name))
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field(field_name, is_group, group_name)
		self.handler.user_includes.append(field_type)
		self.handler.field_type_and_name.append([field_type, field_name])
		logging.debug('gen_message_composite_field_def: %s', field_name)


	def gen_nested_group_def(self, group_name\
		, dimension_type, block_length_name, num_in_group_name\
		, num_in_group_type):
		field_def = self.nested_group_def_ct\
			.replace('S_GROUP_NAME', group_name).replace('S_GROUP_SNAKE', to_snake_case(group_name))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_BLOCK_LENGTH_NAME', to_snake_case(block_length_name))\
			.replace('S_NUM_IN_GROUP_NAME', to_snake_case(num_in_group_name))\
			.replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)
		self.handler.content += self.indentation.indent(field_def)
		self.handler.user_includes.append(dimension_type)
		logging.debug('gen_nested_group_def: %s', group_name)

	def gen_nested_group_def_extended(self, group_name\
		, dimension_type, block_length_name, num_in_group_name\
		, num_in_group_type, num_groups_type, num_var_data_field_type):
		field_def = self.nested_group_def_ct_extended\
			.replace('S_GROUP_NAME', group_name).replace('S_GROUP_SNAKE', to_snake_case(group_name))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_BLOCK_LENGTH_NAME', to_snake_case(block_length_name))\
			.replace('S_NUM_IN_GROUP_NAME', to_snake_case(num_in_group_name))\
			.replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)\
			.replace('S_NUM_GROUPS_TYPE', num_groups_type)\
			.replace('S_NUM_VAR_DATA_FIELDS_TYPE', num_var_data_field_type)             
		self.handler.content += self.indentation.indent(field_def)
		self.handler.user_includes.append(dimension_type)
		logging.debug('gen_nested_group_def_extended: %s', group_name)        


	def gen_group_def(self, group_name, previous_group_name, group_id\
		, dimension_type, block_length_name
		, num_in_group_name, num_in_group_type):
		field_def = self.group_def_ct\
			.replace('S_GROUP_NAME', group_name).replace('S_GROUP_SNAKE', to_snake_case(group_name))\
			.replace('S_GROUP_ID', group_id)\
			.replace('S_GROUP_OFFSET', self.get_group_offset(str(previous_group_name)))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_BLOCK_LENGTH_NAME', to_snake_case(block_length_name))\
			.replace('S_NUM_IN_GROUP_NAME', to_snake_case(num_in_group_name))\
			.replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)                           
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(group_name)
		logging.debug('gen_group_def: %s', group_name)

	def gen_group_def_extended(self, group_name, previous_group_name, group_id\
		, dimension_type, block_length_name
		, num_in_group_name, num_in_group_type\
		, num_groups_name, num_groups_type\
		, num_var_data_fields_name, num_var_data_fields_type):
		field_def = self.group_def_ct_extended\
			.replace('S_GROUP_NAME', group_name).replace('S_GROUP_SNAKE', to_snake_case(group_name))\
			.replace('S_GROUP_ID', group_id)\
			.replace('S_GROUP_OFFSET', self.get_group_offset(str(previous_group_name)))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_BLOCK_LENGTH_NAME', to_snake_case(block_length_name))\
			.replace('S_NUM_IN_GROUP_NAME', to_snake_case(num_in_group_name))\
			.replace('S_NUM_IN_GROUP_TYPE', num_in_group_type)\
			.replace('S_NUM_GROUPS_NAME', to_snake_case(num_groups_name))\
			.replace('S_NUM_GROUPS_TYPE', num_groups_type)\
			.replace('S_NUM_VAR_DATA_FIELDS_NAME', to_snake_case(num_var_data_fields_name))\
			.replace('S_NUM_VAR_DATA_FIELDS_TYPE', num_var_data_fields_type)                            
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_field_def(group_name)
		logging.debug('gen_group_def_extended: %s', group_name)


	def gen_nested_variable_length_data_def(self, variable_length_data_name\
		, dimension_type, dimension):
		variable_length_data_length_name = dimension[0]['name']
		variable_length_data_length_type = dimension[0]['type']
		variable_length_data_var_data_type = dimension[1]['type']

		field_def = self.nested_variable_length_data_def_ct\
			.replace('S_VAR_LEN_DATA_NAME', variable_length_data_name).replace('S_VAR_LEN_SNAKE', to_snake_case(variable_length_data_name))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_VAR_LEN_DATA_LENGTH_NAME', to_snake_case(variable_length_data_length_name))\
			.replace('S_VAR_LEN_DATA_LENGTH_TYPE', variable_length_data_length_type)\
			.replace('S_VAR_LEN_DATA_VAR_DATA_TYPE', variable_length_data_var_data_type)
		self.handler.content += self.indentation.indent(field_def)
		self.handler.user_includes.append(dimension_type)
		logging.debug('nested_variable_length_data_def: %s', variable_length_data_name)

	def gen_variable_length_data_def(self, variable_length_data_name, previous_variable_length_data_name, variable_length_data_id\
		, dimension_type, dimension):
		variable_length_data_length_name = dimension[0]['name']
		variable_length_data_length_type = dimension[0]['type']
		variable_length_data_var_data_type = dimension[1]['type']    
		field_def = self.variable_length_data_def_ct\
			.replace('S_VAR_LEN_DATA_NAME', variable_length_data_name).replace('S_VAR_LEN_SNAKE', to_snake_case(variable_length_data_name))\
			.replace('S_VAR_LEN_DATA_ID', variable_length_data_id)\
			.replace('S_VAR_LEN_DATA_OFFSET', self.get_group_offset(str(previous_variable_length_data_name)))\
			.replace('S_DIAMENTION_TYPE', dimension_type)\
			.replace('S_VAR_LEN_DATA_LENGTH_NAME', to_snake_case(variable_length_data_length_name))\
			.replace('S_VAR_LEN_DATA_LENGTH_TYPE', variable_length_data_length_type)\
			.replace('S_VAR_LEN_DATA_VAR_DATA_TYPE', variable_length_data_var_data_type)
		self.handler.content += self.indentation.indent(field_def)
		self.gen_ostream_variable_length_data_def(variable_length_data_name)
		logging.debug('gen_variable_length_data_def: %s', variable_length_data_name)            


	def gen_constructor(self):
		string_fields = []
		ct_args_list = []
		# A char-array (string) field is tagged 'string' on append and takes a
		# string_view arg assigned via copy(); every other field - including a
		# bare char, whose C++ type is also 'char' - is passed/initialized by value.
		def is_string(type_and_name):
			return len(type_and_name) > 2 and type_and_name[2] == 'string'
		for type_and_name in self.handler.field_type_and_name:
			field = to_snake_case(type_and_name[1])
			if(is_string(type_and_name)):
				string_fields.append(field)
				ct_args_list.append('std::string_view ' + field)
			else:
				ct_args_list.append(type_and_name[0] + ' ' + field)
		initilizer_args_list = []
		for type_and_name in self.handler.field_type_and_name:
			field = to_snake_case(type_and_name[1])
			if(not is_string(type_and_name)):
				initilizer_args_list.append(field + '_(' + field + ')')

		ct_args = ', '.join(ct_args_list)
		initilizer_args = ', '.join(initilizer_args_list)
		str_assign = ''
		for field_name in string_fields:
			str_assign += field_name + '.copy(' + field_name + '_,' + field_name + '_size());'

		field_def = self.constructor_ct\
			.replace('S_MESSAGE_NAME', self.message_name)\
			.replace('S_ARGS_LIST', ct_args)\
			.replace('S_INITIALIZER_LIST', initilizer_args)\
			.replace('S_STRING_FIELDS_ASSIGN', str_assign)

		self.handler.content += self.indentation.indent(field_def)


	def gen_buffer_def(self):
		# the buffer length is the message's template parameter N, not a fixed size
		self.handler.content += self.indentation.indent(self.buffer_def_ct)
		logging.debug('gen_buffer_def')


	def __init__(self, handler, indentation, message_name, class_gen, namespace, is_message = False):
		self.handler = handler
		self.indentation = indentation
		self.namespace = namespace
		self.message_name = message_name
		self.class_gen = class_gen
		self.is_message = is_message

		# byte cursor and current field offset, maintained by layout_field
		self.current_offset = 0
		self.field_offset = 0

		logging.debug('create FieldGen: %s', self.message_name)
		self.indentation.increment()
		
	def __del__(self):
		self.indentation.decrement()
		logging.debug('delete FieldGen: %s', self.message_name)


class MessageGen:
	"""Assemble a complete message or composite class - the schema descriptor
	and its fields - into a content handler.
	"""

	def __init__(self, handler, message_name, message_id, schema, version, description, namespace, descriptor = True, block_length = 0, header_types = None):
		self.handler = handler
		self.message_name = message_name
		self.namespace = namespace

		logging.debug('create MessageGen:%s ', message_name)
		self.indentation = Indentation(0)
		# a message is a class template parameterized by its group-buffer size N;
		# a composite (descriptor=False) is a plain class.
		template_prefix = "template <std::size_t N = 1>\n" if descriptor else ''
		self.class_gen = ClassGen(handler = self.handler, indentation = self.indentation\
			, class_name = message_name, template_prefix = template_prefix)
		self.field_gen = FieldGen(handler = self.handler, indentation = self.indentation\
			, message_name = message_name, class_gen = self.class_gen, namespace = namespace, is_message = descriptor)

		# composites pass descriptor=False: template_id/schema/version would
		# collide with same-named composite fields (e.g. MessageHeader.version).
		if descriptor:
			self.field_gen.gen_message_descriptor(message_name = message_name, message_id = message_id\
				, schema = schema, version = version, description = description, block_length = block_length\
				, header_types = header_types)


	def __del__(self):
		logging.debug('delete MessageGen: %s', self.message_name)


