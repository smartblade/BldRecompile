from .wrap_manager import WrapManager


class LengthCounter(WrapManager):
    def __init__(self):
        super().__init__(None, None, None)

    def _wrap_token(self, token, indentation_required=None):
        assert len(self._lines_buffers) == 1
        start_pos = self._current_pos
        super()._wrap_token(token)
        end_pos = self._current_pos
        token.length = end_pos - start_pos
        assert token.length > 0
