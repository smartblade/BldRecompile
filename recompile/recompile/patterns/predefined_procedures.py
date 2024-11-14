from calling_convention import CallingConvention
import data_types
import expressions
from hex_conversion import from_hex
from procedure_declaration import ProcedureDeclaration

_procedures = {
    "REGVALUE": lambda *args: _unpack_args(*args, reg=str),
    "STACKVAR": lambda *args: _unpack_args(*args, offset=int, size=int),
    "ACCESS": lambda *args: _unpack_args(
        *args, expression=None, offset=int, size=int),
    "GLOBAL": lambda *args: _unpack_args(*args, address=from_hex),
    "I": lambda *args: _unpack_args(*args, expression=None),
    "S": lambda *args: _unpack_args(*args, expression=None),
}


class DataTypeDefiner:
    @staticmethod
    def define_data_type(proc_call, **kwargs):
        cb = getattr(DataTypeDefiner, "on_{}".format(proc_call.name.lower()))
        data_type = cb(**kwargs)
        proc_decl = ProcedureDeclaration(
            proc_call.name, CallingConvention.CDECL, None, [], data_type)
        proc_call.set_declaration(proc_decl)

    @staticmethod
    def unknown_type(size):
        if size == 4:
            return data_types.Unknown32()
        raise Exception("Undefined type for size: {}".format(size))

    @staticmethod
    def on_access(size, **kwargs):
        return DataTypeDefiner.unknown_type(size)

    @staticmethod
    def on_global(**kwargs):
        return data_types.Pointer32()

    @staticmethod
    def on_stackvar(size, **kwargs):
        return DataTypeDefiner.unknown_type(size)


def visit_predefined_procedures(e, **kwargs):
    if not isinstance(e, expressions.ProcedureCall):
        return e
    cb_map = {}
    cb_args = {}
    for name, value in kwargs.items():
        if name.startswith("on_"):
            proc_name = name[3:].upper()
            cb_map[proc_name] = value
        else:
            cb_args[name] = value
    callback = cb_map.get(e.name)
    if callback is None:
        return e
    return _procedures[e.name](e, callback, cb_args)


def _unpack_args(procedure_call, callback, cb_args, **kwargs):
    args = procedure_call.arguments
    if len(args) != len(kwargs):
        raise Exception(
            "Expected {} argument of {} but was {}.".format(
                len(kwargs), procedure_call.name, len(args)))
    values_map = {}
    for index, (key, convert) in enumerate(kwargs.items()):
        values_map[key] = args[index]
        if convert is not None:
            values_map[key] = convert(values_map[key].emit_code())
    transformed_expression = callback(**cb_args, **values_map)
    if transformed_expression is None:
        DataTypeDefiner.define_data_type(procedure_call, **values_map)
        return procedure_call
    return transformed_expression
