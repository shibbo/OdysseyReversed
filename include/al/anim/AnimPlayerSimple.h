/**
 * @file AnimPlayerSimple.h
 * @brief Animation player.
 */

#pragma once

#include "types.h"
#include "AnimPlayerBase.h"

namespace al
{
    class AnimResInfo;
    class AnimPlayerInitInfo;

    class AnimPlayerSimple : public al::AnimPlayerBase
    {
    public:
        AnimPlayerSimple();

        virtual bool calcNeedUpdateAnimNext();
        virtual void init(al::AnimPlayerInitInfo const *) = 0;
        virtual void setAnimToModel(al::AnimResInfo const *) = 0;
        virtual void applyTo();

        void startAnim(char const *);
        void update();
        void clearAnim();
        f32 getAnimFrame() const;
        void setAnimFrame(f32);
        f32 getAnimFrameMax() const;
        f32 getAnimFrameMax(char const *) const;
        f32 getAnimFrameRate() const;
        void setAnimFrameRate(f32);
        bool isAnimExist(char const *) const;
        bool isAnimEnd() const;
        bool isAnimOneTime() const;
        bool isAnimOneTime(char const *) const;
        bool isAnimPlaying() const;
        char* getPlayingAnimName() const;

        u64* _18;
        u64* _20;
    };
};