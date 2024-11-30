class Goto:
    def __init__(self, label):
        self._label = label

    def __repr__(self):
        return "Goto({})".format(self._label)

    def transform(self, transform_callback, **kwargs):
        return transform_callback(self, **kwargs)

    def emit_code(self, writer):
        writer.write_line("goto {};".format(self._label))
