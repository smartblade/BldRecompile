import re

from hex_conversion import from_hex

addr_export_regexp = re.compile(
    r'(?P<addr>[\dABCDEF]+)\s(?P<export_name>\S+)\s(?P<internal_name>\w+)'
)


def read_exports(file_name):
    with open(file_name) as f:
        lines = f.readlines()
    exported_procedures = {}
    for line in lines:
        match = re.search(addr_export_regexp, line)
        if match:
            addr = from_hex(match.group('addr'))
            export_name = match.group('export_name')
            internal_name = match.group('internal_name')
            if internal_name.startswith("l"):
                exported_procedures[addr] = export_name
    return exported_procedures
