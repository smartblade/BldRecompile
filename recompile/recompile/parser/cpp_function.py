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
    is_vararg = False
    parameters = []
    arg_index = 0
    for (var_type, var_name) in declaration.parameters:
        if var_name == "...":
            is_vararg = True
            continue
        var_decl = "{} {}".format(var_type, var_name).strip()
        arg_index += 1
        try:
            var_type = parser.parse_data_type(var_decl, declared_types)
            var_name = "arg_{}".format(arg_index)
        except exceptions.UnknownTypeException:
            var_type, var_name = parser.parse_cpp_variable_declaration(
                var_decl, declared_types)
        parameters.append((var_type, var_name))
    match = procedure_regexp.search(func)
    if not match:
        raise Exception(
            "Failed to parse procedure declaration: {}".format(func))
    parsed_class_name = match.group("class")
    is_definition = parsed_class_name is not None
    if class_name is not None:
        if is_definition:
            raise Exception(
                "Unexpected class name '{}' for '{}'".format(class_name, func))
    else:
        class_name = parsed_class_name
    if class_name is not None:
        method_class = parser.parse_data_type(class_name, declared_types)
    else:
        method_class = None
    proc_name = match.group("name")
    is_static, return_type = _extract_static(match.group("return"))
    if is_definition:
        is_static = _get_static_from_declaration(method_class, proc_name)
    convention = _get_calling_convention(is_static, method_class)
    _validate_calling_convention(is_vararg, convention)
    return ProcedureDeclaration(
        proc_name=proc_name,
        convention=convention,
        method_class=method_class,
        parameters=parameters,
        return_arg=_extract_return_type(return_type, declared_types),
        is_static=is_static,
        is_vararg=is_vararg,
    )


def _validate_calling_convention(is_vararg, convention):
    if is_vararg and convention != CallingConvention.CDECL:
        raise Exception(
            "Expected {} for vararg but was: {}".format(
                CallingConvention.CDECL, convention
            )
        )


def _get_calling_convention(is_static, method_class):
    if method_class is not None and not is_static:
        return CallingConvention.THISCALL
    return CallingConvention.CDECL


def _get_static_from_declaration(method_class, proc_name):
    declared_procedure = method_class.find_method(proc_name)
    if declared_procedure is not None:
        return declared_procedure.is_static
    return False


def _strip_start(definition, start):
    definition = definition.strip()
    if definition.startswith(start):
        return True, definition[len(start):].strip()
    return False, definition


def _extract_static(s):
    if s is None:
        return False, None
    return _strip_start(s, "static")


def _extract_return_type(s, declared_types):
    if s is None:
        return None
    s = s.replace("virtual", "")
    if not s:
        return None
    return parser.parse_data_type(s, declared_types)
