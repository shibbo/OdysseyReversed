/**
 * @file array.h
 * @brief Functions that define arrays.
 */

#pragma once

#include "heap.h"
#include "random.h"
#include "types.h"

namespace sead
{
    template<typename T>
    class ConstPtrArray
    {
    public:
        u64 mNumPtrs; // _0
        u64* mPtrs; // _8
    };

    class PtrArrayImpl
    {
    public:
        void setBuffer(s32 size, void *buf);
        void allocBuffer(s32 size, sead::Heap *heapSrc, s32);
        bool tryAllocBuffer(s32 size, sead::Heap *heapSrc, s32);
        void freeBuffer();
        void erase(s32 start, s32 end);
        void reverse();
        void shuffle(sead::Random *);
        void insert(s32 where, void *buf);
        bool checkInsert(s32 start, s32 end);
        void insertArray(s32, void *, s32, s32);
        void sort(s32 (*)(void const *, void const *));
        void heapSort(s32 (*)(void const *, void const *));
        bool compare(sead::PtrArrayImpl const &, s32 (*)(void const *, void const *)) const;
        void uniq(s32 (*)(void const *, void const *));
        s32 binarySearch(void const *, s32 (*)(void const *, void const *)) const;

        u32 _0;
        s32 mBufferSize; // _4
        void* mBuffer; // _8
    };

    template<typename T>
    class ObjArray
    {
    public:
        bool compareT(T const *, T const *);
    };
};