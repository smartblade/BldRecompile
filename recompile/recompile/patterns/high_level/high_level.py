import instructions
import expressions
import patterns.high_level.goto_eliminator as goto_eliminator
import patterns.high_level.inline_functions as inline_functions
from patterns.predefined_procedures import make_predefined_procedure_visitor
from patterns.predefined_procedures import visit_predefined_procedures
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration

from .call_arguments_matcher import CallArgumentsMatcher
from .transform_access import transform_access
from .transform_arrptr import transform_arrptr
from .transform_assignment import transform_assignment
from .transform_binary import transform_binary
from .transform_global import transform_global
from .transform_stackvar import transform_stackvar
from .transform_procedure_call import transform_procedure_call
from .transform_reinterpret import transform_reinterpret
from .transform_returns import transform_returns


def make_high_level_code(
    proc_info, proc_decl, characteristics, declarations, instrs
):
    instrs = goto_eliminator.transform(instrs)
    stack_vars = proc_info.stack_variables
    if proc_decl is not None:
        stack_vars.update(proc_decl.stack_variables)
    instrs = _transform_instructions(
        instrs, stack_vars=stack_vars, declarations=declarations)
    _validate_procedure_info(proc_info, proc_decl)
    if proc_decl is not None:
        instrs = _eliminate_procedure_info(proc_info, instrs)
    instrs = transform_returns(proc_info, proc_decl, characteristics, instrs)
    instrs = _transform_instructions(
        instrs, stack_vars=stack_vars, declarations=declarations)
    return instrs


def _transform_instructions(instrs, **kwargs):
    new_instructions = []
    call_args_matcher = CallArgumentsMatcher()
    for instr in instrs:
        instr = instr.transform(
            lambda e: _transform(
                e,
                call_args_matcher=call_args_matcher,
                **kwargs,
            )
        )
        new_instructions.append(instr)
    call_args_matcher.expect_all_args_are_matched()
    return new_instructions


def _transform(e, **kwargs):
    if isinstance(e, instructions.Assignment):
        return transform_assignment(e, **kwargs)
    if isinstance(e, expressions.Bin):
        return transform_binary(e, **kwargs)
    if isinstance(e, expressions.ReinterpretCast):
        return transform_reinterpret(e, **kwargs)
    if isinstance(e, expressions.StaticCast):
        return expressions.do_static_cast(e.data_type, e.expression)
    if isinstance(e, instructions.IfInstruction):
        return inline_functions.transform_if(e)
    if isinstance(e, expressions.ProcedureCall) and not e.is_predefined:
        return transform_procedure_call(e, **kwargs)
    e = visit_predefined_procedures(
        e, _predefined_procedure_visitor, **kwargs,
    )
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


_predefined_procedure_visitor = make_predefined_procedure_visitor(
    on_stackvar=transform_stackvar,
    on_access=transform_access,
    on_global=transform_global,
    on_arrptr=transform_arrptr,
)
