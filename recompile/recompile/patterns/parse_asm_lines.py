import re

asm_line_regexp = re.compile(r'^((?P<label>[gl][\dABCDEF]+):?\s+)?(?P<cmd>.+)$')


def parse_asm_lines(lines):
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
            new_lines.append("label {}".format(label))
        new_lines.append(command)
    return new_lines
