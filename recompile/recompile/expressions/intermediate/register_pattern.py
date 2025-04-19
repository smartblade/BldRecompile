class RegisterPattern:
    def __init__(self, pattern):
        self._pattern = pattern

    def transform(self, transformer, **kwargs):
        e = transformer.transform_register_pattern(self._pattern, **kwargs)
        if e is not None:
            return e
        return self
