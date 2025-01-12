import data_types
import parser
from calling_convention import CallingConvention
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration

from .convert_expression_to_type import convert_expression_to_type
from .explicit_arg_cast import explicit_arg_cast
from .narrow_constant import narrow_constant


def transform_procedure_call(pc, declarations, **kwargs):
    proc_decl = _get_callee_declaration(pc, declarations)
    if proc_decl is None:
        return pc
    assert pc.proc_decl is not None
    arguments = _convert_arguments_to_parameters_types(pc, proc_decl)
    return pc.copy(
        name=proc_decl.proc_name, proc_decl=proc_decl, arguments=arguments)


def _get_callee_declaration(pc, declarations):
    if pc.callee_expression is not None:
        assert pc.callee_address is None
        return _get_declaration_from_callee_expression(pc.callee_expression)
    if pc.callee_address is None:
        return None
    cpp_declaration = declarations.symbols.procedures.get(pc.callee_address)
    if cpp_declaration is None:
        return None
    return parser.parse_cpp_function(
        cpp_declaration.class_name,
        cpp_declaration.declaration,
        declarations.declared_types,
    )


def _get_declaration_from_callee_expression(e):
    function = e.data_type
    if isinstance(function, data_types.Unknown32):
        return None
    assert isinstance(function, data_types.Function)
    return function.proc_decl


def _convert_arguments_to_parameters_types(pc, proc_decl):
    if (
        len(pc.arguments) != len(proc_decl.get_parameters_ids()) and
        (
            not proc_decl.is_vararg or
            len(pc.arguments) < len(proc_decl.get_parameters_ids())
        )
    ):
        raise Exception(
            "Expected to be {} arguments at {} but was: {}".format(
                len(pc.arguments),
                proc_decl.proc_name,
                len(proc_decl.get_parameters_ids()),
            )
        )
    validate_procedure_declaration(
        proc_decl,
        stack_delta=pc.proc_decl.stack_delta,
        is_thiscall=pc.proc_decl.convention == CallingConvention.THISCALL)
    new_arguments = []
    parameters = list(
        proc_decl.get_parameters_ids(expected_args_types=True).values())
    for i, argument in enumerate(pc.arguments):
        parameter = parameters[i] if i < len(parameters) else None
        new_argument = _convert_argument_to_parameters_type(
            argument, parameter, proc_decl)
        new_arguments.append(new_argument)
    return new_arguments


def _convert_argument_to_parameters_type(argument, parameter, proc_decl):
    if parameter is None:
        return argument
    c = narrow_constant(argument, parameter.data_type)
    if c is not None:
        return c
    new_argument = convert_expression_to_type(argument, parameter.data_type)
    new_argument = explicit_arg_cast(
        proc_decl, new_argument, parameter.data_type) or new_argument
    return new_argument
