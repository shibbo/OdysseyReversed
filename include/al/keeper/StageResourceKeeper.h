/**
 * @file StageResourceKeeper.h
 * @brief Keeper for a stages' resources, like maps, design, and sound.
 */

#pragma once

#include "al/stage/StageResourceList.h"
#include "types.h"

namespace al
{
    class StageResourceKeeper
    {
    public:
        StageResourceKeeper();

        void initAndLoadResource(char const *, s32);

        al::StageResourceList* mMapResourceList; // _0
        al::StageResourceList* mDesignResourceList; // _8
        al::StageResourceList* mSoundResourceList; // _10
    };
};