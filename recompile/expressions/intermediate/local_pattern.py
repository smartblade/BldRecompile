class LocalPattern:
    def __init__(self, expression):
        self._expression = expression

    def transform(self, transformer, **kwargs):
        e = transformer.transform_local_pattern(self._expression, **kwargs)
        if e is not None:
            return e
        return self
