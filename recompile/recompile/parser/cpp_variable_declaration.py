import re

import parser

variable_decl_regexp = re.compile(
    r'^(?P<type>.*[*\s])(?P<name>[^\W\d]\S*)(\s*=\s*\d*\s*)?$')


def parse_cpp_variable_declaration(s, declared_types):
    match = re.search(variable_decl_regexp, s)
    if not match:
        raise Exception("'{}' is not variable declaration.".format(s))
    field_type = match.group("type").strip()
    field_name = match.group("name")
    field_type = parser.parse_data_type(field_type, declared_types)
    return field_type, field_name
