from .make_operand import make_operand


class Instruction:
    def __init__(self, json, operand_sets, cmd_code_dict):
        command = next(iter(json.keys()))
        self._command_code = cmd_code_dict[command]
        assert self._command_code < 128
        self._operands = []
        for operand in next(iter(json.values())):
            self._operands.append(make_operand(operand, operand_sets))

    @property
    def command_code(self):
        return self._command_code

    @property
    def operands(self):
        return self._operands
