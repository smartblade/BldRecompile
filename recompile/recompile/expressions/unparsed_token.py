class UnparsedToken:
    def __init__(self, token):
        self._token = token

    def __repr__(self):
        return "UnparsedToken({})".format(self._token)

    def transform_expression(self, **kwargs):
        return self

    def visit(self, on_expression_visited, **kwargs):
        on_expression_visited(self, **kwargs)

    def transform(self, transformer, **kwargs):
        e = transformer.transform_unparsed_token(self._token, **kwargs)
        if e is not None:
            return e
        return self

    def emit_code(self):
        return self._token

    @property
    def data_type(self):
        raise Exception("Can't deduce data type for: {}".format(self))
