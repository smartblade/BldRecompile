import unittest

from calling_convention import CallingConvention
import data_types
import expressions
from patterns.high_level.call_arguments_matcher import CallArgumentsMatcher
from patterns.make_proc_decl_from_args import make_proc_decl_from_args
from procedure_declaration import ProcedureDeclaration


class TestCallArgumentsMatcher(unittest.TestCase):
    def test_unmatched_argument(self):
        args = [
            expressions.Identifier(data_types.Int32(), "a"),
            expressions.Identifier(data_types.Int32(), "b"),
        ]
        pc = expressions.ProcedureCall(
            name="f", arguments=args,
            proc_decl=make_proc_decl_from_args(args))
        proc_decl = ProcedureDeclaration(
            "f", CallingConvention.STDCALL, None,
            [(data_types.Int32(), "a")], None)
        pc = CallArgumentsMatcher().match_args(pc, proc_decl)
        self.assertEqual(["a"], [arg.emit_code() for arg in pc.arguments])
        self.assertEqual(4, pc.proc_decl.stack_delta)
