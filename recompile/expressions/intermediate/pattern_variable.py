class PatternVariable:
    def __init__(self, variable_name):
        self._variable_name = variable_name

    @property
    def variable_name(self):
        return self._variable_name

    def transform(self, transformer, **kwargs):
        e = transformer.transform_pattern_variable(
            self._variable_name, **kwargs)
        if e is not None:
            return e
        return self
