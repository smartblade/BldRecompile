import data_types
from hex_conversion import to_hex
import naming


def define_class_names(gbl_vars):
    renamed_types = {}
    for gbl in gbl_vars.values():
        data_type = _define_class_names(
            gbl.data_type, renamed_types,
            "unknown_class_{}".format(to_hex(gbl.address)),
        )
        if data_type is not None:
            gbl.change_data_type(data_type)


def _define_class_names(data_type, renamed_types, default_name):
    if isinstance(data_type, data_types.ClassType):
        if data_type in renamed_types:
            return renamed_types[data_type]
        new_type = naming.ensure_class_name(data_type, default_name)
        if new_type != data_type:
            renamed_types[data_type] = new_type
            return new_type
    if isinstance(data_type, data_types.Pointer32):
        pointee = _define_class_names(
            data_type.pointee, renamed_types, default_name
        )
        if pointee is not None:
            return data_types.Pointer32(pointee)
