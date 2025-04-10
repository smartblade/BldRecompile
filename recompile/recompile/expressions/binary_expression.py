import data_types
import expressions
from expressions.operator import logical, Operator
import expressions.writer


class BinaryExpression:
    def __init__(self, operator, left, right):
        self._operator = operator
        self._left = left
        self._right = right

    def __repr__(self):
        return "Bin({} {} {})".format(
            self._left, self._operator.value, self._right
        )

    @property
    def data_type(self):
        if self._operator in logical:
            return data_types.Bool()
        left_type = self._left.data_type
        right_type = self._right.data_type
        if self._operator in [Operator.SHL, Operator.SHR, Operator.ASS]:
            return left_type
        if (
            isinstance(left_type, (data_types.Float, data_types.Double)) and
            isinstance(right_type, (data_types.Float, data_types.Double))
        ):
            if data_types.are_same(left_type, right_type):
                return left_type
            return data_types.Double()
        if (
            left_type.is_any_int and
            right_type.is_any_int
        ):
            if data_types.are_same(left_type, right_type):
                return left_type
            if isinstance(self._right, expressions.Constant):
                return left_type
            if isinstance(self._left, expressions.Constant):
                return right_type
            if left_type.size == right_type.size:
                return data_types.AnyInt(left_type.size)
        if (
            self._operator == Operator.ADD and
            isinstance(left_type, data_types.Pointer32) and
            isinstance(right_type, data_types.Int32)
        ):
            return left_type
        raise Exception("Can't union {} and {}".format(left_type, right_type))

    @property
    def operator(self):
        return self._operator

    @property
    def left(self):
        return self._left

    @property
    def right(self):
        return self._right

    def transform_expression(self, **kwargs):
        left = self._left.transform_expression(**kwargs)
        right = self._right.transform_expression(**kwargs)
        return BinaryExpression(self._operator, left, right)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._left.visit(on_expression_visited, **kwargs)
        self._right.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        left = self._left.transform(transformer, **kwargs)
        right = self._right.transform(transformer, **kwargs)
        e = transformer.transform_binary(
            self._operator, left, right, **kwargs)
        if e is not None:
            return e
        if left == self._left and right == self._right:
            return self
        return self.__class__(self._operator, left, right)

    def emit_code(self):
        return expressions.writer.write_binary(
            self._operator,
            self._left,
            self._right,
        )
