import json
import argparse
import os
import os.path
import time

from common_header import create_common_header
from exceptions import SkippedProcedureException
from files_location import FilesLocation
from header_declarations import HeaderDeclarations
import make_project as prj
from process_procedure import process_procedure

argument_parser = argparse.ArgumentParser()
argument_parser.add_argument(
    "--rebuild", action='store_true', dest="rebuild",
    help="Clean up intermediate and output directories and rerun Reko."
)
options = argument_parser.parse_args()


def run():
    root_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..")
    files = FilesLocation(root_path, options.rebuild)
    with open(files.procedures_dict_file, "rt") as f:
        proc_dict = json.load(f)
    prj.make_project_file(
        files.project_template, files.intermediate_project, proc_dict.keys(),
        HeaderDeclarations(None, {}, {}, [], {})
    )
    create_common_header(files)
    recompiled_decls = {}
    for addr, proc in proc_dict.items():
        try:
            recompiled_decls[addr] = process_procedure(
                files.for_procedure(addr), addr, recompiled_decls
            )
        except SkippedProcedureException:
            print("Skipping {} procedure...".format(addr))
        if addr >= "00407E80":
            break


if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
