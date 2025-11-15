from parser.wrap.tokens.token import Token


class StringToken(Token):
    def __init__(self, string: str):
        super().__init__()
        self._string = string

    @property
    def string(self):
        return self._string

    def wrap(self, wrap_manager):
        wrap_manager.add_string(self)
