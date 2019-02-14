/**
 * @file PlayerHitPointData.h
 * @brief Keeps track on the player's health.
 */

#pragma once

#include "types.h"

class PlayerHitPointData
{
public:
    PlayerHitPointData();

    void setKidsModeFlag(bool);
    void init();
    void recoverMax();
    s32 getCurrent() const;
    s32 getMaxCurrent() const;
    s32 getMaxWithItem() const;
    s32 getMaxWithoutItem() const;
    bool isMaxCurrent() const;
    bool isMaxWithItem() const;
    void getMaxUpItem();
    void recover();
    void recoverForDebug();
    void damage();
    void kill();
    void forceNormalMode();
    void endForceNormalMode();
    bool isForceNormalMode() const;

    bool mIsKidsMode; // _8
    u8 reserved_0; // _9
    u16 reserved_1; // _A
    s32 mCurHealth; // _C
    bool mIsHaveMaxUpItem; // _10
    bool mIsForceNormalMode; // _11
};