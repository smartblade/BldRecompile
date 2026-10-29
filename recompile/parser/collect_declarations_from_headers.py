import re

class_regexp = re.compile(r'^class\s+(LIB_EXP\s+)?(?P<class>\w+)')


def collect_declarations_from_headers(lines):
    declarations = []
    cur_declaration = None
    class_name = None
    brackets_depth = 0
    current_depth = 0
    is_comment = False
    stripped_lines = []
    for line_index, line in enumerate(lines):
        cur_line_buffer = []
        for c_index, c in enumerate(line):
            prev_c = line[c_index - 1] if c_index > 0 else None
            next_c = line[c_index + 1] if c_index + 1 < len(line) else None
            if (
                c == "/" and
                next_c == "/"
            ):
                break
            if (
                c == "/" and
                next_c == "*"
            ):
                is_comment = True
                continue
            if (
                prev_c == "*" and
                c == "/"
            ):
                is_comment = False
                continue
            if is_comment:
                continue
            cur_line_buffer.append(c)
            if c == "{":
                brackets_depth += 1
            elif c == "}":
                brackets_depth -= 1
        line = "".join(cur_line_buffer).strip()
        stripped_lines.append(line + "\n")
        new_declaration_at_next_line = False
        if (
            len(line) == 0 or line.startswith("#") or line.endswith("{") or
            line.endswith("}") or line.endswith(":")
        ):
            new_declaration_at_next_line = True
        match = class_regexp.search(line)
        if match and not line.endswith(";"):
            class_name = match.group("class")
            current_depth += 1
        if brackets_depth + 1 == current_depth and line.startswith("};"):
            class_name = None
            current_depth -= 1
            new_declaration_at_next_line = True
        elif brackets_depth == current_depth and line.endswith(";"):
            _add_declaration(
                declarations, cur_declaration, line_index, stripped_lines)
            new_declaration_at_next_line = True
        if new_declaration_at_next_line:
            cur_declaration = _HeaderDeclaration(class_name)
            cur_declaration.start_line = line_index + 1
    return declarations


def _add_declaration(declarations, declaration, end_line, lines):
    if declaration is None:
        return
    declaration.end_line = end_line
    declaration.make_declaration(lines)
    if declaration.declaration.count("(") != 1:
        return
    if " = " in declaration.declaration:
        return
    if declaration.declaration.startswith("typedef"):
        return
    declarations.append(declaration)


class _HeaderDeclaration:
    def __init__(self, class_name):
        self.class_name = class_name
        self.start_line = None
        self.end_line = None
        self.declaration = None

    def make_declaration(self, lines):
        self.declaration = "".join(
            lines[i] for i in range(self.start_line, self.end_line + 1)
        )
