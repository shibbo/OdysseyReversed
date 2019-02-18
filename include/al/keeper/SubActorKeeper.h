/**
 * @file SubActorKeeper.h
 * @brief Keeper for sub-actors stored within an actor.
 */

#pragma once

#include "types.h"
#include "al/ActorInitInfo.h"
#include "al/LiveActor.h"

namespace al
{
    class SubActorKeeper
    {
    public:
        SubActorKeeper(al::LiveActor *);

        void registerSubActor(al::LiveActor *, u32);
        void init(al::ActorInitInfo const &,char const *, s32);
        void init(s32);

        static al::SubActorKeeper* create(al::LiveActor *);
        static al::SubActorKeeper* tryCreate(al::LiveActor *, char const *, s32);

        al::LiveActor* _0;
        u32 _8;
        u32 mActorCount; // _C
        u32 _10;
        u32 _14;
    };
};

class alSubActorFunction
{
public:
    static void trySyncAlive(al::SubActorKeeper *);
    static void trySyncDead(al::SubActorKeeper *);
};