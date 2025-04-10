from expressions.operator import Operator
import expressions.writer


class BitNot:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "BitNot({})".format(self._expression)

    @property
    def data_type(self):
        return self._expression.data_type

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_unary(Operator.BIT_NOT, expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self):
        return expressions.writer.write_unary(
            Operator.BIT_NOT, self._expression)
