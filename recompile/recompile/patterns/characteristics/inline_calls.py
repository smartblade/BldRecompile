import patterns.characteristics as characteristics


class InlineCalls:
    def __init__(self, json_list):
        self._inline_calls = []
        for inline_call_dict in json_list:
            self._inline_calls.append(
                characteristics.InlineCall(inline_call_dict))

    def by_this_offset(self, offset):
        for inline_call in self._inline_calls:
            if inline_call.this_offset == offset:
                return inline_call
        return None
