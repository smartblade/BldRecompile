import instructions


class SwitchBuilder:
    def __init__(self):
        self._case_set_dict_by_table_address = {}
        self._current_table_address = None
        self._index = None

    def make_switch(self, index, address):
        case_set_dict = {}
        self._case_set_dict_by_table_address[address] = case_set_dict
        return instructions.Switch(index, case_set_dict, {})

    def start_table(self, address):
        self._current_table_address = address
        self._index = 0

    def add_address_entry(self, address_entry):
        assert address_entry.startswith("0x")
        label = "l{}".format(address_entry[2:])
        case_set_dict = self._case_set_dict_by_table_address[
            self._current_table_address]
        if label not in case_set_dict:
            case_set_dict[label] = set()
        case_set_dict[label].add(self._index)
        self._index += 1
