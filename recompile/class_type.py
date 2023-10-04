from unknown32 import Unknown32

class ClassType:
    def __init__(self, class_name, fields):
        self._class_name = class_name
        self._fields = fields
        self._methods = []

    def __repr__(self):
        return "class {}".format(self._class_name)

    @property
    def class_name(self):
        return self._class_name

    def rename(self, new_name):
        return self.__class__(new_name, self._fields)

    def add_method(self, method):
        self._methods.append(method)

    def ensure_field(self, offset):
        if offset in self._fields:
            return
        self._fields[offset] = (Unknown32(), "unknown_field_{:04X}".format(offset))

    def update_method(self, updated_method):
        methods = []
        for method in self._methods:
            if method.proc_name == updated_method.proc_name:
                method = updated_method
            methods.append(method)
        self._methods = methods

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
            if method.method_class is None:
                raise Exception("Method class should be set.")
            parameters = []
            for parameter_type, parameter_name in method.parameters:
                type_name = parameter_type.get_type_name(is_metafile=False)
                sep = "" if type_name.endswith("*") else " "
                parameters.append("{}{}{}".format(type_name, sep, parameter_name))
            lines.append(
                "{}{}{}({});".format(
                    indent,
                    method.return_arg,
                    method.proc_name,
                    ", ".join(parameters),
                )
            )
        lines.append("")
        self._write_fields(lines, is_metafile=False)
        lines.append("};")
        return "\n".join(lines) + "\n"

    def _write_fields(self, lines, is_metafile):
        cur_offset = 0
        for offset, (field_type, field_name) in self._fields.items():
            indent = " " * 4
            if cur_offset != offset:
                self._fill_unused_fields(lines, cur_offset, offset - cur_offset)
            type_name = field_type.get_type_name(is_metafile=is_metafile)
            lines.append("{}{} {};".format(indent, type_name, field_name))
            cur_offset = offset + field_type.size

    def _fill_unused_fields(self, lines, offset, size):
        indent = " " * 4
        lines.append(
            "{}char unused_fields_{}[0x{}];".format(
                indent, format(offset, '04X'), format(size, '04X')
            )
        )
