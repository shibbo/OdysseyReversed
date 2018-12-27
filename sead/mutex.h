#pragma once

#include "heap.h"
#include "os.h"

namespace sead
{
    class Mutex : public sead::IDisposer
    {
    public:
        Mutex();
        Mutex(sead::Heap *);
        Mutex(sead::Heap *, sead::IDisposer::HeapNullOption);
        ~Mutex();

        void lock();
        bool tryLock();
        void unlock();

        nn::os::MutexType* mMutexType; // _20
    };
};