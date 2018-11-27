#pragma once

#include "al/LiveActor.h"

namespace al
{
    class ActorItemKeeper
    {
        public:
        ActorItemKeeper(al::LiveActor const *, s32);

        void reset();

        al::LiveActor* mActor; // _0
        u64* mTable; // _8 table of items
        u32 mNumEntries; // _10
        u64 _14;
        u64 _1C;
        u64 _24;
        u64 _2C;
    };
};