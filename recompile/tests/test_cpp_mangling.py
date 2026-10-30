import unittest

import parser


class TestCppMangling(unittest.TestCase):
    @staticmethod
    def _declaration(mangled_name):
        return parser.parse_cpp_mangling(mangled_name, {}).get_declaration()

    def test_operator_shr(self):
        self.assertEqual(
            "B_IDataFile &operator >>(B_IDataFile &arg_1, short &arg_2)",
            self._declaration("??5@YAAAVB_IDataFile@@AAV0@AAF@Z"))

    def test_operator_shl(self):
        self.assertEqual(
            "B_ODataFile &operator <<("
            "B_ODataFile &arg_1, const double &arg_2)",
            self._declaration("??6@YAAAVB_ODataFile@@AAV0@ABN@Z"))

    def test_operator_mul(self):
        self.assertEqual(
            "const B_Color &operator *(float arg_1) const",
            self._declaration("??DB_Color@@QBEABV0@M@Z"))

    def test_operator_add(self):
        self.assertEqual(
            "const B_Name &operator +(const char *arg_1) const",
            self._declaration("??HB_Name@@QBEABV0@PBD@Z"))

    def test_operator_div(self):
        self.assertEqual(
            "const B_Color &operator /(float arg_1) const",
            self._declaration("??KB_Color@@QBEABV0@M@Z"))

    def test_operator_ass(self):
        self.assertEqual(
            "const B_Name &operator =(const B_Name &arg_1)",
            self._declaration("??4B_Name@@QAEABV0@ABV0@@Z"))

    def test_operator_add_ass(self):
        self.assertEqual(
            "const B_Name &operator +=(const char *arg_1)",
            self._declaration("??YB_Name@@QAEABV0@PBD@Z"))

    def test_operator_lt(self):
        self.assertEqual(
            "unsigned int operator <(const B_Name &arg_1) const",
            self._declaration("??MB_Name@@QBEIABV0@@Z"))

    def test_operator_gt(self):
        self.assertEqual(
            "unsigned int operator >(const B_Name &arg_1) const",
            self._declaration("??OB_Name@@QBEIABV0@@Z"))
