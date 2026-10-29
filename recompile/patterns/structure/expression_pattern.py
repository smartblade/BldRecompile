import parser

import data_types
import expressions.intermediate
from expression_transformer import ExpressionTransformer
from patterns.predefined_procedures import make_predefined_procedure_visitor
from patterns.predefined_procedures import visit_predefined_procedures


class ExpressionPattern:
    def __init__(self, expression_str):
        expression = parser.parse_cpp_expression(expression_str, {}, {})
        self._expression = expression.transform(_ExpressionTransformer)

    def transform(self, transformer):
        return self._expression.transform(transformer)


class _ExpressionTransformer(ExpressionTransformer):
    @staticmethod
    def transform_procedure_call(copy_pc, proc_name, arguments, **kwargs):
        return visit_predefined_procedures(
            proc_name, arguments, _predefined_procedure_visitor, **kwargs)

    @staticmethod
    def transform_unparsed_token(s, **kwargs):
        if s.startswith("%") and s.endswith("%"):
            var_name = s[1:-1]
            if "%" not in var_name:
                return expressions.intermediate.PatternVariable(var_name)
        if "%" in s:
            return expressions.intermediate.PatternText(s)
        return None


def _transform_reg_value(reg):
    if isinstance(reg, expressions.UnparsedToken):
        return expressions.intermediate.RegisterValue(str(reg.emit_code()))
    return expressions.intermediate.RegisterPattern(reg)


def _transform_pop_fpu():
    return expressions.intermediate.PopFpu()


def _transform_access(expression, offset, size):
    return expressions.intermediate.AccessPattern(expression, offset, size)


def _transform_global(address):
    if not isinstance(address, expressions.intermediate.PatternVariable):
        raise Exception("Unexpected address variable: {}.".format(address))
    return expressions.intermediate.GlobalPattern(address.variable_name)


def _transform_local(offset):
    return expressions.intermediate.LocalPattern(offset)


def _transform_externvar(name):
    if isinstance(name, expressions.intermediate.PatternVariable):
        return expressions.intermediate.ExternVariablePattern(
            name.variable_name
        )
    raise Exception("Unexpected extern variable: {}.".format(name))


def _transform_stackvar(offset, size):
    return expressions.intermediate.StackvarPattern(offset, size)


def _transform_arrptr(base, scale, index, offset):
    if (
        isinstance(scale, expressions.Constant) and
        isinstance(offset, expressions.Constant)
    ):
        assert isinstance(scale.value, int)
        assert isinstance(offset.value, int)
        return expressions.intermediate.Arrptr(
            base, scale.value, index, offset.value)
    return expressions.intermediate.ArrptrPattern(base, scale, index, offset)


def _transform_real64(high, low):
    if not isinstance(high, expressions.intermediate.PatternVariable):
        raise Exception("Unexpected real64 high variable: {}.".format(high))
    if not isinstance(low, expressions.intermediate.PatternVariable):
        raise Exception("Unexpected real64 low variable: {}.".format(low))
    return expressions.intermediate.Real64Pattern(
        high.variable_name, low.variable_name
    )


def _transform_expect(expression, const):
    return expressions.intermediate.Expect(expression, const)


def _transform_eval(expression):
    return expressions.intermediate.Eval(expression)


def _transform_zeroextend(size, expression):
    return expressions.StaticCast(
        data_types.AnyInt(size), expressions.intermediate.U(expression))


def _transform_signextend(size, expression):
    return expressions.StaticCast(
        data_types.AnyInt(size), expressions.intermediate.S(expression)
    )


def _transform_i(expression):
    return expressions.intermediate.I(expression)


def _transform_s(expression):
    return expressions.intermediate.S(expression)


def _transform_u(expression):
    return expressions.intermediate.U(expression)


def _transform_f(expression):
    return expressions.intermediate.F(expression)


_predefined_procedure_visitor = make_predefined_procedure_visitor(
    on_regvalue=_transform_reg_value,
    on_popfpu=_transform_pop_fpu,
    on_access=_transform_access,
    on_global=_transform_global,
    on_local=_transform_local,
    on_externvar=_transform_externvar,
    on_stackvar=_transform_stackvar,
    on_arrptr=_transform_arrptr,
    on_real64=_transform_real64,
    on_expect=_transform_expect,
    on_eval=_transform_eval,
    on_zeroextend=_transform_zeroextend,
    on_signextend=_transform_signextend,
    on_i=_transform_i,
    on_s=_transform_s,
    on_u=_transform_u,
    on_f=_transform_f,
)
