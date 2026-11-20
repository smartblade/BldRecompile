import unittest

import parser
from tests.memory_file_tree import MemoryFileTree

# The declarations of the tests instead of recompile/parser/externdefs:
# reading all of them takes most of the time of a test
_procedures_xml = """<?xml version="1.0" encoding="utf-8"?>
<library xmlns="http://schemata.jklnet.org/Decompiler">
  <Types />
{}
</library>
"""

_procedure_xml = """  <procedure name="{}">
    <signature>
      <return>
        <prim domain="SignedInt" size="4" />
      </return>
    </signature>
  </procedure>"""

_externdefs = {
    "python.h": "#include <windows32.xml>\n#include <python.xml>\n",
    "windows.h": "#define FormatMessage FormatMessageA\n",
    "windows32.xml": _procedures_xml.format("\n".join(
        _procedure_xml.format(name)
        for name in ("FormatMessageA", "MessageBoxA"))),
    "python.xml": _procedures_xml.format(_procedure_xml.format("PyTuple_New")),
}


class TestCppHeaders(unittest.TestCase):
    @staticmethod
    def _external_procedures(header):
        src_tree = MemoryFileTree({"test.h": header})
        externdefs_tree = MemoryFileTree(_externdefs, root="externdefs")
        return parser.parse_cpp_header(src_tree, externdefs_tree)[2]

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
