/**
 * @file ByamlHashPair.h
 * @brief Storage for a value referenced by a key (hash).
 */

#pragma once

#include "types.h"

namespace al
{
    class ByamlHashPair
    {
    public:
        u32 getKey(bool swapEndianess) const;
        u8 getType() const;
        u32 getValue(bool swapEndianess) const;

        u16 mTopHalfNameID; // _0
        u8 mBottomNameID; // _2
        u8 mType; // _3
        u32 mVal; // _4
    };
}