/**
 * @file bit.h
 * @brief Functions for bit operations.
 */

#include "types.h"

namespace sead
{
    class BitFlagUtil
    {
    public:
        static u32 countOnBit(u32 val);
        static u32 countRightOnBit(u32, s32);
        static s32 findOnBitFromRight(u32, s32);
        static u32 countRightOnBit64(u64, s32);
        static s32 findOnBitFromRight64(u64, s32);
    };
};