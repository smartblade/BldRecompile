import expressions
import instructions
from expression_transformer import ExpressionTransformer


def insert_declarations(procedure, stack_vars):
    collector = _IdentifiersCollector(
        procedure.exclude_implicit_stack_variables(stack_vars))
    collector.collect_identifiers(procedure.instructions)
    return procedure.transform(collector)


class _IdentifiersCollector(ExpressionTransformer):
    def __init__(self, local_stack_variables):
        self._local_variables_set = _make_variables_set(local_stack_variables)
        self._cur_path = []
        self._cur_instr = None
        self._ids = {}
        self._uses = {}
        self._to_be_declared_before = {}

    def collect_identifiers(self, instrs):
        self._collect(None, instrs)
        for identifier, (path, instr) in self._ids.items():
            ids = self._to_be_declared_before.get(instr)
            if ids is None:
                ids = []
                self._to_be_declared_before[instr] = ids
            ids.append(identifier)

    def _collect(self, parent_instr, instrs):
        self._cur_path.append((parent_instr, instrs))
        for instr in instrs:
            self._cur_instr = instr
            if isinstance(instr, instructions.IfInstruction):
                instr.if_clause.visit(self._on_visit)
                self._collect(instr, instr.if_block)
                if instr.else_block is not None:
                    self._collect(instr, instr.else_block)
            elif isinstance(instr, instructions.WhileInstruction):
                instr.clause.visit(self._on_visit)
                self._collect(instr, instr.block)
            elif isinstance(instr, instructions.ForInstruction):
                if instr.init is not None:
                    instr.init.visit(self._on_visit)
                instr.clause.visit(self._on_visit)
                instr.increment.visit(self._on_visit)
                self._collect(instr, instr.block)
            elif isinstance(instr, instructions.LabeledBlock):
                self._collect(instr, instr.instructions)
            else:
                instr.visit(self._on_visit)
        self._cur_path.pop()

    def _on_visit(self, e):
        if (
            isinstance(e, expressions.Identifier) and
            e in self._local_variables_set and
            not e.is_implicit
        ):
            self._update_id_path(e, self._cur_path, self._cur_instr)
            self._uses.setdefault(e, []).append(
                (tuple(self._cur_path), self._cur_instr))

    def _update_id_path(self, identifier, new_path, new_instr):
        if identifier not in self._ids:
            self._ids[identifier] = tuple(new_path), new_instr
            return
        existing_path, existing_instr = self._ids[identifier]
        new_path = _find_common_path(existing_path, new_path)
        if len(new_path) < len(existing_path):
            new_instr, path = existing_path[len(new_path)]
        else:
            new_instr = existing_instr
        self._ids[identifier] = new_path, new_instr

    def pre_transform_block_instructions(self, block_instructions, **kwargs):
        chain = block_instructions.interval(0)
        instr = chain.as_instr(0)
        ids = self._to_be_declared_before.get(instr)
        if ids is None:
            return
        ass = None
        if isinstance(instr, instructions.Assignment):
            ass = instr
        for_init = None
        if (
            isinstance(instr, instructions.ForInstruction) and
            isinstance(instr.init, instructions.Assignment) and
            self._is_used_only_in(instr.init.dst, instr)
        ):
            for_init = instr.init
        new_instructions = []
        for identifier in ids:
            if ass is not None and identifier == ass.dst:
                instr = instructions.VariableDeclaration(ass.dst, ass.src)
                ass = None
            elif for_init is not None and identifier == for_init.dst:
                # Declare variable in 'for' statement
                instr = instr.copy(init=instructions.VariableDeclaration(
                    for_init.dst, for_init.src))
                instr = instr.transform(self, **kwargs)
                for_init = None
            else:
                new_instructions.append(
                    instructions.VariableDeclaration(identifier, None))
        new_instructions.append(instr)
        chain.replace_instructions(new_instructions)

    def _is_used_only_in(self, identifier, instr):
        for path, use_instr in self._uses.get(identifier, []):
            if use_instr is instr:
                continue
            if not any(parent is instr for parent, _ in path):
                return False
        return True


def _find_common_path(first_path, second_path):
    i = 0
    while i < len(first_path) and i < len(second_path):
        if first_path[i] != second_path[i]:
            break
        i += 1
    max_common_len = i
    if len(first_path) == max_common_len:
        return first_path
    if len(second_path) == max_common_len:
        return second_path
    return first_path[0:max_common_len]


def _make_variables_set(stack_vars):
    variables_set = set()
    for offset, identifier in stack_vars.items():
        variables_set.add(identifier)
    return variables_set
