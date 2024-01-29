import os
import re

from hex_conversion import from_hex
from make_tuple import make_tuple

globals_imp_regexp = re.compile(
    r'^<anonymous>\s\*\s__imp__[\w@.?$]+\s=\s&g_t(?P<ptr_addr>[\dABCDEF]+);'
    r'\s//\s[\dABCDEF]+$'
)
word32_imp_regexp = re.compile(
    r'^word32 g_dw[\dABCDEF]+\s=\s(?P<value>(0x)?[\dABCDEF]+);'
    r'\s//\s[\dABCDEF]+$'
)


def reduce_header_file(header_file):
    with open(header_file) as f:
        lines = f.readlines()
    with open(header_file, "wt") as f:
        skip = False
        for line in lines:
            if line.startswith("//"):
                continue
            elif line.startswith("/*"):
                skip = True
            elif line.startswith("*/"):
                skip = False
                continue
            elif line.startswith("typedef struct Globals"):
                skip = True
            elif line.startswith("}"):
                if skip:
                    skip = False
                    continue
            if skip:
                continue
            f.write(line)


def reduce_globals_file(globals_file):
    with open(globals_file) as f:
        lines = f.readlines()
    imp_addresses = set()
    new_lines = []
    for line in lines:
        if line.startswith("\n"):
            continue
        if line.startswith("//"):
            continue
        if line.startswith("#"):
            continue
        match = re.search(globals_imp_regexp, line)
        if match:
            ptr_addr = match.group("ptr_addr")
            imp_addresses.add(from_hex(ptr_addr))
            continue
        match = re.search(word32_imp_regexp, line)
        if match:
            value = match.group("value")
            if value.startswith("0x"):
                value = from_hex(value)
            else:
                value = int(value)
            if value in imp_addresses:
                continue
        new_lines.append(line)
    if len(new_lines) == 0:
        os.remove(globals_file)
        return
    with open(globals_file, "wt") as f:
        for line in new_lines:
            f.write(line)
    return globals_file


def process_output_dir(output_dir):
    code_file = None
    header_file = None
    dis_file = None
    globals_file = None
    for root, dirs, files in os.walk(output_dir):
        for file in files:
            if file.endswith("globals.c"):
                globals_file = os.path.join(output_dir, file)
                globals_file = reduce_globals_file(globals_file)
            elif file.endswith(".c"):
                code_file = os.path.join(output_dir, file)
            elif file.endswith(".h"):
                header_file = os.path.join(output_dir, file)
                reduce_header_file(header_file)
            elif file.endswith(".dis"):
                dis_file = os.path.join(output_dir, file)
    return make_tuple(
        'OutputDirectory',
        code_file=code_file,
        header_file=header_file,
        dis_file=dis_file,
        globals_file=globals_file,
    )
