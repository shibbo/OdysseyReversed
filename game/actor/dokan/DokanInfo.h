/**
 * @file DokanInfo.h
 * @brief Information for a Pipe is stored in this class.
 */

#pragma once

#include "types.h"
#include "al/LiveActor.h"

enum DOKAN_TYPE
{
    REGULAR = 0,
    IS2D = 1,
    CRACK = 2
};

class DokanInfo
{
public:
    DokanInfo();

    al::LiveActor* mDokanActor; // _0
    u32 _8;
    bool mIsExitOnly; // _C
    u8 _D;
    bool mIsMoon; // _E
    u8 _F;
    u32 _10;
    u8 _14;
    u8 _15;
    u8 _16;
    bool mIsChangeStage; // _17
};