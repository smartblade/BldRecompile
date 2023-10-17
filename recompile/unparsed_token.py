from float_type import Float

class UnparsedToken:
    def __init__(self, token):
        self._token = token

    def __repr__(self):
        return "UnparsedToken({})".format(self._token)

    def transform_expression(self, declared_identifiers, **kwargs):
        return declared_identifiers.get(self._token, self)

    def emit_code(self):
        return self._token

    @property
    def data_type(self):
        raise Exception("Can't deduce data type for: {}".format(self))
