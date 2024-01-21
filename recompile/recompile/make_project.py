import re
import shutil

import data_types
from hex_conversion import to_hex
from writer import Writer

intv_regexp = re.compile(r'procedure name="decompile_(?P<intv>[\d\-_ABCDEF]+)"')


def make_project_file(
    template_name, output_file_name, proc_addrs, declarations,
):
    with open(template_name) as f:
        lines = f.readlines()
    with open(output_file_name, "wt") as f:
        procedure_start = "<procedure name=\"{}\">\n"
        addr_str = "<address>{}</address>\n"
        cdecl_str = "<CSignature>{}</CSignature>\n"
        procedure_end = "</procedure>\n"
        global_start = "<global>\n"
        gbl_addr_str = "<Address>{}</Address>\n"
        name_str = "<Name>{}</Name>\n"
        global_end = "</global>\n"
        defined_procedures = set()
        procedure_declarations_inserted = False
        for line in lines:
            if "<address>" in line:
                defined_procedures.add(line[17:25])
            if "<registerValues />" in line:
                for addr in proc_addrs:
                    if addr in defined_procedures:
                        continue
                    proc_name, cdecl = declarations.get_declaration_at(addr)
                    f.write(" " * 6 + procedure_start.format(proc_name))
                    f.write(" " * 8 + addr_str.format(addr))
                    if cdecl is not None:
                        f.write(" " * 8 + cdecl_str.format(cdecl))
                    f.write(" " * 6 + procedure_end)
                for gbl in declarations.gbl_vars.values():
                    if gbl.data_type is None:
                        continue
                    f.write(" " * 6 + global_start)
                    f.write(" " * 8 + gbl_addr_str.format(to_hex(gbl.address)))
                    f.write(_type_to_xml(gbl.data_type))
                    f.write(" " * 8 + name_str.format(gbl.name))
                    f.write(" " * 6 + global_end)
                procedure_declarations_inserted = True
            f.write(line)
        if not procedure_declarations_inserted:
            raise Exception(
                'Failed to insert declarations of procedures to project file.'
            )


def set_decompiled_part(project_file_name, addr):
    with open(project_file_name) as f:
        lines = f.readlines()
    with open(project_file_name, "wt") as f:
        for line in lines:
            match = re.search(intv_regexp, line)
            if match:
                intv = match.group('intv')
                line = line.replace(intv, '{}'.format(addr))
            f.write(line)


def set_output_dir(project_file_name, output_dir):
    with open(project_file_name) as f:
        lines = f.readlines()
    with open(project_file_name, "wt") as f:
        for line in lines:
            if ".reko" in line:
                line = line.replace(".reko", output_dir)
            f.write(line)


def set_declarations(files, declarations, addr):
    metafile_created = declarations.emit_metafile(files.decl)
    if declarations.proc_decl is not None:
        cdecl = declarations.proc_decl.get_declaration(is_metafile=True)
    else:
        cdecl = None
    with open(files.project) as f:
        lines = f.readlines()
    with open(files.project, "wt") as f:
        cdecl_str = "<CSignature>{}</CSignature>\n"
        metadata_start = "<metadata>\n"
        filename_str = "<filename>{}</filename>\n"
        metadata_end = "</metadata>\n"
        decl_file_entry_written = False
        for line in lines:
            if not decl_file_entry_written and "<script>" in line:
                if metafile_created:
                    f.write(" " * 2 + metadata_start)
                    f.write(" " * 4 + filename_str.format(files.decl_basename))
                    f.write(" " * 2 + metadata_end)
                decl_file_entry_written = True
            f.write(line)
            if "<address>" in line and addr == line[17:25]:
                if cdecl is not None:
                    f.write(" " * 8 + cdecl_str.format(cdecl))


def make_procedure_project(files, callees, addr, declarations):
    if callees is not None:
        procs = [*callees, addr]
        make_project_file(
            files.project_template, files.project, sorted(procs), declarations,
        )
    else:
        shutil.copyfile(files.intermediate_project, files.project)
    set_decompiled_part(files.project, addr)


def _type_to_xml(data_type):
    writer = Writer(indent_length=2)
    with writer.indent():
        with writer.indent():
            with writer.indent():
                with writer.indent():
                    _write_xml_type(data_type, writer)
    return writer.get_string()


def _write_xml_type(data_type, writer):
    if isinstance(data_type, data_types.Pointer32):
        if data_type.pointee is None:
            writer.write_line('<prim domain="Pointer" size="4" />')
            return
        writer.write_line('<ptr size="4">')
        with writer.indent():
            _write_xml_type(data_type.pointee, writer)
        writer.write_line('</ptr>')
        return
    if isinstance(data_type, data_types.ClassType):
        writer.write_line("<type>{}</type>".format(data_type.class_name))
        return
    if isinstance(data_type, data_types.Unknown32):
        writer.write_line('<prim domain="Any" size="4" />')
        return
    raise Exception("Can't convert {} to xml.".format(data_type))
