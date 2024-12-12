import data_types
import expressions
import instructions
from patterns.make_proc_decl_from_args import make_proc_decl_from_args


class BlockBuilder:
    def __init__(self, instrs):
        self._instructions = instrs

    def merge_args_into_cdecl_procedure_call(self, expected_size):
        pc = self.try_pop_procedure_call()
        if pc is None:
            raise Exception(
                "Stack pointer restore should be after procedure call.")
        size = 0
        args = []
        while size < expected_size:
            arg = self._try_pop_arg_instruction()
            if arg is None:
                break
            args.append(arg)
            size += arg.data_type.size
            size = ((size + 3) // 4) * 4
        if size != expected_size:
            raise Exception(
                "Expected arguments size: {}, but was: {}.".format(
                    expected_size, size))
        proc_decl = make_proc_decl_from_args(
            callee_cleanup=False, args=args)
        assert pc.proc_decl is None
        pc = pc.copy(arguments=args, proc_decl=proc_decl)
        self.add_instruction(instructions.CodeInstruction(pc))

    def pop_reg_value(self, reg):
        if isinstance(self.last_instruction, instructions.ProcedureInfo):
            return self.last_instruction.pop_reg_value(reg)
        if isinstance(
            self.last_instruction, instructions.TemporaryRegisterDefinition
        ):
            value = self.last_instruction.pop_reg_value(reg)
            if self.last_instruction.is_empty():
                self.pop_instruction()
            return value
        if isinstance(self.last_instruction, instructions.CodeInstruction):
            return self._extract_call_return(reg)
        raise Exception(
            "Unexpected instruction type {}".format(
                type(self.last_instruction)))

    def _try_pop_arg_instruction(self):
        pc = self.try_pop_procedure_call("ARG", 1)
        if pc is None:
            return None
        return pc.arguments[0]

    def try_pop_procedure_call(self, name=None, num_arguments=0):
        if not isinstance(self.last_instruction, instructions.CodeInstruction):
            return None
        pc = self.last_instruction.expression
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
        self.pop_instruction()
        return pc

    def _try_pop_this_arg(self):
        if isinstance(
            self.last_instruction, instructions.TemporaryRegisterDefinition
        ):
            return self.pop_reg_value("ecx")
        return None

    def _try_merge_args_into_procedure_call(self):
        pc = self.try_pop_procedure_call()
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
        self.add_instruction(instructions.CodeInstruction(pc))

    def _extract_call_return(self, reg):
        return_types = {
            "ax": data_types.AnyInt16(),
            "eax": data_types.AnyInt32(),
        }
        return_type = return_types[reg]
        self._try_merge_args_into_procedure_call()
        assert isinstance(self.last_instruction, instructions.CodeInstruction)
        pc = self.last_instruction.expression
        assert isinstance(pc, expressions.ProcedureCall)
        assert pc.proc_decl is not None
        self.pop_instruction()
        assert pc.proc_decl.return_type is None
        pc.proc_decl.change_return_type(return_type)
        return pc

    @property
    def last_instruction(self):
        if not self._instructions:
            return None
        return self._instructions[-1]

    def add_instruction(self, instruction):
        self._try_merge_args_into_procedure_call()
        self._instructions.append(instruction)

    def pop_instruction(self):
        return self._instructions.pop()
