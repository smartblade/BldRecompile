from .make_regexp_pattern import make_regexp_pattern


class Operand:
    def __init__(self, operand_pattern):
        self._pattern = make_regexp_pattern(operand_pattern)

    def match(self, operand, operand_size):
        return self._pattern.match(operand, operand_size)
