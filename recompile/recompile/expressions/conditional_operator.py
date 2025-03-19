import data_types


class ConditionalOperator:
    def __init__(self, if_clause, then_expression, else_expression):
        self._if_clause = if_clause
        self._then_expression = then_expression
        self._else_expression = else_expression

    def __repr__(self):
        return "ConditionalOperator({})".format(
            self._if_clause, self._then_expression, self._else_expression)

    @property
    def data_type(self):
        assert data_types.are_same(
            self._then_expression.data_type, self._else_expression.data_type)
        return self._then_expression.data_type

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._if_clause.visit(on_expression_visited, **kwargs)
        self._then_expression.visit(on_expression_visited, **kwargs)
        self._else_expression.visit(on_expression_visited, **kwargs)

    def transform(self, transform_callback, **kwargs):
        if_clause = self._if_clause.transform(transform_callback, **kwargs)
        then_expression = self._then_expression.transform(
            transform_callback, **kwargs)
        else_expression = self._else_expression.transform(
            transform_callback, **kwargs)
        if_instr = self.__class__(if_clause, then_expression, else_expression)
        return transform_callback(if_instr, **kwargs)

    def emit_code(self):
        return "{} ? {} : {}".format(
            self._if_clause.emit_code(),
            self._then_expression.emit_code(),
            self._else_expression.emit_code(),
        )
