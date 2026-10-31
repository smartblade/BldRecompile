import unittest

import data_types
import parser


class TestCppVariableDeclaration(unittest.TestCase):
    def test_extern_variable(self):
        var_type, var_name = parser.parse_cpp_variable_declaration(
            "extern unsigned int gbl_node_count",
            {"unsigned int": data_types.UInt32()},
        )
        self.assertIsInstance(var_type, data_types.UInt32)
        self.assertEqual("gbl_node_count", var_name)
