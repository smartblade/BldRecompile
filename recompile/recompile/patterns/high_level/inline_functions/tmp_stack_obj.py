import data_types
import expressions
from expression_transformer import ExpressionTransformer
import instructions


def transform_tmp_stack_obj(
    block_instructions, code_instr, stack_vars, **kwargs
):
    pc = code_instr.expression
    constructor = _extract_constructor(pc)
    if constructor is None:
        return
    constructor_class, obj_offset = constructor
    tmp_stack_alloc_chain = block_instructions.interval(2)
    assert tmp_stack_alloc_chain.as_instr(0, None) == code_instr
    last_instr = tmp_stack_alloc_chain.as_instr(2, instructions.CodeInstruction)
    if last_instr is None:
        return
    destructor = _extract_destructor(last_instr.expression)
    if destructor is None:
        return
    destructor_class, deleting_obj_offset = destructor
    if constructor_class != destructor_class:
        return
    if obj_offset != deleting_obj_offset:
        return
    instr = tmp_stack_alloc_chain.as_instr(1, None)
    transformer = _Transformer(obj_offset, pc)
    new_instr = instr.transform(transformer)
    if not transformer.is_valid:
        return
    assert obj_offset not in stack_vars
    stack_vars[obj_offset] = expressions.Identifier(
        constructor_class, "__tmp_stack_obj")
    tmp_stack_alloc_chain.replace_instructions([new_instr])


def _extract_constructor(pc):
    if not pc.is_method:
        return
    if pc.proc_decl is None:
        return
    if not pc.proc_decl.is_instance_method:
        return
    if not pc.proc_decl.is_constructor:
        return
    constructor_class = pc.proc_decl.method_class
    obj_offset = _extract_local_offset_from_cast(
        pc.arguments[0], constructor_class)
    if obj_offset is None:
        return
    return constructor_class, obj_offset


def _extract_destructor(pc):
    if not isinstance(pc, expressions.ProcedureCall):
        return
    if not pc.proc_decl.is_instance_method:
        return
    if not pc.proc_decl.is_destructor:
        return
    destructor_class = pc.proc_decl.method_class
    class_name = destructor_class.class_name
    if pc.proc_decl.proc_name != "~{}".format(class_name):
        return
    if len(pc.arguments) != 1:
        return
    obj_offset = _extract_local_offset_from_cast(
        pc.arguments[0], destructor_class)
    if obj_offset is None:
        return
    return destructor_class, obj_offset


def _extract_local_offset_from_cast(cast, required_class):
    if not isinstance(cast, expressions.ReinterpretCast):
        return
    cast_type_ptr = cast.data_type
    if not isinstance(cast_type_ptr, data_types.Pointer32):
        return
    cast_type = cast_type_ptr.pointee
    if not isinstance(cast_type, data_types.ClassType):
        return
    if cast_type != required_class:
        return
    obj = cast.expression
    if not isinstance(obj, expressions.intermediate.Local):
        return
    return obj.offset


class _Transformer(ExpressionTransformer):
    def __init__(self, obj_offset, constructor_call):
        self._obj_offset = obj_offset
        self._constructor_call = constructor_call
        self._num_variables = 0

    @property
    def is_valid(self):
        return self._num_variables == 1

    def transform_local(self, local, **kwargs):
        if local.offset == self._obj_offset:
            self._num_variables += 1
            return self._constructor_call
        return None

    def transform_stackvar(self, offset, size, **kwargs):
        obj_size = self._constructor_call.proc_decl.method_class.size
        if (
            self._obj_offset + obj_size > offset and
            self._obj_offset < offset + size
        ):
            self._num_variables += 1
