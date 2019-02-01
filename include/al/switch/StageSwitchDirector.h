/**
 * @file StageSwitchDirector.h
 * @brief Manager for a stage switches.
 */

#pragma once

#include "types.h"
#include "al/execute.h"
#include "al/PlacementId.h"

namespace al
{
    class StageSwitchAccesser;
    class StageSwitchListener;

    class StageSwitchDirector
    {
    public:
        StageSwitchDirector(al::ExecuteDirector *);

        void useSwitch(al::StageSwitchAccesser *);
        s32 findSwitchNoFromObjId(al::PlacementId const *);
        void onSwitch(al::StageSwitchAccesser const *);
        void offSwitch(al::StageSwitchAccesser const *);
        bool isOnSwitch(al::StageSwitchAccesser const *);
        void addListener(al::StageSwitchListener *, al::StageSwitchAccesser *);

        u64 _0;
        u64* _8;
        u64 _10;
        u64* _18; // StageSwitchWatcherHolder*
    };
};