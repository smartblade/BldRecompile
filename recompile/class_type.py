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
        for offset, (field_type, field_name) in self._fields.items():
            indent = " " * 4
            type_name = field_type.get_type_name(is_metafile=True)
            lines.append("{}{} {};".format(indent, type_name, field_name))
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
            if len(method.parameters) > 0:
                raise Exception("Parameters are not implemented.")
            lines.append(
                "{}{}{}();".format(
                    indent,
                    method.return_arg,
                    method.proc_name,
                )
            )
        lines.append("")
        for offset, (field_type, field_name) in self._fields.items():
            type_name = field_type.get_type_name(is_metafile=False)
            lines.append("{}{} {};".format(indent, type_name, field_name))
        lines.append("};")
        return "\n".join(lines) + "\n"
