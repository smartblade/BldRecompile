import re

from hex_conversion import from_hex

labeled_instr_regexp = re.compile(r'^g(?P<addr>[\dABCDEF]+)\s+(?P<instr>.+)')
variable_regexp = re.compile(r'g(?P<addr>[\dABCDEF]+)')


def collect_string_constants(code_lines):
    variables_count = {}
    string_constants = {}
    prev_label_addr = None
    current_label_addr = None
    current_bytes = []
    for line in code_lines:
        if line.startswith(";"):
            continue
        if line.startswith("l"):
            current_label_addr = None
        match = labeled_instr_regexp.search(line)
        if match:
            new_label_addr = from_hex(match.group("addr"))
            if current_label_addr is not None:
                s = _bytes_to_string(current_bytes)
                if s is not None:
                    string_constants[current_label_addr] = s
            if variables_count.get(new_label_addr) == 1:
                if (
                    current_label_addr is not None and
                    (
                        new_label_addr - prev_label_addr == 2 or
                        new_label_addr - prev_label_addr == 4
                    ) and
                    (
                        len(current_bytes) ==
                        new_label_addr - current_label_addr
                    ) and
                    current_bytes[-1] != 0
                ):
                    prev_label_addr = new_label_addr
                else:
                    current_label_addr = new_label_addr
                    prev_label_addr = new_label_addr
                    current_bytes = []
                line = match.group("instr")
            else:
                current_label_addr = None
        if current_label_addr is not None:
            _parse_data_line(line.strip(), current_bytes)
            if not current_bytes:
                current_label_addr = None
            else:
                continue
        match = variable_regexp.search(line)
        while match:
            variable_addr = from_hex(match.group("addr"))
            variable_count = variables_count.get(variable_addr, 0)
            variables_count[variable_addr] = variable_count + 1
            match = variable_regexp.search(line, pos=match.end())
    return string_constants


def _parse_data_line(line, current_bytes):
    if line.startswith("dd"):
        _parse_32_bit_data(line[2:].strip(), current_bytes)
        return
    if line.startswith("db"):
        _parse_8_bit_data(line[2:].strip(), current_bytes)
        return
    raise Exception("Can't parse data line: '{}'.".format(line))


def _parse_32_bit_data(line, current_bytes):
    if line.startswith("l") or line.startswith("g"):
        current_bytes.clear()
        return
    if _is_dup(line):
        current_bytes.clear()
        return
    assert line[0] == '0' and line[-1] == 'h' and len(line) == 10
    for i in range(4):
        current_bytes.append(from_hex(line[-2 * i - 3: -2 * i - 1]))


def _parse_8_bit_data(line, current_bytes):
    assert line[0] == '0' and line[-1] == 'h' and len(line) == 4
    current_bytes.append(from_hex(line[1:3]))


def _is_dup(line):
    return line[0] != '0' and 'dup' in line


def _bytes_to_string(bytes_list):
    if not bytes_list:
        return None
    null_terminated = False
    while len(bytes_list) > 0 and bytes_list[-1] == 0:
        null_terminated = True
        bytes_list.pop()
    if not null_terminated:
        return None
    chars = []
    for byte in bytes_list:
        if not _is_ascii(byte):
            return None
        chars.append(_byte_to_char(byte))
    return "".join(chars)


def _is_ascii(byte):
    if 32 <= byte <= 126:
        return True
    if byte == 10:
        return True
    return False


def _byte_to_char(byte):
    if byte == 10:
        return "\\n"
    return chr(byte)
