class ArrptrPattern:
    def __init__(self, base, scale_pattern, index, offset_pattern):
        self._base = base
        self._scale_pattern = scale_pattern
        self._index = index
        self._offset_pattern = offset_pattern

    def transform(self, transformer, **kwargs):
        base = self._base.transform(transformer, **kwargs)
        scale_pattern = self._scale_pattern.transform(transformer, **kwargs)
        index = self._index.transform(transformer, **kwargs)
        offset_pattern = self._offset_pattern.transform(transformer, **kwargs)
        e = transformer.transform_arrptr_pattern(
            base, scale_pattern, index, offset_pattern, **kwargs)
        if e is not None:
            return e
        if (
            base == self._base and
            scale_pattern == self._scale_pattern and
            index == self._index and
            offset_pattern == self._offset_pattern
        ):
            return self
        return self.__class__(base, scale_pattern, index, offset_pattern)
