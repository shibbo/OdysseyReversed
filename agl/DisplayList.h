#pragma once

#include "types.h"
#include "GPUMemAddr.h"
#include "sead/Heap.h"

namespace agl
{
    class DisplayList
    {
    public:
        DisplayList();

        virtual ~DisplayList();

        void setControlMemeory(void *, s32);
        void clear();
        void setBuffer(agl::GPUMemAddr<u8>, u64);
        void setValidSize(u64 size);
        void copyTo(agl::DisplayList *) const;
        void beginDisplayList();
        void endDisplayList();
        bool beginDisplayListBuffer(agl::GPUMemAddr<u8>, u64, bool);
        void endDisplayListBuffer(sead::Heap *);
        void adjustValueSize();
        void invalidateCPUCache() const;
        void dump() const;
        bool suspend(void **);
        void resume(void *, u64);
        u64 calcRemainingSize();

        u64 _8;
        u64 _10;
        u64 _18;
        u32 mUsedSize; // _20
        u32 _24;
        u64 mSize; // _28
    };
};