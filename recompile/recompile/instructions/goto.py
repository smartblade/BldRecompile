class Goto:
    def __init__(self, label):
        self._label = label

    def __repr__(self):
        return "Goto({})".format(self._label)

    @property
    def label(self):
        return self._label

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transform_callback, **kwargs):
        return transform_callback(self, **kwargs)

    def emit_code(self, writer):
        writer.write_line("goto {};".format(self._label))
