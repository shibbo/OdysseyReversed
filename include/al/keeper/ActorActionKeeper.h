/**
 * @file ActorActionKeeper.h
 * @brief Keeper for an actor's executed actions.
 */

#pragma once

#include "al/LiveActor.h"

namespace al
{
    class ActorActionKeeper
    {
    public:
        ActorActionKeeper(al::LiveActor *, char const *, u64*, u64*, u64*, u64*, u64*, u64*, u64*, u64*);

        static al::ActorActionKeeper* tryCreate(al::LiveActor *, u64 *, char const *srcFile, char const *);
        void startAction(char const *actionName);
        void tryStartActionNoAnim(char const *actionName);
        void updatePrev();
        void updatePost();
        void init();

        al::LiveActor* mActor; // _0
        char* mName; // _8
        u64* _10; // al::ActionAnimCtrl *
        u64* _18; // al::NerveActionCtrl *
        u64* _20; // al::ActionFlagCtrl *
        u64* _28;
        u64* _30;
        u64* _38;
        u64* _40;
        u64* _48;
    };
};