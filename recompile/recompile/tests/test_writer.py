import unittest

import data_types
import expressions
from expressions.operator import Operator
import instructions
from writer import Writer


class TestWriter(unittest.TestCase):
    @staticmethod
    def _write_instruction(instr):
        writer = Writer(max_line_len=80)
        instr.emit_code(writer)
        return "\n" + writer.get_string()

    def test_write_wrapped_if(self):
        a = expressions.Identifier(data_types.Int32(), "very_long_identifier_a")
        b = expressions.Identifier(data_types.Int32(), "very_long_identifier_b")
        c = expressions.Identifier(data_types.Int32(), "very_long_identifier_c")
        if_instr = instructions.IfInstruction(
            if_clause=expressions.Bin(
                Operator.AND,
                expressions.Bin(Operator.LT, a, b),
                expressions.Bin(Operator.GT, b, c),
            ),
            if_block=[],
        )

        code = self._write_instruction(if_instr)

        expected = """
if (
    very_long_identifier_a < very_long_identifier_b &&
    very_long_identifier_b > very_long_identifier_c
)
{
}
"""
        self.assertEqual(expected, code)

    def test_write_wrapped_if_and_add_lt(self):
        a = expressions.Identifier(data_types.Int32(), "very_long_identifier_a")
        b = expressions.Identifier(data_types.Int32(), "very_long_identifier_b")
        c = expressions.Identifier(data_types.Int32(), "very_long_identifier_c")
        if_instr = instructions.IfInstruction(
            if_clause=expressions.Bin(
                Operator.AND,
                expressions.ProcedureCall(name="p"),
                expressions.Bin(
                    Operator.LT,
                    expressions.Bin(Operator.ADD, a, b),
                    c,
                ),
            ),
            if_block=[],
        )

        code = self._write_instruction(if_instr)

        expected = """
if (
    p() &&
    very_long_identifier_a + very_long_identifier_b < very_long_identifier_c
)
{
}
"""
        self.assertEqual(expected, code)

    def test_write_wrapped_procedure_call(self):
        a = expressions.Identifier(data_types.Int32(), "very_long_identifier_a")
        b = expressions.Identifier(data_types.Int32(), "very_long_identifier_b")
        c = expressions.Identifier(data_types.Int32(), "very_long_identifier_c")
        if_instr = instructions.CodeInstruction(
            expressions.ProcedureCall(
                name="proc_abc",
                arguments=[a, b, c]
            )
        )

        code = self._write_instruction(if_instr)

        expected = """
proc_abc(
    very_long_identifier_a,
    very_long_identifier_b,
    very_long_identifier_c
);
"""
        self.assertEqual(expected, code)
