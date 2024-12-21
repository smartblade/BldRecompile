import re

import data_types
from hex_conversion import from_hex
import parser

variable_decl_regexp = re.compile(
    r'^(?P<type>[^=]*[*\s])(?P<name>[^\W\d]\S*)(\s*=\s*\w*\s*)?$')
array_size_regexp = re.compile(r'(?P<name>.+)\[(?P<size>(0x[\dABCDEF]+)|\d+)]$')


def parse_cpp_variable_declaration(s, declared_types):
    match = re.search(variable_decl_regexp, s)
    if not match:
        raise Exception("'{}' is not variable declaration.".format(s))
    field_type = match.group("type").strip()
    field_name = match.group("name")
    field_type = parser.parse_data_type(field_type, declared_types)
    field_type, field_name = _extract_array_size(field_type, field_name)
    return field_type, field_name


def _extract_array_size(field_type, field_name):
    match = re.search(array_size_regexp, field_name)
    if not match:
        return field_type, field_name
    size_str = match.group("size")
    if size_str.startswith("0x"):
        size = from_hex(size_str)
    else:
        size = int(size_str)
    return data_types.Array(field_type, size), match.group("name")
