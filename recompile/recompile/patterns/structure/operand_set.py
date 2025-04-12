import re

from patterns.apply_pattern import replace_variables

from .expression_pattern import ExpressionPattern
from .expression_pattern_match import ExpressionPatternMatch
from .make_regexp_pattern import make_regexp_string
from .offset_match import OffsetMatch


class OperandSet:
    def __init__(self, name, patterns):
        self._name = name
        self._patterns = patterns
        self._items = []
        patterns_strings = []
        for i, (pattern, expression) in enumerate(patterns):
            defined_groups, regexp_string = make_regexp_string(pattern, i)
            group_name = "g{}".format(i)
            patterns_strings.append(
                "(?P<{}>{})".format(group_name, regexp_string))
            expression = _add_index_expression_variables(expression, pattern, i)
            self._items.append(
                (group_name, defined_groups, ExpressionPattern(expression)))
        self._compiled_pattern = re.compile("|".join(patterns_strings))

    @property
    def name(self):
        return self._name

    @property
    def patterns(self):
        return self._patterns

    def match(self, operand, operand_size):
        match = self._compiled_pattern.fullmatch(operand)
        if not match:
            return None
        group_dict = match.groupdict()
        item = self._find_matched_item(group_dict)
        matched_group_name, defined_groups, expression = item
        match_dict = {}
        for group_name in defined_groups.keys():
            value = group_dict[group_name]
            var_name = group_name.replace("_", "-")
            match_dict[var_name] = _convert_variable_value(
                defined_groups, group_name, value)
        if operand_size is not None:
            match_dict["size"] = OffsetMatch(operand_size)
        return {
            self._name: ExpressionPatternMatch(expression, match_dict)
        }

    def _find_matched_item(self, group_dict):
        for group_name, defined_groups, expression in self._items:
            if group_dict[group_name] is not None:
                return group_name, defined_groups, expression
        raise Exception("Can't find matched item.")


def _convert_variable_value(defined_groups, group_name, value):
    convertor = defined_groups[group_name]
    if convertor is not None:
        return convertor(value=value)
    return value


def _add_index_expression_variables(expression, pattern, group_index):
    defined_groups, regexp_string = make_regexp_string(pattern, group_index)
    group_names_with_index = list(defined_groups.keys())
    defined_groups, regexp_string = make_regexp_string(pattern)
    group_names = list(defined_groups.keys())
    match_dict = {}
    for i, group_name in enumerate(group_names):
        match_dict[group_name.replace("_", "-")] = "%{}%".format(
            group_names_with_index[i].replace("_", "-"))
    return replace_variables(expression, match_dict)
