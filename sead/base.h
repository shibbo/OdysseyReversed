/**
 * @file base.h
 * @brief Base64 encoding / decoding.
 */

#pragma once

#include "types.h"

namespace sead
{
    class Base64
    {
    public:
        static void encode(char *dest, void const *srcBytes, u64 length, bool useDiffSet);
        static u32 decode(void *, u64, char const *, u64, u64 *);
    };
};