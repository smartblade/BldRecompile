import expressions
import instructions

from .extract_incremented_expression import extract_incremented_expression
from .transform_to_increment import transform_to_increment


def try_build_post_increment(block_builder, reg):
    ass = block_builder.last_instruction
    if not isinstance(ass, instructions.Assignment):
        return None
    incremented_tuple = extract_incremented_expression(ass)
    if incremented_tuple is None:
        return None
    incremented_expression, increment_step = incremented_tuple
    block_builder.pop_instruction()
    tmpdef = block_builder.last_instruction
    if not isinstance(tmpdef, instructions.TemporaryRegisterDefinition):
        raise Exception(
            "Expected to be TemporaryRegisterDefinition but was: {}.".format(
                tmpdef
            )
        )
    reg_expression = block_builder.pop_reg_value(reg)
    replacing_expression = None
    if isinstance(block_builder.last_instruction, instructions.Assignment):
        replacing_expression = block_builder.last_instruction.dst
        if not isinstance(replacing_expression, expressions.ProcedureCall):
            replacing_expression = None
        if not replacing_expression.is_predefined:
            replacing_expression = None
    return transform_to_increment(
        reg_expression,
        block_builder=block_builder,
        replacing_expression=replacing_expression,
        incremented_expression=incremented_expression,
        increment_step=increment_step,
        pre_increment=False,
    )
