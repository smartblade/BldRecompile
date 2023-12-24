class DataType:
    def make_variable_declaration(self, var_name, is_metafile):
         return "{} {}".format(self.get_type_name(is_metafile), var_name)
