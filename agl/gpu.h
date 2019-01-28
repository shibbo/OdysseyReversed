#pragma once

#include "types.h"
#include "agl/detail/MemoryPool.h"
#include "agl/detail/MemoryPoolHeap.h"
#include "nn/gfx/api.h"
#include "nn/gfx/memory.h"
#include "sead/heap.h"

namespace agl
{
    typedef u64 GPUMemVoidAddr;

    class GPUMemBlockBase
    {
    public:
        GPUMemBlockBase();

        virtual ~GPUMemBlockBase();

        void clear();
        void freeBuffer();
        void free();
        void allocBuffer_(u64, sead::Heap *, s32, agl::MemoryAttribute);
        bool tryAllocBuffer_(u64, sead::Heap *, s32, agl::MemoryAttribute);
        void setBuffer_(u64, void *, void *, agl::MemoryAttribute);
        void setVirtual_(u64, sead::Heap *, agl::MemoryAttribute, agl::GPUMemVoidAddr, s32);
        void initializeGfxMemoryPool(nn::gfx::TMemoryPool<nn::gfx::ApiVariation<nn::gfx::ApiType<s8>, nn::gfx::ApiVersion<s8>>> *) const;
        void addList(agl::GPUMemBlockBase*);
        void setMemoryPool(void *, u64, agl::detail::MemoryPool *);
        void setMemoryPoolHeap(void *, unsigned long, agl::detail::MemoryPoolHeap *);
        u64 getByteOffset() const;
        u64 getMemoryPoolType() const;

        void* mMemBlockBuffer; // _8
        u64 mMemBlockBufferSize; // _10
        agl::detail::MemoryPool* mMemoryPool; // _18
        agl::detail::MemoryPoolHeap* mMemoryPoolHeap; // _20
        u8 _28; // this is some sort of bitflag
        u8 _29;
        u8 _2A;
        u8 _2B;
        u32 _2C;
        u64 _30;
    };
};