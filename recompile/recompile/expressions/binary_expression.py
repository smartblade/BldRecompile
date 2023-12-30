import data_types


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
        left_type = self._left.data_type
        right_type = self._right.data_type
        if (
            isinstance(left_type, data_types.Double) and
            isinstance(right_type, data_types.Double)
        ):
            return left_type
        if (
            isinstance(left_type, data_types.Float) and
            isinstance(right_type, data_types.Double)
        ):
            return right_type
        if (
            isinstance(left_type, data_types.Float) and
            isinstance(right_type, data_types.Float)
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

    def emit_code(self):
        return "{} {} {}".format(
            self._left.emit_code(),
            self._operator.value,
            self._right.emit_code(),
        )
