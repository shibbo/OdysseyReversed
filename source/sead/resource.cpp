#include "sead/resource.h"

namespace sead
{
    Resource::Resource() { }
    Resource::~Resource() { }

    DirectResource::DirectResource()
    {
        this->_18 = 0;
        this->mResource = 0;
        this->_10 = 0;
    }

    u32 DirectResource::getLoadDataAlignment() const
    {
        return 4;
    }

    void DirectResource::doCreate_(u8 *src, u32 unk1, sead::Heap* heap)
    {
        return;
    }

    void DirectResource::create(u8 *src, u32 unk1, u32 unk2, bool unk3, sead::Heap *heap)
    {
        u32 v6, v7, v8;

        // check to see if resources are already created
        if (!this->mResource)
        {
            v6 = this->_18;
            v7 = v6 & 0xFFFFFFFE;
            v8 = v6 | 1;
            if (!unk3 & 1)
            {
                v8 = v7;
            }
            this->_18 = v8;
            this->mResource = src;
            this->_10 = unk1;
            this->_14 = unk2;
            this->doCreate_(src, unk1, heap);
        }
    }

    IndirectResource::IndirectResource() { }
    IndirectResource::~IndirectResource() { }

    void IndirectResource::create(sead::ReadStream *stream, u32 unk1, sead::Heap *heap)
    {
        // ReadStream doesn't seem to really have any virtual functions...
        // TODO: figure out what ReadStream + 0x20 is 
    }

    ArchiveRes::~ArchiveRes() { }

    u32 ArchiveRes::getLoadDataAlignment() const
    {
        return 0x80;
    }
    
    void ArchiveRes::doCreate_(u8 *src, u32 unk1, sead::Heap *heap)
    {
        // can't figure out what virtual function gets called
    }

    void ArchiveRes::load(sead::ResourceMgr::LoadArg &arg)
    {
        arg.device = new ArchiveFileDevice(this);
        sead::ResourceMgr::sInstance->tryLoadWithoutDecomp(arg);
        arg.device = 0;
    }
};