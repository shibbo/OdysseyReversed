/**
 * @file ActorItemKeeper.h
 * @brief Keeper for an actor's spawned item.
 */

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
        u32 _14; // another count related to the info
        char* mFactor; // _18
        u64* _20; // al::HitSensor*
        u32 _28;
        u64 _2C;
    };
};