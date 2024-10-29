import parser
from calling_convention import CallingConvention
import data_types
import instructions
import expressions
from patterns.predefined_procedures import visit_predefined_procedures


def make_high_level_code(proc_info, proc_decl, declarations, instrs):
    stack_vars = proc_info.stack_variables
    new_instructions = []
    for instr in instrs:
        instr = instr.transform(
            lambda e: _transform(
                e, stack_vars=stack_vars, declarations=declarations))
        new_instructions.append(instr)
    _validate_procedure_info(proc_info, proc_decl)
    new_instructions = _eliminate_procedure_info(proc_info, new_instructions)
    new_instructions = _rewrite_returns(proc_decl, new_instructions)
    new_instructions = _eliminate_unnecessary_returns(
        proc_info, proc_decl, new_instructions)
    return new_instructions


def _transform(e, **kwargs):
    return visit_predefined_procedures(
        e, **kwargs,
        on_stackvar=_transform_stackvar,
        on_access=_transform_access,
        on_global=_transform_global,
    )


def _transform_stackvar(offset, size, stack_vars, **kwargs):
    variable = stack_vars.get(offset)
    if variable is not None and variable.data_type.size == size:
        return variable
    return None


def _transform_access(expression, offset, size, **kwargs):
    data_type = expression.data_type
    if not isinstance(data_type, data_types.Pointer32):
        raise Exception(
            "Data type of {} expected to be pointer but was: {}.".format(
                expression, data_type))
    pointee = data_type.pointee
    if isinstance(pointee, data_types.ClassType):
        try:
            data_type, field_name = pointee.get_field_by_offset(offset)
        except KeyError:
            return None
        if data_type.size != size:
            raise Exception(
                "Data type size expected to be {} but was: {}.".format(
                    size, data_type.size))
        return expressions.FieldAccess(expression, field_name)
    return None


def _transform_global(address, declarations, **kwargs):
    global_var = declarations.symbols.variables.get(address)
    if global_var is not None:
        var_type, var_name = parser.parse_cpp_variable_declaration(
            global_var.declaration.strip().strip(";"),
            declarations.declared_types,
        )
        return expressions.AddressOf(expressions.Identifier(var_type, var_name))
    return None


def _validate_procedure_info(proc_info, proc_decl):
    if proc_decl is None:
        return
    if proc_info.stack_delta != proc_decl.stack_delta:
        raise Exception(
            "Stack delta expected to be {} but was: {}.".format(
                proc_info.stack_delta, proc_decl.stack_delta))
    if (
        proc_info.is_thiscall and
        proc_decl.convention != CallingConvention.THISCALL
    ):
        raise Exception(
            "Convention expected to be 'thiscall' but was: {}".format(
                proc_decl.convention))
    if (
        not proc_info.is_thiscall and
        proc_decl.convention == CallingConvention.THISCALL
    ):
        raise Exception(
            "Convention expected to be non-'thiscall' but was: {}".format(
                proc_decl.convention))


def _eliminate_procedure_info(proc_info, instrs):
    if instrs[0] == proc_info:
        instrs.pop(0)
    return instrs


def _eliminate_unnecessary_returns(proc_info, proc_decl, instrs):
    ri = instrs[-1]
    if isinstance(ri, instructions.ReturnInstruction):
        if (
            ri.expression is None or
            proc_decl.is_constructor and
            proc_info.is_this_expression(ri.expression)
        ):
            instrs.pop()
    return instrs


def _rewrite_returns(proc_decl, instrs):
    new_instructions = []
    i = 0
    while i < len(instrs):
        instr = instrs[i]
        if i + 1 < len(instrs):
            next_instr = instrs[i + 1]
        else:
            next_instr = None
        updated_instrs = _rewrite_return(proc_decl, instr, next_instr)
        if updated_instrs:
            new_instructions.extend(updated_instrs)
            i += 2
            continue
        new_instructions.append(instr)
        i += 1
    return new_instructions


def _rewrite_return(proc_decl, regdef, return_instr):
    if not isinstance(regdef, instructions.TemporaryRegisterDefinition):
        return
    if not isinstance(return_instr, instructions.ReturnInstruction):
        return
    if proc_decl is None:
        return
    if proc_decl.return_type is None:
        return
    data_type = proc_decl.return_type
    if (
        not isinstance(data_type, data_types.Pointer32) and
        not isinstance(data_type, data_types.Reference) and
        not isinstance(data_type, data_types.Int32) and
        not isinstance(data_type, data_types.UInt32)
    ):
        return
    return_value = regdef.pop_reg_value("eax")
    return_value = _convert_expression_to_type(return_value, data_type)
    new_instructions = []
    if not regdef.is_empty():
        new_instructions.append(regdef)
    new_instructions.append(instructions.ReturnInstruction(return_value))
    return new_instructions


def _convert_expression_to_type(e, target_type):
    src_type = e.data_type
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Pointer32)
    ):
        if _can_convert_pointees(src_type.pointee, target_type.pointee):
            return e
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Reference)
    ):
        if _can_convert_pointees(src_type.pointee, target_type.referent):
            return expressions.Dereference(e)
    if (
        isinstance(src_type, data_types.UInt32) and
        isinstance(target_type, data_types.UInt32)
    ):
        return e
    raise Exception("Can't convert {} to {}".format(src_type, target_type))


def _can_convert_pointees(src_type, target_type):
    if (
        isinstance(src_type, data_types.ClassType) and
        isinstance(target_type, data_types.ClassType)
    ):
        return src_type.class_name == target_type.class_name
    raise Exception("Can't convert {} to {}".format(src_type, target_type))
