from double import Double
from float_type import Float

class Cast:
    def __init__(self, data_type, expression):
        self._data_type = data_type
        self._expression = expression

    def emit_code(self):
        expression_code = self._expression.emit_code()
        if self._is_implicit():
            return expression_code
        type_name = self._data_type.get_type_name(is_metafile=False)
        return "({}) {}".format(type_name, expression_code)

    def _is_implicit(self):
        # Cast float -> double can be done implicitly
        if (
            isinstance(self._data_type, Double) and
            isinstance(self._expression.data_type, Float)
        ):
            return True
        return False
