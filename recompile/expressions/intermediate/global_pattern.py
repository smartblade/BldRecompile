class GlobalPattern:
    def __init__(self, pattern_variable_name):
        self._pattern_variable_name = pattern_variable_name

    def transform(self, transformer, **kwargs):
        e = transformer.transform_global_pattern(
            self._pattern_variable_name, **kwargs)
        if e is not None:
            return e
        return self
