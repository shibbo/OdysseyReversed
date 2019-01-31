/**
 * @file EffectUserInfo.h
 * @brief User information storage container.
 */

#pragma once

#include "types.h"

namespace al
{
    class EffectInfo;
    class EffectHitReactionInfo;

    class EffectUserInfo
    {
    public:
        EffectUserInfo();

        al::EffectInfo* tryGetEffectInfo(char const *) const;
        al::EffectHitReactionInfo* tryFindHitReactionInfo(char const *) const;
        
        u64 _0;
        u32 mEffectInfoCount; // _8
        u32 _C; // padding
        al::EffectInfo* mEffectInfoArry; // _10
        u32 mHitReactionInfoCount; // _18
        u32 _1C; // padding
        al::EffectHitReactionInfo* mEffectHitReactionArry; // _20
        u64 _28;
    };
};