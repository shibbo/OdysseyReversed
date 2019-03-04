# patchNSO.py
# Patches the MOD0 section of an NSO to properly set the user-runtime object offset

import subprocess
import os
import ntpath

project = ntpath.basename(os.getcwd())
subprocess.run("../tools/nsnsotool " + project + ".nso")

with open(project + ".nso", 'r+b') as nso_file:
    nso = nso_file.read()
    mod0_offset = nso.find(b'MOD0')
    nso_file.seek(mod0_offset + 8)
    bss_start = nso_file.read(4)
    nso_file.seek(mod0_offset + 24)
    nso_file.write(bss_start)
    nso_file.close()

print('patched')