"""Correction script for this exercise.
For each depot name found in depots.txt:
- clones the repo.
- confirms main.c is the same as the original.
- invokes make test.
- runs test.
- prints the return code of test or a negative value if an earlier error occured:
    - -1: failed to clone the repo.
    - -2: mismatch detected between original in main.c and depot's main.c.
    - -3: failed to compile.
"""

import hashlib
import itertools
import os
import platform

import pygit2

def hash_test_code(main_path):
    """Hashes all lines in file main_path.
       The same function was used to hash the original main.c."""
    with open(main_path) as main:
        test_code_hash = hashlib.sha256()
        for line in main:
            test_code_hash.update(line.encode())
    return test_code_hash.hexdigest()

PROFESSOR_TEST_CODE_HEXDIGEST = 'd4f15976f23772064cbc86d02fb3e7c366e354012eb242b29466f0abe9721cb0'
CALLBACKS = pygit2.RemoteCallbacks(credentials=pygit2.KeypairFromAgent("git"))

with open('depots.txt') as remote_depot_names:
    for remote_depot_name in itertools.dropwhile(lambda line: line.startswith('#'),
                                                 remote_depot_names):
        try:
            # Craft URL to clone given a deopt name.
            remote_depot_name = remote_depot_name.rstrip()
            remote_depot_url = 'ssh://git@github.com/' + remote_depot_name + '.git'
            local_depot_path = remote_depot_name.replace('/', '-')
            print(local_depot_path, end=' ')

            # Clone the repo.
            if pygit2.clone_repository(remote_depot_url, local_depot_path, callbacks=CALLBACKS) \
                    is None:
                raise RuntimeError('-1')

            # Confirm test code is intact.
            student_test_code_hexdigest = hash_test_code(local_depot_path + '/test/main.c')
            if student_test_code_hexdigest != PROFESSOR_TEST_CODE_HEXDIGEST:
                raise RuntimeError('-2')

            # Compile.
            if os.system('cd ' + local_depot_path + ' && make test') != 0:
                raise RuntimeError('-3')

            # Run and print result.
            print(str(os.WEXITSTATUS(os.system('cd ' + local_depot_path + ' && build/' + \
                      platform.system() + '/test'))))
        except pygit2.GitError:
            print('-1')
        except RuntimeError as error:
            print(error.args[0])
