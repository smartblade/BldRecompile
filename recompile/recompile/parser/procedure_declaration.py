from calling_convention import CallingConvention
import data_types
from hex_conversion import from_hex
from make_tuple import make_tuple
import parser
from procedure_declaration import ProcedureDeclaration


def split_procedure_parameters(s):
    start_brackets_pos = s.find("(")
    if start_brackets_pos < 0:
        raise Exception("Failed to parse declaration: '(' was not found.")
    end_brackets_pos = s.find(")")
    if end_brackets_pos < 0:
        raise Exception("Failed to parse declaration: ')' was not found.")
    parameters = s[start_brackets_pos + 1:end_brackets_pos].split(',')
    if len(parameters) == 1 and not parameters[0]:
        parameters = []
    parsed_parameters = []
    for p in parameters:
        parsed_parameters.append(parser.parse_variable_declaration(p.strip()))
    if parsed_parameters:
        var_type, var_name = parsed_parameters[0]
    else:
        var_name = None
    # Check if it is 'thiscall' convention
    if var_name == "ecx":
        class_type = var_type
        parameters = parsed_parameters[1:]
    else:
        class_type = None
        parameters = parsed_parameters
    return make_tuple(
        'ProcedureDeclaration',
        class_type=class_type,
        parameters=parameters
    )


def parse_procedure_declaration(proc, addr, stack_offset, fpu_offset, classes):
    par_by_orig_name = {}
    method_class = None
    if proc.class_type is not None:
        ptr_to_class = parser.parse_data_type(proc.class_type, classes)
        if isinstance(ptr_to_class, data_types.Pointer32):
            if ptr_to_class.pointee is None:
                method_class = data_types.ClassType("", {})
            else:
                method_class = ptr_to_class.pointee
        else:
            raise Exception(
                "Not supported type as method class: {}.".format(ptr_to_class)
            )
        method_class = _ensure_class_name(
            method_class, "unknown_class_{}".format(addr)
        )
        par_by_orig_name["ecx"] = "this"
    if proc.class_type is not None:
        convention = CallingConvention.THISCALL
    else:
        if stack_offset == 4:
            convention = CallingConvention.CDECL
        else:
            convention = CallingConvention.STDCALL
    parameters = []
    cur_offset = 4  # Return address size at stack
    for (var_type, var_name) in proc.parameters:
        offset = from_hex(var_name[-2:])
        _fill_unused_params(parameters, cur_offset, offset - cur_offset)
        var_type = parser.parse_data_type(var_type, classes)
        if (
                isinstance(var_type, data_types.Pointer32) and
                isinstance(var_type.pointee, data_types.ClassType)
        ):
            var_type = data_types.Pointer32(
                _ensure_class_name(
                    var_type.pointee,
                    "unknown_class_{}_p_{}".format(addr, var_name[-2:])
                )
            )
        par_by_orig_name[var_name] = parser.define_parameter_name(
            var_type, var_name
        )
        var_name = par_by_orig_name[var_name]
        parameters.append((var_type, var_name))
        cur_offset = offset + var_type.size
    if convention != CallingConvention.CDECL:
        _fill_unused_params(parameters, cur_offset, stack_offset - cur_offset)
    if fpu_offset == 1:
        return_arg = data_types.Double()
    else:
        return_arg = data_types.Unknown32()
    if method_class is not None:
        proc_name = "unknown_method_{}".format(addr)
    else:
        proc_name = "unknown_function_{}".format(addr)
    proc_decl = ProcedureDeclaration(
        proc_name=proc_name,
        convention=convention,
        method_class=method_class,
        parameters=parameters,
        return_arg=return_arg,
    )
    if method_class is not None:
        method_class.add_method(proc_decl)
    return par_by_orig_name, proc_decl


def _ensure_class_name(c, default_name):
    if not c.class_name or c.class_name.startswith("Eq_"):
        return c.rename(default_name)
    return c


def _fill_unused_params(parameters, offset, size):
    if size < 0:
        raise Exception(
            "Inconsistent parameters at {:X} before {:X} offset.".format(
                offset + size, offset
            )
        )
    if size % 4 != 0:
        raise Exception("Size {} should be multiple of 4.".format(size))
    for i in range(offset, offset + size, 4):
        parameters.append(
            (data_types.Unknown32(), "unused_param_{:02X}".format(i))
        )
