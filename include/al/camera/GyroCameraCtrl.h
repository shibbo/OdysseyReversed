/**
 * @file GyroCameraCtrl.h
 * @brief Information about gyro controlled cameras.
 */

#pragma once

#include "sead/vector.h"
#include "types.h"

namespace al
{
    class GyroCameraCtrl
    {
    public:
        GyroCameraCtrl();

        void reset(sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        void update(sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &);
        void reduceSensitivity();

        u8 _0[0x30]; // matrix34
        u64 _30;
        f32 _3C;
        u32 _40;
        f32 _44;
        f32 _48;
        f32 _4C;
        f32 _50;
        u64 _54;
        u32 _5C;
        u32 _60;
        u32 _64;
        u32 _68;
        u32 _6C;
        u32 _70;
        u32 _74;
        f32 _78;
        f32 _7C;
        f32 _80;
        f32 _84;
        f32 _88;
        f32 _8C;
        f32 _90;
        f32 _94;
        f32 _98;
        s32 mSensitivity; // _9C
        f32 _A0;
        f32 _A4;
        f32 _A8;
        u8 _AC;
        u8 _AD[0x3];
        f32 _B0;
        f32 _B4;
        f32 _B8;
        f32 _BC;
        f32 _C0;
        f32 _C4;
    };
};