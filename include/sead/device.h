/**
 * @file device.h
 * @brief Defines file devices and extensions.
 */

#pragma once

#include "heap.h"
#include "runtime.h"
#include "string.h"
#include "types.h"

namespace sead
{
    class ArchiveRes;
    class FileDevice;
    class HandleBase;

    class FileHandle
    {
    public:
        bool close();
        bool tryClose();
        bool flush();
        bool tryFlush();
        bool read(u8 *, u32);
        bool tryRead(u32 *, u8 *, u32);
        bool write(u8 const *, u32);
        bool tryWrite(u8 const *, u32);

        u64 _0;
        sead::FileDevice* mDevice; // _8
    };

    class DirectoryEntry;
    class DirectoryHandle;

    class FileDevice
    {
    public:

        enum FileOpenFlag { };

        struct LoadArg
        {
            u64 _0;
            u64 _8;
            u64 _10;
            u64 _18;
            u64 _20;
            u32 _28;
            u8 _2C;
            u8 _2D;
            u8 _2E;
            u8 _2F;
            u32 _30;
        };

        struct SaveArg; // todo: finish me

        enum SeekOrigin { };

        virtual ~FileDevice();
        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual void traceFilePath(sead::SafeStringBase<char> const &) const;
        virtual void traceDirectoryPath(sead::SafeStringBase<char> const &) const;
        virtual void resolveFilePath(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &) const;
        virtual void resolveDirectoryPath(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &) const;
        virtual bool isMatchDevice_(sead::HandleBase const *) const;
        virtual bool doIsAvailable_() const = 0;
        virtual void doLoad_(sead::FileDevice::LoadArg &);
        virtual void doSave_(sead::FileDevice::SaveArg &);
        virtual void doOpen_(sead::FileHandle *, sead::SafeStringBase<char> const &, sead::FileDevice::FileOpenFlag) = 0;
        virtual bool doClose_(sead::FileHandle *) = 0;
        virtual bool doFlush_(sead::FileHandle *) = 0;
        virtual bool doRemove_(sead::SafeStringBase<char> const &) = 0;
        virtual bool doRead_(u32 *, sead::FileHandle *, u8 *, u32) = 0;
        virtual bool doWrite_(u32 *, sead::FileHandle *, u8 const *, u32) = 0;
        virtual bool doSeek_(sead::FileHandle *, s32, sead::FileDevice::SeekOrigin) = 0;
        virtual bool doGetCurrentSeekPos_(u32 *, sead::FileHandle *) = 0;
        virtual bool doGetFileSize_(u32 *, sead::SafeStringBase<char> const &) = 0;
        virtual bool doGetFileSize_(u32 *, sead::FileHandle *) = 0;
        virtual bool doIsExistFile_(bool *, sead::SafeStringBase<char> const &) = 0;
        virtual bool doIsExistDirectory_(bool *, sead::SafeStringBase<char> const &) = 0;
        virtual bool doOpenDirectory_(sead::DirectoryHandle *, sead::SafeStringBase<char> const &) = 0;
        virtual bool doCloseDirectory_(sead::DirectoryHandle *) = 0;
        virtual bool doReadDirectory_(u32 *, sead::DirectoryHandle *, sead::DirectoryEntry *, u32) = 0;
        virtual bool doMakeDirectory_(sead::SafeStringBase<char> const &, u32) = 0;
        virtual u64* doGetLastRawError_() const = 0;
        virtual void doTracePath_(sead::SafeStringBase<char> const&) const;
        virtual void doResolvePath_(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &) const;
    };

    class ArchiveFileDevice : public sead::IDisposer
    {
    public:
        ArchiveFileDevice(sead::ArchiveRes *);
    };
};