import data_types
import expressions
from expression_transformer import ExpressionTransformer
from expressions.operator import Operator


def transform_to_increment(expression, **kwargs):
    transformer = _Transformer(**kwargs)
    e = expression.transform(transformer)
    transformer.validate()
    return e


def _make_increment(incremented_expression, step, pre_increment):
    assert incremented_expression.data_type.size == 4
    abs_step = abs(step)
    if abs_step == 1:
        data_type = data_types.AnyInt32()
    elif abs_step == 2:
        data_type = data_types.Pointer32(data_types.AnyInt16())
    else:
        raise Exception("Unsupported increment step: {}.".format(step))
    cast = expressions.do_reinterpret(data_type, incremented_expression)
    if pre_increment:
        if step > 0:
            return expressions.PreIncrement(cast)
        raise Exception("Unsupported increment step: {}.".format(step))
    else:
        if step > 0:
            return expressions.Increment(cast)
        else:
            return expressions.Decrement(cast)


class _Transformer(ExpressionTransformer):
    def __init__(
        self, block_builder, replacing_expression, incremented_expression,
        increment_step, pre_increment,
    ):
        self._block_builder = block_builder
        self._replacing_expression = replacing_expression
        self._expression_replaced = False
        self._incremented_expression = incremented_expression
        self._increment_created = False
        self._increment_step = increment_step
        self._pre_increment = pre_increment

    def transform_procedure_call(
        self, copy_pc, is_predefined, **kwargs
    ):
        if not is_predefined:
            return None
        pc = copy_pc()
        if (
            self._replacing_expression is not None and
            pc.emit_code() == self._replacing_expression.emit_code()
        ):
            assert not self._expression_replaced
            ass_instr = self._block_builder.pop_instruction()
            assert ass_instr.dst == self._replacing_expression
            self._expression_replaced = True
            src = ass_instr.src.transform(self)
            return expressions.Bin(Operator.ASS, ass_instr.dst, src)
        elif pc.emit_code() == self._incremented_expression.emit_code():
            assert not self._increment_created
            self._increment_created = True
            return _make_increment(
                self._incremented_expression, self._increment_step,
                self._pre_increment)
        return None

    def validate(self):
        if not self._increment_created:
            raise Exception("Increment was not created.")
