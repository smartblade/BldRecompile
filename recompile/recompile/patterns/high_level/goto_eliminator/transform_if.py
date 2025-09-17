import data_types
import expressions
from expressions.operator import Operator
import instructions

from .collect_label_uses import collect_label_uses
from .eliminate_unused_label import eliminate_unused_label
from .transform_switch import transform_switch_statements


def transform_if_statements(instrs, label_uses, stack_vars, **kwargs):
    labeled_block = instrs[-1]
    if not isinstance(labeled_block, instructions.LabeledBlock):
        return instrs
    instrs = list(instrs)
    new_instructions = []
    i = 0
    while len(instrs) - i > 0:
        i += 1
        instr = instrs[-i]
        if i > 1:
            new_instructions.append(instr)
        goto_instr = _as_if_goto_instr(instr)
        if goto_instr is None:
            continue
        if goto_instr.label != labeled_block.label:
            continue
        del instrs[-i:]
        new_instructions.pop()
        new_instructions.reverse()
        switch = _try_make_switch(instr, new_instructions, label_uses)
        instrs.append(
            switch or
            _add_block_to_if_instruction(instr, new_instructions)
        )
        instrs.append(labeled_block)
        if switch is not None:
            instrs = transform_switch_statements(instrs, label_uses)
            instrs = _eliminate_switch_index_assignment(instrs, stack_vars)
        else:
            label_uses[goto_instr.label].remove(goto_instr)
            eliminate_unused_label(instrs, label_uses)
        labeled_block = instrs[-1]
        if not isinstance(labeled_block, instructions.LabeledBlock):
            break
        new_instructions = []
        i = 0
    return instrs


def _as_if_goto_instr(if_instruction):
    if not isinstance(if_instruction, instructions.IfInstruction):
        return None
    if if_instruction.else_block is not None:
        return None
    goto_instr = if_instruction.if_block[-1]
    if not isinstance(goto_instr, instructions.Goto):
        return None
    return goto_instr


def _add_block_to_if_instruction(if_instruction, instrs):
    assert if_instruction.else_block is None
    assert isinstance(if_instruction.if_block[-1], instructions.Goto)
    if len(if_instruction.if_block) == 1:
        return _make_if(
            expressions.do_logical_not(if_instruction.if_clause),
            instrs,
        )
    return instructions.IfInstruction(
        if_instruction.if_clause,
        if_instruction.if_block[:-1],
        instrs,
    )


def _make_if(clause, instrs):
    while True:
        if len(instrs) != 1:
            break
        if_instr = instrs[0]
        if not isinstance(if_instr, instructions.IfInstruction):
            break
        if if_instr.else_block is not None:
            break
        clause = expressions.Bin(Operator.AND, clause, if_instr.if_clause)
        instrs = if_instr.if_block
    return instructions.IfInstruction(clause, instrs)


def _try_make_switch(if_instruction, instrs, label_uses):
    case_item = _extract_switch_case(if_instruction)
    if case_item is None:
        return None
    index, case, goto_instr = case_item
    case_items = [case_item]
    if len(instrs) != 2 and len(instrs) != 3:
        return None
    last_goto = instrs[-1]
    if not isinstance(last_goto, instructions.Goto):
        return None
    for i in range(len(instrs) - 1):
        case_item = _extract_switch_case(instrs[i])
        if case_item is None:
            return None
        cur_index, case, goto_instr = case_item
        if cur_index.offset != index.offset or cur_index.size != index.size:
            return None
        case_items.append(case_item)
    case_set_dict = {}
    for case_item in case_items:
        index, case, goto_instr = case_item
        if goto_instr.label not in case_set_dict:
            case_set_dict[goto_instr.label] = set()
        case_set_dict[goto_instr.label].add(case)
        label_uses[goto_instr.label].remove(goto_instr)
    label_uses[last_goto.label].remove(last_goto)
    switch = instructions.Switch(index, case_set_dict, {}, last_goto.label)
    switch_label_uses = collect_label_uses([switch])
    for label, uses in switch_label_uses.items():
        cur_label_uses = label_uses.get(label, set())
        cur_label_uses |= uses
        label_uses[label] = cur_label_uses
    return switch


def _extract_switch_case(if_instruction):
    if not isinstance(if_instruction, instructions.IfInstruction):
        return None
    if if_instruction.else_block is not None:
        return None
    if len(if_instruction.if_block) != 1:
        return None
    goto_instr = if_instruction.if_block[-1]
    if not isinstance(goto_instr, instructions.Goto):
        return None
    clause = if_instruction.if_clause
    if not isinstance(clause, expressions.Bin):
        return None
    if clause.operator != Operator.EQ:
        return None
    right = clause.right
    if not isinstance(right, expressions.Constant):
        return None
    if not isinstance(right.data_type, data_types.UnknownTypes):
        return None
    left = clause.left
    if not isinstance(left, expressions.intermediate.Stackvar):
        return None
    return left, right.value, goto_instr


def _eliminate_switch_index_assignment(instrs, stack_vars):
    labeled_block = instrs[-1]
    switch = instrs[-2]
    switch_index_ass = instrs[-3]
    assert isinstance(switch, instructions.Switch)
    assert isinstance(switch_index_ass, instructions.Assignment)
    switch_index_ass_dst = switch_index_ass.dst
    assert isinstance(
        switch_index_ass_dst, expressions.intermediate.Stackvar)
    switch_index = switch.index
    assert isinstance(switch_index, expressions.intermediate.Stackvar)
    assert switch_index.offset == switch_index_ass_dst.offset
    assert switch_index.size == switch_index_ass_dst.size
    assert switch_index.offset not in stack_vars
    stack_vars[switch_index.offset] = expressions.Identifier(
        switch_index.data_type, "__switch_index")
    new_instrs = instrs[:-3]
    new_instrs.append(switch.copy(switch_index_ass.src))
    new_instrs.append(labeled_block)
    return new_instrs
