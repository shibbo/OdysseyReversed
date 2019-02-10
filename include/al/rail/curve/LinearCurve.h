/**
 * @file LinearCurve.h
 * @brief A class that represents a node in a linear curve.
 */

#pragma once

#include "sead/vector.h"
#include "types.h"

namespace al
{
    class LinearCurve
    {
    public:
        LinearCurve();

        void set(sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        void calcPos(sead::Vector3<f32> *out, f32) const;
        void calcVelocity(sead::Vector3<f32> *, f32);
        f32 calcLength(f32, f32) const;
        f32 calcCurveParam(f32) const;
        f32 calcNearestParam(sead::Vector3<f32> const &) const;
        void calcNearestLength(f32 *length, sead::Vector3<f32> const &, f32) const;
        void calcNearestPos(sead::Vector3<f32> *outPos, sead::Vector3<f32> const &) const;
        void calcStartPos(sead::Vector3<f32> *out) const;
        void calcEndPos(sead::Vector3<f32> *out) const;

        sead::Vector3<f32> mPosition; // _0
        sead::Vector3<f32> mVelocity; // _C
        f32 mLength; // _18
        f32 _1C;
    };
};