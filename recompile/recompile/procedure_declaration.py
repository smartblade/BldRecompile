import re

from calling_convention import CallingConvention
import data_types
import expressions
from expressions.operator import operators
import parser

operator_regexp = re.compile(r'^operator\s*(?P<op>\S+)$')


class ProcedureDeclaration:
    def __init__(
        self, proc_name, convention, method_class, parameters, return_arg,
        is_static=False,
    ):
        self._proc_name = proc_name
        self._convention = convention
        self._method_class = method_class
        self._return_arg = return_arg
        self._parameters = parameters
        self._is_static = is_static
        self._operator = self._get_operator()

    @property
    def proc_name(self):
        return self._proc_name

    @property
    def convention(self):
        return self._convention

    @property
    def method_class(self):
        return self._method_class

    @property
    def return_type(self):
        if self._return_arg is None and self.is_constructor:
            return data_types.Pointer32(self.method_class)
        return self._return_arg

    @property
    def is_static(self):
        return self._is_static

    @property
    def is_instance_method(self):
        return not self._is_static and self._method_class is not None

    @property
    def is_constructor(self):
        if self._method_class is None:
            return False
        return self._method_class.class_name == self._proc_name

    @property
    def is_destructor(self):
        return self._proc_name.startswith("~")

    @property
    def stack_delta(self):
        if self._convention == CallingConvention.CDECL:
            return 0
        stack_delta = 0
        for parameter_type, parameter_name in self._parameters:
            stack_delta += parameter_type.size
        return stack_delta

    @property
    def stack_variables(self):
        param_ids = list(self.get_parameters_ids().values())
        if self.is_instance_method:
            param_ids = param_ids[1:]
        offset = 8
        stack_dict = {}
        for param_id in param_ids:
            stack_dict[offset] = param_id
            offset += param_id.data_type.size
        return stack_dict

    @property
    def operator(self):
        return self._operator

    def _get_operator(self):
        if self._proc_name is None:
            return None
        match = re.search(operator_regexp, self._proc_name)
        if match:
            return operators[match.group("op")]
        return None

    def change_return_type(self, return_type):
        self._return_arg = return_type

    def get_parameters_ids(self, expected_args_types=False):
        make_id = expressions.Identifier
        param_dict = {}
        if self.is_instance_method:
            param_name = "this"
            reference_to = self._reference_to_this(expected_args_types)
            param_type = reference_to(self._method_class)
            param_dict[param_name] = make_id(param_type, param_name)
        for param_type, param_name in self._parameters:
            param_dict[param_name] = make_id(param_type, param_name)
        return param_dict

    def _reference_to_this(self, expected_args_types):
        if expected_args_types and self.operator is not None:
            return data_types.Reference
        return data_types.Pointer32

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
            parameter = self._make_variable_declaration(
                parameter_type, parameter_name, is_metafile, is_brief
            )
            parameters.append(parameter)
        proc_name = self._proc_name
        if is_definition and self._method_class is not None:
            proc_name = "{}::{}".format(
                self._method_class.class_name, self._proc_name
            )
        return_arg = self._get_return_type_name(
            is_metafile=is_metafile, is_brief=full_typed_args is not None
        )
        sep = "" if not return_arg or return_arg[-1] in {"*", "&"} else " "
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

    def extract_return_arg_from_line(self, line, declarations):
        name_pos = line.find(self._proc_name)
        self._return_arg = parser.parse_data_type(
            line[:name_pos].strip(), declarations.get_types_declarations()
        )

    def _make_variable_declaration(
        self, data_type, var_name, is_metafile, is_brief
    ):
        if is_brief and isinstance(data_type, data_types.Pointer32):
            return "ptr32 {}".format(var_name)
        return data_type.make_variable_declaration(var_name, is_metafile)

    def _get_return_type_name(self, is_metafile, is_brief):
        if not is_metafile and (self.is_constructor or self.is_destructor):
            return ""
        if self._return_arg is None:
            return "void"
        if is_brief and isinstance(self._return_arg, data_types.Pointer32):
            return "ptr32"
        return self._return_arg.get_type_name(is_metafile=is_metafile)
