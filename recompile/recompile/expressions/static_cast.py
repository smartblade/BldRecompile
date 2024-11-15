class StaticCast:
    def __init__(self, data_type, expression):
        self._data_type = data_type
        self._expression = expression

    def __repr__(self):
        return "StaticCast({}, {})".format(
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

    def transform(self, transform_callback, **kwargs):
        expression = self._expression.transform(transform_callback, **kwargs)
        cast = StaticCast(self._data_type, expression)
        return transform_callback(cast, **kwargs)

    def emit_code(self):
        expression_code = self._expression.emit_code()
        type_name = self._data_type.get_type_name(is_metafile=False)
        return "static_cast<{}>({})".format(type_name, expression_code)
