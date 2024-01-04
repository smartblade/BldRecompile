class Dereference:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "Deref({})".format(self._expression)

    def emit_code(self):
        return "*{}".format(self._expression.emit_code())
