/**
 * @file StageSwitchInfo.h
 * @brief Storage container for stage switches.
 */

#pragma once

#include "types.h"

namespace al
{
    class StageSwitchInfo
    {
    public:
        u64 _0;
        u8 _8;
        u8 _9; // padding?
        u8 _A; // ^^
        u8 _B; // ^^
    };
};