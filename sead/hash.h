#pragma once

#include "types.h"

namespace sead
{
    class HashCRC16
    {
    public:
        void Initialize();
        s16 calcHash(void const *data, u32);
        s16 calcStringHash(char const *str);

        static s8 sTable[0x100];
        static s8 sInitialized;
    };

    class HashCRC32
    {
    public:
        void Initialize();
        s32 calcHash(void const *data, u32);
        s32 calcStringHash(char const *str);

        static s8 sTable[0x10000];
        static s8 sInitialized;
    };
};