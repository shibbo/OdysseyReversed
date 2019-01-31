/**
 * @file PlayerHeadCostumeInfo.h
 * @brief Information on a costume head on Mario.
 */

#pragma once

#include "types.h"

class PlayerHeadCostumeInfo
{
public:
    PlayerHeadCostumeInfo();

    char* mName; // _0
    u8 mNeedsFullFaceAnim; // _8
    u8 mIsShrinkNose; // _9
    u8 mPreventHeadPain; // _8
    u8 mIsBigEar; // _B
    u8 _C;
    u8 _D;
    u16 _E;
    u16 _10;
    u8 _12;
    u8 mSyncSunglasses; // _13
    u8 _14;
    u8 mInvisibleHead; // _15
    u8 _16;
    u8 _17;
};