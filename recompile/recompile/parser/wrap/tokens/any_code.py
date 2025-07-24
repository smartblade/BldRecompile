from parser.wrap.tokens.token import Token


class AnyCodeToken(Token):
    def __init__(self, text: str):
        super().__init__()
        self._text = text

    @property
    def text(self):
        return self._text

    def wrap(self, wrap_manager):
        wrap_manager.add_any_code(self)
