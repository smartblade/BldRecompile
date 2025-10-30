import patterns.characteristics as characteristics


class Parameter:
    def __init__(self, json_dict):
        self._json_dict = json_dict
        self._array_length = None
        array_length_dict = self._json_dict.get("arraylength")
        if array_length_dict is not None:
            self._array_length = characteristics.ArrayLength(array_length_dict)

    @property
    def constant_set(self):
        return self._json_dict.get("constantset", None)

    @property
    def array_length(self):
        return self._array_length
