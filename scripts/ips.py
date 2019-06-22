# ips.py
# Writes IPS patches to a .ips file

import struct

def writeHeader(s):
    s.write(bytes('IPS32', 'utf-8'))

def writeEOF(s):
    s.write(bytes('EEOF', 'utf-8'))

def writeRec(s, offset, data):
    # each is structured with an offset as a 32-bit value, and the length of the data being a 16-bit value
    s.write(struct.pack('>I', offset))
    s.write(struct.pack('>H', len(data)))
    s.write(data)