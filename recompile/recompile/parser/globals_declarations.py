import re

import parser
import expressions

global_regexp = re.compile(r'^(?P<data_type>.+)\s(?P<var_name>g_\w+)\s=')


def parse_globals_declarations(lines, defined_types):
    gbl_vars = {}
    for line in lines:
        match = re.search(global_regexp, line)
        if not match:
            continue
        data_type = parser.parse_data_type(
            match.group('data_type'), defined_types
        )
        var_name = match.group('var_name')
        gbl_vars[var_name] = expressions.Identifier(data_type, var_name)
    return gbl_vars
