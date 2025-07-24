import abc


class Token(abc.ABC):
    def __init__(self):
        self.length = None

    @abc.abstractmethod
    def wrap(self, wrap_manager):
        pass
