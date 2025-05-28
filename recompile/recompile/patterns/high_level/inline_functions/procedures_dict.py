import expressions
import instructions
from calling_convention import CallingConvention
from procedure_declaration import ProcedureDeclaration
import patterns.high_level as high_level
from patterns.procedure import Procedure


class ProceduresDict:
    def __init__(self):
        self._classes = {}

    def add_destructor(self, destructor_class, this_offset, instrs):
        proc_info = instructions.ProcedureInfo(destructor_class, None)
        proc_info.define_this_offset(
            expressions.intermediate.Stackvar(this_offset, 4))
        proc_info.set_stack_delta(0)
        proc_info.pop_reg_value("ecx")
        proc_dict = self._classes.get(destructor_class.class_name)
        if proc_dict is None:
            proc_dict = {}
            self._classes[destructor_class.class_name] = proc_dict
        proc_name = "~{}".format(destructor_class.class_name)
        proc_decl = ProcedureDeclaration(
            proc_name, CallingConvention.THISCALL, destructor_class, [], None)
        assert proc_name not in proc_dict
        proc_dict[proc_name] = Procedure(proc_info, None, proc_decl, instrs)

    def make_high_level_code(self, declarations):
        for class_methods in self._classes.values():
            for name, procedure in class_methods.items():
                class_methods[name] = high_level.make_high_level_code(
                    procedure, declarations, None)

    def write_procedures(self, writer):
        for class_name, class_methods in self._classes.items():
            writer.write_line()
            writer.write_line("class {}".format(class_name))
            writer.write_line("{")
            with writer.indent():
                for procedure in class_methods.values():
                    procedure.emit_code(writer, is_definition=False)
            writer.write_line("};")
