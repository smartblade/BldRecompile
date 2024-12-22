def make_named_type(data_type, name):
    class _NamedType(NamedType, type(data_type)):
        pass
    return _NamedType(data_type, name)


class NamedType:
    def __init__(self, referenced_type, type_name):
        self.__referenced_type = referenced_type
        self.__name = type_name

    def __getattr__(self, attr_name):
        return getattr(self.__referenced_type, attr_name)

    @property
    def referenced_type(self):
        return self.__referenced_type

    def get_type_name(self, is_metafile):
        return self.__name
