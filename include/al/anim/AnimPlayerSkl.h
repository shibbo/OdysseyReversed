#pragma once

/**
 * @file AnimPlayerSkl.h
 * @brief Skeleton animation player.
 */

#include "AnimPlayerBase.h"

namespace al
{
    class AnimPlayerInitInfo;

    class AnimPlayerSkl : public al::AnimPlayerBase
    {
    public:
        AnimPlayerSkl(al::AnimPlayerInitInfo const *, s32);

        virtual void updateLast();
        virtual bool calcNeedUpdateAnimNext();

        static al::AnimPlayerSkl* tryCreate(al::AnimPlayerInitInfo const *, s32);
        void startSklAnim(char const *, char const *, char const *, char const *, char const *, char const *, char const *);
        void clearSklAnimBlend();
        void setSklAnim(char const *, s32);
        void calcSklAnim();
        void initInterp(char const *);
        void setSklAnimBlendWeight(s32, f32);
        f32 getSklAnimBlendWeight(s32) const;
        s32 getSklAnimBlendNum() const;
        f32 getSklAnimFrame(s32) const;
        u64* getAnimObj(s32) const;
        void setSklAnimFrame(s32, f32);
        u64* getAnimObj(s32);
        f32 getSklAnimFrameMax(s32) const;
        f32 getSklAnimFrameMax(char const *) const;
        f32 getSklAnimFrameRate(s32) const;
        void setSklAnimFrameRate(s32, f32);
        bool isSklAnimExist(char const *) const;
        bool isSklAnimEnd(s32) const;
        bool isSklAnimOneTime(s32) const;
        bool isSklAnimOneTime(char const *) const;
        bool isSklAnimPlaying(s32) const;
        char* getPlayingSklAnimName(s32) const;
        void update();
        void reset();
        void prepareAnimInterpDirect(s32);
        void initPartialAnim(s32, s32, s32);
        s32 getPartialAnimSlotNum() const;
        s32 getJoitsAmountFromJoint(char const *) const;

        u64* _18; // al::AnimPlayerInitInfo->_8
        u32 _20;
        u32 _24;
        u64 _28;
        u32 _30;
        u32 _34;
        u64 _38;
        u64 _40; // al::ModelAnimInterp*
        u64* _48; // some struct of size 0x20
        u32 _50;
        u32 _54;
        u64 _58;
        u32 _60;
        u32 _64;
        u64 _68;
        u64 _70;
        u32 _78;
        u32 _7C;
        u64 _80;
        u8 _88;
        u8 _89;
    };
};