import expressions
from hex_conversion import from_hex
import instructions
from patterns.high_level import make_high_level_code
from patterns.make_proc_decl_from_args import make_proc_decl_from_args


class ProcedureBuilder:
    def __init__(self, proc_decl):
        self._instructions = []
        self._proc_decl = proc_decl
        if self._proc_decl is not None:
            self._method_class = self._proc_decl.method_class
        else:
            self._method_class = None

    def make_prolog(self, allocated):
        self._add_instruction(
            instructions.ProcedureInfo(
                self._method_class, int(allocated.emit_code())))

    def make_restore(self, restore):
        self._add_instruction(instructions.CodeInstruction(restore))

    def make_epilog(self, size):
        if (
            not self._try_pop_restore_instruction("esp") and
            self._expect_first_procedure_info().is_stack_pointer_trashed
        ):
            raise Exception("Changed stack pointer was not restored.")
        stack_delta = from_hex(size.emit_code())
        self._expect_first_procedure_info().set_stack_delta(stack_delta)
        self._add_instruction(instructions.ReturnInstruction(None))

    def make_assignment(self, dst, src):
        if isinstance(self._last_instruction, instructions.ProcedureInfo):
            if self._last_instruction.is_this_expression(src):
                self._last_instruction.define_this_offset(dst)
                return
        self._add_instruction(instructions.Assignment(dst, src))

    def make_arg(self, arg):
        self._add_instruction(instructions.CodeInstruction(arg))

    def make_call(self, address):
        procedure_call = expressions.ProcedureCall(
            callee_addr=from_hex(address.emit_code()))
        self._add_instruction(instructions.CodeInstruction(procedure_call))

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
        proc_decl = make_proc_decl_from_args(
            callee_cleanup=False, args=args)
        assert pc.proc_decl is None
        pc = pc.copy(arguments=args, proc_decl=proc_decl)
        self._add_instruction(instructions.CodeInstruction(pc))

    def update_temporary_reg(self, dst, src):
        reg = dst.emit_code()
        tmp_def = self._last_instruction
        if not isinstance(tmp_def, instructions.TemporaryRegisterDefinition):
            tmp_def = instructions.TemporaryRegisterDefinition()
            self._add_instruction(tmp_def)
        tmp_def.define_reg_value(reg, src)

    def pop_reg_value(self, reg):
        if isinstance(self._last_instruction, instructions.ProcedureInfo):
            return self._last_instruction.pop_reg_value(reg)
        if isinstance(
            self._last_instruction, instructions.TemporaryRegisterDefinition
        ):
            value = self._last_instruction.pop_reg_value(reg)
            if self._last_instruction.is_empty():
                self._pop_instruction()
            return value
        raise Exception(
            "Unexpected instruction type {}".format(
                type(self._last_instruction)))

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
        if not isinstance(self._last_instruction, instructions.CodeInstruction):
            return None
        pc = self._last_instruction.expression
        if not isinstance(pc, expressions.ProcedureCall):
            return None
        if name is not None and pc.name != name:
            return None
        if name is None and pc.proc_decl is not None:
            return None
        if len(pc.arguments) != num_arguments:
            if name is None:
                return
            raise Exception(
                "Expected {} argument of {} but was {}.".format(
                    num_arguments, pc.name, len(pc.arguments)))
        self._pop_instruction()
        return pc

    def _try_pop_this_arg(self):
        if isinstance(
            self._last_instruction, instructions.TemporaryRegisterDefinition
        ):
            return self.pop_reg_value("ecx")
        return None

    def _try_merge_args_into_procedure_call(self):
        pc = self._try_pop_procedure_call()
        if pc is None:
            return
        args = []
        this_arg = self._try_pop_this_arg()
        if this_arg is not None:
            args.append(this_arg)
            pc = pc.copy(is_method=True)
        while True:
            arg = self._try_pop_arg_instruction()
            if arg is None:
                break
            args.append(arg)
        proc_decl = make_proc_decl_from_args(
            is_method=this_arg is not None, args=args)
        assert pc.proc_decl is None
        pc = pc.copy(arguments=args, proc_decl=proc_decl)
        self._add_instruction(instructions.CodeInstruction(pc))

    @property
    def _last_instruction(self):
        if not self._instructions:
            return None
        return self._instructions[-1]

    def _add_instruction(self, instruction):
        self._try_merge_args_into_procedure_call()
        self._instructions.append(instruction)

    def _pop_instruction(self):
        self._instructions.pop()

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
