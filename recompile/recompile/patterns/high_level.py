import parser
from calling_convention import CallingConvention
import data_types
import instructions
import expressions
from patterns.predefined_procedures import visit_predefined_procedures
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration


def make_high_level_code(proc_info, proc_decl, declarations, instrs):
    stack_vars = proc_info.stack_variables
    if proc_decl is not None:
        stack_vars.update(proc_decl.stack_variables)
    new_instructions = []
    for instr in instrs:
        instr = instr.transform(
            lambda e: _transform(
                e, stack_vars=stack_vars, declarations=declarations))
        new_instructions.append(instr)
    _validate_procedure_info(proc_info, proc_decl)
    if proc_decl is not None:
        new_instructions = _eliminate_procedure_info(
            proc_info, new_instructions)
    new_instructions = _rewrite_returns(proc_decl, new_instructions)
    new_instructions = _eliminate_unnecessary_returns(
        proc_info, proc_decl, new_instructions)
    return new_instructions


def _transform(e, **kwargs):
    if isinstance(e, instructions.Assignment):
        return _transform_assignment(e, **kwargs)
    e = visit_predefined_procedures(
        e, **kwargs,
        on_stackvar=_transform_stackvar,
        on_access=_transform_access,
        on_global=_transform_global,
    )
    if isinstance(e, expressions.ProcedureCall):
        return _transform_procedure_call(e, **kwargs)
    return e


def _transform_stackvar(offset, size, stack_vars, **kwargs):
    variable = stack_vars.get(offset)
    if variable is not None and variable.data_type.size == size:
        return variable
    return None


def _transform_access(expression, offset, size, **kwargs):
    data_type = expression.data_type
    if isinstance(data_type, data_types.Unknown32):
        return None
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
    if isinstance(pointee, (data_types.Int32, data_types.UInt32)):
        if pointee.size != size:
            raise Exception(
                "Data type size expected to be {} but was: {}.".format(
                    size, pointee.size))
        if offset != 0:
            raise Exception(
                "Data access offset expected to be {} but was: {}.".format(
                    0, offset))
        return expressions.do_dereference(expression)
    return None


def _transform_global(address, declarations, **kwargs):
    global_var = declarations.symbols.variables.get(address)
    if global_var is not None and global_var.declaration is not None:
        var_type, var_name = parser.parse_cpp_variable_declaration(
            global_var.declaration.strip().strip(";"),
            declarations.declared_types,
        )
        return expressions.AddressOf(expressions.Identifier(var_type, var_name))
    return None


def _transform_assignment(ass, **kwargs):
    src = _convert_expression_to_type(ass.src, ass.dst.data_type)
    return instructions.Assignment(ass.dst, src)


def _transform_procedure_call(pc, declarations, **kwargs):
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
    for i, parameter in enumerate(proc_decl.get_parameters_ids().values()):
        new_argument = _convert_expression_to_type(
            pc.arguments[i], parameter.data_type)
        new_arguments.append(new_argument)
    return new_arguments


def _validate_procedure_info(proc_info, proc_decl):
    if proc_decl is None:
        return
    validate_procedure_declaration(
        proc_decl, proc_info.stack_delta, proc_info.is_thiscall)


def _eliminate_procedure_info(proc_info, instrs):
    if instrs[0] == proc_info:
        instrs.pop(0)
    return instrs


def _eliminate_unnecessary_returns(proc_info, proc_decl, instrs):
    ri = instrs[-1]
    if isinstance(ri, instructions.ReturnInstruction):
        if (
            ri.expression is None or
            proc_decl is not None and
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
        updated_instrs = _rewrite_return_from_last_call(
            proc_decl, instr, next_instr)
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
    if return_instr.expression is not None:
        return
    if proc_decl is None:
        return
    if proc_decl.return_type is None:
        return
    data_type = proc_decl.return_type
    if not _is_eax_return_type(data_type):
        return
    return_value = regdef.pop_reg_value("eax")
    return_value = _convert_expression_to_type(return_value, data_type)
    new_instructions = []
    if not regdef.is_empty():
        new_instructions.append(regdef)
    new_instructions.append(instructions.ReturnInstruction(return_value))
    return new_instructions


def _rewrite_return_from_last_call(proc_decl, instr, return_instr):
    if not isinstance(instr, instructions.CodeInstruction):
        return
    pc = instr.expression
    if not isinstance(pc, expressions.ProcedureCall):
        return
    if not isinstance(return_instr, instructions.ReturnInstruction):
        return
    if return_instr.expression is not None:
        return
    if proc_decl is not None:
        return
    if pc.proc_decl is None:
        return
    if pc.proc_decl.return_type is None:
        return
    data_type = pc.proc_decl.return_type
    if not _is_eax_return_type(data_type):
        return
    return_value = _convert_expression_to_type(pc, data_type)
    new_instructions = [instructions.ReturnInstruction(return_value)]
    return new_instructions


def _is_eax_return_type(data_type):
    return (
        isinstance(data_type, data_types.Pointer32) or
        isinstance(data_type, data_types.Reference) or
        isinstance(data_type, data_types.Int32) or
        isinstance(data_type, data_types.UInt32)
    )


def _convert_expression_to_type(e, target_type):
    src_type = e.data_type
    if src_type.size != target_type.size:
        raise Exception("Can't convert {}(size: {}) to {}(size: {}).".format(
            src_type, src_type.size, target_type, target_type.size))
    if data_types.are_compatible(src_type, target_type):
        return e
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Pointer32)
    ):
        converted = _convert_pointees(e, src_type.pointee, target_type.pointee)
        if converted is not None:
            return converted
    if (
        isinstance(src_type, data_types.Pointer32) and
        isinstance(target_type, data_types.Reference)
    ):
        converted = _convert_pointees(e, src_type.pointee, target_type.referent)
        if converted is not None:
            return expressions.Dereference(converted)
    if (
        isinstance(src_type, data_types.Reference) and
        isinstance(target_type, data_types.Pointer32)
    ):
        converted = _convert_pointees(e, src_type.referent, target_type.pointee)
        if converted is not None:
            return expressions.AddressOf(converted)
    if (
        isinstance(src_type, data_types.Unknown32) and
        not isinstance(target_type, data_types.Unknown32)
    ):
        return expressions.do_reinterpret(target_type, e)
    raise Exception("Can't convert {} to {}.".format(src_type, target_type))


def _convert_pointees(e, src_type, target_type):
    if (
        data_types.are_compatible(
            data_types.Pointer32(src_type),
            data_types.Pointer32(target_type),
        )
    ):
        return e
    if src_type is None:
        return expressions.do_reinterpret(data_types.Pointer32(target_type), e)
    raise Exception("Can't convert {} to {}".format(src_type, target_type))
