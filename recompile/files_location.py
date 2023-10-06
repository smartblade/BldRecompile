from contextlib import contextmanager
import os
import re

class FilesLocation:
    def __init__(self, root_directory):
        self._root_directory = root_directory
        self._reko_cmdline = self._path("..", "reko", "decompile.exe")
        self._decompile_file_part_py = self._path(
            "..", "projects", "decompile_file_part.py"
        )
        self._procedures_dict_file = self._path("procedures_dict.json")
        project_name = "Blade.dcproject"
        self._project_template = self._path(project_name)
        self._intermediate_project = self._path("intermediate", project_name)
        self._output = self._path("output")
        self._common_header_name = os.path.join(self._output, "common.h")
        self._compile_bat = self._path("compile.bat")

    @property
    def reko_cmdline(self):
        return self._reko_cmdline

    @property
    def decompile_file_part_py(self):
        return self._decompile_file_part_py

    @property
    def procedures_dict_file(self):
        return self._procedures_dict_file

    @property
    def project_template(self):
        return self._project_template

    @property
    def intermediate_project(self):
        return self._intermediate_project

    @property
    def output(self):
        return self._output

    @property
    def common_header_name(self):
        return self._common_header_name

    @property
    def compile_bat(self):
        return self._compile_bat

    def for_procedure(self, addr):
        return ProcedureFilesLocation(self._root_directory, addr)

    def _path(self, *args):
        return os.path.abspath(os.path.join(self._root_directory, *args))

class ProcedureFilesLocation(FilesLocation):
    def __init__(self, root_directory, addr):
        super().__init__(root_directory)
        self._addr = addr
        self._run_index = 0

    @contextmanager
    def next_run(self):
        files = ProcedureRunFilesLocation(
            self._root_directory, self._addr, self._run_index
        )
        try:
            yield files
        finally:
            self._run_index += 1

class ProcedureRunFilesLocation(FilesLocation):
    def __init__(self, root_directory, addr, run_index):
        super().__init__(root_directory)
        self._addr = addr
        self._run_index = run_index
        fname_regexp = re.compile('^(?P<fname>.+)\.(?P<ext>.+)')
        match = re.search(fname_regexp, self.intermediate_project)
        self._project_prefix = "{}_{}-{}.{}".format(
            match.group('fname'),
            addr,
            format(int(addr, 16) + 1, '08X'),
            match.group('ext'))

    @property
    def project(self):
        return self._add_run_suffix(self._project_prefix)

    @property
    def project_output(self):
        return self._project_relative(self.project_output_basename)

    @property
    def project_output_basename(self):
        return self._add_run_suffix(self._addr)

    @property
    def decl(self):
        return self._project_relative(self.decl_basename)

    @property
    def decl_basename(self):
        return "decl_{}.inc".format(self.project_output_basename)

    def _add_run_suffix(self, s):
        return "{}{}".format(s, "_" * self._run_index)

    def _project_relative(self, *args):
        return os.path.abspath(
            os.path.join(os.path.dirname(self.project), *args)
        )
