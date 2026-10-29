class ExpressionTransformer:
    @staticmethod
    def transform_assignment(dst, src, **kwargs):
        return None

    @staticmethod
    def transform_code_instruction(expression, **kwargs):
        return None

    @staticmethod
    def transform_if(if_clause, if_block, else_block, **kwargs):
        return None

    @staticmethod
    def transform_switch(
        index, case_set_dict, blocks_dict, default_label, constant_dict,
        **kwargs
    ):
        return None

    @staticmethod
    def transform_return(expression, **kwargs):
        return None

    @staticmethod
    def transform_while(clause, block, **kwargs):
        return None

    @staticmethod
    def transform_array_access(array, index, **kwargs):
        return None

    @staticmethod
    def transform_binary(operator, left, right, **kwargs):
        return None

    @staticmethod
    def transform_cast(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_conditional_operator(
        if_clause, then_expression, else_expression, **kwargs
    ):
        return None

    @staticmethod
    def transform_constant(c, **kwargs):
        return None

    @staticmethod
    def transform_decrement(expression, **kwargs):
        return None

    @staticmethod
    def transform_dereference(expression, **kwargs):
        return None

    @staticmethod
    def transform_identifier(identifier, **kwargs):
        return None

    @staticmethod
    def transform_increment(expression, **kwargs):
        return None

    @staticmethod
    def transform_implicit_cast(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_implicit_dereference(expression, **kwargs):
        return None

    @staticmethod
    def transform_field_access(expression, field_name, **kwargs):
        return None

    @staticmethod
    def transform_make_reference(expression, **kwargs):
        return None

    @staticmethod
    def transform_pre_increment(expression, **kwargs):
        return None

    @staticmethod
    def transform_procedure_call(
        copy_pc, proc_name, arguments, **kwargs
    ):
        return None

    @staticmethod
    def transform_static_cast(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_reinterpret_cast(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_unary(operator, expression, **kwargs):
        return None

    @staticmethod
    def transform_unparsed_token(s, **kwargs):
        return None

    @staticmethod
    def transform_access(expression, offset, size, **kwargs):
        return None

    @staticmethod
    def transform_access_pattern(expression, offset, size, **kwargs):
        return None

    @staticmethod
    def transform_arrptr(base, scale, index, offset, **kwargs):
        return None

    @staticmethod
    def transform_arrptr_pattern(
        base, scale_pattern, index, offset_pattern, **kwargs
    ):
        return None

    @staticmethod
    def transform_eval(expression, **kwargs):
        return None

    @staticmethod
    def transform_expect(actual, expected, **kwargs):
        return None

    @staticmethod
    def transform_extern_variable_pattern(var_name, **kwargs):
        return None

    @staticmethod
    def transform_f(expression, **kwargs):
        return None

    @staticmethod
    def transform_global(address, **kwargs):
        return None

    @staticmethod
    def transform_global_pattern(var_name, **kwargs):
        return None

    @staticmethod
    def transform_i(expression, **kwargs):
        return None

    @staticmethod
    def transform_local(local, **kwargs):
        return None

    @staticmethod
    def transform_local_pattern(expression, **kwargs):
        return None

    @staticmethod
    def transform_pattern_text(text, **kwargs):
        return None

    @staticmethod
    def transform_pattern_variable(var_name, **kwargs):
        return None

    @staticmethod
    def transform_pop_fpu(**kwargs):
        return None

    @staticmethod
    def transform_real64_pattern(high_var_name, low_var_name, **kwargs):
        return None

    @staticmethod
    def transform_register_pattern(pattern, **kwargs):
        return None

    @staticmethod
    def transform_register_value(reg, **kwargs):
        return None

    @staticmethod
    def transform_s(expression, **kwargs):
        return None

    @staticmethod
    def transform_stackvar(offset, size, **kwargs):
        return None

    @staticmethod
    def transform_stackvar_pattern(offset_pattern, size_pattern, **kwargs):
        return None

    @staticmethod
    def transform_trash_extend(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_u(expression, **kwargs):
        return None

    @staticmethod
    def pre_transform_block_instructions(block_instructions, **kwargs):
        pass

    @staticmethod
    def transform_block_instructions(block_instructions, **kwargs):
        pass
