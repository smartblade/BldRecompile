import parser
from calling_convention import CallingConvention
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration

from .convert_expression_to_type import convert_expression_to_type
from .explicit_arg_cast import explicit_arg_cast
from .narrow_constant import narrow_constant


def transform_procedure_call(pc, declarations, **kwargs):
    if pc.callee_address is None:
        return pc
    assert pc.proc_decl is not None
    cpp_declaration = declarations.symbols.procedures.get(pc.callee_address)
    if cpp_declaration is None:
        return pc
    proc_decl = parser.parse_cpp_function(
        cpp_declaration.class_name,
        cpp_declaration.declaration,
        declarations.declared_types,
    )
    arguments = _convert_arguments_to_parameters_types(pc, proc_decl)
    return pc.copy(
        name=proc_decl.proc_name, proc_decl=proc_decl, arguments=arguments)


def _convert_arguments_to_parameters_types(pc, proc_decl):
    if len(pc.arguments) != len(proc_decl.get_parameters_ids()):
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
    expected_args = proc_decl.get_parameters_ids(expected_args_types=True)
    for i, parameter in enumerate(expected_args.values()):
        c = narrow_constant(pc.arguments[i], parameter.data_type)
        new_argument = c or convert_expression_to_type(
            pc.arguments[i], parameter.data_type)
        new_argument = explicit_arg_cast(
            proc_decl, new_argument, parameter.data_type) or new_argument
        new_arguments.append(new_argument)
    return new_arguments
