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
    };
};