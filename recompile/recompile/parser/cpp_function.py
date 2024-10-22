import re

from calling_convention import CallingConvention
import exceptions
import parser
from procedure_declaration import ProcedureDeclaration

procedure_regexp = re.compile(
    r'^((?P<return>.*[^:,])\s+)?((?P<class>\w+)::)?'
    r'(?P<name>~?\w+|operator\s*.*\S)\s*\(')


def parse_cpp_function(class_name, func, declared_types):
    declaration = parser.split_procedure_parameters(func)
    parameters = []
    arg_index = 0
    for (var_type, var_name) in declaration.parameters:
        arg_index += 1
        try:
            var_type = parser.parse_data_type(
                "{} {}".format(var_type, var_name).strip(), declared_types)
            var_name = "arg_{}".format(arg_index)
        except exceptions.UnknownTypeException:
            var_type = parser.parse_data_type(var_type, declared_types)
        parameters.append((var_type, var_name))
    match = re.search(procedure_regexp, func)
    if not match:
        raise Exception(
            "Failed to parse procedure declaration: {}".format(func))
    parsed_class_name = match.group("class")
    if class_name is not None:
        if parsed_class_name is not None:
            raise Exception(
                "Unexpected class name '{}' for '{}'".format(class_name, func))
    else:
        class_name = parsed_class_name
    if class_name is not None:
        method_class = parser.parse_data_type(class_name, declared_types)
    else:
        method_class = None
    return ProcedureDeclaration(
        proc_name=match.group("name"),
        convention=CallingConvention.THISCALL,
        method_class=method_class,
        parameters=parameters,
        return_arg=_extract_return_type(match.group("return"), declared_types),
    )


def _extract_return_type(s, declared_types):
    if s is None:
        return None
    s = s.replace("virtual", "")
    if not s:
        return None
    return parser.parse_data_type(s, declared_types)
