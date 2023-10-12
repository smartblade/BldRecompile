from class_type import ClassType
import code_parser as parser
from pointer32 import Pointer32
from unknown32 import Unknown32

class ProcedureDeclaration:
    def __init__(self, proc_name, method_class, parameters):
        self._proc_name = proc_name
        self._method_class = method_class
        self._return_arg = Unknown32()
        self._parameters = parameters

    @property
    def proc_name(self):
        return self._proc_name

    @property
    def return_type(self):
        return self._return_arg

    def change_return_type(self, return_type):
        self._return_arg = return_type

    def get_used_types(self):
        types = {}
        if self._method_class is None:
            raise Exception("Only thiscall is implemented.")
        for parameter_type, parameter_name in self._parameters:
            if (
                isinstance(parameter_type, Pointer32) and
                isinstance(parameter_type.pointee, ClassType)
            ):
                class_type = parameter_type.pointee
                types[class_type.class_name] = class_type
        types[self._method_class.class_name] = self._method_class
        return types

    def get_types_declarations(self, is_metafile):
        lines = []
        for data_type in self.get_used_types().values():
            alignment = data_type.alignment
            if (alignment):
                lines.append("#pragma pack(push, {})".format(alignment))
                lines.append("")
            lines.append(data_type.get_declaration(is_metafile))
            if (alignment):
                lines.append("#pragma pack(pop)")
                lines.append("")
        return "\n".join(lines)

    def get_declaration(self, is_metafile, is_definition=False):
        if self._method_class is None:
            raise Exception("Only thiscall is implemented.")
        parameters = []
        if is_metafile:
            this_arg = "{} *this".format(self._method_class.class_name)
            parameters.append(this_arg)
        for parameter_type, parameter_name in self._parameters:
            type_name = parameter_type.get_type_name(is_metafile=is_metafile)
            sep = "" if type_name.endswith("*") else " "
            parameters.append("{}{}{}".format(type_name, sep, parameter_name))
        proc_name = self._proc_name
        if is_definition:
            proc_name = "{}::{}".format(
                self._method_class.class_name, self._proc_name
            )
        return_arg = self._return_arg.get_type_name(is_metafile=is_metafile)
        sep = "" if return_arg.endswith("*") else " "
        calling_convention = ""
        if is_metafile:
            calling_convention = "__thiscall "
        return "{}{}{}{}({})".format(
            return_arg,
            sep,
            calling_convention,
            proc_name,
            ", ".join(parameters),
        )

    def extract_return_arg_from_line(self, line):
        name_pos = line.find(self._proc_name)
        self._return_arg = parser.parse_data_type(
            line[:name_pos].strip(), self.get_used_types()
        )
