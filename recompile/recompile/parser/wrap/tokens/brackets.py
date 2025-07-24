from parser.wrap.tokens.token import Token


class BracketsToken(Token):
    def __init__(self, token: Token):
        super().__init__()
        assert token is not None
        self._token = token

    @property
    def token(self):
        return self._token

    def wrap(self, wrap_manager):
        wrap_manager.add_brackets(self)
