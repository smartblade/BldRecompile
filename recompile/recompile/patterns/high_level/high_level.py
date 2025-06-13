from expression_transformer import ExpressionTransformer
import patterns.high_level.analysis as analysis
import patterns.high_level.goto_eliminator as goto_eliminator
import patterns.high_level.inline_functions as inline_functions
from patterns.procedure import Procedure
from patterns.validate_procedure_declaration import \
    validate_procedure_declaration

from .call_arguments_matcher import CallArgumentsMatcher
from .transform_access import transform_access
from .transform_arrptr import transform_arrptr
from .transform_assignment import transform_assignment
from .transform_binary import transform_binary
from .transform_constant import transform_constant
from .transform_global import transform_global
from .transform_local import transform_local
from .transform_stackvar import transform_stackvar
from .transform_procedure_call import transform_procedure_call
from .transform_reinterpret import transform_reinterpret
from .transform_returns import transform_returns
from .variables_declarations import insert_declarations


def make_high_level_code(procedure, declarations, inline_procedures):
    proc_info = procedure.proc_info
    proc_decl = procedure.proc_decl
    if procedure.address is not None:
        file_declarations = declarations.symbols.get_file_declarations(
            procedure.address, declarations.files_declarations)
    else:
        file_declarations = None
    characteristics = declarations.characteristics[procedure.address]
    instrs = goto_eliminator.transform(procedure.instructions)
    stack_vars = procedure.implicit_stack_variables
    locals_analysis = analysis.LocalsAnalysis()
    context = dict(
        analysis=locals_analysis,
        cur_proc_addr=procedure.address,
        stack_vars=stack_vars,
        file_declarations=file_declarations,
        declarations=declarations,
        inline_procedures=inline_procedures,
    )
    instrs = _transform_instructions(instrs, **context)
    _validate_procedure_info(proc_info, proc_decl)
    if proc_decl is not None:
        instrs = _eliminate_procedure_info(proc_info, instrs)
    instrs = transform_returns(proc_info, proc_decl, characteristics, instrs)
    instrs = _transform_instructions(instrs, **context)
    locals_analysis.fill_stack_variables(
        stack_vars, characteristics.variables_names)
    instrs = _transform_instructions(instrs, **context)
    procedure = Procedure(proc_info, procedure.address, proc_decl, instrs)
    return insert_declarations(procedure, stack_vars)


def _transform_instructions(instrs, **kwargs):
    new_instructions = []
    call_args_matcher = CallArgumentsMatcher()
    for instr in instrs:
        instr = instr.transform(
            _ExpressionTransformer,
            call_args_matcher=call_args_matcher,
            **kwargs,
        )
        new_instructions.append(instr)
    call_args_matcher.expect_all_args_are_matched()
    return new_instructions


def _validate_procedure_info(proc_info, proc_decl):
    if proc_decl is None:
        return
    validate_procedure_declaration(
        proc_decl, proc_info.stack_delta, proc_info.is_thiscall)


def _eliminate_procedure_info(proc_info, instrs):
    if instrs[0] == proc_info:
        instrs.pop(0)
    return instrs


class _ExpressionTransformer(ExpressionTransformer):
    @staticmethod
    def transform_assignment(dst, src, **kwargs):
        return transform_assignment(dst, src, **kwargs)

    @staticmethod
    def transform_if(if_clause, if_block, else_block, **kwargs):
        return inline_functions.transform_if(if_clause, if_block, else_block)

    @staticmethod
    def transform_binary(operator, left, right, **kwargs):
        return transform_binary(operator, left, right, **kwargs)

    @staticmethod
    def transform_constant(c, **kwargs):
        return transform_constant(c, **kwargs)

    @staticmethod
    def transform_procedure_call(copy_pc, proc_name, arguments, **kwargs):
        return transform_procedure_call(copy_pc(), **kwargs)

    @staticmethod
    def transform_static_cast(data_type, expression, **kwargs):
        return inline_functions.transform_static_cast(
            data_type, expression, **kwargs)

    @staticmethod
    def transform_reinterpret_cast(data_type, expression, **kwargs):
        return transform_reinterpret(data_type, expression, **kwargs)

    @staticmethod
    def transform_access(*args, **kwargs):
        return transform_access(*args, **kwargs)

    @staticmethod
    def transform_arrptr(*args, **kwargs):
        return transform_arrptr(*args, **kwargs)

    @staticmethod
    def transform_global(*args, **kwargs):
        return transform_global(*args, **kwargs)

    @staticmethod
    def transform_local(*args, **kwargs):
        return transform_local(*args, **kwargs)

    @staticmethod
    def transform_stackvar(*args, **kwargs):
        return transform_stackvar(*args, **kwargs)

    @staticmethod
    def transform_block_instructions(block_instructions, **kwargs):
        inline_functions.transform_block_instructions(
            block_instructions, **kwargs)
