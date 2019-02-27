/**
 * @file CameraAngleSwingInfo.h
 * @brief Information on a camera's "swing" animations.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "sead/camera.h"
#include "sead/vector.h"

namespace al
{
    class CameraAngleSwingInfo
    {
    public:
        CameraAngleSwingInfo();

        void load(al::ByamlIter const &);
        void update(sead::Vector2<f32> const &, f32);
        void makeLookAtCamera(sead::LookAtCamera *);

        bool mIsInvalidSwing; // _0
        u8 reserved[0x3];
        f32 _4;
        f32 _8;
        f32 mMaxSwingDegreeH; // _C
        f32 mMaxSwingDegreeV; // _10
        f32 _14;
        f32 _18;
    };
};