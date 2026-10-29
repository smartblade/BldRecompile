class Expect:
    def __init__(self, actual, expected):
        self._actual = actual
        self._expected = expected

    def transform(self, transformer, **kwargs):
        actual = self._actual.transform(transformer, **kwargs)
        expected = self._expected.transform(transformer, **kwargs)
        e = transformer.transform_expect(actual, expected, **kwargs)
        if e is not None:
            return e
        if actual == self._actual and expected == self._expected:
            return self
        return self.__class__(actual, expected)
