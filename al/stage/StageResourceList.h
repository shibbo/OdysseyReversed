/**
 * @file StageResourceList.h
 * @brief Storage container for a stages' resources.
 */

#pragma once

#include "StageInfo.h"
#include "types.h"

namespace al
{
    class StageResourceList
    {
    public:
        StageResourceList(char const *fileName, s32, char const *innerFileName);

        u32 getStageResourceNum() const;
        al::StageInfo* getStageInfo(s32 idx) const;

        u32 mResourceNum; // _0
        u32 mPad;
        al::StageInfo* mStageInfos; // _8
    };
};