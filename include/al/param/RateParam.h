/**
 * @file RateParam.h
 * @brief Parameters for camera rates.
 */

#pragma once

#include "al/camera/CameraTicket.h"
#include "al/iuse/IUseCamera.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class RateParamV3f
    {
    public:
        RateParamV3f();

        void setParam(sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        void getParam(sead::Vector3<f32> *, sead::Vector3<f32> *) const;
        void calcLerpValue(sead::Vector3<f32> *, f32) const;
        void calcEaseInValue(sead::Vector3<f32> *, f32) const;
        void calcEaseOutValue(sead::Vector3<f32> *, f32) const;
        void calcEaseInOutValue(sead::Vector3<f32> *, f32) const;

        f32 mStartX; // _0
        f32 mStartZ; // _4
        f32 mEndX; // _8
        f32 mEndZ; // _C
    };

    class RateParamF32
    {
    public:
        RateParamF32();

        void setParam(f32, f32);

        IUseCamera* _0;
        al::CameraTicket* _8;
        u64 _10;
        u64 _18;
    };
};