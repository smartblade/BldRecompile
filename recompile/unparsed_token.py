class UnparsedToken:
    def __init__(self, token):
        self._token = token

    def transform_expression(self, declared_identifiers, **kwargs):
        return declared_identifiers.get(self._token, self)

    def emit_code(self):
        return self._token
