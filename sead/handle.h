#pragma once

#include "types.h"

namespace sead
{
    class FileHandle
    {
        public:
        bool close();
        bool tryClose();
        bool flush();
        bool tryFlush();
        u32 read(u8 *, u32);
        bool tryRead(u32 *dest, u8 *, u32);

        u64* _8; // sead::FileHandle *
        u64* _10;
    };
};