/**
 * @file BgmPlayingRequest.h
 * @brief Stores data related to the next playable BGM.
 */

#pragma once

#include "types.h"

namespace al
{
    struct BgmPlayingRequest
    {
        char* _0;
        char* _8;
        char* _10;
        u32 _18;
        u32 _1C;
        u32 _20;
        u32 _24;
        u32 _28;
        u8 _2C;
        bool _2D; // changeSpeakerParamMode 2nd arg
        bool _2E; // startBgm boolean arg
        u8 _2F;
    };
};