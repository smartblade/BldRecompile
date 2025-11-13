import patterns.characteristics as characteristics


class Parameter(characteristics.Identifier):
    def __init__(self, json_dict):
        super().__init__(json_dict)
        self._json_dict = json_dict
        self._array_length = None
        array_length_dict = self._json_dict.get("arraylength")
        if array_length_dict is not None:
            self._array_length = characteristics.ArrayLength(array_length_dict)

    @property
    def array_length(self):
        return self._array_length
