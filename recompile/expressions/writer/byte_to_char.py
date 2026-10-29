def byte_to_char(byte):
    if byte == 0:
        return "\\0"
    if byte == 10:
        return "\\n"
    if byte > 126:
        return "\\x{:X}".format(byte)
    return chr(byte)
