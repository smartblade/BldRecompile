from contextlib import contextmanager
import os
import shutil

class FilesLocation:
    def __init__(self, root_directory, cleanup=False):
        self._root_directory = root_directory
        self._reko_cmdline = self._path("..", "reko", "decompile.exe")
        self._decompile_file_part_py = self._path(
            "..", "projects", "decompile_file_part.py"
        )
        self._procedures_dict_file = self._path("procedures_dict.json")
        project_name = "Blade.dcproject"
        self._project_template = self._path(project_name)
        self._intermediate = self._path("intermediate")
        self._intermediate_project = os.path.join(
            self._intermediate, project_name
        )
        self._output = self._path("output")
        self._common_header_name = os.path.join(self._output, "common.h")
        self._compile_bat = self._path("compile.bat")
        if cleanup:
            self._cleanup()

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
    def intermediate(self):
        return self._intermediate

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

    def _cleanup(self):
        self._cleanup_directory(self.intermediate)
        self._cleanup_directory(self.output)

    def _cleanup_directory(self, directory):
        try:
            shutil.rmtree(directory)
        except FileNotFoundError:
            pass
        os.mkdir(directory)

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
        self._run_index = run_index
        run_dir = os.path.join(self.intermediate, addr)
        project_basename = os.path.basename(self.intermediate_project) + "_"
        self._project_prefix = os.path.join(run_dir, project_basename)
        self._ensure_directory(run_dir)

    @property
    def project(self):
        return self._add_run_suffix(self._project_prefix)

    @property
    def project_output(self):
        return self._project_relative(self.project_output_basename)

    @property
    def project_output_basename(self):
        return self._add_run_suffix("")

    @property
    def decl(self):
        return self._project_relative(self.decl_basename)

    @property
    def decl_basename(self):
        return "decl_{}.inc".format(self.project_output_basename)

    @property
    def reko_hash(self):
        return self._project_relative(self.reko_hash_basename)

    @property
    def reko_hash_basename(self):
        return "reko{}.hash".format(self.project_output_basename)

    def _add_run_suffix(self, s):
        return "{}{:02d}".format(s, self._run_index)

    def _project_relative(self, *args):
        return os.path.abspath(
            os.path.join(os.path.dirname(self.project), *args)
        )

    def _ensure_directory(self, directory):
        try:
            os.mkdir(directory)
        except FileExistsError:
            pass
