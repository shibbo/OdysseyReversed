/**
 * @file ParameterIo.h
 * @brief I/O parameters.
 */

#pragma once

#include "types.h"

namespace al
{
    class ParameterIo
    {
    public:
        ParameterIo();

        u64 _0;
        u64 _8;
        u64 _10;
        u64 _18;
        u64 _20;
        u64 _28;
        u64* _30;
        u8 _38[0x80-0x38];
    };
};