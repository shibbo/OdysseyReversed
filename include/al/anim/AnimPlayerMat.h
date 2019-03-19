/**
 * @file AnimPlayerMat.h
 * @brief Material animation.
 */

#pragma once

#include "types.h"
#include "AnimPlayerSimple.h"
#include "AnimResInfo.h"

namespace al
{
    class AnimPlayerInitInfo;

    class AnimPlayerMat : public al::AnimPlayerSimple
    {
    public:
        static AnimPlayerMat* tryCreate(AnimPlayerInitInfo const *, s32);
        void init(al::AnimPlayerInitInfo const *);
        void setAnimToModel(al::AnimResInfo const *);

        u32 _28;
        u32 _2C;
        u64 _30;
        u64 _38;
    };
};