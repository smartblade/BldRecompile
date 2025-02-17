import data_types
import expressions
from expressions.operator import logical, Operator, priorities, is_associative


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

    def transform(self, transform_callback, **kwargs):
        left = self._left.transform(transform_callback, **kwargs)
        right = self._right.transform(transform_callback, **kwargs)
        bin_exp = BinaryExpression(self._operator, left, right)
        return transform_callback(bin_exp, **kwargs)

    def _emit_left(self):
        if not isinstance(self._left, BinaryExpression):
            return self._left
        if priorities[self.operator] >= priorities[self._left.operator]:
            return self._left
        return expressions.BracketsExpression(self._left)

    def _emit_right(self):
        if not isinstance(self._right, BinaryExpression):
            return self._right
        if priorities[self.operator] > priorities[self._right.operator]:
            return self._right
        if priorities[self.operator] < priorities[self._right.operator]:
            return expressions.BracketsExpression(self._right)
        if is_associative[self.operator]:
            return self._right
        else:
            return expressions.BracketsExpression(self._right)

    def emit_code(self):
        return "{} {} {}".format(
            self._emit_left().emit_code(),
            self._operator.value,
            self._emit_right().emit_code(),
        )
