import data_types
import expressions


class ReinterpretCast:
    def __init__(self, data_type, expression):
        self._data_type = data_type
        self._expression = expression

    def __repr__(self):
        return "ReinterpretCast({}, {})".format(
            self._data_type, self._expression)

    @property
    def data_type(self):
        return self._data_type

    @property
    def expression(self):
        return self._expression

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_reinterpret_cast(
            self._data_type, expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(self._data_type, expression)

    def emit_code(self):
        expression_code = self._expression.emit_code()
        type_name = self._data_type.get_type_name(is_metafile=False)
        return "reinterpret_cast<{}>({})".format(type_name, expression_code)
