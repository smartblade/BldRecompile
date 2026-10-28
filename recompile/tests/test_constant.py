import unittest

import data_types
import expressions


class TestConstant(unittest.TestCase):
    def test_emit_float(self):
        constant = expressions.Constant(data_types.Float(), 1.5)

        self.assertEqual("1.5F", constant.emit_code())

    def test_emit_double(self):
        constant = expressions.Constant(data_types.Double(), 1.5)

        self.assertEqual("1.5", constant.emit_code())

    def test_emit_unknown_byte(self):
        self.assertEqual(
            "0", expressions.Constant(data_types.UnknownByte(), 0).emit_code())
        self.assertEqual(
            "0x0A",
            expressions.Constant(data_types.UnknownByte(), 10).emit_code())

    def test_emit_bool(self):
        constant = expressions.Constant(data_types.Bool(), 1)

        self.assertEqual("true", constant.emit_code())
