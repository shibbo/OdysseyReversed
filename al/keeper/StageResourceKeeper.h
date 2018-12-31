#pragma once

#include "stage/StageResourceList.h"
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