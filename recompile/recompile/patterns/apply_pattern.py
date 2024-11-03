from hex_conversion import from_hex
import parser
from patterns.predefined_procedures import visit_predefined_procedures

_actions = {
    "prolog": lambda builder, **kwargs: builder.make_prolog(**kwargs),
    "epilog-restore": lambda builder, **kwargs: builder.make_restore(**kwargs),
    "epilog-return": lambda builder, **kwargs: builder.make_epilog(**kwargs),
    "assignment": lambda builder, **kwargs: builder.make_assignment(**kwargs),
    "tmpreg": lambda builder, **kwargs: builder.update_temporary_reg(**kwargs),
    "stackarg": lambda builder, **kwargs: builder.make_arg(**kwargs),
    "call": lambda builder, **kwargs: builder.make_call(**kwargs),
}


def apply_pattern(builder, pattern, match_dict):
    action = pattern["action"]
    action_name = next(iter(action.keys()))
    action_args = next(iter(action.values()))
    action_args = _evaluate_args(
        action_args, builder=builder, match_dict=match_dict)
    _actions[action_name](builder=builder, **action_args)


def _evaluate_args(args, **kwargs):
    evaluated_args = {}
    for arg_name, expression in args.items():
        evaluated_args[arg_name] = _evaluate_expression(expression, **kwargs)
    return evaluated_args


def _evaluate_expression(expression, builder, match_dict):
    for key, value in match_dict.items():
        if value.endswith("h"):
            if not value.startswith("0"):
                value = str(from_hex(value[:-1]))
            else:
                value = "0x{}".format(value[1:-1])
        if value.startswith("g") or value.startswith("l"):
            value = "0x{}".format(value[1:])
        expression = expression.replace("%{}%".format(key), value)
    expression = parser.parse_cpp_expression(expression, {}, {})
    return expression.transform(
        lambda e: _evaluate_procedure_calls(e, builder=builder))


def _evaluate_procedure_calls(expression, **kwargs):
    return visit_predefined_procedures(
        expression, on_regvalue=_evaluate_reg_value, **kwargs)


def _evaluate_reg_value(reg, builder):
    return builder.pop_reg_value(reg)
