/**
 * @file EffectInfo.h
 * @brief Effect information storage container.
 */

#pragma once

#include "types.h"
#include "sead/color.h"

namespace al
{
    class EffectInfo
    {
    public:
        EffectInfo();

        u64 _0;
        u32 _8;
        u32 _C;
        u64 _10;
        u32 _18;
        u32 _1C;
        u64 _20;
        u64 _28;
        u64 _30;
        u64 _38;
        f32 _40;
        f32 _44;
        f32 _48;
        u32 _4C;
        u64 _50;
        sead::Color4f _58;
        u64 _60;
        u32 _68;
        u32 _6C;
        u8 _70;
        u8 _71;
        u8 _72;
        u64 _73;
        u64 _7B;
        u8 _83;
        u32 _84;
        u32 _88;
        u32 _8C;
        u64 _90;
        u32 _98;
        u32 _9C;
    };
};