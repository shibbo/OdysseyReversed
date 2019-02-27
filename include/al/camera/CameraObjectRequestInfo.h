/**
 * @file CameraObjectRequestInfo.h
 * @brief Requests for camera angles and locks.
 */

#pragma once

#include "types.h"

namespace al
{
    struct CameraObjectRequestInfo
    {
        bool mIsRequestStopVerticalAbsorb; // _0
        bool mRequestResetPosition; // _1
        bool mIsRequestAngleV; // _2
        bool mIsRequestDownToDefaultAngleSpeed; // _3
        bool mIsRequestUpToTargetAngleSpeed; // _4
        f32 mRequestTargetAngleV; // _8
        f32 mRequestAngleSpeed; // _C
        bool mIsRequestMoveDownAngleV; // _10
        bool mIsRequestSetAngleV; // _11
        u8 reserved[0x3];
        f32 mRequestAngleV; // _14
    };
};