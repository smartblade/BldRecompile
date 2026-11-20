import os


class FileTree:
    """Files of the directory: the declarations are read only via the
    tree, so unit tests can give the files of the sources from memory."""

    def __init__(self, path):
        self._path = path

    def walk(self):
        """Paths of all files of the directory and its subdirectories."""
        for root, dirs, files in os.walk(self._path):
            for file in files:
                yield os.path.join(root, file)

    def open(self, file_name, mode="r"):
        return open(file_name, mode)
