/**
 * @file ParameterObj.h
 * @brief Parameter instance object.
 */

#pragma once

#include "types.h"

namespace al
{
    class ParameterObj
    {
    public:
        ParameterObj();

        u64 _0;
        u64 _8;
        u64 _10;
        u64 _18;
        u8 _20[0x78-0x20];
    };
};