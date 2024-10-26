import expressions
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
        last_instruction = self._instructions[-1]
        if not isinstance(last_instruction, instructions.CodeInstruction):
            return False
        pc = last_instruction.expression
        if not isinstance(pc, expressions.ProcedureCall):
            return False
        if pc.name != "RESTORE":
            return False
        if len(pc.arguments) != 1:
            raise Exception(
                "Expected {} argument of {} but was {}.".format(
                    1, pc.name, len(pc.arguments)))
        if pc.arguments[0].emit_code() != reg:
            return False
        self._instructions.pop()
        return True

    def _expect_first_procedure_info(self):
        first_instruction = self._instructions[0]
        if not isinstance(first_instruction, instructions.ProcedureInfo):
            raise Exception(
                "Unexpected first instruction type {}".format(
                    type(first_instruction)))
        return first_instruction

    def make_high_level_code(self):
        self._instructions = make_high_level_code(
            self._expect_first_procedure_info(),
            self._proc_decl,
            self._instructions,
        )

    def emit_code(self, writer):
        writer.write_line("{")
        with writer.indent():
            for instr in self._instructions:
                instr.emit_code(writer)
        writer.write_line("}")
