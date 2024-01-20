import hashlib
import subprocess


def execute_command(command):
    print("command started: {}".format(command))
    process = subprocess.Popen(command)
    code = process.wait()
    print("command finished with code {}".format(code))
    if code:
        raise Exception('Failed to execute {}.'.format(command))


def update_hash(hasher, file_name):
    with open(file_name, "rb") as f:
        hasher.update(f.read())
    return hasher.digest()


def is_hash_changed(hash_file_name, new_hash):
    try:
        with open(hash_file_name, "rb") as f:
            existing_hash = f.read()
            return existing_hash != new_hash
    except FileNotFoundError:
        return True


def write_hash(hash_file_name, new_hash):
    with open(hash_file_name, "wb") as f:
        f.write(new_hash)


def reko(files, has_decl_file=True):
    hasher = hashlib.sha256()
    update_hash(hasher, files.project)
    if has_decl_file:
        update_hash(hasher, files.decl)
    new_hash = hasher.digest()
    if not is_hash_changed(files.reko_hash, new_hash):
        print("Input files were not changed: skipping executing of Reko...")
        return
    execute_command([files.reko_cmdline, files.project])
    write_hash(files.reko_hash, new_hash)


def compile_cpp(files, cpp_file_name, header_file_name):
    hasher = hashlib.sha256()
    update_hash(hasher, cpp_file_name)
    update_hash(hasher, header_file_name)
    new_hash = hasher.digest()
    if not is_hash_changed(files.compile_hash, new_hash):
        print("Source files were not changed: skipping compilation...")
        return
    execute_command([files.compile_bat, cpp_file_name])
    write_hash(files.compile_hash, new_hash)
