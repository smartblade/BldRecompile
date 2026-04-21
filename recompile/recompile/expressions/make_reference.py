import data_types
import expressions
import expressions.writer


class MakeReference:
    def __init__(self, expression):
        assert isinstance(
            expression, (
                expressions.Identifier,
                expressions.FieldAccess,
                expressions.Dereference,
            )
        )
        assert not isinstance(expression.data_type, data_types.Reference)
        self._expression = expression

    def __repr__(self):
        return "Ref({})".format(self._expression)

    @property
    def expression(self):
        return self._expression

    @property
    def data_type(self):
        return data_types.Reference(self._expression.data_type)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_make_reference(expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self):
        return self._expression.emit_code()
