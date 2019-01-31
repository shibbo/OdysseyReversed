/**
 * @file disposer.h
 * @brief Basic disposer class.
 */

#pragma once

#include "types.h"

namespace sead
{
    class Heap;
    
    class IDisposer
    {
    public:

        enum HeapNullOption
        {
            UNKNOWN_0 = 0,
            UNKNOWN_1 = 1,
            UNKNOWN_2 = 2,
            UNKNOWN_3 = 3
        };

        IDisposer();
        IDisposer(sead::Heap *heap, sead::IDisposer::HeapNullOption nullOption);

        virtual ~IDisposer();

        sead::Heap* mHeapPtr; // _8
        u64 _10;
        u64 _18;
    };
};