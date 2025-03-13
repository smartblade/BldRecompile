import expressions
import instructions


class SwitchBuilder:
    def __init__(self):
        self._case_set_dict_by_table_address = {}
        self._labels_list_by_table_address = {}
        self._addr_labels_by_addr_indices = {}
        self._current_table_address = None
        self._index = None

    def make_switch(self, index, addr_addresses, addr_indices):
        case_set_dict = {}
        if addr_indices is not None:
            address = addr_indices
            self._labels_list_by_table_address[addr_addresses] = []
            self._addr_labels_by_addr_indices[addr_indices] = addr_addresses
        else:
            address = addr_addresses
        self._case_set_dict_by_table_address[address] = case_set_dict
        return instructions.Switch(index, case_set_dict, {})

    def start_table(self, address):
        self._current_table_address = address
        self._index = 0

    def add_address_entry(self, address_entry):
        assert address_entry.startswith("0x")
        label = "l{}".format(address_entry[2:])
        if self._current_table_address in self._labels_list_by_table_address:
            labels_list = self._labels_list_by_table_address[
                self._current_table_address]
            labels_list.append(label)
            return
        self._add_label_entry(label)

    def add_32bit_index_entry(self, index32):
        assert isinstance(index32, expressions.Constant)
        value = index32.value
        for i in range(4):
            self._add_index_entry(value % 256)
            value = value // 256

    def add_8bit_index_entry(self, index8):
        assert isinstance(index8, expressions.Constant)
        self._add_index_entry(index8.value % 256)

    def _add_index_entry(self, index):
        addr_labels = self._addr_labels_by_addr_indices[
            self._current_table_address]
        labels_list = self._labels_list_by_table_address[addr_labels]
        label = labels_list[index]
        self._add_label_entry(label)

    def _add_label_entry(self, label):
        case_set_dict = self._case_set_dict_by_table_address[
            self._current_table_address]
        if label not in case_set_dict:
            case_set_dict[label] = set()
        case_set_dict[label].add(self._index)
        self._index += 1
