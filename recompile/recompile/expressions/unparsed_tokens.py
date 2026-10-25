class UnparsedTokens:
    def __init__(self, tokens):
        self._tokens = tokens

    def __repr__(self):
        return "UnparsedTokens({})".format(self._tokens)

    def is_ptr_type(self):
        if len(self._tokens) < 1:
            return False
        return self._tokens[-1].emit_code() == "*"

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)
        for token in self._tokens:
            token.visit(on_expression_visited, **kwargs)

    def emit_code(self):
        return " ".join(map(lambda token: token.emit_code(), self._tokens))
