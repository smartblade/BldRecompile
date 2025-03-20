import data_types
import expressions
from expressions.operator import Operator
import instructions


def try_build_post_increment(block_builder, reg):
    ass = block_builder.last_instruction
    if not isinstance(ass, instructions.Assignment):
        return None
    incremented_tuple = _extract_incremented_expression(ass)
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
    transformer = _Transformer(
        block_builder, replacing_expression, incremented_expression,
        increment_step)
    return reg_expression.transform(transformer.transform)


def _extract_incremented_expression(ass):
    b = ass.src
    if not isinstance(b, expressions.Bin):
        return None
    increment_operator = b.operator
    if (
        increment_operator != Operator.ADD and
        increment_operator != Operator.SUB
    ):
        return None
    if not b.left.data_type.is_any_int:
        return None
    if not b.right.data_type.is_any_int:
        return None
    right_const = b.right
    if not isinstance(right_const, expressions.Constant):
        return None
    left_cast = b.left
    if not isinstance(left_cast, expressions.ReinterpretCast):
        return None
    dst = ass.dst
    if not isinstance(dst, expressions.ProcedureCall):
        return None
    if not dst.is_predefined:
        return None
    left = left_cast.expression
    if not isinstance(left, expressions.ProcedureCall):
        return None
    if not left.is_predefined:
        return None
    if dst.emit_code() != left.emit_code():
        return None
    if increment_operator == Operator.ADD:
        step = right_const.value
    else:
        step = -right_const.value
    return dst, step


def _make_increment(incremented_expression, step):
    assert incremented_expression.data_type.size == 4
    abs_step = abs(step)
    if abs_step == 1:
        data_type = data_types.AnyInt32()
    elif abs_step == 2:
        data_type = data_types.Pointer32(data_types.AnyInt16())
    else:
        raise Exception("Unsupported increment step: {}.".format(step))
    cast = expressions.do_reinterpret(data_type, incremented_expression)
    if step > 0:
        return expressions.Increment(cast)
    else:
        return expressions.Decrement(cast)


class _Transformer:
    def __init__(
        self, block_builder, replacing_expression, incremented_expression,
        increment_step
    ):
        self._block_builder = block_builder
        self._replacing_expression = replacing_expression
        self._expression_replaced = False
        self._incremented_expression = incremented_expression
        self._increment_step = increment_step

    def transform(self, e):
        if not isinstance(e, expressions.ProcedureCall):
            return e
        if not e.is_predefined:
            return e
        if (
            self._replacing_expression is not None and
            e.emit_code() == self._replacing_expression.emit_code()
        ):
            assert not self._expression_replaced
            ass_instr = self._block_builder.pop_instruction()
            assert ass_instr.dst == self._replacing_expression
            self._expression_replaced = True
            src = ass_instr.src.transform(self.transform)
            return expressions.Bin(Operator.ASS, ass_instr.dst, src)
        elif e.emit_code() == self._incremented_expression.emit_code():
            return _make_increment(
                self._incremented_expression, self._increment_step)
        return e
