/**
 * @file handle.h
 * @brief File and Directory handling for devices.
 */

#pragma once

#include "types.h"

namespace sead
{
    class DirectoryEntry;
    class FileDevice;

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

    class DirectoryHandle
    {
    public:
        virtual ~DirectoryHandle();

        void close();
        bool tryClose();
        u32 read(sead::DirectoryEntry *, u32);
        bool tryRead(u32 *, sead::DirectoryEntry *, u32);

        u64 _8;
        sead::FileDevice* mDevice; // _10
    };
};