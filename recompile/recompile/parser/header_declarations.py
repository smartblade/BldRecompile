import re

from calling_convention import calling_conventions
import data_types
from make_tuple import make_tuple
import parser
from procedure_declaration import ProcedureDeclaration

typedef_regexp = re.compile(
    r'^typedef\s(?P<type_name>\w+)\s(?P<new_type_name>Eq_\d+);$')
extproc_regexp = re.compile(
    r'^(?P<return_type>.*)\s(?P<convention>__\w+)\s((?P<class_name>\w+)::)?'
    r'(?P<proc_name>(\w+)|operator\s[><]+)\((?P<parameters>.*)\);'
)


def parse_header_declarations(lines, defined_types):
    unions = {}
    classes = {}
    class_sizes = {}
    cur_class = None
    union_types = None
    ext_proc_dicts = []
    for line in lines:
        if line.startswith("//"):
            continue
        if line.startswith("typedef struct "):
            class_name = line.split(" ")[2]
            cur_class = {}
            tokens = line.split("// size: ")
            if len(tokens) > 1:
                class_sizes[class_name] = int(tokens[1].split(" ")[0])
        elif cur_class is not None:
            if line.startswith("}"):
                classes[class_name] = cur_class
                cur_class = None
                continue
            tokens = line.split("//")
            offset = int(tokens[1], 16)
            decl = tokens[0].strip().strip(";")
            var_type, var_name = parser.parse_variable_declaration(decl)
            cur_class[offset] = (var_type, var_name)
        elif line.startswith("typedef union Eq_"):
            union_name = line.split(" ")[2]
            union_types = {}
        elif union_types is not None:
            if line.startswith("}"):
                unions[union_name] = union_types
                union_types = None
                continue
            decl = line.strip().strip(";")
            var_type, var_name = parser.parse_variable_declaration(decl)
            union_types[var_type] = var_name
        else:
            match = re.search(typedef_regexp, line)
            if match:
                type_name = match.group('type_name')
                new_type_name = match.group('new_type_name')
                if type_name not in defined_types:
                    defined_types[type_name] = data_types.ClassType(
                        type_name, {}
                    )
                defined_types[new_type_name] = defined_types[type_name]
                continue
            match = re.search(extproc_regexp, line)
            if match:
                ext_proc_dicts.append(match.groupdict())
    for class_name in classes.keys():
        skip_offset_if_word32 = None
        new_fields = {}
        for offset, (var_type, var_name) in classes[class_name].items():
            if offset == skip_offset_if_word32 and var_type == "word32":
                continue
            if (
                var_type in unions and
                "real64" in unions[var_type] and
                "word32" in unions[var_type]
            ):
                # Merge 2 'word32' fields into 1 'double'
                var_type = "real64"
                skip_offset_if_word32 = offset + 4
            var_type = parser.parse_data_type(var_type, {})
            var_name = parser.define_field_name(var_type, var_name)
            if (
                class_name in class_sizes and
                len(classes[class_name]) == 1 and
                offset == 0 and
                class_sizes[class_name] % var_type.pointee.size == 0
            ):
                size = class_sizes[class_name] // var_type.pointee.size
                var_type = data_types.Array(var_type.pointee, size)
            new_fields[offset] = (var_type, var_name)
        defined_types[class_name] = data_types.ClassType(
            class_name, new_fields
        )
    external_procedures = []
    for ext_proc_dict in ext_proc_dicts:
        external_procedure = _make_external_procedure(
            defined_types, **ext_proc_dict
        )
        external_procedures.append(external_procedure)
    return make_tuple(
        'Declarations',
        defined_types=defined_types,
        external_procedures=external_procedures,
    )


def _make_external_procedure(
    defined_types, return_type, convention, class_name, proc_name, parameters
):
    return_type = parser.parse_data_type(return_type, defined_types)
    convention = calling_conventions[convention]
    if class_name is not None:
        method_class = defined_types[class_name]
    else:
        method_class = None
    parameters = parameters.split(',')
    parsed_parameters = []
    for p in parameters:
        var_type, var_name = parser.parse_variable_declaration(p.strip())
        var_type = parser.parse_data_type(var_type, defined_types)
        var_name = parser.define_parameter_name(var_type, var_name)
        parsed_parameters.append((var_type, var_name))
    external_procedure = ProcedureDeclaration(
        proc_name, convention, method_class, parsed_parameters, return_type
    )
    if method_class is not None:
        method_class.add_method(external_procedure)
    # TODO remove it when procedure name demangling will be implemented
    if external_procedure.proc_name.startswith("operator"):
        return _replace_pointers_to_references(external_procedure)
    return external_procedure


def _replace_pointers_to_references(proc):
    parameters = proc.get_parameters_ids()
    new_parameters = []
    for parameter in parameters.values():
        if isinstance(parameter.data_type, data_types.Pointer32):
            data_type = data_types.Reference(parameter.data_type.pointee)
            data_type.set_qualifiers(parameter.data_type.qualifiers)
        else:
            data_type = parameter.data_type
        new_parameters.append((data_type, parameter.name))
    if isinstance(proc.return_type, data_types.Pointer32):
        return_type = data_types.Reference(proc.return_type.pointee)
        return_type.set_qualifiers(proc.return_type.qualifiers)
    else:
        return_type = proc.return_type
    return ProcedureDeclaration(
        proc.proc_name, proc.convention, proc.method_class, new_parameters,
        return_type
    )
