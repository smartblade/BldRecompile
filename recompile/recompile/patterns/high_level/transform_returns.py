import data_types
import expressions
import instructions

from .convert_expression_to_type import convert_expression_to_type


def transform_returns(proc_info, proc_decl, instrs):
    instrs = _rewrite_returns(proc_decl, instrs)
    instrs = _eliminate_unnecessary_returns(proc_info, proc_decl, instrs)
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
    return_value = convert_expression_to_type(return_value, data_type)
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
    return_value = convert_expression_to_type(pc, data_type)
    new_instructions = [instructions.ReturnInstruction(return_value)]
    return new_instructions


def _is_eax_return_type(data_type):
    return (
        isinstance(data_type, data_types.Pointer32) or
        isinstance(data_type, data_types.Reference) or
        isinstance(data_type, data_types.Int32) or
        isinstance(data_type, data_types.UInt32)
    )
