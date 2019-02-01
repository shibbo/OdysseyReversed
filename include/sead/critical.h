/**
 * @file critical.h
 * @brief Critical sections.
 */

#pragma once

#include "heap.h"
#include "nn/os.h"

namespace sead
{
    class CriticalSection : public sead::IDisposer
    {
    public:
        CriticalSection();
        CriticalSection(sead::Heap *);
        CriticalSection(sead::Heap *, sead::IDisposer::HeapNullOption);
        ~CriticalSection();

        void lock();
        bool tryLock();
        void unlock();

        nn::os::MutexType mMutexType; // _20
    };
};