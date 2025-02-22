import os
import re

import data_types
import parser
from procedure_declaration import ProcedureDeclaration

from .xml_metadata import XmlMetadata

include_regexp = re.compile(r'^#include\s+["<](?P<file>.+)[">]')
comment_regexp = re.compile(r'^(?P<line>.*)//')
comment_start_regexp = re.compile(r'^(?P<line>.*)/\*')
comment_end_regexp = re.compile(r'\*/(?P<line>.*)$')
class_regexp = re.compile(
    r'^(class|struct)\s+(LIB_EXP\s+)?(?P<class>\w+)(?P<semicolon>;)?'
    r'(\s*:\s*public\s*(?P<parent>\w+))?')
template_regexp = re.compile(r'^template<class\s+(?P<class>\w+)>')

_standard_types = {
    "bool": data_types.ClassType("bool", {}),
    "char": data_types.Char(),
    "unsigned char": data_types.UChar(),
    "byte": data_types.make_named_type(data_types.UChar(), "byte"),
    "short": data_types.Short(),
    "unsigned short": data_types.UShort(),
    "int": data_types.Int32(),
    "long": data_types.make_named_type(data_types.Int32(), "long"),
    "unsigned int": data_types.UInt32(),
    "unsigned long": data_types.make_named_type(
        data_types.UInt32(), "unsigned long"),
    "float": data_types.Float(),
    "double": data_types.Double(),
    "BitMapType": data_types.make_named_type(data_types.Int32(), "BitMapType"),
    "B_CharData": data_types.ClassType("B_CharData", {}),
    "EventFn": data_types.Pointer32(),
}


class HeaderState:
    def __init__(
            self, file_name, header_states, declared_types, incomplete_types
    ):
        self._file_name = file_name
        self._header_states = header_states
        self._declared_types = declared_types
        self._incomplete_types = incomplete_types
        self._visited = False

    def parse(self):
        if self._visited:
            return
        self._visited = True
        with open(self._file_name) as f:
            lines = f.readlines()
        is_comment = False
        class_name = None
        parent_size = 0
        fields = None
        definition_chars = []
        brackets_depth = 0
        for line in lines:
            line, is_comment = _strip_comments(line, is_comment)
            self._try_parse_include_file(line)
            line = self._try_parse_template(line)
            match = re.search(class_regexp, line)
            if match and brackets_depth == 0:
                class_name = match.group("class")
                parent_name = match.group("parent")
                is_forward = bool(match.group("semicolon"))
                if class_name in self._incomplete_types:
                    fields = self._incomplete_types[class_name]
                    if fields and not is_forward:
                        raise Exception(
                            "Redeclared type: {}".format(class_name))
                else:
                    fields = {}
                    self._incomplete_types[class_name] = fields
                    self._declared_types[class_name] = data_types.ClassType(
                        class_name, fields)
                parent_size = 0
                if parent_name is not None:
                    class_type = self._declared_types[class_name]
                    parent = self._declared_types[parent_name]
                    class_type.set_parent(parent)
                    parent_size = parent.size
                if is_forward:
                    fields = None
                definition_chars = []
            for c in line:
                if c == "{":
                    brackets_depth += 1
                elif c == "}":
                    brackets_depth -= 1
                    if brackets_depth == 0 and fields is not None:
                        definition = "".join(definition_chars)
                        self._parse_class_definition(
                            class_name, definition, parent_size, fields)
                        fields = None
                if fields is not None and brackets_depth == 1:
                    definition_chars.append(c)

    def _parse_class_definition(
        self, class_name, definition, parent_size, fields
    ):
        offset = parent_size
        has_virtual_methods = False
        for field_definition in re.split(r'[{};]', definition):
            decl = self._parse_definition(class_name, field_definition)
            if decl is None:
                # Add space for vtable if necessary
                if (
                    offset == 0 and
                    not has_virtual_methods
                    and field_definition.find("virtual") >= 0
                ):
                    offset += 4
                    has_virtual_methods = True
                continue
            if isinstance(decl, ProcedureDeclaration):
                self._declared_types[class_name].add_method(decl)
                continue
            field_type, field_name = decl
            fields[offset] = field_type, field_name
            offset += field_type.size

    def _parse_definition(self, class_name, definition):
        definition = _strip_start(definition.strip(), "public:")
        definition = _strip_start(definition.strip(), "protected:")
        definition = _strip_start(definition.strip(), "private:")
        definition = definition.strip()
        if not definition:
            return
        is_static = definition.startswith("static")
        if definition.find("(") >= 0:
            if is_static:
                return parser.parse_cpp_function(
                    class_name, definition, self._declared_types)
            return
        if is_static:
            return
        if definition.startswith("enum"):
            return
        if re.search(class_regexp, definition):
            return
        field_type, field_name = parser.parse_cpp_variable_declaration(
            definition, self._declared_types)
        return field_type, field_name

    def _try_parse_include_file(self, line):
        match = re.search(include_regexp, line)
        if not match:
            return
        include_file = match.group("file")
        included_header_state = self._header_states.get(include_file)
        if included_header_state is not None:
            included_header_state.parse()

    def _try_parse_template(self, line):
        match = re.search(template_regexp, line)
        if not match:
            return line
        arg_class = match.group("class")
        self._declared_types[arg_class] = data_types.ClassType(arg_class, {})
        return re.sub(template_regexp, "", line).strip()


def _strip_start(definition, start):
    if definition.startswith(start):
        definition = definition[len(start):]
    return definition


def _strip_comments(line, is_comment):
    match = re.search(comment_regexp, line)
    if match:
        line = match.group("line")
    match = re.search(comment_start_regexp, line)
    if match:
        line = match.group("line")
        is_comment = True
    if is_comment:
        match = re.search(comment_end_regexp, line)
        if match:
            line = match.group("line")
            is_comment = False
        else:
            line = ""
    return line, is_comment


def _parse_cpp_headers(src_path, declared_types, incomplete_types):
    header_states = {}
    for (root, dirs, files) in os.walk(src_path):
        for file in files:
            if file.lower().endswith(".h") or file.lower().endswith(".xml"):
                file_name = os.path.join(root, file)
                head, dir_name1 = os.path.split(root)
                head, dir_name2 = os.path.split(head)
                if file.lower().endswith(".xml"):
                    metadata_state_class = XmlMetadata
                else:
                    metadata_state_class = HeaderState
                header_state = metadata_state_class(
                    file_name, header_states, declared_types, incomplete_types)
                header_states[file] = header_state
                header_states["{}/{}".format(dir_name1, file)] = header_state
                header_states[
                    "{}/{}/{}".format(
                        dir_name2, dir_name1, file)] = header_state
    for header_state in header_states.values():
        header_state.parse()


def parse_cpp_header(src_path):
    declared_types = _standard_types
    incomplete_types = {}
    extern_definitions_path = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "externdefs")
    _parse_cpp_headers(
        extern_definitions_path, declared_types, incomplete_types)
    _parse_cpp_headers(src_path, declared_types, incomplete_types)
    return declared_types
