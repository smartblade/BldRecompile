import data_types
from expressions.operator import Operator
import expressions.writer


class Dereference:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Deref({})".format(self._expression)

    @property
    def data_type(self):
        data_type = self._expression.data_type
        assert isinstance(data_type, data_types.Pointer32)
        return data_type.pointee

    @property
    def expression(self):
        return self._expression

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_unary(Operator.DEREF, expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self):
        return expressions.writer.write_unary(Operator.DEREF, self._expression)
