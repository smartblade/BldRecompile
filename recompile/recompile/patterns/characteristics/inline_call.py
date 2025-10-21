import patterns.characteristics as characteristics


class InlineCall:
    def __init__(self, json_dict):
        self._json_dict = json_dict
        self._arguments = []
        arguments = self._json_dict.get("arguments", [])
        for arg_dict in arguments:
            self._arguments.append(characteristics.InlineCallArgument(arg_dict))

    @property
    def this_offset(self):
        return int(self._json_dict["this"])

    @property
    def name(self):
        return self._json_dict["name"]

    @property
    def arguments(self):
        return self._arguments
