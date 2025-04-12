import parser

import expressions.intermediate
from expression_transformer import ExpressionTransformer


class ExpressionPattern:
    def __init__(self, expression_str):
        expression = parser.parse_cpp_expression(expression_str, {}, {})
        self._expression = expression.transform(_ExpressionTransformer)

    def transform(self, transformer):
        return self._expression.transform(transformer)


class _ExpressionTransformer(ExpressionTransformer):
    @staticmethod
    def transform_unparsed_token(s, **kwargs):
        if s.startswith("%") and s.endswith("%"):
            var_name = s[1:-1]
            if "%" not in var_name:
                return expressions.intermediate.PatternVariable(var_name)
        if "%" in s:
            return expressions.intermediate.PatternText(s)
        return None
