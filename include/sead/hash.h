/**
 * @file hash.h
 * @brief Basic CRC implementation.
 */

#pragma once

#include "types.h"

namespace sead
{
    class HashCRC16
    {
    public:
        static void Initialize();
        static s16 calcHash(void const *data, u32);
        static s16 calcStringHash(char const *str);

        static s8 sTable[0x100];
        static s8 sInitialized;
    };

    class HashCRC32
    {
    public:
        static void Initialize();
        static s32 calcHash(void const *data, u32);
        static s32 calcStringHash(char const *str);

        static s8 sTable[0x10000];
        static s8 sInitialized;
    };
};