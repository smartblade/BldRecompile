def parse_excluded_procedures(lines, file_name):
    """Procedures not updated in the sources: a set of (module, address).

    The lines are 'MODULE:ADDRESS' with a hexadecimal address, e.g.
    'BBLibc.dll:100022D0'. Text after '#' is a comment, blank lines are
    ignored. file_name names the lines in errors.
    """
    procedures = set()
    for line_number, line in enumerate(lines, 1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        module, sep, addr = line.partition(":")
        if not sep or not module.strip() or not addr.strip():
            raise Exception(
                "{}:{}: expected MODULE:ADDRESS but was: {}".format(
                    file_name, line_number, line))
        procedures.add((module.strip(), int(addr.strip(), 16)))
    return procedures
