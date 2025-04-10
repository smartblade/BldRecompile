import data_types


class _Null:
    def transform_expression(self, **kwargs):
        return self

    @property
    def data_type(self):
        return data_types.NullptrType

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        return self

    @staticmethod
    def emit_code():
        return "nullptr"


Null = _Null()
