/**
 * @file ActorInitInfo.h
 * @brief Storage container for an actors' intialization.
 */

#pragma once

#include "types.h"
#include "ActorSceneInfo.h"
#include "PlacementInfo.h"

namespace al
{
    class ActorInitInfo
    {
    public:
        ActorInitInfo();

        u64 _0;
        al::PlacementInfo* mActorContainer; // _8
        u64 _10;
        al::ActorSceneInfo mSceneInfo; // _18
    };
};