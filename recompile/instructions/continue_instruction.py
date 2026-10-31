class Continue:
    def __repr__(self):
        return "Continue"

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        return self

    @staticmethod
    def emit_code(writer):
        writer.write_line("continue;")
