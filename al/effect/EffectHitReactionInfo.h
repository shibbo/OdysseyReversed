/**
 * @file EffectHitReactionInfo.h
 * @brief Reaction information for a spawned effect.
 */

#pragma once

#include "types.h"

namespace al
{
    class EffectHitReactionInfo
    {
    public:
        EffectHitReactionInfo();

        u64 _0;
        u32 _8;
        u32 _C;
        u64 _10;
    };
};