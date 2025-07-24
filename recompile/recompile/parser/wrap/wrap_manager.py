from expressions.operator import Operator
import parser.wrap.tokens as tokens


class WrapManager:
    def __init__(self, max_line_len, indent_len, indent):
        self._wrap = max_line_len is not None
        self._max_line_len = max_line_len
        self._indent_len = indent_len
        self._indent = indent
        self._current_pos = 0
        if indent_len is not None:
            self._lines_buffers = []
            self._new_line()
        else:
            self._lines_buffers = [[]]

    def get_lines(self):
        lines = []
        for buffer in self._lines_buffers:
            lines.append("".join(buffer))
        return lines

    def wrap_if_needed(self, token):
        if not self._wrap or self._can_add_to_current_line(token):
            self._add_to_current_line(token)
            return
        self._wrap_token(token)

    def _wrap_token(self, token):
        token.wrap(self)

    def _can_add_to_current_line(self, token: tokens.Token):
        offset = self._indent * self._indent_len + self._current_pos
        return offset + token.length <= self._max_line_len

    def _add_to_current_line(self, token: tokens.Token):
        old_wrap_flag = self._wrap
        self._wrap = False
        self._wrap_token(token)
        self._wrap = old_wrap_flag

    def _add_text_to_current_line(self, s: str):
        self._lines_buffers[-1].append(s)
        self._current_pos += len(s)

    def _add_operator(self, operator):
        text = operator.value
        if operator != Operator.COMMA:
            text = " " + text
        self._add_text_to_current_line(text)
        if self._wrap:
            self._new_line()
        else:
            self._add_text_to_current_line(" ")

    def _add_opening_bracket(self):
        self._add_text_to_current_line("(")
        if self._wrap:
            self._new_line_and_indent()

    def _add_closing_bracket(self):
        if self._wrap:
            self._new_line_and_unindent()
        self._add_text_to_current_line(")")

    def _new_line(self):
        self._lines_buffers.append([" " * self._indent * self._indent_len])
        self._current_pos = 0

    def _new_line_and_indent(self):
        self._indent += 1
        self._new_line()

    def _new_line_and_unindent(self):
        self._indent -= 1
        self._new_line()

    def add_tokens_list(self, tokens_list):
        for token in tokens_list.tokens:
            self._wrap_token(token)

    def add_any_code(self, any_code):
        self._add_text_to_current_line(any_code.text)

    def add_brackets(self, brackets):
        self._add_opening_bracket()
        self._wrap_token(brackets.token)
        self._add_closing_bracket()

    def add_op_separated_list(self, op_list):
        for token, operator in op_list.pairs:
            self.wrap_if_needed(token)
            if operator is None:
                continue
            self._add_operator(operator)
