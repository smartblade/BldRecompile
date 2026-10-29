class RegisterValue:
    def __init__(self, reg):
        self._reg = reg

    def transform(self, transformer, **kwargs):
        e = transformer.transform_register_value(self._reg, **kwargs)
        if e is not None:
            return e
        return self
