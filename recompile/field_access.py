class FieldAccess:
    def __init__(self, expression, field_name):
        self._expression = expression
        self._field_name = field_name

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

    def emit_code(self):
        return "{}->{}".format(self._expression.emit_code(), self._field_name)
