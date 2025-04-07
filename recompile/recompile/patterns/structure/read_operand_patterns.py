from patterns.apply_pattern import replace_variables

from .operand_set import OperandSet


def read_operand_patterns(json):
    operand_sets = {}
    for set_name, operand_set in json.items():
        operand_sets["%{}%".format(set_name)] = OperandSet(
            set_name,
            list(_read_operand_set(operand_set, operand_sets)),
        )
    return operand_sets


def _read_operand_set(operand_set, operand_sets):
    for operand_pattern in operand_set:
        yield from _read_operand_pattern(
            **operand_pattern, operand_sets=operand_sets
        )


def _read_operand_pattern(operand, expression, operand_sets):
    if operand in operand_sets:
        operand_set = operand_sets[operand]
        for pattern_operand, pattern_expression in operand_set.patterns:
            match_dict = {operand_set.name: pattern_expression}
            pattern_expression = replace_variables(expression, match_dict)
            yield pattern_operand, pattern_expression
        return
    yield operand, expression
