/**
 * @file AnimPlayerBase.h
 * @brief Basic animation player, using animation tables to sort and play them.
 */

#pragma once

#include "AnimInfoTable.h"
#include "types.h"

namespace al
{
    class AnimPlayerBase
    {
    public:
        AnimPlayerBase();

        virtual void updateLast();
        virtual bool calcNeedUpdateAnimNext() = 0;

        al::AnimInfoTable* mInfoTable; // _8
        u32 _10;
        u32 _14; // most likely padding
    };
};