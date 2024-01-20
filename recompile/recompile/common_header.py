def create_common_header(files):
    with open(files.common_header_name, "wt") as f:
        f.write("#pragma once\n\n")
        f.write("#include <math.h>\n")
        f.write("#include <string.h>\n\n")
        f.write("typedef char unknown_byte;\n")
        f.write("typedef int unknown32;\n")
