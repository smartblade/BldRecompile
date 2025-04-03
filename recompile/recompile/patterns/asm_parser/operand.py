import re

operand_regexp = re.compile(
    r'^(?P<size>(byte|word|dword|qword|near)\s+ptr\s+)?(?P<operand>.+)$')


class Operand:
    def __init__(self, operand):
        match = re.search(operand_regexp, operand)
        self._asm = match.group("operand")
        self._size = _get_operand_size(match.group("size"))

    @property
    def asm(self):
        return self._asm

    @property
    def size(self):
        return self._size


def _get_operand_size(s):
    if s is None:
        return None
    if s.startswith("byte"):
        return 1
    if s.startswith("word"):
        return 2
    if s.startswith("dword"):
        return 4
    if s.startswith("qword"):
        return 8
    if s.startswith("near"):
        return None
    raise Exception("Unknown operand size: {}.".format(s))