/**
 * @file PlayerInitInfo.h
 * @brief Initialization structure for playable actors.
 */

#pragma once

#include "types.h"

struct PlayerInitInfo
{
    u64* mGamepadSystem; // _0
    u64* mViewMtx; // _8
    s32 mPortNo; // _10
    u32 _14;
    char* mPlayerModelName; // _18
    char* mInitCapTypeName; // _20
    u32 _28;
    u32 _2C;
    u32 _30;
    f32 _34;
    f32 _38;
    f32 _3C;
    f32 _40;
    bool mIsNeedCreateNoseNeedle; // _44
    bool mIsClosestScenePlayer; // _45
};