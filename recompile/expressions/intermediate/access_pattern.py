class AccessPattern:
    def __init__(self, expression, offset_pattern, size_pattern):
        self._expression = expression
        self._offset_pattern = offset_pattern
        self._size_pattern = size_pattern

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        offset_pattern = self._offset_pattern.transform(transformer, **kwargs)
        size_pattern = self._size_pattern.transform(transformer, **kwargs)
        e = transformer.transform_access_pattern(
            expression, offset_pattern, size_pattern, **kwargs)
        if e is not None:
            return e
        if (
            expression == self._expression and
            offset_pattern == self._offset_pattern and
            size_pattern == self._size_pattern
        ):
            return self
        return self.__class__(expression, offset_pattern, size_pattern)
