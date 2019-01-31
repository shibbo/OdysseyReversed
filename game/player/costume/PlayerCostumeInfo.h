/**
 * @file PlayerCostumeInfo.h
 * @brief Costume information is stored here.
 */

#pragma once

#include "PlayerBodyCostumeInfo.h"
#include "PlayerHeadCostumeInfo.h"

class PlayerCostumeInfo
{
public:
    PlayerCostumeInfo();

    void init(PlayerBodyCostumeInfo const *, PlayerHeadCostumeInfo const *);
    bool isEnableBigEar() const;
    bool isEnableHairNoCap() const;
    bool isEnableCostume2D() const;
    bool isNeedShrinkNose() const;
    bool isNeedBodyHair() const;
    bool isNeedSyncBodyHair() const;
    bool isNeedFullFaceAnim() const;
    bool isHidePainNose() const;
    bool isEnableEarring() const;
    bool isEnableStrap() const;
    bool isSyncFaceBeard() const;
    bool isSyncStrap() const;
    bool isSyncSunglass() const;
    bool isFollowJoeStrap() const;
    bool isOffsetSunglass() const;
    bool isPreventHeadPain() const;
    bool isInvisibleHead() const;
    bool is8Bit() const;
    s32 calcWarmLevel(s32) const;
    

    PlayerBodyCostumeInfo* mBodyCostumeInfo; // _0
    PlayerHeadCostumeInfo* mHeadCostumeInfo; // _8
};