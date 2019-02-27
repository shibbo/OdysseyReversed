/**
 * @file CameraAngleCtrlInfo.h
 * @brief Information about any camera object, such as angles, rotations locks, etc
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class CameraAngleCtrlInfo
    {
    public:
        CameraAngleCtrlInfo();

        static al::CameraAngleCtrlInfo* createWithRelativeH();
        void load(al::ByamlIter const &);
        void start(f32);
        void update(sead::Vector2<f32> const &, f32, bool);

        u64* _0;
        u64* _8;
        bool mIsValidRotateX; // _10
        u8 reserved0[0x3];
        u32 _14;
        f32 _18;
        f32 _1C;
        f32 mMinAngleH; // _20
        f32 mMaxAngleH; // _24
        f32 _28;
        f32 mAngleV; // _2C
        f32 _30;
        f32 mMinAngleV; // _34
        f32 mMaxAngleV; // _38
        f32 _3C;
        f32 _40;
        f32 _44;
        f32 _48;
        f32 _4C;
        bool mIsKeepPreAngleV; // _50
        bool _51;
        u8 reserved1[0x2];
        f32 mResetAngleV; // _54
        bool mIsInvalidRecieveRequest; // _58
    };
};