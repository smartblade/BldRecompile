class PatternText:
    def __init__(self, text):
        self._text = text

    def transform(self, transformer, **kwargs):
        e = transformer.transform_pattern_text(self._text, **kwargs)
        if e is not None:
            return e
        return self
