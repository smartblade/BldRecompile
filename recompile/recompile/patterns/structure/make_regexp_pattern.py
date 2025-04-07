import re

from hex_conversion import from_hex

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


class RegexpPattern:
    def __init__(self, pattern, defined_groups):
        self._pattern = pattern
        self._defined_groups = defined_groups

    def match(self, s, operand_size):
        match = self._pattern.search(s)
        if not match:
            return None
        match_dict = {}
        for group_name, value in match.groupdict().items():
            var_name = group_name.replace("_", "-")
            match_dict[var_name] = self._convert_variable_value(
                group_name, value)
        if operand_size is not None:
            match_dict["size"] = str(operand_size)
        return match_dict

    def _convert_variable_value(self, group_name, value):
        convertor = self._defined_groups[group_name]
        if convertor is not None:
            return convertor(value=value)
        return value


def make_regexp_pattern(operand_pattern):
    defined_groups, operand_regexp = make_regexp_string(operand_pattern)
    operand_regexp = r"^{}$".format(operand_regexp)
    compiled_regexp = re.compile(operand_regexp)
    return RegexpPattern(compiled_regexp, defined_groups)


def make_regexp_string(operand_pattern, suffix=None):
    defined_groups = {}
    expected_operand_regexp = re.escape(operand_pattern)
    expected_operand_regexp = re.sub(
        r"%(?P<variable>[\w\\-]*)%",
        lambda matchobj: _define_variable_regexp(
            matchobj, defined_groups, suffix),
        expected_operand_regexp)
    return defined_groups, expected_operand_regexp


def _define_variable_regexp(matchobj, defined_groups, suffix):
    var_name = matchobj.group("variable")
    var_name = var_name.replace("\\-", "-")
    regexp_value, convertor = _find_pattern_variable_by_name(var_name, suffix)
    if regexp_value is not None:
        group_name = _make_group_name(var_name, suffix)
        if convertor is not None:
            defined_groups[group_name] = convertor
            return r"({})".format(regexp_value)
        if group_name not in defined_groups:
            defined_groups[group_name] = None
            return r"(?P<{}>{})".format(group_name, regexp_value)
        else:
            return r"(?P={})".format(group_name)
    raise Exception("Unexpected variable: %{}%".format(var_name))


def _find_pattern_variable_by_name(var_name, suffix):
    for key, variable_info in _regexp_map.items():
        if var_name.startswith(key):
            regexp_value, convertor = variable_info
            var_name = _make_group_name(var_name, suffix)
            return regexp_value.format(var_name), convertor
    return None, None


def _make_group_name(var_name, suffix):
    group_name = var_name.replace("-", "_")
    if suffix is not None:
        group_name = "{}_{}".format(group_name, suffix)
    return group_name


def _convert_hex(value):
    return "0x{}".format(value)


def _convert_offset(value):
    hex_offset = value
    if hex_offset is not None:
        int_offset = from_hex(hex_offset)
    else:
        int_offset = 0
    return str(int_offset)


def _convert_external(value):
    return value
