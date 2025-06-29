import bisect
import os
import re

from hex_conversion import from_hex, to_hex


def collectProceduresFromFile(fileName):
    mangledNames = {}
    nativeProcedures = set()
    declarations = {}
    f = open(fileName)
    lines = f.readlines()
    module_regexp = re.compile('Module:\s+(?P<module>[\S]+)')
    addr_regexp = re.compile('Entry\s+point:\s+0x(?P<addr>[\dABCDEF]+)')
    mangling_regexp = re.compile('VC\+\+\s+mangling:\s+(?P<mangling>[\S]+)')
    proc_regexp = re.compile('\W(?P<proc>\w+)\s*\([^\(\)]*\)')
    class_regexp = re.compile(r'^class\s+(LIB_EXP\s+)?(?P<class>\w+)')
    class_name = None
    meta = False
    definition_finished = True
    module = None
    addr_by_module = {}
    for line in lines:
        match = re.search(class_regexp, line)
        if match:
            class_name = match.group("class")
        if line.startswith("};"):
            class_name = None
        if line.find("/*") >= 0:
            meta = True
            module = None
            addr_by_module = {}
            mangling = None
        if line.find("*/") >= 0:
            meta = False
            definition = ""
            definition_finished = False
            for module, addr in addr_by_module.items():
                mangledNames[(module, addr)] = mangling
        if line.find("BLD_NATIVE") >= 0:
            for module, addr in addr_by_module.items():
                nativeProcedures.add((module, addr))
        if meta:
            match = re.search(module_regexp, line)
            if match:
                module = match.group('module')
            match = re.search(addr_regexp, line)
            if match:
                addr_by_module[module] = from_hex(match.group('addr'))
            match = re.search(mangling_regexp, line)
            if match:
                mangling = match.group('mangling')
        else:
            if (
                not definition_finished and
                line.find("*/") < 0 and
                not line.startswith("#")
            ):
                definition += line
            if not definition_finished and line.find("{") >= 0:
                definition_finished = True
                definition = definition.strip().strip("{")
                for module, addr in addr_by_module.items():
                    declarations[(module, addr)] = definition, class_name
        if (
            not meta and
            len(addr_by_module) > 0 and
            mangledNames[(module, addr_by_module[module])] is None
        ):
            if definition_finished:
                cdecl_mangling = None
                match = re.search(proc_regexp, definition)
                if match:
                    proc_name = match.group('proc')
                    cdecl_mangling = "_{}".format(proc_name)
                for module, addr in addr_by_module.items():
                    fallback = "fn{}".format(to_hex(addr))
                    mangledNames[(module, addr)] = cdecl_mangling or fallback
    f.close()
    procedures_dict = {}
    for key, mangled_name in mangledNames.items():
        is_implemented = key not in nativeProcedures
        if key in declarations:
            declaration, class_name = declarations[key]
        else:
            declaration = None
            class_name = None
        procedures_dict[key] = CppDeclaration(
            fileName, mangled_name, declaration, class_name, is_implemented)
    return procedures_dict


def collectVariablesFromFile(fileName):
    varNames = {}
    declarations = {}
    nativeVariables = set()
    f = open(fileName)
    lines = f.readlines()
    module_regexp = re.compile('Module:\s+(?P<module>[\S]+)')
    addr_regexp = re.compile('Data\s+address:\s+0x(?P<addr>[\dABCDEF]+)')
    mangling_regexp = re.compile('VC\+\+\s+mangling:\s+(?P<mangling>[\S]+)')
    name_regexp = re.compile('(\W+(?P<name>\w+)(\s*\[\s*\d*\s*\])*\s*)?(=\s*\d*\s*)?;')
    meta = False
    module = None
    addr_by_module = {}
    for line in lines:
        if line.find("/*") >= 0:
            meta = True
            module = None
            addr_by_module = {}
            mangling = None
        if line.find("*/") >= 0:
            meta = False
            for module, addr in addr_by_module.items():
                varNames[(module, addr)] = mangling
        if line.find("BLD_NATIVE") >= 0:
            for module, addr in addr_by_module.items():
                nativeVariables.add((module, addr))
        if meta:
            match = re.search(module_regexp, line)
            if match:
                module = match.group('module')
            match = re.search(addr_regexp, line)
            if match:
                addr_by_module[module] = from_hex(match.group('addr'))
            match = re.search(mangling_regexp, line)
            if match:
                mangling = match.group('mangling')
        elif len(addr_by_module) > 0:
            match = re.search(name_regexp, line)
            if match:
                for module, addr in addr_by_module.items():
                    declarations[(module, addr)] = line
                    if varNames[(module, addr)] is None:
                        varNames[(module, addr)] = "_{}".format(
                            match.group('name'))
                        nativeVariables.add((module, addr))
                addr_by_module = {}
    f.close()
    variables_dict = {}
    for key, mangled_name in varNames.items():
        is_implemented = key not in nativeVariables
        variables_dict[key] = CppDeclaration(
            fileName, mangled_name, declarations.get(key), None, is_implemented)
    return variables_dict


def collectSymbolsFromSources(src_dir):
    variables = {}
    procedures = {}
    for (root, dirs, files) in os.walk(src_dir):
        for file in files:
            if file.lower().endswith(".cpp") or file.lower().endswith(".h"):
                fileName = os.path.join(root, file)
                file_procs = collectProceduresFromFile(fileName)
                procedures.update(file_procs)
                file_vars = collectVariablesFromFile(fileName)
                variables.update(file_vars)
    return SrcSymbols.create_symbols_dict(
        variables,
        procedures,
    )


class CppDeclaration:
    def __init__(
        self, file_name, mangled_name, declaration, class_name, is_implemented
    ):
        self.file_name = file_name
        self.mangled_name = mangled_name
        self.declaration = declaration
        self.class_name = class_name
        self.is_implemented = is_implemented


class SrcSymbols:
    def __init__(self, module):
        self.variables = {}
        self.procedures = {}
        self._sorted_addresses = None
        self.module = module

    def is_implemented_procedure(self, addr):
        return addr in self.procedures and self.procedures[addr].is_implemented

    def is_implemented_variable(self, addr):
        return addr in self.variables and self.variables[addr].is_implemented

    def get_file_declarations(self, addr, files_declarations):
        if addr in self.procedures:
            found_addr = addr
        else:
            if self._sorted_addresses is None:
                self._sorted_addresses = sorted(self.procedures.keys())
            index = bisect.bisect_left(self._sorted_addresses, addr) - 1
            found_addr = self._sorted_addresses[index]
        return files_declarations[self.procedures[found_addr].file_name]

    @staticmethod
    def ensure_symbols_for_module(symbols_dict, module):
        symbols = symbols_dict.get(module)
        if symbols is None:
            symbols = SrcSymbols(module)
            symbols_dict[module] = symbols
        return symbols

    @staticmethod
    def create_symbols_dict(variables, procedures):
        symbols_dict = {}
        for (module, addr), variable in variables.items():
            symbols = SrcSymbols.ensure_symbols_for_module(symbols_dict, module)
            symbols.variables[addr] = variable
        for (module, addr), procedure in procedures.items():
            symbols = SrcSymbols.ensure_symbols_for_module(symbols_dict, module)
            symbols.procedures[addr] = procedure
        return symbols_dict

    @staticmethod
    def collect(src_dir):
        return collectSymbolsFromSources(src_dir)
