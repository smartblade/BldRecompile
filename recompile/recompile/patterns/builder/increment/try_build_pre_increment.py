import instructions

from .extract_incremented_expression import extract_incremented_expression
from .transform_to_increment import transform_to_increment


def try_build_pre_increment(block_builder, expression):
    ass = block_builder.last_instruction
    if not isinstance(ass, instructions.Assignment):
        return None
    incremented_tuple = extract_incremented_expression(ass)
    if incremented_tuple is None:
        return None
    incremented_expression, increment_step = incremented_tuple
    block_builder.pop_instruction()
    return transform_to_increment(
        expression,
        block_builder=block_builder,
        replacing_expression=None,
        incremented_expression=incremented_expression,
        increment_step=increment_step,
        pre_increment=True,
    )
