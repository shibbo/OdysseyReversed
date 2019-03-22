#pragma once

/**
 * @file AnimPlayerVis.h
 * @brief Visibility animation player.
 */

#include "AnimPlayerSimple.h"

namespace al
{
    class AnimResInfo;

    class AnimPlayerVis : public al::AnimPlayerSimple
    {
    public:
        AnimPlayerVis();

        virtual void init(al::AnimPlayerInitInfo const *);
        virtual void setAnimToModel(al::AnimResInfo const *);

        static al::AnimPlayerVis* tryCreate(al::AnimPlayerInitInfo const *);
    };
}