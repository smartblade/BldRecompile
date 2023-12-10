class FieldAccess:
    def __init__(self, expression, field_name):
        self._expression = expression
        self._field_name = field_name

    def __repr__(self):
        return "{}->{}".format(self._expression, self._field_name)

    @property
    def data_type(self):
        object_type = self._expression.data_type
        return object_type.pointee.find_data_type_by_field(self._field_name)

    @property
    def expression(self):
        return self._expression

    @property
    def field_name(self):
        return self._field_name

    def transform_expression(self, **kwargs):
        expression = self._expression.transform_expression(**kwargs)
        return FieldAccess(expression, self._field_name)

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._expression.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return "{}->{}".format(self._expression.emit_code(), self._field_name)
