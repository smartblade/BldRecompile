from calling_convention import CallingConvention
from class_type import ClassType
import code_parser as parser
from identifier import Identifier
from pointer32 import Pointer32

class ProcedureDeclaration:
    def __init__(
        self, proc_name, convention, method_class, parameters, return_arg
    ):
        self._proc_name = proc_name
        self._convention = convention
        self._method_class = method_class
        self._return_arg = return_arg
        self._parameters = parameters

    @property
    def proc_name(self):
        return self._proc_name

    @property
    def return_type(self):
        return self._return_arg

    def change_return_type(self, return_type):
        self._return_arg = return_type

    def get_parameters_ids(self):
        param_dict = {}
        for param_type, param_name in self._parameters:
            param_dict[param_name] = Identifier(param_type, param_name)
        if self._method_class is not None:
            param_name = "this"
            param_type = Pointer32(self._method_class)
            param_dict[param_name] = Identifier(param_type, param_name)
        return param_dict

    def get_used_types(self):
        types = {}
        for parameter_type, parameter_name in self._parameters:
            if (
                isinstance(parameter_type, Pointer32) and
                isinstance(parameter_type.pointee, ClassType)
            ):
                class_type = parameter_type.pointee
                types[class_type.class_name] = class_type
        if self._method_class is not None:
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

    def get_declaration(self, is_metafile, is_definition=False, is_brief=False):
        parameters = []
        if is_metafile and self._method_class is not None:
            if is_brief:
                this_arg = "ptr32 this"
            else:
                this_arg = "{} *this".format(self._method_class.class_name)
            parameters.append(this_arg)
        for parameter_type, parameter_name in self._parameters:
            type_name = self._get_type_name(
                parameter_type, is_metafile, is_brief
            )
            sep = "" if type_name.endswith("*") else " "
            parameters.append("{}{}{}".format(type_name, sep, parameter_name))
        proc_name = self._proc_name
        if is_definition and self._method_class is not None:
            proc_name = "{}::{}".format(
                self._method_class.class_name, self._proc_name
            )
        return_arg = self._get_return_type_name(is_metafile=is_metafile)
        sep = "" if return_arg.endswith("*") else " "
        calling_convention = ""
        if is_metafile and self._convention == CallingConvention.THISCALL:
            calling_convention = "__thiscall "
        elif self._convention == CallingConvention.STDCALL:
            calling_convention = "__stdcall "
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

    def _get_type_name(self, data_type, is_metafile, is_brief):
        if is_brief and isinstance(data_type, Pointer32):
            return "ptr32"
        return data_type.get_type_name(is_metafile=is_metafile)

    def _get_return_type_name(self, is_metafile):
        if self._return_arg is None:
            return "void"
        return self._return_arg.get_type_name(is_metafile=is_metafile)
