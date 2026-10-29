class Real64Pattern:
    def __init__(self, high_variable_name, low_variable_name):
        self._high_variable_name = high_variable_name
        self._low_variable_name = low_variable_name

    def transform(self, transformer, **kwargs):
        e = transformer.transform_real64_pattern(
            self._high_variable_name, self._low_variable_name, **kwargs)
        if e is not None:
            return e
        return self
