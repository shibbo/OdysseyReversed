/**
 * @file NwAllocator.h
 * @brief Allocator for NintendoWare, for layout files.
 */

#pragma once

#include "sead/heap.h"

namespace eui
{
    class NwAllocator
    {
    public:
        static void initialize(sead::Heap *);
        static void* ui2dAllocateFunction(u64, u64, void *);
        static void ui2dDeallocateFunction(void *, void *);
        static void finalize();
        static void ui2dDeallocateFunctionWithFindContainHeap(void *, void *);
    };
};