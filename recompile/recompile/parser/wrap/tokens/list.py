from parser.wrap.tokens.token import Token


class TokensList(Token):
    def __init__(self, tokens: list[Token]):
        super().__init__()
        self._tokens = tokens

    @property
    def tokens(self):
        return self._tokens

    def wrap(self, wrap_manager):
        wrap_manager.add_tokens_list(self)
