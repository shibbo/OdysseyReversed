/**
 * @file RailPart.h
 * @brief A node contained in a rail, which can include curves.
 */

#pragma once

#include "curve/BezierCurve.h"
#include "curve/LinearCurve.h"
#include "types.h"

namespace al
{
    class RailPart
    {
    public:
        RailPart();

        void init(sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        void calcPos(sead::Vector3<f32> *, f32) const;
        void calcVelocity(sead::Vector3<f32> *, f32) const;
        void calcDir(sead::Vector3<f32> *, f32) const;
        void calcStartPos(sead::Vector3<f32> *) const;
        void calcEndPos(sead::Vector3<f32> *) const;
        f32 calcLength(f32, f32, s32) const;
        f32 calcCurveParam(f32) const;
        f32 calcNearestParam(sead::Vector3<f32> const &, f32) const;
        void calcNearestPos(sead::Vector3<f32> *, sead::Vector3<f32> const &, f32) const;
        void calcNearestLength(f32 *outLength, sead::Vector3<f32> const &, f32, f32) const;
        f32 getPartLength() const;

        al::BezierCurve* mBezierCurve; // _0
        al::LinearCurve* mLinearCurve; // _8
        u32 _10;
        u32 reserved;
    };
};