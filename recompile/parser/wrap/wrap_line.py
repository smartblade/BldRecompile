from .length_counter import LengthCounter
from .parse_line import parse_line
from .wrap_manager import WrapManager


def wrap_line(line, max_line_len, indent_len, indent):
    token = parse_line(line)
    length_counter = LengthCounter()
    length_counter.wrap_if_needed(token)
    wrap_manager = WrapManager(max_line_len, indent_len, indent)
    wrap_manager.wrap_if_needed(token)
    return wrap_manager.get_lines()
