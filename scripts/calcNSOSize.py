import sys
from nso import NsoHeader

def fatal(msg):
    print(msg)
    sys.exit(1)

def roundSegment(size):
    size += 0xFFF
    size &= ~0xFFF
    return size


def main(argc, argv):
    
    if argc != 2:
        fatal('Usage: %s <nso>' % argv[0])

    try:
        nso_file = open(argv[1], "rb")
    except:
        fatal('Opening input NSO failed!')

    header = NsoHeader()
    header.load(nso_file.read())

    size = 0
    size += roundSegment(header.text_segment.decompressed_size)
    size += roundSegment(header.rodata_segment.decompressed_size)
    size += roundSegment(header.data_segment.decompressed_size + header.bss_size)

    print('Memory size of NSO \"%s\": 0x%08X' % (argv[1], size))
    sys.exit(0)

if __name__ == '__main__':
    main(len(sys.argv), sys.argv)