import unittest

import data_types
import expressions
from patterns.high_level.transform_arrptr import transform_arrptr
from tests.builder import i32_id


def _node_pointer():
    node = data_types.ClassType("B_Node", {
        0: (data_types.Int32(), "count"),
        4: (data_types.Array(data_types.Pointer32(data_types.Int32()), 8),
            "children"),
    })
    return expressions.Identifier(data_types.Pointer32(node), "node")


class TestTransformArrptr(unittest.TestCase):
    def test_element_of_array_field(self):
        e = transform_arrptr(_node_pointer(), 4, i32_id("i"), 4)
        self.assertEqual("&node->children[i]", e.emit_code())

    def test_element_size_mismatch(self):
        self.assertIsNone(transform_arrptr(_node_pointer(), 8, i32_id("i"), 4))

    def test_not_array_field(self):
        self.assertIsNone(transform_arrptr(_node_pointer(), 4, i32_id("i"), 0))
