from contextlib import contextmanager

class Writer:
    def __init__(self, indent_length=4):
        self._lines = []
        self._indent_length = indent_length
        self._indent = 0

    def write_line(self, line):
        self._lines.append(" " * self._indent * self._indent_length + line)

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
