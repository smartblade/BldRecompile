import data_types
import expressions.writer


class ConditionalOperator:
    def __init__(self, if_clause, then_expression, else_expression):
        self._if_clause = if_clause
        self._then_expression = then_expression
        self._else_expression = else_expression

    def __repr__(self):
        return "ConditionalOperator({}, {}, {})".format(
            self._if_clause, self._then_expression, self._else_expression)

    @property
    def if_clause(self):
        return self._if_clause

    @property
    def then_expression(self):
        return self._then_expression

    @property
    def else_expression(self):
        return self._else_expression

    @property
    def data_type(self):
        if data_types.are_compatible(
            self._then_expression.data_type, self._else_expression.data_type
        ):
            return self._else_expression.data_type
        elif data_types.are_compatible(
            self._else_expression.data_type, self._then_expression.data_type
        ):
            return self._then_expression.data_type
        else:
            assert data_types.are_same(
                self._then_expression.data_type,
                self._else_expression.data_type,
            )
        return self._then_expression.data_type

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        self._if_clause.visit(on_expression_visited, **kwargs)
        self._then_expression.visit(on_expression_visited, **kwargs)
        self._else_expression.visit(on_expression_visited, **kwargs)

    def transform(self, transformer, **kwargs):
        if_clause = self._if_clause.transform(transformer, **kwargs)
        then_expression = self._then_expression.transform(transformer, **kwargs)
        else_expression = self._else_expression.transform(transformer, **kwargs)
        e = transformer.transform_conditional_operator(
            if_clause, then_expression, else_expression, **kwargs)
        if e is not None:
            return e
        if (
            if_clause == self._if_clause and
            then_expression == self._then_expression and
            else_expression == self._else_expression
        ):
            return self
        return self.__class__(if_clause, then_expression, else_expression)

    def emit_code(self):
        return expressions.writer.write_conditional_operator(self)
