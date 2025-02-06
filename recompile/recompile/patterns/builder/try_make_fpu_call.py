import data_types
import instructions
from patterns.make_proc_decl_from_args import make_proc_decl_from_args

_fpu_calls = {
    "_CIsqrt": "sqrt",
    "_CIsin": "sin",
    "_CIcos": "cos",
}


def try_make_fpu_call(block_builder, pc):
    if pc.name not in _fpu_calls:
        return False
    assert pc.proc_decl is None
    tmp_reg_def = block_builder.last_instruction
    assert isinstance(tmp_reg_def, instructions.TemporaryRegisterDefinition)
    arg = tmp_reg_def.pop_fpu()
    pc = pc.copy(
        name=_fpu_calls[pc.name],
        arguments=[arg],
        proc_decl=_make_declaration([arg]))
    tmp_reg_def.push_fpu(pc)
    return True


def _make_declaration(args):
    proc_decl = make_proc_decl_from_args(
        is_method=False, args=args)
    proc_decl.change_return_type(data_types.Double())
    return proc_decl
