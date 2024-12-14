import instructions

_fpu_calls = {
    "_CIsqrt": "sqrt",
    "_CIsin": "sin",
    "_CIcos": "cos",
}


def try_make_fpu_call(block_builder, pc):
    if pc.name not in _fpu_calls:
        return False
    tmp_reg_def = block_builder.last_instruction
    assert isinstance(tmp_reg_def, instructions.TemporaryRegisterDefinition)
    arg = tmp_reg_def.pop_fpu()
    pc = pc.copy(name=_fpu_calls[pc.name], arguments=[arg])
    tmp_reg_def.push_fpu(pc)
    return True
