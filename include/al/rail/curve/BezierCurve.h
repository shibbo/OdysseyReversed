/**
 * @file BezierCurve.h
 * @brief A class that represents a node in a bezier curve.
 */

#pragma once

#include "sead/vector.h"
#include "types.h"

namespace al
{
    class BezierCurve
    {
    public:
        BezierCurve();

        void set(sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        f32 calcLength(f32, f32, s32) const;
        void calcPos(sead::Vector3<f32> *out, f32) const;
        void calcVelocity(sead::Vector3<f32> *, f32) const;
        f32 calcDeltaLength(f32) const;
        f32 calcCurveParam(f32) const;
        f32 calcNearestParam(sead::Vector3<f32> const &, f32) const;
        f32 calcNearestLength(f32 *, sead::Vector3<f32> const &, f32, f32) const;
        void calcNearestPos(sead::Vector3<f32> *outPos, sead::Vector3<f32> const &, f32) const;
        void calcStartPos(sead::Vector3<f32> *outPos) const;
        void calcCtrlPos1(sead::Vector3<f32> *) const;
        void calcCtrlPos2(sead::Vector3<f32> *) const;
        void calcEndPos(sead::Vector3<f32> *) const;

        sead::Vector3<f32> mStartPosition; // _0
        sead::Vector3<f32> mControlPos1; // _C
        sead::Vector3<f32> mControlPos2; // _18
        sead::Vector3<f32> mEndPos; // _24
        f32 mLength; // _30
    };
};