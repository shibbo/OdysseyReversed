# nso.py
# Library for processing NSO information

import struct

class NsoSegment(struct.Struct):
    def __init__(self):
        super().__init__('<3I')

        self.file_offset = 0
        self.memory_offset = 0
        self.decompressed_size = 0

    def load(self, data, pos):
        (self.file_offset,
         self.memory_offset,
         self.decompressed_size) = self.unpack_from(data, pos)

    def save(self):
        return struct.pack(
            self.format,
            self.file_offset,
            self.memory_offset,
            self.decompressed_size,
        )


class NsoHeader(struct.Struct):
    def __init__(self):
        super().__init__('<4I12xI12xI12xI32s3I28s3Q32s32s32s')

        self.magic = 0x304F534E
        self.version = 0
        self._8 = 0
        self.flags = 0
        self.module_offset = 0
        self.module_file_size = 0
        self.bss_size = 0
        self.build_id = b'\0' * 32
        self.text_compressed_size = 0
        self.rodata_compressed_size = 0
        self.data_compressed_size = 0
        self._6C = b'\0' * 28
        self.api_info_extents = 0
        self.dynstr_extents = 0
        self.dynsym_extents = 0
        self.text_section_hash = b'\0' * 32
        self.rodata_section_hash = b'\0' * 32
        self.data_section_hash = b'\0' * 32

        self.text_segment = NsoSegment()
        self.rodata_segment = NsoSegment()
        self.data_segment = NsoSegment()

    def load(self, data, pos=0):
        (self.magic,
         self.version,
         self._8,
         self.flags,
         self.module_offset,
         self.module_file_size,
         self.bss_size,
         self.build_id,
         self.text_compressed_size,
         self.rodata_compressed_size,
         self.data_compressed_size,
         self._6C,
         self.api_info_extents,
         self.dynstr_extents,
         self.dynsym_extents,
         self.text_section_hash,
         self.rodata_section_hash,
         self.data_section_hash) = self.unpack_from(data, pos)

        self.text_segment.load(data, pos + 0x10)
        self.rodata_segment.load(data, pos + 0x20)
        self.data_segment.load(data, pos + 0x30)

    def save(self):

        outBuffer = bytearray(struct.pack(
            self.format,
            self.magic,
            self.version,
            self._8,
            self.flags,
            self.module_offset,
            self.module_file_size,
            self.bss_size,
            self.build_id,
            self.text_compressed_size,
            self.rodata_compressed_size,
            self.data_compressed_size,
            self._6C,
            self.api_info_extents,
            self.dynstr_extents,
            self.dynsym_extents,
            self.text_section_hash,
            self.rodata_section_hash,
            self.data_section_hash,
        ))

        outBuffer[0x10:0x10 + self.text_segment.size] = self.text_segment.save()
        outBuffer[0x20:0x20 + self.rodata_segment.size] = self.rodata_segment.save()
        outBuffer[0x30:0x30 + self.data_segment.size] = self.data_segment.save()

        return outBuffer