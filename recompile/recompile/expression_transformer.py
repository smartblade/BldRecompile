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
    def transform_switch(index, case_set_dict, blocks_dict, **kwargs):
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
    def transform_identifier(identifier, **kwargs):
        return None

    @staticmethod
    def transform_increment(expression, **kwargs):
        return None

    @staticmethod
    def transform_implicit_cast(data_type, expression, **kwargs):
        return None

    @staticmethod
    def transform_field_access(expression, field_name, **kwargs):
        return None

    @staticmethod
    def transform_pre_increment(expression, **kwargs):
        return None

    @staticmethod
    def transform_procedure_call(
        copy_pc, proc_name, arguments, is_predefined, **kwargs
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
    def transform_pattern_text(text, **kwargs):
        return None

    @staticmethod
    def transform_pattern_variable(var_name, **kwargs):
        return None
