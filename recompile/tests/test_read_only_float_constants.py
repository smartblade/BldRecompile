from types import SimpleNamespace
import unittest

import data_types
import expressions
from patterns.collect_read_only_data import collect_read_only_data
from patterns.high_level.transform_global import transform_global
from patterns.high_level.transform_reinterpret import get_float_constant

CODE_LINES = [
    ";   Name   | VirtAddr | VirtSize |  Offset  | PhysSize |  Flags   | Code",
    "; .text    | 10001000 | 000408E2 | 00001000 | 00041000 | 60000020 |  Yes",
    "; .rdata   | 10042000 | 0000459D | 00042000 | 00005000 | 40000040 |  ",
    "; .data    | 10047000 | 00004F88 | 00047000 | 00003000 | C0000040 |  ",
    ";Section .rdata",
    "g10042000  dd 000000000h",
    "           dd 040240000h",
    "g10042008  dd 03F3504F3h",
    "g1004200C  dd g10047000",
    "g10042010  dd 2 dup (0)",
    "g10042018  dd 1 dup (?)",
    ";Section .data",
    "g10047000  dd 03F800000h",
]


def _get_constant(data_type, address):
    read_only_data = collect_read_only_data(CODE_LINES)
    expression = expressions.intermediate.Access(
        expressions.intermediate.Global(address), 0, data_type.size)
    declarations = SimpleNamespace(read_only_data=read_only_data)
    return get_float_constant(data_type, expression, declarations)


class TestReadOnlyFloatConstants(unittest.TestCase):
    def test_double_constant(self):
        self.assertEqual(10.0, _get_constant(data_types.Double(), 0x10042000))

    def test_float_constant(self):
        self.assertEqual(
            0.70710677, _get_constant(data_types.Float(), 0x10042008))

    def test_zero_constant(self):
        self.assertEqual(0.0, _get_constant(data_types.Double(), 0x10042010))

    def test_address_is_not_constant(self):
        self.assertIsNone(_get_constant(data_types.Float(), 0x1004200C))

    def test_unknown_data_is_not_constant(self):
        self.assertIsNone(_get_constant(data_types.Float(), 0x10042018))

    def test_writable_data_is_not_constant(self):
        self.assertIsNone(_get_constant(data_types.Float(), 0x10047000))

    def test_variable_at_float_constant(self):
        declarations = SimpleNamespace(
            symbols=SimpleNamespace(variables={
                0x10042000: SimpleNamespace(declaration="double margin;"),
            }),
            declared_types={"double": data_types.Double()},
            read_only_data=collect_read_only_data(CODE_LINES),
        )
        with self.assertRaisesRegex(Exception, "read only float constant"):
            transform_global(0x10042000, declarations)

    def test_variable_at_writable_data(self):
        declarations = SimpleNamespace(
            symbols=SimpleNamespace(variables={
                0x10047000: SimpleNamespace(declaration="float scale;"),
            }),
            declared_types={"float": data_types.Float()},
            read_only_data=collect_read_only_data(CODE_LINES),
        )
        variable = transform_global(0x10047000, declarations)
        self.assertEqual("&scale", variable.emit_code())
