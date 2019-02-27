/**
 * @file CameraParamMoveLimit.h
 * @brief Limiations on movement for camera objects.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "sead/camera.h"
#include "types.h"

namespace al
{
    class CameraPoser;

    class CameraParamMoveLimit
    {
    public:
        CameraParamMoveLimit();

        static al::CameraParamMoveLimit* create(al::CameraPoser const *);
        void load(al::ByamlIter const &);
        void apply(sead::LookAtCamera *) const;

        f32 mPlusX; // _0
        f32 mPlusY; // _4
        f32 mPlusZ; // _8
        f32 mMinusX; // _C
        f32 mMinusY; // _10
        f32 mMinusZ; // _14
        bool mHasPlusX; // _18
        bool mHasMinusX; // _19
        bool mHasPlusY; // _1A
        bool mHasMinusY; // _1B
        bool mHasPlusZ; // _1C
        bool mHasMinusZ; // _1D
    };
};