import re

from calling_convention import CallingConvention
import data_types
import exceptions
import parser
from procedure_declaration import ProcedureDeclaration

procedure_regexp = re.compile(
    r'^((?P<return>.*[^:,])\s+)?((?P<class>\w+)::)?'
    r'(?P<name>~?\w+|operator\s*.*\S)\s*\(')

_standard_types = {
    "char": data_types.ClassType("char", {}),
    "unsigned char": data_types.ClassType("unsigned char", {}),
    "short": data_types.ClassType("short", {}),
    "unsigned short": data_types.ClassType("unsigned short", {}),
    "int": data_types.Int32(),
    "long": data_types.Int32(),
    "unsigned int": data_types.UInt32(),
    "unsigned long": data_types.UInt32(),
    "float": data_types.Float(),
    "double": data_types.Double(),
    "PyObject": data_types.ClassType("PyObject", {}),
    "B_IDataFile": data_types.ClassType(
        "B_IDataFile", {
            4: (
                data_types.Pointer32(data_types.ClassType("char", {})),
                "file_name",
            )
        }
    ),
    "B_ODataFile": data_types.ClassType("B_ODataFile", {}),
    "B_Name": data_types.ClassType("B_Name", {}),
    "B_NamedObj": data_types.ClassType("B_NamedObj", {}),
    "B_MessageChannel": data_types.ClassType("B_MessageChannel", {}),
    "B_MessageManager": data_types.ClassType("B_MessageManager", {}),
    "B_List": data_types.ClassType("B_List", {}),
    "B_ListElement": data_types.ClassType("B_ListElement", {}),
    "B_Resource": data_types.ClassType("B_Resource", {}),
    "B_ResourceManager": data_types.ClassType("B_ResourceManager", {}),
    "B_Color": data_types.ClassType("B_Color", {}),
    "B_BitMap": data_types.ClassType("B_BitMap", {}),
    "BitMapType": data_types.Int32(),
    "B_BitMap24": data_types.ClassType("B_BitMap24", {}),
    "B_RDataLight": data_types.ClassType("B_RDataLight", {}),
    "B_RDataTriangle": data_types.ClassType("B_RDataTriangle", {}),
    "B_MeshEdge": data_types.ClassType("B_MeshEdge", {}),
    "B_Pal": data_types.ClassType("B_Pal", {}),
    "B_3DRasterDevice": data_types.ClassType("B_3DRasterDevice", {}),
    "B_NDataBase<B_ElementCSV>": data_types.ClassType(
        "B_NDataBase<B_ElementCSV>", {}),
    "B_ParticleGType": data_types.ClassType("B_ParticleGType", {}),
    "B_ObjDscr": data_types.ClassType("B_ObjDscr", {}),
    "B_ElementCSV": data_types.ClassType("B_ElementCSV", {}),
}


def parse_cpp_function(class_name, func):
    declaration = parser.split_procedure_parameters(func)
    parameters = []
    declared_types = _standard_types
    arg_index = 0
    for (var_type, var_name) in declaration.parameters:
        arg_index += 1
        try:
            var_type = parser.parse_data_type(
                "{} {}".format(var_type, var_name).strip(), declared_types)
            var_name = "arg_{}".format(arg_index)
        except exceptions.UnknownTypeException:
            var_type = parser.parse_data_type(var_type, declared_types)
        parameters.append((var_type, var_name))
    match = re.search(procedure_regexp, func)
    if not match:
        raise Exception(
            "Failed to parse procedure declaration: {}".format(func))
    parsed_class_name = match.group("class")
    if class_name is not None:
        if parsed_class_name is not None:
            raise Exception(
                "Unexpected class name '{}' for '{}'".format(class_name, func))
    else:
        class_name = parsed_class_name
    if class_name is not None:
        method_class = parser.parse_data_type(class_name, declared_types)
    else:
        method_class = None
    return ProcedureDeclaration(
        proc_name=match.group("name"),
        convention=CallingConvention.THISCALL,
        method_class=method_class,
        parameters=parameters,
        return_arg=_extract_return_type(match.group("return"), declared_types),
    )


def _extract_return_type(s, declared_types):
    if s is None:
        return None
    s = s.replace("virtual", "")
    if not s:
        return None
    return parser.parse_data_type(s, declared_types)
