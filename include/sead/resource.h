/**
 * @file resource.h
 * @brief Resource management classes.
 */

#pragma once

#include "device.h"
#include "heap.h"
#include "runtime.h"
#include "stream.h"

namespace sead
{
    class Decompressor;
    class Resource;
    class ResourceFactory;

    class ResourceMgr : public sead::IDisposer
    {
    public:
        struct LoadArg
        {
            u8 _0[0x40];
            sead::ArchiveFileDevice* device; // _40
        };

        class SingletonDisposer_
        {
        public:
            virtual ~SingletonDisposer_();

            static sead::ResourceMgr::SingletonDisposer_* sStaticDisposer;
        };

        ResourceMgr();
        ~ResourceMgr();

        void registerFactory(sead::ResourceFactory *, sead::SafeStringBase<char> const &);
        void unregisterFactory(sead::ResourceFactory *);
        void setDefaultFactory(sead::ResourceFactory *);
        void tryLoadWithoutDecomp(sead::ResourceMgr::LoadArg const &);
        sead::ResourceFactory* findFactory(sead::SafeStringBase<char> const &);
        void unload(sead::Resource *);
        void registerDecompressor(sead::Decompressor *, sead::SafeStringBase<char> const &);
        void unregisterDecompressor(sead::Decompressor *);
        void tryLoad(sead::ResourceMgr::LoadArg const &, sead::SafeStringBase<char> const &, sead::Decompressor *);
        sead::Decompressor* findDecompressor(sead::SafeStringBase<char> const &);
        

        static sead::ResourceMgr* createInstance(sead::Heap *);
        static void deleteInstance();

        u32 mFactoryCount; // _30

        static sead::ResourceMgr* sInstance;
    };

    class Resource
    {
    public:
        Resource();
        virtual ~Resource();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();
    };

    class DirectResource : public sead::Resource
    {
    public:
        DirectResource();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();

        virtual u32 getLoadDataAlignment() const;
        virtual void doCreate_(u8 *, u32, sead::Heap *);

        void create(u8 *, u32, u32, bool, sead::Heap *);

        u8* mResource; // _8
        u32 _10;
        u32 _14;
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

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();

        virtual u32 getLoadDataAlignment() const;
        virtual void doCreate_(u8 *, u32, sead::Heap *);

        void load(sead::ResourceMgr::LoadArg &);
        
        u8 _1C;
    };
};