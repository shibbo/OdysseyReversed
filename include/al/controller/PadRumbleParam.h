/**
 * @file PadRumbleParam.h
 * @brief Parameter structure for rumbles.
 */

#pragma once

#include "types.h"

namespace al
{
    class PadRumbleParam
    {
    public:
        void setVolumeByBalance();

        u64 _0; // unused?
        f32 _8; // cosf_0(710191024C)
        f32 _C; // sinf_0(71019102DC)
    };
};