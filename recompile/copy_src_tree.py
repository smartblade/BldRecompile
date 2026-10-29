import os
import re

preprocessor_regexp = re.compile(
    r'^#(include\s+["<](?P<file>.+)[">]|'
    r'define\s+(?P<const_name>\S+)\s+(?P<const_value>.+))'
)
number_regexp = re.compile(r'^(0x[\dABCDEF]+|\d+)$')
module_regexp = re.compile(r'Module:\s+(?P<module>\S+)')
data_addr_regexp = re.compile(r'Data\s+address:\s+0x(?P<addr>[\dABCDEF]+)')
name_regexp = re.compile(
    r'(\W+(?P<name>\w+)(\s*\[\s*\d*\s*])*\s*)?(=\s*\d*\s*)?;')
templated_class_regexp = re.compile(
    r'^template<class\s+(?P<class>\w+)>\s+class')


def copy_src_tree(src_path, dst_path):
    cpp_files = []
    headers = {}
    for root, dirs, files in os.walk(src_path):
        relative_root = os.path.relpath(root, src_path)
        for file in files:
            src_file_name = os.path.join(root, file)
            dst_file_name = os.path.join(dst_path, relative_root, file)
            if file.lower().endswith(".h"):
                headers[file] = _Header(src_file_name, dst_file_name)
            elif file.lower().endswith(".cpp"):
                cpp_files.append(src_file_name)
    parser = _Parser(headers, _get_external_headers())
    for src_file_name in cpp_files:
        relative_path = os.path.relpath(src_file_name, src_path)
        dst_file_name = os.path.join(dst_path, relative_path)
        parser.process_cpp(src_file_name, dst_file_name)


def _get_external_headers():
    externdefs_path = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "parser", "externdefs")
    external_headers = set()
    for root, dirs, files in os.walk(externdefs_path):
        for file in files:
            if file.lower().endswith(".h"):
                relative_path = os.path.relpath(
                    os.path.join(root, file), externdefs_path)
                external_headers.add(relative_path.replace(os.sep, "/"))
    return external_headers


class _Header:
    def __init__(self, src_file_name, dst_file_name):
        self._src_file_name = src_file_name
        self._dst_file_name = dst_file_name
        self._processed = False
        self._is_empty = True

    @property
    def is_empty(self):
        return self._is_empty

    def process(self, parser):
        if self._processed:
            return
        self._processed = True
        if parser.process_header(self._src_file_name, self._dst_file_name):
            self._is_empty = False


class _Parser:
    def __init__(self, headers, external_headers):
        self._headers = headers
        self._external_headers = external_headers

    def process_cpp(self, src_file_name, dst_file_name):
        with open(src_file_name) as f:
            lines = f.readlines()
        output_lines = []
        definition_parser = _DefinitionParser()
        for line in lines:
            if self._try_parse_preprocessed_line(line, output_lines):
                continue
            definition_parser.parse(line, output_lines)
        if not definition_parser.definition_added:
            return
        _write_lines(dst_file_name, output_lines)

    def process_header(self, src_file_name, dst_file_name):
        with open(src_file_name) as f:
            lines = f.readlines()
        output_lines = []
        is_class = False
        template_line = None
        brackets_depth = 0
        definition_parser = _DefinitionParser()
        for line in lines:
            if self._try_parse_preprocessed_line(line, output_lines):
                continue
            if (
                (
                    line.startswith("class") or
                    line.startswith("struct") or
                    templated_class_regexp.search(line)
                ) and
                brackets_depth == 0
            ):
                if line.strip().endswith(";"):
                    output_lines.append(line)
                    continue
                is_class = True
                output_lines.append("\n")
                if template_line is not None:
                    output_lines.append(template_line)
            if line.startswith("template") and not is_class:
                template_line = line
                continue
            if is_class:
                output_lines.append(line)
                if line.startswith("};"):
                    is_class = False
            else:
                definition_parser.parse(line, output_lines)
            template_line = None
            for c in line:
                if c == "{":
                    brackets_depth += 1
                elif c == "}":
                    brackets_depth -= 1
        if len(output_lines) == 0:
            return False
        _write_lines(dst_file_name, output_lines)
        return True

    def _try_parse_preprocessed_line(self, line, output_lines):
        match = preprocessor_regexp.search(line)
        if match:
            include_file = match.group("file")
            if include_file in self._external_headers:
                output_lines.append(line)
                return True
            if include_file is not None:
                include_base_file = os.path.basename(include_file)
                header = self._headers.get(include_base_file)
                if header is None:
                    return True
                header.process(self)
                if header.is_empty:
                    return True
            const_value = match.group("const_value")
            if const_value is not None:
                const_value = const_value.strip()
                if not number_regexp.search(const_value):
                    return True
            output_lines.append(line)
            return True
        return False


class _DefinitionParser:
    def __init__(self):
        self._is_comment = False
        self._is_meta = False
        self._is_data = False
        self._is_definition = False
        self._definition = None
        self._definition_added = False
        self._meta_lines = None

    @property
    def definition_added(self):
        return self._definition_added

    def parse(self, line, output_lines):
        if line.find("/*") >= 0:
            self._is_comment = True
            self._is_meta = False
            self._is_data = False
            self._meta_lines = []
        if self._is_comment:
            self._meta_lines.append(line)
            match = re.search(module_regexp, line)
            if match:
                self._is_meta = True
            match = re.search(data_addr_regexp, line)
            if match:
                self._is_data = True
        if self._is_definition:
            if not line.startswith("#"):
                self._definition += line
            if line.find("{") >= 0:
                self._is_definition = False
                self._definition = self._definition.strip().strip("{").strip()
                output_lines.append("\n\n")
                output_lines.extend(self._meta_lines)
                output_lines.append("\n")
                output_lines.append("{}\n{{\n}}\n".format(self._definition))
                self._definition_added = True
            elif self._is_data and re.search(name_regexp, line):
                self._is_definition = False
                output_lines.append("\n")
                output_lines.extend(self._meta_lines)
                output_lines.append(line)
                self._definition_added = True
        if line.find("*/") >= 0:
            if self._is_meta:
                self._is_definition = True
                self._definition = ""
            self._is_comment = False


def _write_lines(file_name, lines):
    dst_directory = os.path.dirname(file_name)
    os.makedirs(dst_directory, exist_ok=True)
    with open(file_name, "wt") as f:
        for line in lines:
            f.write(line)
