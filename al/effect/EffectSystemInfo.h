/**
 * @file EffectSystemInfo.h
 * @brief Global system information storage for effects.
 */

#pragma once

#include "types.h"

namespace al
{
    class EffectSystemInfo
    {
    public:
        EffectSystemInfo();

        u64* getEffectSystem() const;

        u32 _0;
        u32 _4;
        u64* mEffectSystem; // _8 most likely al::EffectSystem*
        u64 _10;
        u32 _18;
    };
};