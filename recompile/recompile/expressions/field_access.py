import expressions

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

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_field_access(
            expression, self._field_name, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression, self._field_name)

    def emit_code(self):
        expression = self._expression
        if isinstance(expression, expressions.AddressOf):
            expression = expression.expression
            sep = "."
        else:
            sep = "->"
        if isinstance(expression, expressions.Bin):
            expression = expressions.BracketsExpression(expression)
        return "{}{}{}".format(expression.emit_code(), sep, self._field_name)
