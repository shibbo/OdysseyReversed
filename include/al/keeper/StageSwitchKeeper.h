/**
 * @file StageSwitchKeeper.h
 * @brief Keeper for stage switches.
 */

#pragma once

#include "types.h"
#include "al/PlacementId.h"
#include "al/PlacementInfo.h"
#include "al/util.h"
#include "al/switch/StageSwitchAccesser.h"
#include "al/switch/StageSwitchDirector.h"

namespace al
{
    class StageSwitchKeeper
    {
    public:
        StageSwitchKeeper();

        void init(al::StageSwitchDirector *, al::PlacementInfo const &);
        al::StageSwitchAccesser* tryGetStageSwitchAccesser(char const *name) const;

        al::StageSwitchAccesser* _0;
        s32 mLinkCount; // _8
        u32 _C;
        al::StageSwitchAccesser* _10;
    };
};