import re

from hex_conversion import from_hex
from patterns.apply_pattern import replace_variables

_regexp_map = {
    "a-b-c-d": (r"a|b|c|d", None),
    "al-bl-cl-dl": (r"al|bl|cl|dl", None),
    "ax-cx-dx": (r"ax|cx|dx", None),
    "eax-ecx-edx": (r"eax|ecx|edx", None),
    "tmpreg32": (r"eax|ebx|ecx|edx|edi|esi", None),
    "label": (
        r"(offset\s+)?(g|l)(?P<{}>[\dABCDEF]+)",
        lambda **kwargs: _convert_hex(**kwargs)),
    "variable-label": (
        r"(offset\s+)?g(?P<{}>[\dABCDEF]+)",
        lambda **kwargs: _convert_hex(**kwargs)),
    "hex": (
        r"0(?P<{}>[\dABCDEF]+)h",
        lambda **kwargs: _convert_hex(**kwargs)),
    "offset": (
        r"((?P<{}>[\+\-][\dABCDEF]+)h)?",
        lambda **kwargs: _convert_offset(**kwargs)),
    "external": (
        r"[^\s;]+;\s+\[\w+\.(?P<{}>.+)\]\.",
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
        match_dict = _apply_operand_pattern(
            operand,
            pattern["operand"],
            pattern["expression"],
            operand_pattern_sets,
        )
        if match_dict is not None:
            operand_expression = match_dict.pop("expression")
            return {set_name: operand_expression, **match_dict}
    return None


def _apply_operand_pattern(
    operand, operand_pattern, expression, operand_pattern_sets
):
    match_dict = match_operand(operand, operand_pattern, operand_pattern_sets)
    if match_dict is None:
        return None
    expression = replace_variables(expression, match_dict)
    size = {'size': match_dict["size"]} if 'size' in match_dict else {}
    return {
        'expression': expression,
        **size,
    }


def _match_operand(operand, operand_pattern):
    defined_groups = set()
    expected_operand_regexp = re.escape(operand_pattern)
    expected_operand_regexp = re.sub(
        r"%(?P<variable>[\w\\-]*)%",
        lambda matchobj: _define_variable_regexp(matchobj, defined_groups),
        expected_operand_regexp)
    expected_operand_regexp = r"^{}$".format(expected_operand_regexp)
    match = re.search(expected_operand_regexp, operand.asm)
    if not match:
        return None
    operand_match_dict = {}
    for param, value in match.groupdict().items():
        if param.startswith("inner_"):
            continue
        param = param.replace("_", "-")
        operand_match_dict[param] = _convert_variable_value(param, value)
    if operand.size is not None:
        operand_match_dict["size"] = str(operand.size)
    return operand_match_dict


def _define_variable_regexp(matchobj, defined_groups):
    var_name = matchobj.group("variable")
    var_name = var_name.replace("\\-", "-")
    regexp_value, convertor = _find_pattern_variable_by_name(var_name)
    if regexp_value is not None:
        var_name = var_name.replace("-", "_")
        if var_name not in defined_groups:
            defined_groups.add(var_name)
            return r"(?P<{}>{})".format(var_name, regexp_value)
        else:
            return r"(?P={})".format(var_name)
    raise Exception("Unexpected variable: %{}%".format(var_name))


def _find_pattern_variable_by_name(var_name):
    for key, variable_info in _regexp_map.items():
        if var_name.startswith(key):
            regexp_value, convertor = variable_info
            inner_var_name = _make_inner_var_name(var_name)
            return regexp_value.format(inner_var_name), convertor
    return None, None


def _make_inner_var_name(var_name):
    return "inner_{}".format(var_name.replace("-", "_"))


def _convert_variable_value(var_name, value):
    regexp_value, convertor = _find_pattern_variable_by_name(var_name)
    if convertor is not None:
        match = re.search(regexp_value, value)
        return convertor(
            inner_var_name=_make_inner_var_name(var_name),
            match_dict=match.groupdict(),
        )
    return value


def _convert_hex(inner_var_name, match_dict):
    return "0x{}".format(match_dict[inner_var_name])


def _convert_offset(inner_var_name, match_dict):
    hex_offset = match_dict[inner_var_name]
    if hex_offset is not None:
        int_offset = from_hex(hex_offset)
    else:
        int_offset = 0
    return str(int_offset)


def _convert_external(inner_var_name, match_dict):
    return match_dict[inner_var_name]
