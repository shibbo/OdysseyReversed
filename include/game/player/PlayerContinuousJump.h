/**
 * @file PlayerContinuousJump.h
 * @brief Class that stores the jump of the player.
 */

#pragma once

#include "PlayerConst.h"
#include "../../sead/vector.h"

class PlayerContinuousJump
{
public:
    PlayerContinuousJump(PlayerConst const *);

    void update(bool);
    void clear();
    void countUp(sead::Vector3<f32> const &);

    PlayerConst* mPlayerConst; // _0
    u32 _8;
    f32 _C;
    sead::Vector3<f32> _10;
};