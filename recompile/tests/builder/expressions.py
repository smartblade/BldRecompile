import data_types
import expressions


def call(*args, **kwargs):
    return expressions.ProcedureCall(*args, **kwargs)


def i32_id(name):
    return expressions.Identifier(data_types.Int32(), name)


def string(s):
    return expressions.StringConstant(s)
