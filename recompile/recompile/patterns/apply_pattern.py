import struct

import data_types
import expressions
from hex_conversion import to_hex
import parser
from expressions.operator import Operator
from patterns.evaluate_expression import evaluate_expression
from patterns.predefined_procedures import visit_predefined_procedures

_actions = {
    "standard-proc": lambda builder, **kwargs: builder.make_standard(**kwargs),
    "prolog": lambda builder, **kwargs: builder.make_prolog(**kwargs),
    "prolog-preserved": lambda builder, **kwargs: builder.make_preserved(
        **kwargs),
    "epilog-restore": lambda builder, **kwargs: builder.make_restore(**kwargs),
    "epilog-return": lambda builder, **kwargs: builder.make_epilog(**kwargs),
    "instruction": lambda builder, **kwargs: builder.make_instruction(**kwargs),
    "validate": lambda builder, **kwargs: builder.validate(**kwargs),
    "assignment": lambda builder, **kwargs: builder.make_assignment(**kwargs),
    "fassignment": lambda builder, **kwargs: builder.make_float_assignment(
        **kwargs),
    "tmpreg": lambda builder, **kwargs: builder.update_temporary_reg(**kwargs),
    "pushfpu": lambda builder, **kwargs: builder.push_fpu(**kwargs),
    "stackarg": lambda builder, **kwargs: builder.make_arg(**kwargs),
    "call": lambda builder, **kwargs: builder.make_call(**kwargs),
    "addsp": lambda builder, **kwargs: builder.add_stack_pointer(**kwargs),
    "jump": lambda builder, **kwargs: builder.make_jump(**kwargs),
    "label": lambda builder, **kwargs: builder.start_labeled_block(**kwargs),
}


def apply_pattern(builder, pattern, match_dict):
    actions = pattern.get("actions")
    if actions is None:
        apply_action(builder, pattern["action"], match_dict)
        return
    for action in actions:
        apply_action(builder, action, match_dict)


def apply_action(builder, action, match_dict):
    action_name = next(iter(action.keys()))
    action_args = next(iter(action.values()))
    action_args = _evaluate_args(
        action_args, builder=builder, match_dict=match_dict)
    _actions[action_name](builder=builder, **action_args)


def replace_variables(expression, match_dict):
    for key, value in match_dict.items():
        expression = expression.replace("%{}%".format(key), value)
    return expression


def _evaluate_args(args, **kwargs):
    evaluated_args = {}
    for arg_name, expression in args.items():
        evaluated_args[arg_name] = _evaluate_expression(expression, **kwargs)
    return evaluated_args


def _evaluate_expression(expression, builder, match_dict):
    expression = replace_variables(expression, match_dict)
    expression = parser.parse_cpp_expression(expression, {}, {})
    return expression.transform(
        lambda e: _evaluate_procedure_calls(e, builder=builder))


def _evaluate_procedure_calls(expression, **kwargs):
    if isinstance(expression, expressions.Bin):
        return _evaluate_binary(expression)
    if isinstance(expression, expressions.Cast):
        return _evaluate_cast(expression)
    return visit_predefined_procedures(
        expression,
        on_regvalue=_evaluate_reg_value,
        on_popfpu=_evaluate_pop_fpu,
        on_access=_keep,
        on_global=_keep,
        on_local=_keep,
        on_stackvar=_keep,
        on_arrptr=_keep,
        on_real64=_evaluate_real64,
        on_expect=_evaluate_expect,
        on_eval=_evaluate_constants,
        on_i=_evaluate_any_int_conversion,
        on_s=_evaluate_int_conversion,
        on_u=_evaluate_uint_conversion,
        on_f=evaluate_float_conversion,
        **kwargs)


def _evaluate_reg_value(reg, builder):
    return builder.pop_reg_value(reg)


def _evaluate_pop_fpu(builder):
    return builder.pop_fpu()


def _evaluate_real64(high, low, **kwargs):
    (double, ) = struct.unpack(
        '>d',
        bytes.fromhex(to_hex(high) + to_hex(low)),
    )
    return expressions.Constant(data_types.Double(), double)


def _evaluate_expect(expression, const, **kwargs):
    if (
        isinstance(expression, expressions.Constant) and
        expression.value == const
    ):
        return expression
    raise Exception("Expected {} but was: {}".format(const, expression))


def _evaluate_constants(expression, **kwargs):
    return evaluate_expression(expression)


def _evaluate_any_int_conversion(expression, **kwargs):
    size = expression.data_type.size
    return expressions.do_reinterpret(data_types.AnyInt(size), expression)


def _evaluate_uint_conversion(expression, **kwargs):
    if expression.data_type.size == 1:
        return expressions.do_reinterpret(data_types.UChar(), expression)
    if expression.data_type.size == 4:
        return expressions.do_reinterpret(data_types.UInt32(), expression)
    raise Exception("Conversion to uint{} is not supported.".format(
        expression.data_type.size * 8))


def _evaluate_int_conversion(expression, **kwargs):
    if expression.data_type.size == 4:
        return expressions.do_reinterpret(data_types.Int32(), expression)
    raise Exception("Conversion to int{} is not supported.".format(
        expression.data_type.size * 8))


def evaluate_float_conversion(expression, **kwargs):
    if expression.data_type.size == 4:
        return expressions.do_reinterpret(data_types.Float(), expression)
    if expression.data_type.size == 8:
        return expressions.do_reinterpret(data_types.Double(), expression)
    raise Exception("Conversion to real{} is not supported.".format(
        expression.data_type.size * 8))


def _keep(**kwargs):
    return None


def _evaluate_binary(b):
    if (
        b.operator == Operator.ADD and
        isinstance(b.right, expressions.Constant) and
        isinstance(b.right.data_type, data_types.Int32) and
        b.right.value < 0
    ):
        right = expressions.Constant(b.right.data_type, -b.right.value)
        return expressions.Bin(Operator.SUB, b.left, right)
    return b


def _evaluate_cast(cast):
    expression = cast.expression
    if isinstance(expression, expressions.BracketsExpression):
        expression = expression.expression
    return expressions.StaticCast(cast.data_type, expression)
