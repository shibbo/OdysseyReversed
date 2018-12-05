#pragma once

#include "al/LiveActor.h"

namespace al
{
    class ActorItemInfo;

    class ActorItemKeeper
    {
        public:
        ActorItemKeeper(al::LiveActor const *, s32);

        void reset();

        al::LiveActor* mActor; // _0
        al::ActorItemInfo* mTable; // _8 table of items
        u32 mNumEntries; // _10
        u64 _14; // another count related to the info
        u64 _1C;
        u64 _24;
        u64 _2C;
    };
};