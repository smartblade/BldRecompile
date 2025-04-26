import data_types
from expressions.operator import Operator


class ImplicitDereference:
    def __init__(self, expression):
        self._expression = expression

    def __repr__(self):
        return "ImplicitDeref({})".format(self._expression)

    @property
    def data_type(self):
        data_type = self._expression.data_type
        assert isinstance(data_type, data_types.Reference)
        return data_type.referent

    def transform(self, transformer, **kwargs):
        expression = self._expression.transform(transformer, **kwargs)
        e = transformer.transform_implicit_dereference(expression, **kwargs)
        if e is not None:
            return e
        if expression == self._expression:
            return self
        return self.__class__(expression)

    def emit_code(self):
        return self._expression.emit_code()
