from custom_block_transformer import transform_block
from hex_conversion import to_hex


class Procedure:
    def __init__(self, proc_info, address, proc_decl, instrs):
        self._proc_info = proc_info
        self._address = address
        self._proc_decl = proc_decl
        self._instructions = tuple(instrs)

    @property
    def proc_info(self):
        return self._proc_info

    @property
    def proc_decl(self):
        return self._proc_decl

    @property
    def address(self):
        return self._address

    @property
    def instructions(self):
        return self._instructions

    @property
    def implicit_stack_variables(self):
        stack_vars = self._proc_info.stack_variables
        if self._proc_decl is not None:
            stack_vars.update(self._proc_decl.stack_variables)
        return stack_vars

    def exclude_implicit_stack_variables(self, stack_vars):
        implicit_stack_variables = self.implicit_stack_variables
        return dict(
            (o, identifier) for o, identifier in stack_vars.items()
            if o not in implicit_stack_variables
        )

    def transform(self, transformer, **kwargs):
        new_instrs = transform_block(self._instructions, transformer, **kwargs)
        return Procedure(
            self._proc_info, self._address, self._proc_decl, new_instrs)

    def emit_code(self, writer, show_address=True, is_definition=True):
        if self._proc_decl is not None:
            decl_string = self._proc_decl.get_declaration(
                is_metafile=False, is_definition=is_definition)
        else:
            decl_string = "p{}".format(to_hex(self._address))
        if not show_address:
            writer.write_line()
        elif self._address is not None:
            writer.write_line("// address: 0x{}".format(to_hex(self._address)))
        else:
            writer.write_line("// address: inline")
        writer.write_line(decl_string)
        writer.write_line("{")
        with writer.indent():
            for instr in self._instructions:
                instr.emit_code(writer)
        writer.write_line("}")
