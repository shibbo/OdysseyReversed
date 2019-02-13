/**
 * @file MessageSystem.h
 * @brief Storage class for the LMS message library.
 */

#pragma once

#include "sead/heap.h"
#include "types.h"

namespace al
{
    class MessageSystem
    {
    public:
        MessageSystem();

        u64* _0; // al::MessageProjectEx*
        u64 _8;
        sead::ExpHeap* mMessageHeap; // _18
    };
};