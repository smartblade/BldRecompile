import unittest

import data_types
import expressions


class TestDoReinterpret(unittest.TestCase):
    def test_null_ptr_is_not_named(self):
        c = expressions.NamedConstant(
            data_types.Unknown32(), "NAME_C", 0)
        ptr = expressions.do_reinterpret(data_types.Pointer32(), c)
        self.assertEqual("nullptr", ptr.emit_code())

    def test_constant_keeps_name(self):
        c = expressions.NamedConstant(data_types.Int32(), "sizeof(float)", 4)
        size = expressions.do_reinterpret(data_types.UInt32(), c)
        self.assertEqual("sizeof(float)", size.emit_code())

    def test_size_t_keeps_name(self):
        c = expressions.NamedConstant(
            data_types.AnyInt(4), "IFILE_CACHE_SIZE", 4096)
        size = expressions.do_reinterpret(data_types.SizeT(), c)
        self.assertEqual("IFILE_CACHE_SIZE", size.emit_code())

    def test_negated_constant_keeps_name(self):
        c = expressions.NamedConstant(
            data_types.AnyInt(4), "-IFILE_CACHE_SIZE", 0xFFFFF000)
        position = expressions.do_reinterpret(data_types.Int32(), c)
        self.assertEqual("-IFILE_CACHE_SIZE", position.emit_code())

    def test_sign_change_keeps_name(self):
        c = expressions.NamedConstant(data_types.UInt32(), "FLAG", 0x80000000)
        flag = expressions.do_reinterpret(data_types.Int32(), c)
        self.assertEqual("FLAG", flag.emit_code())
