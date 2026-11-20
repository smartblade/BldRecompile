import unittest

import parser
from tests.memory_file_tree import MemoryFileTree


class TestCppHeaders(unittest.TestCase):
    @staticmethod
    def _external_procedures(header):
        src_tree = MemoryFileTree({"test.h": header})
        return parser.parse_cpp_header(src_tree)[2]

    def test_macro_of_declarations_of_recompile(self):
        """'#define FormatMessage FormatMessageA' of externdefs/windows.h"""
        procedures = self._external_procedures("")
        self.assertEqual(
            "FormatMessage", procedures["FormatMessageA"].proc_name)

    def test_ansi_macro_of_sources(self):
        """'#define MessageBox MessageBoxA' of the sources"""
        procedures = self._external_procedures(
            "#define MessageBox MessageBoxA\n")
        self.assertEqual("MessageBox", procedures["MessageBoxA"].proc_name)

    def test_old_name_of_sources_is_not_used(self):
        """'#define newtupleobject PyTuple_New' of rename2.h of Python"""
        procedures = self._external_procedures(
            "#define newtupleobject PyTuple_New\n")
        self.assertEqual("PyTuple_New", procedures["PyTuple_New"].proc_name)
