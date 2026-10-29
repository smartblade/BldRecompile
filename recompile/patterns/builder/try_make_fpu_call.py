import data_types
import expressions
import instructions
from patterns.make_proc_decl_from_args import make_proc_decl_from_args

_fpu_calls = {
    "_CIsqrt": lambda **kwargs: _make_call(name="sqrt", **kwargs),
    "_CIsin": lambda **kwargs: _make_call(name="sin", **kwargs),
    "_CIcos": lambda **kwargs: _make_call(name="cos", **kwargs),
    "_ftol": lambda **kwargs: _make_ftl(**kwargs),
}


def try_make_fpu_call(block_builder, pc):
    if pc.name not in _fpu_calls:
        return False
    assert pc.proc_decl is None
    tmp_reg_def = block_builder.last_instruction
    assert isinstance(tmp_reg_def, instructions.TemporaryRegisterDefinition)
    arg = tmp_reg_def.pop_fpu()
    _fpu_calls[pc.name](tmp_reg_def=tmp_reg_def, pc=pc, arg=arg)
    return True


def _make_declaration(args):
    proc_decl = make_proc_decl_from_args(callee_cleanup=False, args=args)
    proc_decl.change_return_type(data_types.Double())
    return proc_decl


def _make_call(tmp_reg_def, pc, name, arg):
    pc = pc.copy(
        name=name,
        arguments=[arg],
        proc_decl=_make_declaration([arg]))
    tmp_reg_def.push_fpu(pc)


def _make_ftl(tmp_reg_def, arg, **kwargs):
    value = expressions.do_static_cast(data_types.Int32(), arg)
    tmp_reg_def.define_reg_value("eax", value)
