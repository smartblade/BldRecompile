class ExpressionPatternMatch:
    def __init__(self, pattern, match_dict):
        self._pattern = pattern
        self._match_dict = match_dict

    def make_expression(self, transformer):
        return transformer.transform_expression(self._pattern, self._match_dict)
