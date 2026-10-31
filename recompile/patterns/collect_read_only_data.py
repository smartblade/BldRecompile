import re

from hex_conversion import from_hex

IMAGE_SCN_CNT_CODE = 0x00000020
IMAGE_SCN_MEM_WRITE = 0x80000000

section_info_regexp = re.compile(
    r'^;\s*(?P<name>\S+)\s*\|\s*(?P<addr>[\dABCDEF]{8})\s*\|'
    r'\s*(?P<size>[\dABCDEF]{8})\s*\|\s*[\dABCDEF]{8}\s*\|'
    r'\s*[\dABCDEF]{8}\s*\|\s*(?P<flags>[\dABCDEF]{8})\s*\|')
section_regexp = re.compile(r'^;Section (?P<name>\S+)')
labeled_data_regexp = re.compile(r'^g(?P<addr>[\dABCDEF]+)\s+(?P<data>d[bd]\s.*)$')
data_regexp = re.compile(r'^\s+(?P<data>d[bd]\s.*)$')
dup_regexp = re.compile(r'^(?P<count>\d+) dup \((?P<value>[^)]*)\)$')


class ReadOnlyData:
    def __init__(self, data):
        self._data = data

    def get_bytes(self, addr, size):
        """Return bytes of read only data or None if they are unknown."""
        values = [self._data.get(addr + i) for i in range(size)]
        if None in values:
            return None
        return bytes(values)


def collect_read_only_data(code_lines):
    """Collect known bytes of data sections which are not writable."""
    read_only_sections = set()
    is_read_only = False
    addr = None
    data = {}
    for line in code_lines:
        match = section_info_regexp.search(line)
        if match:
            flags = from_hex(match.group("flags"))
            if not flags & (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_WRITE):
                read_only_sections.add(match.group("name"))
            continue
        match = section_regexp.search(line)
        if match:
            is_read_only = match.group("name") in read_only_sections
            addr = None
            continue
        if not is_read_only or line.startswith(";"):
            continue
        match = labeled_data_regexp.search(line)
        if match:
            addr = from_hex(match.group("addr"))
        else:
            match = data_regexp.search(line)
            if not match or addr is None:
                addr = None
                continue
        addr = _parse_data(addr, match.group("data"), data)
    return ReadOnlyData(data)


def _parse_data(addr, line, data):
    line = line.split(";")[0].strip()
    size = 4 if line.startswith("dd") else 1
    value = line[2:].strip()
    count = 1
    match = dup_regexp.search(value)
    if match:
        count = int(match.group("count"))
        value = match.group("value").strip()
    if value.endswith("h") and value[0].isdigit():
        number = from_hex(value[:-1])
    elif value.isdigit():
        number = int(value)
    else:
        # Unknown value or address of a label
        number = None
    for _ in range(count):
        if number is not None:
            for i in range(size):
                data[addr + i] = (number >> (8 * i)) & 0xFF
        addr += size
    return addr
