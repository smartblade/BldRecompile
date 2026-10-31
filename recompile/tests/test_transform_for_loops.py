import unittest

import data_types
import expressions
import instructions
from patterns.high_level.transform_for_loops import transform_for_loops
from tests.builder import ass, call_instr, i32_id, if_instr, lt
from writer import Writer


def _increment(name):
    return instructions.CodeInstruction(expressions.Increment(i32_id(name)))


def _const(value):
    return expressions.Constant(data_types.Int32(), value)


def _loop(init, body, rest, condition=None):
    """Make instructions compiled from 'for (init; i < n; i++) body'."""
    condition = condition or lt(i32_id("i"), i32_id("n"))
    return init + [
        instructions.Goto("l_cond"),
        instructions.LabeledBlock("l_inc", [
            _increment("i"),
            instructions.LabeledBlock("l_cond", [
                if_instr(condition, body + [instructions.Goto("l_inc")]),
            ] + rest),
        ]),
    ]


def _emit(instrs):
    writer = Writer()
    for instr in instrs:
        instr.emit_code(writer)
    return writer.get_string()


class TestTransformForLoops(unittest.TestCase):
    def test_for_loop(self):
        instrs = _loop(
            [ass(i32_id("i"), _const(0))],
            [call_instr(name="f", arguments=[i32_id("i")])],
            [call_instr(name="g")],
        )
        self.assertEqual(
            "for (i = 0; i < n; i++)\n"
            "{\n"
            "    f(i);\n"
            "}\n"
            "g();\n",
            _emit(transform_for_loops(instrs)))

    def test_for_loop_without_init(self):
        instrs = _loop(
            [ass(i32_id("j"), _const(0))],
            [call_instr(name="f")],
            [],
        )
        self.assertEqual(
            "j = 0;\n"
            "for (; i < n; i++)\n"
            "{\n"
            "    f();\n"
            "}\n",
            _emit(transform_for_loops(instrs)))

    def test_label_used_elsewhere(self):
        instrs = _loop(
            [ass(i32_id("i"), _const(0))],
            [if_instr(i32_id("c"), [instructions.Goto("l_inc")])],
            [],
        )
        self.assertIsInstance(
            transform_for_loops(instrs)[-1], instructions.LabeledBlock)
