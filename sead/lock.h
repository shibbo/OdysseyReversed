/**
 * @file lock.h
 * @brief DrawLock Context Implementation.
 */

#pragma once

#include "critical.h"
#include "heap.h"
#include "hostio.h"

namespace sead
{
    class DrawLockContext
    {
    public:
        DrawLockContext();

        void initialize(sead::Heap *);
        void lock();
        void unlock();
        void genMessage(sead::hostio::Context *);

        u32 _8;
        u32 _C;
        sead::CriticalSection mCritical; // _10
    };
};