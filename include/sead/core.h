/**
 * @file core.h
 * @brief Core thread information.
 */

#pragma once

#include "types.h"

namespace sead
{
    typedef u32 CoreId;

    class CoreIdMask
    {
        u32 countOnBits() const;

        u32 mBits; // _0
    };

    class CoreInfo
    {
    public:
        static void configure();
        static u32 getPlatformMask(sead::CoreId);
        static void dump();

        static u8 sNumCores;
        static sead::CoreId sPlatformCoreId;
        static u64* sCoreIdFromPlatformCoreIdTable;
    };
};