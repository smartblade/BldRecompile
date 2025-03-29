class Instruction:
    def __init__(self, command_name, command_code, operands):
        self._command_name = command_name
        self._command_code = command_code
        self._operands = operands

    def __repr__(self):
        return "{} {}".format(self._command_name, ", ".join(self._operands))

    @property
    def command_code(self):
        return self._command_code

    @property
    def operands(self):
        return self._operands
