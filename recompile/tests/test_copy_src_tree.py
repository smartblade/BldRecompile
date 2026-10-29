import os
import tempfile
import unittest

from copy_src_tree import copy_src_tree

_definition = """

/*
* Module:                 BBLibc.dll
* Entry point:            0x10001000
* VC++ mangling:          ?Close@@YAXXZ
*/

void Close()
{
    close(0);
}
"""


class TestCopySrcTree(unittest.TestCase):
    @staticmethod
    def _copy_cpp(includes):
        with tempfile.TemporaryDirectory() as temp_dir:
            src_path = os.path.join(temp_dir, "src")
            dst_path = os.path.join(temp_dir, "dst")
            os.makedirs(src_path)
            with open(os.path.join(src_path, "File.cpp"), "wt") as f:
                f.write(includes + _definition)
            copy_src_tree(src_path, dst_path)
            with open(os.path.join(dst_path, "File.cpp"), "rt") as f:
                return f.read()

    def test_keep_include_of_external_header(self):
        code = self._copy_cpp("#include <io.h>\n")

        self.assertTrue(code.startswith("#include <io.h>\n"))

    def test_keep_include_of_external_header_in_subdirectory(self):
        code = self._copy_cpp("#include <sys/stat.h>\n")

        self.assertTrue(code.startswith("#include <sys/stat.h>\n"))

    def test_drop_include_of_unknown_header(self):
        code = self._copy_cpp("#include <windows.h>\n")

        self.assertNotIn("#include", code)
