import sys
import struct
import hashlib
import lz4.block

from nso import NsoHeader
from elftools.elf.elffile import ELFFile
from elftools.common.exceptions import ELFError, ELFParseError


def fatal(msg):
    print(msg)
    sys.exit(1)


def main(argc, argv):

    # Check arguments
    if argc < 3:
        fatal('Usage: %s <input elf> <output nso> [flags]\n -c  compress\n -s  check segment checksums' % argv[0])
    
    do_compress  = '-c' in argv[3:]
    do_checksums = '-s' in argv[3:]


    # Load ELF
    try:
        elf = ELFFile(open(argv[1], 'rb'))
    except IOError:
        fatal('Opening ELF for reading failed!')
    except (ELFError, ELFParseError):
        fatal('Reading ELF failed!')


    # Check architecture
    if elf.get_machine_arch() != 'ARM' and elf.get_machine_arch() != 'AArch64':
        fatal('Only ARM and AArch64 ELFs are supported! Input arch: %s' % elf.get_machine_arch())


    # Check segments
    pt_load_segments = []
    
    for section in elf.iter_segments():
        if section.header.p_type == 'PT_LOAD':
            pt_load_segments.append(section)

    if len(pt_load_segments) != 3:
        fatal('Invalid ELF: Expected 3 loadable segments! Got %d' % len(pt_load_segments))

    text_segment = pt_load_segments[0]
    rodata_segment = pt_load_segments[1]
    data_segment = pt_load_segments[2]


    # Open output file
    try:
        out = open(argv[2], 'wb')
    except IOError:
        fatal('Opening NSO for writing failed!')


    # Create NSO
    header = NsoHeader()
    if do_compress == True:
        header.flags |= 0b000111
    if do_checksums == True:
        header.flags |= 0b111000


    # Module is alyways a single zeroed byte directly after the header
    header.module_offset = header.size
    header.module_file_size = 1
    out.seek(header.size, 0)
    out.write(struct.pack('B', 0))


    # text segment
    header.text_segment.file_offset = out.tell()
    header.text_segment.memory_offset = text_segment.header.p_vaddr
    header.text_segment.decompressed_size = text_segment.header.p_filesz

    elf.stream.seek(text_segment.header.p_offset)
    text_segment_data = elf.stream.read(text_segment.header.p_filesz)

    if do_checksums == True:
        header.text_section_hash = hashlib.sha256(text_segment_data).digest()

    if do_compress == True:
        text_segment_data = lz4.block.compress(text_segment_data, store_size=False)

    header.text_compressed_size = len(text_segment_data)    
    out.write(text_segment_data)


    # rodata segment
    header.rodata_segment.file_offset = out.tell()
    header.rodata_segment.memory_offset = rodata_segment.header.p_vaddr
    header.rodata_segment.decompressed_size = rodata_segment.header.p_filesz

    elf.stream.seek(rodata_segment.header.p_offset)
    rodata_segment_data = elf.stream.read(rodata_segment.header.p_filesz)

    if do_checksums == True:
        header.rodata_section_hash = hashlib.sha256(rodata_segment_data).digest()

    if do_compress == True:
        rodata_segment_data = lz4.block.compress(rodata_segment_data, store_size=False)

    header.rodata_compressed_size = len(rodata_segment_data)    
    out.write(rodata_segment_data)


    # data segment
    header.data_segment.file_offset = out.tell()
    header.data_segment.memory_offset = data_segment.header.p_vaddr
    header.data_segment.decompressed_size = data_segment.header.p_filesz

    elf.stream.seek(data_segment.header.p_offset)
    data_segment_data = elf.stream.read(data_segment.header.p_filesz)

    if do_checksums == True:
        header.data_section_hash = hashlib.sha256(data_segment_data).digest()

    if do_compress == True:
        data_segment_data = lz4.block.compress(data_segment_data, store_size=False)

    header.data_compressed_size = len(data_segment_data)
    out.write(data_segment_data)


    # bss size
    header.bss_size = data_segment.header.p_memsz - data_segment.header.p_filesz


    # Write Header
    out.seek(0, 0)
    out.write(header.save())
    out.close()


    sys.exit(0)


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)