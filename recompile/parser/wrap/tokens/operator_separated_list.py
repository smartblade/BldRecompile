from expressions.operator import Operator
from parser.wrap.tokens.token import Token


class OperatorSeparatedList(Token):
    def __init__(self, pairs: list[tuple[Token, Operator]]):
        super().__init__()
        self._pairs = pairs

    @property
    def pairs(self):
        return self._pairs

    def wrap(self, wrap_manager):
        wrap_manager.add_op_separated_list(self)
