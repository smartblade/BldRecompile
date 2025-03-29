import re

from .instruction import Instruction

asm_line_regexp = re.compile(r'^((?P<label>[gl][\dABCDEF]+):?\s+)?(?P<cmd>.+)$')
command_regexp = re.compile(r'^(?P<cmd>\w+)(\s+(?P<operands>.+))?$')


def parse_asm_lines(lines, cmd_code_dict):
    new_lines = []
    for line in lines:
        if line.startswith(";"):
            continue
        match = re.search(asm_line_regexp, line)
        if not match:
            raise Exception("Can't parse line: {}".format(line))
        label = match.group("label")
        command = match.group("cmd")
        if label is not None:
            new_lines.append(
                _parse_command_line("label {}".format(label), cmd_code_dict))
        new_lines.append(_parse_command_line(command, cmd_code_dict))
    return new_lines


def _parse_command_line(line, cmd_code_dict):
    line = _add_size_to_call_operand(line)
    match = re.search(command_regexp, line)
    if not match:
        raise Exception("Can't parse line: {}".format(line))
    cmd_name = match.group("cmd")
    cmd_code = cmd_code_dict[cmd_name]
    operands_str = match.group("operands")
    if operands_str is not None:
        operands = operands_str.split(",")
    else:
        operands = []
    for operand_index in range(len(operands)):
        operands[operand_index] = operands[operand_index].strip()
    return Instruction(cmd_name, cmd_code, operands)


def _add_size_to_call_operand(line):
    if not line.startswith("call"):
        return line
    return line.replace("call [", "call dword ptr [")
