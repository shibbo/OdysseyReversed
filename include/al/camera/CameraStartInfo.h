/**
 * @file CameraStartInfo.h
 * @brief Contains initialization info for a camera.
 */

#pragma once

#include "types.h"

namespace al
{
    struct CameraStartInfo
    {
        s32 _0;
        s32 reserved; // _4
        char* mCameraName; // _8
        f32 mPreCameraSwingAngleH; // _10
        f32 mPreCameraSwingAngleV; // _14
        f32 mPreCameraMaxSwingAngleH; // _18
        f32 mPreCameraMaxSwingAngleV; // _1C
        bool mIsInvalidColliderPreCamera; // _20
        bool mIsInvalidKeepPreCameraDistance; // _21
        bool mIsInvalidKeepPreCameraDistanceIfNoCollide; // _22
        bool mIsValidResetPreCameraPose; // _23
        bool mIsValidKeepPreSelfCameraPose; // _24
        u8 reserved1; // _25
        bool mIsExistAreaAngleH; // _26
        u8 reserved2; // _27
        f32 mAreaAngleH; // _28
        bool mIsExistAreaAngleV; // _2C
        u8 reserved3[0x3];
        f32 mAreaAngleV; // _30
        bool mIsExistNExtPoseByPreCamera; // _34

        f32 mGetNextAngleHByPreCamera; // _38
        f32 mGetNextAngleVByPreCamera; // _3C
    };
};