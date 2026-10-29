_procedures = {
    "REGVALUE": lambda *args: _unpack_args(*args, reg=None),
    "POPFPU": lambda *args: _unpack_args(*args),
    "STACKVAR": lambda *args: _unpack_args(*args, offset=None, size=None),
    "ACCESS": lambda *args: _unpack_args(
        *args, expression=None, offset=None, size=None),
    "GLOBAL": lambda *args: _unpack_args(*args, address=None),
    "LOCAL": lambda *args: _unpack_args(*args, offset=None),
    "EXTERNVAR": lambda *args: _unpack_args(*args, name=None),
    "ARRPTR": lambda *args: _unpack_args(
        *args, base=None, scale=None, index=None, offset=None),
    "REAL64": lambda *args: _unpack_args(*args, high=None, low=None),
    "EXPECT": lambda *args: _unpack_args(*args, expression=None, const=None),
    "EVAL": lambda *args: _unpack_args(*args, expression=None),
    "ZEROEXTEND": lambda *args: _unpack_args(*args, size=int, expression=None),
    "SIGNEXTEND": lambda *args: _unpack_args(*args, size=int, expression=None),
    "I": lambda *args: _unpack_args(*args, expression=None),
    "S": lambda *args: _unpack_args(*args, expression=None),
    "U": lambda *args: _unpack_args(*args, expression=None),
    "F": lambda *args: _unpack_args(*args, expression=None),
}


def make_predefined_procedure_visitor(**kwargs):
    cb_map = {}
    for name, value in kwargs.items():
        if name.startswith("on_"):
            proc_name = name[3:].upper()
            cb_map[proc_name] = value
    return cb_map


def visit_predefined_procedures(name, arguments, callbacks, **kwargs):
    callback = callbacks.get(name)
    if callback is None:
        return None
    return _procedures[name](name, arguments, callback, kwargs)


def _unpack_args(proc_name, args, callback, cb_args, **kwargs):
    if len(args) != len(kwargs):
        raise Exception(
            "Expected {} argument of {} but was {}.".format(
                len(kwargs), proc_name, len(args)))
    values_map = {}
    for index, (key, convert) in enumerate(kwargs.items()):
        values_map[key] = args[index]
        if convert is not None:
            values_map[key] = convert(values_map[key].emit_code())
    return callback(**cb_args, **values_map)
