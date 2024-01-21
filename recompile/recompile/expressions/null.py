class _Null:
    def transform_expression(self, **kwargs):
        return self

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    @staticmethod
    def emit_code():
        return "NULL"


Null = _Null()
