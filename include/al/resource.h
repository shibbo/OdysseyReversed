/**
 * @file resource.h
 * @brief Resource management for actors.
 */

#pragma once

#include "nn/g3d/ResFile.h"
#include "sead/resource.h"
#include "sead/string.h"

namespace al
{
    class Resource
    {
    public:
        Resource(sead::SafeStringBase<char> const &, sead::ArchiveRes *);
        
        bool isExistFile(sead::SafeStringBase<char> const &) const;
        bool isExistByml(char const *) const;
        u32 getSize() const;
        u32 getEntryNum(sead::SafeStringBase<char> const &) const;
        void getEntryName(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &, u32) const;
        u32 getFileSize(sead::SafeStringBase<char> const &) const;
        u8* getByml(sead::SafeStringBase<char> const &) const;
        u8* tryGetByml(sead::SafeStringBase<char> const &) const;
        void* getKcl(sead::SafeStringBase<char> const &) const;
        void* tryGetKcl(sead::SafeStringBase<char> const &) const;
        void* getPa(sead::SafeStringBase<char> const &) const;
        void* tryGetPa(sead::SafeStringBase<char> const &) const;
        char* getArchiveName() const;
        bool tryCreateResGraphicsFile(sead::SafeStringBase<char> const &, nn::g3d::ResFile *);
        void cleanupResGraphicsFile();
        
        u64* _0;
        u64* _8; // sead::ArchiveFileDevice*
        u32 _10;
        u32 _14;
        u64 _18;
        u32 _20;
        u32 _24;
        u8 _28[0xA8-0x28];
        sead::Heap* mHeap; // _A8
        u64 _B0;
        nn::g3d::ResFile* _B8;
    };

    class ActorResource
    {
    public:
        ActorResource(sead::SafeStringBase<char> const &, al::Resource *, al::Resource *);
        virtual ~ActorResource();

        void initResourceData(char const *, bool);

        u8 _0[0xB8];
        u64* _B8; // al::InitResourceDataAnim*
        u64* _C0; // al::InitResourceDataAction*
    };
};