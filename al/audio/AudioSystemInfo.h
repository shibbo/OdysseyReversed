/**
 * @file AudioSystemInfo.h
 * @brief Databases of information for all audio / sound effects.
 */

#pragma once

#include "types.h"

namespace al
{
    class AudioSystemInfo
    {
    public:
        AudioSystemInfo();

        u64 _0;
        u64 _8;
        u64 _10;
        u64* _18; // al::SeDataBase*
        u64* _20; // al::BgmDataBase*
        u64 _28;
        u64 _30;
        u64 _38;
        u64 _40;
        u64* _48; // al::SeadAudioPlayer*
        u8 _50[0xA0-0x50];
    };
};