import data_types
import expressions


def convert_sizeof_arguments(arguments, proc_decl):
    if len(arguments) != 3:
        return arguments
    if proc_decl.method_class is None:
        return arguments
    parameters = list(proc_decl.get_parameters_ids().values())
    if len(parameters) != len(arguments):
        return arguments
    void_ptr_param_type = parameters[1].data_type
    if not isinstance(void_ptr_param_type, data_types.Pointer32):
        return arguments
    if void_ptr_param_type.pointee is not None:
        return arguments
    ptr_arg = arguments[1]
    if not isinstance(ptr_arg.data_type, data_types.Pointer32):
        return arguments
    pointee = ptr_arg.data_type.pointee
    if pointee is None:
        return arguments
    const_arg = arguments[2]
    if not isinstance(const_arg, expressions.Constant):
        return arguments
    if not const_arg.data_type.is_any_int:
        return arguments
    if const_arg.value != pointee.size:
        return arguments
    sizeof_expression = "sizeof({})".format(
        pointee.get_type_name(is_metafile=False))
    new_const_arg = expressions.NamedConstant(
        const_arg.data_type.size, sizeof_expression)
    new_arguments = list(arguments)
    new_arguments[2] = new_const_arg
    return new_arguments
