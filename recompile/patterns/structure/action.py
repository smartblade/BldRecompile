from .expression_pattern import ExpressionPattern


class Action:
    def __init__(self, json):
        self._name = next(iter(json.keys()))
        arguments = next(iter(json.values()))
        self._arguments = {}
        for name, expression in arguments.items():
            self._arguments[name] = ExpressionPattern(expression)

    @property
    def name(self):
        return self._name

    @property
    def arguments(self):
        return self._arguments
