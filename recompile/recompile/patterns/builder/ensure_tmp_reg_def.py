import instructions


def ensure_tmp_reg_def(block_builder):
    tmp_def = block_builder.last_instruction
    if not isinstance(tmp_def, instructions.TemporaryRegisterDefinition):
        tmp_def = instructions.TemporaryRegisterDefinition()
        block_builder.add_instruction(tmp_def)
    return tmp_def
