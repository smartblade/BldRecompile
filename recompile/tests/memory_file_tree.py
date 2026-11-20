import io
import os


class MemoryFileTree:
    """FileTree of unit tests: the files are given by their contents."""

    def __init__(self, files, root="src"):
        self._files = {
            os.path.join(root, *path.split("/")): content
            for path, content in files.items()
        }

    def walk(self):
        return iter(self._files)

    def open(self, file_name, mode="r"):
        content = self._files[file_name]
        if "b" in mode:
            return io.BytesIO(content.encode())
        return io.StringIO(content)
