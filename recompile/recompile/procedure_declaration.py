from calling_convention import CallingConvention
import code_parser as parser
import data_types
from expressions import Identifier

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
    def method_class(self):
        return self._method_class

    @property
    def return_type(self):
        return self._return_arg

    def change_return_type(self, return_type):
        self._return_arg = return_type

    def get_parameters_ids(self):
        param_dict = {}
        if self._method_class is not None:
            param_name = "this"
            param_type = data_types.Pointer32(self._method_class)
            param_dict[param_name] = Identifier(param_type, param_name)
        for param_type, param_name in self._parameters:
            param_dict[param_name] = Identifier(param_type, param_name)
        return param_dict

    def get_used_types(self):
        types = {}
        for parameter_type, parameter_name in self._parameters:
            if (
                isinstance(parameter_type, data_types.Pointer32) and
                isinstance(parameter_type.pointee, data_types.ClassType)
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

    def get_declaration(
        self, is_metafile, is_definition=False, full_typed_args=None
    ):
        parameters = []
        if is_metafile and self._method_class is not None:
            is_brief = (
                full_typed_args is not None and
                "this" not in full_typed_args
            )
            if is_brief:
                this_arg = "ptr32 this"
            else:
                this_arg = "{} *this".format(self._method_class.class_name)
            parameters.append(this_arg)
        for parameter_type, parameter_name in self._parameters:
            is_brief = (
                full_typed_args is not None and
                parameter_name not in full_typed_args
            )
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
        return_arg = self._get_return_type_name(
            is_metafile=is_metafile, is_brief=full_typed_args is not None
        )
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
        if is_brief and isinstance(data_type, data_types.Pointer32):
            return "ptr32"
        return data_type.get_type_name(is_metafile=is_metafile)

    def _get_return_type_name(self, is_metafile, is_brief):
        if self._return_arg is None:
            return "void"
        if is_brief and isinstance(self._return_arg, data_types.Pointer32):
            return "ptr32"
        return self._return_arg.get_type_name(is_metafile=is_metafile)
