import re

import data_types
from hex_conversion import from_hex
import parser

variable_decl_regexp = re.compile(
    r'^((static|extern)\s+)?(?P<type>[^=]*[*&\s])(?P<name>[^\W\d]\S*)'
    r'(\s*=\s*\w*\s*)?$')
array_size_regexp = re.compile(r'(?P<name>.+)\[(?P<size>(0x[\dABCDEF]+)|\w+)]$')


def parse_cpp_variable_declaration(s, declared_types, constants=None):
    match = variable_decl_regexp.search(s)
    if not match:
        raise Exception("'{}' is not variable declaration.".format(s))
    field_type = match.group("type").strip()
    field_name = match.group("name")
    field_type = parser.parse_data_type(field_type, declared_types)
    field_type, field_name = _extract_array_size(
        field_type, field_name, constants)
    return field_type, field_name


def _extract_array_size(field_type, field_name, constants):
    match = array_size_regexp.search(field_name)
    if not match:
        return field_type, field_name
    size_str = match.group("size")
    if size_str.startswith("0x"):
        size = from_hex(size_str)
    elif size_str[0].isdigit():
        size = int(size_str)
    else:
        size = constants and constants.get_value(size_str)
        if size is None:
            raise Exception("Can't parse array size: {}.".format(size_str))
    return data_types.Array(field_type, size), match.group("name")
