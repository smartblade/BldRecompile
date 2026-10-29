class StackvarPattern:
    def __init__(self, offset_pattern, size_pattern):
        self._offset_pattern = offset_pattern
        self._size_pattern = size_pattern

    def transform(self, transformer, **kwargs):
        offset_pattern = self._offset_pattern.transform(transformer, **kwargs)
        size_pattern = self._size_pattern.transform(transformer, **kwargs)
        e = transformer.transform_stackvar_pattern(
            offset_pattern, size_pattern, **kwargs)
        if e is not None:
            return e
        if (
            offset_pattern == self._offset_pattern and
            size_pattern == self._size_pattern
        ):
            return self
        return self.__class__(offset_pattern, size_pattern)
