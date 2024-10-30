import data_types
import expressions


def do_reinterpret(data_type, e):
    if isinstance(e, expressions.Constant):
        return _reinterpret_const(data_type, e)
    return expressions.ReinterpretCast(data_type, e)


def _reinterpret_const(data_type, c):
    if (
        isinstance(data_type, data_types.Int32) and
        isinstance(c.data_type, data_types.Unknown32)
    ):
        if c.value < 0x80000000:
            return expressions.Constant(data_type, c.value)
    raise Exception(
        "Unimplemented reinterpret cast from {} to {}".format(
            c.data_type, data_type))
