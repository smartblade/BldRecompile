import data_types


class Access:
    def __init__(self, expression, offset, size):
        self._expression = expression
        self._offset = offset
        self._size = size

    @property
    def data_type(self):
        return data_types.unknown_types[self._size]

    @property
    def expression(self):
        return self._expression

    @property
    def offset(self):
        return self._offset

    @property
    def size(self):
        return self._size

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_access(
            expression, self._offset, self._size, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression, self._offset, self._size)

    def emit_code(self):
        return "ACCESS({}, {}, {})".format(
            self._expression.emit_code(),
            self._offset,
            self._size
        )
