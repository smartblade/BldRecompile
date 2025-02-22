import xml.etree.ElementTree as ElementTree

from calling_convention import calling_conventions
import data_types
from procedure_declaration import ProcedureDeclaration


class XmlMetadata:
    def __init__(
        self, file_name, header_states, declared_types, incomplete_types
    ):
        self._file_name = file_name
        self._header_states = header_states
        self._declared_types = declared_types
        self._incomplete_types = incomplete_types
        self._structs = {}
        self._visited = False

    def parse(self):
        if self._visited:
            return
        self._visited = True
        tree = ElementTree.parse(self._file_name)
        root = tree.getroot()
        types = root.find("Types", _namespace)
        for type_elem in types:
            tag = _strip_namespace(type_elem.tag)
            if tag == "typedef":
                self._parse_typedef_element(type_elem)
            else:
                self._parse_type_element(type_elem)

    def _parse_typedef_element(self, typedef_elem):
        type_name = typedef_elem.attrib["name"]
        data_type = self._parse_type_element(typedef_elem[0])
        if isinstance(data_type, data_types.ClassType):
            fields = self._structs[data_type.class_name]
            self._structs[type_name] = fields
            self._incomplete_types[type_name] = fields
            defined_type = data_type.rename(type_name)
        else:
            defined_type = data_types.make_named_type(data_type, type_name)
        self._declared_types[type_name] = defined_type
        return defined_type

    def _parse_type_element(self, type_elem):
        type_kind = _strip_namespace(type_elem.tag)
        return _parser_by_type[type_kind](self, type_elem)

    def parse_struct_element(self, struct_elem):
        struct_name = struct_elem.attrib["name"]
        field_elements = struct_elem.findall("field", _namespace)
        if struct_name in self._structs:
            fields = self._structs[struct_name]
            if fields and len(field_elements) > 0:
                raise Exception(
                    "Redeclared type: {}".format(struct_name))
        else:
            fields = {}
            self._structs[struct_name] = fields
        for field_element in field_elements:
            offset = int(field_element.attrib["offset"])
            field_name = field_element.get(
                "name", "unnamed_field{}".format(offset))
            field_type = self._parse_type_element(field_element[0])
            fields[offset] = field_type, field_name
        return data_types.ClassType(struct_name, fields)

    def parse_union_element(self, union_elem):
        union_name = union_elem.get("name", "unnamed_union")
        fields = {}
        self._structs[union_name] = fields
        return data_types.ClassType(union_name, fields)

    def parse_pointer_element(self, ptr_elem):
        ptr_size = ptr_elem.get("size", 4)
        assert int(ptr_size) == 4
        pointee = self._parse_type_element(ptr_elem[0])
        if isinstance(pointee, ProcedureDeclaration):
            return data_types.Function(pointee)
        return data_types.Pointer32(pointee)

    def parse_array_element(self, array_elem):
        length = int(array_elem.get("length", 0))
        element_type = self._parse_type_element(array_elem[0])
        return data_types.Array(element_type, length)

    def parse_function_element(self, function_elem):
        convention = calling_conventions[
            function_elem.get("convention", "__cdecl")]
        return_elem = function_elem.find("return", _namespace)
        assert len(return_elem.attrib) == 0
        return_type = self._parse_type_element(return_elem[0])
        parameters = []
        for arg_elem in function_elem.findall("arg", _namespace):
            arg_type = self._parse_type_element(arg_elem[0])
            parameters.append((arg_type, None))
        return ProcedureDeclaration(
            None, convention, None, parameters, return_type)

    def parse_named_type_element(self, type_elem):
        assert len(type_elem.attrib) == 0
        return self._declared_types[type_elem.text]


def _strip_namespace(s):
    pos = s.find("}")
    return s[pos + 1:]


def _parse_primitive_element(primitive_elem):
    domain = primitive_elem.attrib["domain"]
    size = int(primitive_elem.attrib["size"])
    return _primitive_types[(domain, size)]()


def _parse_void_element(void_elem):
    assert len(void_elem.attrib) == 0
    return None


def _parse_enum_element(enum_elem):
    name = enum_elem.attrib["name"]
    return data_types.make_named_type(data_types.Int32(), name)


_namespace = {'': 'http://schemata.jklnet.org/Decompiler'}

_primitive_types = {
    ("Boolean", 1): data_types.Bool,
    ("Character", 1): data_types.Char,
    ("SignedInt", 1): data_types.Char,
    ("UnsignedInt", 1): data_types.UChar,
    ("SignedInt", 2): data_types.Short,
    ("UnsignedInt", 2): data_types.UShort,
    ("SignedInt", 4): data_types.Int32,
    ("UnsignedInt", 4): data_types.UInt32,
    ("SignedInt", 8): data_types.Unknown64,
    ("UnsignedInt", 8): data_types.Unknown64,
    ("Real", 4): data_types.Float,
    ("Real", 8): data_types.Double,
}

_parser_by_type = {
    "struct": lambda parser, elem: parser.parse_struct_element(elem),
    "union": lambda parser, elem: parser.parse_union_element(elem),
    "prim": lambda parser, elem: _parse_primitive_element(elem),
    "ptr": lambda parser, elem: parser.parse_pointer_element(elem),
    "arr": lambda parser, elem: parser.parse_array_element(elem),
    "fn": lambda parser, elem: parser.parse_function_element(elem),
    "type": lambda parser, elem: parser.parse_named_type_element(elem),
    "enum": lambda parser, elem: _parse_enum_element(elem),
    "void": lambda parser, elem: _parse_void_element(elem),
}
