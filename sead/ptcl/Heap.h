/**
 * @file Heap.h
 * @brief Particle heaps.
 */

#pragma once

#include "types.h"

namespace sead
{
    namespace ptcl
    {
        class Heap
        {
        public:
            virtual ~Heap();

            virtual void* Alloc(u64, u64);
            virtual void Free(void *);
        };
    };
};