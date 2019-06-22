# arm.py by RicBent
# Responsible for creating the instructions from the hook

import struct
import os
import subprocess

def run_proc(cmd):
    proc = subprocess.Popen(cmd.split(), shell=False)
    proc.communicate()
    return proc.wait()


branch_conditions = {
    'eq': 0,
    'ne': 1,
    'cs': 2,
    'cc': 3,
    'mi': 4,
    'pl': 5,
    'vs': 6,
    'vc': 7,
    'hi': 8,
    'ls': 9,
    'ge': 10,
    'lt': 11,
    'gt': 12,
    'le': 13,
    'al': 14, 
    ''  : 14
}

import struct

def make_branch_instruction(src, dest, link):

    if dest % 4 or src % 4:
        raise Exception('Source and destination must be 4 byte aligned')

    # Offset (2 complement, 26 bis)
    instruction = (dest // 4) - (src // 4)

    if not (-0x2000000 <= instruction <= 0x1FFFFFF):
        raise Exception('Out of bounds jump range!')

    instruction &= 0x03FFFFFF

    # Brach opcode
    instruction |= 0b00101 << 26

    # Link flag
    if link == True:
        instruction |= 0b1 << 31

    return struct.pack('<I', instruction)