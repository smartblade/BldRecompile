import data_types
from data_types.data_type import DataType
from data_types.unknown32 import Unknown32
from data_types.double import Double


class ClassType(DataType):
    def __init__(self, class_name, fields):
        super().__init__()
        self._class_name = class_name
        self._fields = fields
        self._methods = []
        self._parent = None
        self._fields_sorted = True

    def __repr__(self):
        return "class {}".format(self._class_name)

    @property
    def class_name(self):
        return self._class_name

    def rename(self, new_name):
        return self.__class__(new_name, self._fields)

    @property
    def alignment(self):
        for offset, (field_type, field_name) in self._fields.items():
            if offset % 8 == 4 and field_type.size == 8:
                return 4
        return None

    @property
    def size(self):
        size = 0
        for offset, (field_type, field_name) in self._fields.items():
            if offset + field_type.size > size:
                size = offset + field_type.size
        return size

    @property
    def parent(self):
        return self._parent

    def set_parent(self, parent):
        self._parent = parent

    def add_method(self, method):
        self._methods.append(method)

    def find_method(self, method_name):
        found_method = None
        num_methods = 0
        for method in self._methods:
            if method.proc_name == method_name:
                found_method = method
                num_methods += 1
        if num_methods > 1:
            raise Exception(
                "More than 1 methods found: {}.".format(method_name))
        return found_method

    def get_field_by_offset(self, offset):
        if offset not in self._fields and self._parent is not None:
            return self._parent.get_field_by_offset(offset)
        return self._fields[offset]

    def find_data_type_by_field(self, field_name):
        for field_type, name in self._fields.values():
            if name == field_name:
                return field_type
        if self._parent is not None:
            return self._parent.find_data_type_by_field(field_name)
        raise Exception(
            "Field {} was not found at {}.".format(field_name, self)
        )

    def find_offset_by_field_name(self, field_name):
        for offset, (field_type, name) in self._fields.items():
            if name == field_name:
                return offset
        raise Exception(
            "Field {} was not found at {}.".format(field_name, self)
        )

    def ensure_field(self, offset):
        if offset in self._fields:
            return
        self.add_field(offset, Unknown32())
        self._fields_sorted = False

    def add_field(self, offset, data_type):
        field_name = _define_field_name(data_type, offset)
        self._fields[offset] = data_type, field_name
        self._fields_sorted = False

    def merge_word32_into_double(self, offset):
        (first_field_type, first_field_name) = self._fields[offset]
        # Check if it was already merged
        if isinstance(first_field_type, Double):
            return
        if not isinstance(first_field_type, Unknown32):
            raise Exception(
                "Field {} type expected to be {} bat was: {}".format(
                    first_field_name, Unknown32, first_field_type
                )
            )
        (second_field_type, second_field_name) = self._fields[offset + 4]
        if not isinstance(second_field_type, Unknown32):
            raise Exception(
                "Field {} type expected to be {} bat was: {}".format(
                    second_field_name, Unknown32, second_field_type
                )
            )
        del self._fields[offset + 4]
        self._fields[offset] = (
            Double(), "unknown_double_{:04X}".format(offset)
        )

    def get_type_name(self, is_metafile):
        return self._class_name

    def get_declaration(self, is_metafile):
        if not is_metafile:
            return self._get_cpp_declaration()
        lines = []
        lines.append(
            "typedef struct {} {};".format(self._class_name, self._class_name)
        )
        lines.append("")
        lines.append("struct {} {{".format(self._class_name))
        self._write_fields(lines, is_metafile=True)
        lines.append("};")
        return "\n".join(lines) + "\n"

    def _get_cpp_declaration(self):
        lines = []
        lines.append("class {} {{".format(self._class_name))
        lines.append("public:")
        indent = " " * 4
        for method in self._methods:
            lines.append(
                "{}{};".format(
                    indent, method.get_declaration(is_metafile=False)
                )
            )
        lines.append("")
        self._write_fields(lines, is_metafile=False)
        lines.append("};")
        return "\n".join(lines) + "\n"

    def _write_fields(self, lines, is_metafile):
        self._sort_fields()
        cur_offset = 0
        for offset, (field_type, field_name) in self._fields.items():
            indent = " " * 4
            if cur_offset != offset:
                self._fill_unused_fields(lines, cur_offset, offset - cur_offset)
            field_decl = field_type.make_variable_declaration(
                field_name, is_metafile=is_metafile
            )
            lines.append("{}{};".format(indent, field_decl))
            cur_offset = offset + field_type.size

    def _fill_unused_fields(self, lines, offset, size):
        indent = " " * 4
        lines.append(
            "{}char unused_fields_{}[0x{}];".format(
                indent, format(offset, '04X'), format(size, '04X')
            )
        )

    def _sort_fields(self):
        if self._fields_sorted:
            return
        self._fields = dict(sorted(self._fields.items()))
        self._fields_sorted = True


def _define_field_name(data_type, offset):
    if isinstance(data_type, data_types.Pointer32):
        return "unknown_ptr_{:04X}".format(offset)
    return "unknown_field_{:04X}".format(offset)
