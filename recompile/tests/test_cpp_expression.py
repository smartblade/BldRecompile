import unittest

import data_types
import expressions
import parser


class TestCppExpressionCast(unittest.TestCase):
    @staticmethod
    def _parse(s):
        return parser.parse_cpp_expression(s, {}, {})

    def test_cast_to_type(self):
        e = self._parse("(real64) x")

        self.assertIsInstance(e, expressions.Cast)
        self.assertIsInstance(e.data_type, data_types.Double)
        self.assertEqual("x", e.expression.emit_code())

    def test_cast_to_pointer(self):
        e = self._parse("(word32 *) x")

        self.assertIsInstance(e, expressions.Cast)
        self.assertIsInstance(e.data_type, data_types.Pointer32)
        self.assertIsInstance(e.data_type.pointee, data_types.Unknown32)
        self.assertEqual("x", e.expression.emit_code())
