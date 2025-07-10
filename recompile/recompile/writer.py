from contextlib import contextmanager

class Writer:
    def __init__(self, indent_length=4):
        self._lines = []
        self._indent_length = indent_length
        self._indent = 0

    @property
    def indent_length(self):
        return self._indent_length

    def write_line(self, line="", indent=None):
        indent = indent if indent is not None else self._indent
        if line:
            self._lines.append(" " * indent * self._indent_length + line)
        else:
            self._lines.append("")

    @contextmanager
    def indent(self):
        self._indent += 1
        try:
            yield self
        finally:
            self._unindent()

    def _unindent(self):
        self._indent -= 1

    def get_string(self):
        return "\n".join(self._lines) + "\n"
