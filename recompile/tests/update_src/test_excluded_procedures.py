import unittest

from update_src import parse_excluded_procedures


def _parse(lines):
    return parse_excluded_procedures(lines, "excluded_procedures.txt")


class TestExcludedProcedures(unittest.TestCase):
    def test_procedures(self):
        procedures = _parse([
            "# Procedures\n",
            "\n",
            "BBLibc.dll:100022D0  # B_Name::operator const char *\n",
            "Blade.exe: 0043F332\n",
        ])
        self.assertEqual(
            {("BBLibc.dll", 0x100022D0), ("Blade.exe", 0x0043F332)},
            procedures)

    def test_line_without_module(self):
        with self.assertRaisesRegex(Exception, "excluded_procedures.txt:1"):
            _parse(["100022D0\n"])


if __name__ == "__main__":
    unittest.main()
