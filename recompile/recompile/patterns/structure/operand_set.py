from patterns.apply_pattern import replace_variables


class OperandSet:
    def __init__(self, name, patterns):
        self._name = name
        self._patterns = patterns

    @property
    def name(self):
        return self._name

    @property
    def patterns(self):
        return self._patterns

    def match(self, operand, operand_size):
        for pattern, expression in self._patterns:
            match_dict = pattern.match(operand, operand_size)
            if match_dict is not None:
                return {self._name: replace_variables(expression, match_dict)}
        return None
