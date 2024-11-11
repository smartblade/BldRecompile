import re

from hex_conversion import from_hex
from patterns.apply_pattern import replace_variables

operand_regexp = re.compile(
    r'^(?P<size>dword\s+ptr\s+)?(offset\s+)?(?P<operand>.+)$')

_regexp_map = {
    "ax-cx-dx": (r"ax|cx|dx", None),
    "eax-ecx-edx": (r"eax|ecx|edx", None),
    "label": (
        r"(g|l)(?P<inner_hex>[\dABCDEF]+)",
        lambda **kwargs: _convert_hex(**kwargs)),
    "hex": (
        r"0(?P<inner_hex>[\dABCDEF]+)h",
        lambda **kwargs: _convert_hex(**kwargs)),
    "offset": (
        r"(?P<inner_offset>[\+\-][\dABCDEF]+)h",
        lambda **kwargs: _convert_offset(**kwargs)),
    "external": (
        r"[^\s;]+;\s+\[\w+\.(?P<inner_id>.+)\]\.",
        lambda **kwargs: _convert_external(**kwargs)),
}


def match_operand(operand, operand_pattern, operand_pattern_sets):
    operand_pattern_set_name = _get_operand_pattern_set_name(
        operand_pattern, operand_pattern_sets)
    if operand_pattern_set_name is not None:
        return _match_operand_pattern_set(
            operand, operand_pattern_set_name, operand_pattern_sets)
    return _match_operand(operand, operand_pattern)


def _get_operand_pattern_set_name(operand_pattern, operand_pattern_sets):
    if not operand_pattern.startswith("%"):
        return None
    if not operand_pattern.endswith("%"):
        return None
    set_name = operand_pattern[1:-1]
    if set_name not in operand_pattern_sets:
        return None
    return set_name


def _match_operand_pattern_set(operand, set_name, operand_pattern_sets):
    for pattern in operand_pattern_sets[set_name]:
        operand_expression = _apply_operand_pattern(
            operand, pattern["operand"], pattern["expression"])
        if operand_expression is not None:
            return {set_name: operand_expression}
    return None


def _apply_operand_pattern(operand, operand_pattern, expression):
    match_dict = _match_operand(operand, operand_pattern)
    if match_dict is None:
        return None
    expression = replace_variables(expression, match_dict)
    return expression


def _match_operand(operand, operand_pattern):
    match = re.search(operand_regexp, operand.strip())
    operand = match.group("operand")
    operand_size = _get_operand_size(match.group("size"))
    expected_operand_regexp = re.escape(operand_pattern)
    expected_operand_regexp = re.sub(
        r"%(?P<variable>[\w\\-]*)%",
        _define_variable_regexp,
        expected_operand_regexp)
    expected_operand_regexp = r"^{}$".format(expected_operand_regexp)
    match = re.search(expected_operand_regexp, operand)
    if not match:
        return None
    operand_match_dict = {}
    for param, value in match.groupdict().items():
        if param.startswith("inner_"):
            continue
        param = param.replace("_", "-")
        operand_match_dict[param] = _convert_variable_value(param, value)
    if operand_size is not None:
        operand_match_dict["size"] = str(operand_size)
    return operand_match_dict


def _get_operand_size(s):
    if s is None:
        return None
    if s.startswith("dword"):
        return 4
    raise Exception("Unknown operand size: {}.".format(s))


def _define_variable_regexp(matchobj):
    var_name = matchobj.group("variable")
    var_name = var_name.replace("\\-", "-")
    regexp_value, convertor = _find_pattern_variable_by_name(var_name)
    if regexp_value is not None:
        var_name = var_name.replace("-", "_")
        return r"(?P<{}>{})".format(var_name, regexp_value)
    raise Exception("Unexpected variable: %{}%".format(var_name))


def _find_pattern_variable_by_name(var_name):
    for key, variable_info in _regexp_map.items():
        if var_name.startswith(key):
            return variable_info
    return None, None


def _convert_variable_value(var_name, value):
    regexp_value, convertor = _find_pattern_variable_by_name(var_name)
    if convertor is not None:
        match = re.search(regexp_value, value)
        return convertor(match_dict=match.groupdict())
    return value


def _convert_hex(match_dict):
    return "0x{}".format(match_dict["inner_hex"])


def _convert_offset(match_dict):
    return str(from_hex(match_dict["inner_offset"]))


def _convert_external(match_dict):
    return match_dict["inner_id"]
