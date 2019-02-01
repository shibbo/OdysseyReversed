/**
 * @file PadGyroAddon.h
 * @brief Addon for gyro compatability.
 */

#pragma once

#include "sead/controller.h"
#include "sead/vector.h"

namespace al
{
    // I didn't see any members introducd in ControllerAddon except for the vtable...
    // we can just assume that it was the only one considering the lack of functions
    class PadGyroAddon : public sead::ControllerAddon
    {
    public:
        PadGyroAddon(sead::Controller *, s32);
        virtual ~PadGyroAddon();

        virtual void calc_();

        u64 _8;
        u64 _10;
        u32 _18;
        u32 _1C;
        sead::Controller* mController; // _20
        u32 _28;
        u64 _2C;
        u32 _34;
        f32* _38;
        u32 _40;
        u32 _44;
        u32 _48;
        f32 _4C;
        u64 _50;
        u64 _58;
        u64 _60;
        u64 _68;
        u32 _70;
        u32 _74;
    };
};