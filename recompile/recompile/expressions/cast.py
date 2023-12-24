import data_types


class Cast:
    def __init__(self, data_type, expression):
        self._data_type = data_type
        self._expression = expression

    def __repr__(self):
        return "Cast({}, {})".format(self._data_type, self._expression)

    @property
    def data_type(self):
        return self._data_type

    @property
    def expression(self):
        return self._expression

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        cast = Cast(self._data_type, expression)
        if cast._is_implicit():
            return expression
        return cast

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        expression_code = self._expression.emit_code()
        type_name = self._data_type.get_type_name(is_metafile=False)
        return "({}) {}".format(type_name, expression_code)

    def _is_implicit(self):
        # Cast float -> double can be done implicitly
        if (
            isinstance(self._data_type, data_types.Double) and
            isinstance(self._expression.data_type, data_types.Float)
        ):
            return True
        return False
