import data_types
import expressions
from expressions.operator import Operator
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
    result = _convert_struct_return_implicit_arg(pc, proc_decl)
    if result is not None:
        return result
    return _convert_procedure_call_arguments(pc, proc_decl)


def _convert_procedure_call_arguments(pc, proc_decl):
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


def _convert_struct_return_implicit_arg(pc, proc_decl):
    if not isinstance(proc_decl.return_type, data_types.ClassType):
        return None
    this_arg = None
    new_arguments = pc.arguments
    if pc.is_method:
        this_arg = new_arguments[0]
        new_arguments = new_arguments[1:]
    return_arg = new_arguments[0]
    return_arg = convert_expression_to_type(
        return_arg, data_types.Pointer32(proc_decl.return_type))
    new_arguments = new_arguments[1:]
    if this_arg is not None:
        new_arguments.insert(0, this_arg)
    pc = pc.copy(arguments=new_arguments)
    pc = _convert_procedure_call_arguments(pc, proc_decl)
    dst = expressions.do_dereference(return_arg)
    if isinstance(dst.data_type, data_types.ClassType):
        dst = expressions.ImplicitCast(data_types.Reference(dst.data_type), dst)
    return expressions.Bin(Operator.ASS, dst, pc)
