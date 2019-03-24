/**
 * @file PlayerOxygen.h
 * @brief Class that holds oxygen data for the player.
 */

#pragma once

#include "types.h"

class PlayerOxygen
{
public:
    PlayerOxygen();
    
    void setup(s32, s32, s32, s32);
    void reset();
    void reduce();
    void recovery();
    bool isTriggerDamage() const;

    f32 mCurOxygen; // _0
    u32 _4; // frame related
    u32 _8;
    s32 mNoReduceFrame; // _C
    s32 mReduceFrame; // _10
    s32 mRecoveryFrame; // _14
    s32 mDamageInterval; // _18
};