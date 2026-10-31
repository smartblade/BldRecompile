import unittest

from parser.collect_symbols_from_sources import SrcSymbols


class TestCollectSymbolsFromSources(unittest.TestCase):
    def test_comment_before_definition(self):
        procedures = SrcSymbols.collect_procedures([
            "/*\n",
            "* Module:                 Blade.exe\n",
            "* Entry point:            0x0045327B\n",
            "*/\n",
            "\n",
            "// TODO double check\n",
            "int B_OctTreeSectorsList::BuildSurfaceCache()\n",
            "{\n",
            "}\n",
        ])
        self.assertEqual(
            "int B_OctTreeSectorsList::BuildSurfaceCache()",
            procedures[("Blade.exe", 0x0045327B)].declaration.strip())
