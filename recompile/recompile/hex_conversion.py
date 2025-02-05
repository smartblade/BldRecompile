def to_hex(n):
    return format(n, '08X')


def from_hex(h):
    return int(h, 16)


def to_int(s):
    if s.startswith("0x"):
        return from_hex(s)
    return int(s)
