import unittest

import data_types
import parser


class TestCppFunction(unittest.TestCase):
    def test_conversion_operator_return_type(self):
        declared_types = {
            "B_Name": data_types.ClassType("B_Name", {}),
            "int": data_types.Int32(),
        }

        proc_decl = parser.parse_cpp_function(
            "B_Name", "operator int() const", declared_types)

        self.assertIsInstance(proc_decl.return_type, data_types.Int32)
        self.assertEqual("operator int() const", proc_decl.get_declaration())
