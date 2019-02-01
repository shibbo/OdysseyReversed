/**
 * @file RootObject.h
 * @brief RootObject for NEX.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace nex
    {
        class RootObject
        {
        public:
            enum TargetPool;

            virtual ~RootObject();

            void* operator new(size_t);
            void operator delete(void *);
            void* operator new(size_t, char const *, u32);
            void* operator new[](size_t);
            void* operator new[](size_t,  char const *, u32);
            void operator delete[](void *);
            void operator delete(void *,char const *, u32);
            void operator delete[](void *,char const *, u32);
            void* operator new(size_t, nn::nex::RootObject::TargetPool);
            void* operator new(size_t, nn::nex::RootObject::TargetPool, char const *, u32);
        };
    };
};