import instructions
import expressions
from patterns.predefined_procedures import visit_predefined_procedures
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration

from .transform_access import transform_access
from .transform_arrptr import transform_arrptr
from .transform_assignment import transform_assignment
from .transform_binary import transform_binary
from .transform_global import transform_global
from .transform_stackvar import transform_stackvar
from .transform_procedure_call import transform_procedure_call
from .transform_returns import transform_returns


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
    new_instructions = transform_returns(proc_info, proc_decl, new_instructions)
    return new_instructions


def _transform(e, **kwargs):
    if isinstance(e, instructions.Assignment):
        return transform_assignment(e, **kwargs)
    if isinstance(e, expressions.Bin):
        return transform_binary(e, **kwargs)
    if isinstance(e, expressions.ReinterpretCast):
        return expressions.do_reinterpret(e.data_type, e.expression)
    e = visit_predefined_procedures(
        e, **kwargs,
        on_stackvar=transform_stackvar,
        on_access=transform_access,
        on_global=transform_global,
        on_arrptr=transform_arrptr,
    )
    if isinstance(e, expressions.ProcedureCall):
        return transform_procedure_call(e, **kwargs)
    return e


def _validate_procedure_info(proc_info, proc_decl):
    if proc_decl is None:
        return
    validate_procedure_declaration(
        proc_decl, proc_info.stack_delta, proc_info.is_thiscall)


def _eliminate_procedure_info(proc_info, instrs):
    if instrs[0] == proc_info:
        instrs.pop(0)
    return instrs
