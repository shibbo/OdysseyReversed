/**
 * @file KCPrismData.h
 * @brief Stores information of a triangle contained in a collision file.
 */

#pragma once

#include "types.h"

namespace al
{
    class KCPrismData
    {
    public:
        f32 mLength; // _0
        u16 mPosIndex; // _4
        u16 mDirIndex; // _6
        u16 mNormAIndex; // _8
        u16 mNormBIndex; // _A
        u16 mNormCIndex; // _C
        u16 mCollisionFlags; // _E
        u32 mGlobalTriIndex; // _10
    };
};