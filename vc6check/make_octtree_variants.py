"""Make variants of OctTree.cpp with different declarations of constants.

- OctTree_const.cpp: 'static const double' instead of 'static double';
- OctTree_literal.cpp: literals instead of the variables.
"""
import re
import sys

CONSTANTS = {
    "child_size_divisor": "2.0",
    "child_offset_divisor": "4.0",
    "kOctTreeMargin": "10.0",
}

declaration_regexp = re.compile(
    r'^static double (?P<name>\w+) = (?P<value>[^;]+);(?P<eol>\r?\n)', re.M)


def make_variants(src_file_name, out_dir):
    with open(src_file_name, encoding="cp1251", newline="") as f:
        text = f.read()
    declarations = {
        match.group("name"): match.group("value")
        for match in declaration_regexp.finditer(text)
    }
    if declarations != CONSTANTS:
        raise Exception(
            "Unexpected declarations of constants: {}".format(declarations))
    const_text = declaration_regexp.sub(
        r'static const double \g<name> = \g<value>;\g<eol>', text)
    literal_text = declaration_regexp.sub("", text)
    for name, value in CONSTANTS.items():
        literal_text = re.sub(r'\b{}\b'.format(name), value, literal_text)
    for suffix, variant_text in (("const", const_text),
                                 ("literal", literal_text)):
        file_name = "{}/OctTree_{}.cpp".format(out_dir, suffix)
        with open(file_name, "w", encoding="cp1251", newline="") as f:
            f.write(variant_text)


if __name__ == "__main__":
    make_variants(sys.argv[1], sys.argv[2])
