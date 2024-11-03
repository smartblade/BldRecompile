import expressions
from hex_conversion import from_hex
import instructions
from patterns.high_level import make_high_level_code


class ProcedureBuilder:
    def __init__(self, proc_decl):
        self._instructions = []
        self._proc_decl = proc_decl
        if self._proc_decl is not None:
            self._method_class = self._proc_decl.method_class
        else:
            self._method_class = None

    def make_prolog(self, allocated):
        self._instructions.append(
            instructions.ProcedureInfo(
                self._method_class, int(allocated.emit_code())))

    def make_restore(self, restore):
        self._instructions.append(instructions.CodeInstruction(restore))

    def make_epilog(self):
        if (
            not self._try_pop_restore_instruction("esp") and
            self._expect_first_procedure_info().is_stack_pointer_trashed
        ):
            raise Exception("Changed stack pointer was not restored.")
        self._expect_first_procedure_info().set_stack_delta(0)
        self._instructions.append(instructions.ReturnInstruction(None))

    def make_assignment(self, dst, src):
        last_instruction = self._instructions[-1]
        if isinstance(last_instruction, instructions.ProcedureInfo):
            if last_instruction.is_this_expression(src):
                last_instruction.define_this_offset(dst)
                return
        self._instructions.append(instructions.Assignment(dst, src))

    def make_arg(self, arg):
        self._instructions.append(instructions.CodeInstruction(arg))

    def make_call(self, address):
        procedure_call = expressions.ProcedureCall(
            callee_addr=from_hex(address.emit_code()))
        last_instruction = self._instructions[-1]
        if isinstance(
            last_instruction, instructions.TemporaryRegisterDefinition
        ):
            this_arg = self.pop_reg_value("ecx")
            procedure_call = procedure_call.copy(
                is_method=True, arguments=[this_arg])
        self._instructions.append(instructions.CodeInstruction(procedure_call))

    def add_stack_pointer(self, offset):
        pc = self._try_pop_procedure_call()
        if pc is None:
            raise Exception(
                "Stack pointer restore should be after procedure call.")
        expected_size = from_hex(offset.emit_code())
        size = 0
        args = []
        while size < expected_size:
            arg = self._try_pop_arg_instruction()
            if arg is None:
                break
            args.append(arg)
            size += arg.data_type.size
        if size != expected_size:
            raise Exception(
                "Expected arguments size: {}, but was: {}.".format(
                    expected_size, size))
        pc = pc.copy(arguments=args)
        self._instructions.append(instructions.CodeInstruction(pc))

    def update_temporary_reg(self, dst, src):
        reg = dst.emit_code()
        tmp_def = self._instructions[-1]
        if not isinstance(tmp_def, instructions.TemporaryRegisterDefinition):
            tmp_def = instructions.TemporaryRegisterDefinition()
            self._instructions.append(tmp_def)
        tmp_def.define_reg_value(reg, src)

    def pop_reg_value(self, reg):
        last_instruction = self._instructions[-1]
        if isinstance(last_instruction, instructions.ProcedureInfo):
            return last_instruction.pop_reg_value(reg)
        if isinstance(
            last_instruction, instructions.TemporaryRegisterDefinition
        ):
            value = last_instruction.pop_reg_value(reg)
            if last_instruction.is_empty():
                self._instructions.pop()
            return value
        raise Exception(
            "Unexpected instruction type {}".format(type(last_instruction)))

    def _try_pop_restore_instruction(self, reg):
        pc = self._try_pop_procedure_call("RESTORE", 1)
        if pc is None:
            return False
        if pc.arguments[0].emit_code() != reg:
            raise Exception(
                "Expected restore of {} but was: {}.".format(
                    reg, pc.arguments[0].emit_code()))
        return True

    def _try_pop_arg_instruction(self):
        pc = self._try_pop_procedure_call("ARG", 1)
        if pc is None:
            return None
        return pc.arguments[0]

    def _try_pop_procedure_call(self, name=None, num_arguments=0):
        last_instruction = self._instructions[-1]
        if not isinstance(last_instruction, instructions.CodeInstruction):
            return None
        pc = last_instruction.expression
        if not isinstance(pc, expressions.ProcedureCall):
            return None
        if name is not None and pc.name != name:
            return None
        if len(pc.arguments) != num_arguments:
            raise Exception(
                "Expected {} argument of {} but was {}.".format(
                    num_arguments, pc.name, len(pc.arguments)))
        self._instructions.pop()
        return pc

    def _expect_first_procedure_info(self):
        first_instruction = self._instructions[0]
        if not isinstance(first_instruction, instructions.ProcedureInfo):
            raise Exception(
                "Unexpected first instruction type {}".format(
                    type(first_instruction)))
        return first_instruction

    def make_high_level_code(self, declarations):
        self._instructions = make_high_level_code(
            self._expect_first_procedure_info(),
            self._proc_decl,
            declarations,
            self._instructions,
        )

    def emit_code(self, writer):
        writer.write_line("{")
        with writer.indent():
            for instr in self._instructions:
                instr.emit_code(writer)
        writer.write_line("}")
