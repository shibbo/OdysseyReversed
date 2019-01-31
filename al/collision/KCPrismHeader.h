/**
 * @file KCPrismHeader.h
 * @brief Represents the header for the triangle section in a KCL.
 */

#pragma once

#include "types.h"

namespace al
{
    class KCPrismHeader
    {
    public:
        u32 mVertsOffset; // _0
        u32 mNormalsOffset; // _4
        u32 mTrisOffset; // _8
        u32 mSpatialsOffset; // _C
        f32 _10;
        f32 mSpatialGridX; // _14
        f32 mSpatialGridY; // _18
        f32 mSpatialGridZ; // _1C
        u32 mXMask; // _20
        u32 mYMask; // _24
        u32 mZMask; // _28
        u32 mCoordShift; // _2C
        u32 mYShift; // _30
        u32 mZShift; // _34
        f32 _38;
    };
};