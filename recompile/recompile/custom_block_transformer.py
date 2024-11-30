def transform_block(instructions, transform_callback, **kwargs):
    new_instructions = []
    for instruction in instructions:
        new_instructions.append(
            instruction.transform(transform_callback, **kwargs))
    return new_instructions
