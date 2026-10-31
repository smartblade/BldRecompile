import unittest

import expressions
from expressions.operator import Operator
from tests.builder.expressions import i32_id


class TestAddressOf(unittest.TestCase):
    def test_address_of_assignment(self):
        assignment = expressions.Bin(Operator.ASS, i32_id("a"), i32_id("b"))
        self.assertEqual(
            "&(a = b)", expressions.AddressOf(assignment).emit_code())
