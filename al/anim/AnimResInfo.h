/**
 * @file AnimResInfo.h
 * @brief Stores information about an animation (max frames, looping, and name)
 */

#pragma once

#include "types.h"

namespace al
{
    class AnimResInfo
    {
    public:
        AnimResInfo();

        u32 getFrameMax() const;
        bool isLoop() const;

        char* mName; // _0
        u64 _8;
        f32 mFrameMax; // _10
        bool mLoops; // _14
    };
};