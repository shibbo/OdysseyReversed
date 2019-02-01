/*#include "sead/heap.h"

Terrible code. Do not use me.

namespace sead
{
    HeapMgr::HeapMgr()
    {
        this->mHeap = 0;
        this->_10 = 0;
    }

    HeapMgr::~HeapMgr() { }

    void HeapMgr::initialize(u64 size)
    {
        HeapMgr::sHeapTreeLockCS->lock();
        HeapMgr::sArena = HeapMgr::sDefaultArena;
        HeapMgr::sDefaultArena->initialize(size);

        u64* ptr = (u64*)0x71025229F0;
        *ptr = 0;

        HeapMgr::sSleepSpanAtRemoveCacheFailure = (((sead::TickSpan::cFrequency * 0x29F16B11C6D1E109LL) >> 64) >> 14)
                                                + (((sead::TickSpan::cFrequency * 0x29F16B11C6D1E109LL) >> 64) >> 63);

        sead::SafeStringBase<char> strBase;
        sead::Heap* outHeap = ExpHeap::tryCreate(HeapMgr::sArena->_0, HeapMgr::sArena->mSize, strBase, 0);

        if (HeapMgr::sRootHeaps < (((u64*) & (HeapMgr::sRootHeaps) + 1)))
        {
            *((sead::Heap*)0x7102522A28 + (*HeapMgr::sRootHeaps << 32 >> 29)) = *outHeap;
            *((u64*) & (HeapMgr::sRootHeaps)) = *HeapMgr::sRootHeaps + 1;
        }

        HeapMgr::sHeapTreeLockCS->unlock();
    }
};*/