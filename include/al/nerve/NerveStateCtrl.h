/**
 * @file NerveStateCtrl.h
 * @brief Controls multiple nerve states.
 */

#pragma once

#include "Nerve.h"
#include "NerveStateBase.h"
#include "types.h"

namespace al
{
    class NerveStateCtrl
    {
    public:
        NerveStateCtrl(s32 numNerves);

        void addState(al::NerveStateBase *, al::Nerve const *, char const *);
        bool updateCurrentState();
        void startState(al::Nerve const *);
        u64* findStateInfo(al::Nerve const *);
        bool isCurrentStateEnd() const;
        void tryEndCurrentState();

        u32 mNumStates; // _0
        u64* mStateArray; // _4
        u64 _C;
        u32 _14;
    };
};