#pragma once

#include "heap.h"
#include "stream.h"

namespace sead
{
    class Resource
    {
        public:
        Resource();
        virtual ~Resource();

        // virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*);
        // virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();
    };

    class DirectResource : public sead::Resource
    {
        public:
        DirectResource();

        // virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*);
        // virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();

        virtual u32 getLoadDataAlignment() const;
        virtual void doCreate_(u8 *, u32, sead::Heap *);

        u64 _8;
        u64 _10;
        u32 _18;
    };

    class IndirectResource : public sead::Resource
    {
        public:
        IndirectResource();
        virtual ~IndirectResource();

        virtual void doCreate_(sead::ReadStream *, u32,sead::Heap *);

        static void create(sead::ReadStream *, u32, sead::Heap *);
    };

    class ArchiveRes : public sead::DirectResource
    {
        public:
        virtual ~ArchiveRes();

        // virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*);
        // virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();

        virtual u32 getLoadDataAlignment() const;
        virtual void doCreate_(u8 *, u32, sead::Heap *);
        
        u8 _1C;
    };
};