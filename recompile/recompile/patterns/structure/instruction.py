class Instruction:
    def __init__(self, json, cmd_code_dict):
        command = next(iter(json.keys()))
        self._command_code = cmd_code_dict[command]
        assert self._command_code < 128
        self._operands = next(iter(json.values()))

    @property
    def command_code(self):
        return self._command_code

    @property
    def operands(self):
        return self._operands
