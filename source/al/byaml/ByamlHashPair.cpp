/**
 * @file ByamlHashPair.cpp
 * @brief Storage for a value referenced by a key (hash).
 */

#include "al/byaml/ByamlHashPair.h"

namespace al
{
    u32 ByamlHashPair::getKey(bool swap) const
    {
        u32 key;

        // casting to u64 is a bit of a hacky solution but...
        if (swap & 0x1)
        {
            key = (((*(u32*)(u64)this->mTopHalfNameID & 0xFF00) | ((*(u32*)(u64)this->mTopHalfNameID & 0xFF) << 16)) & 0xFFFFFF00) | ((*(u32*)(u64)this->mTopHalfNameID >> 16) & 0xFF);
        }
        else
        {
            key = *(u32*)(u64)this->mTopHalfNameID & 0xFFFFFF;
        }

        return key;
    }

    u8 ByamlHashPair::getType() const
    {
        return this->mType;
    }

    u32 ByamlHashPair::getValue(bool swap) const
    {
        u32 value;

        u32 val = this->mVal;
        u32 revVal = (val << 24) | ((val << 8) & 0xFF0000) | ((val >> 24) & 0xFF) | ((val >> 8) & 0xFF00);

        if (swap & 0x1)
        {
            value = revVal;
        }
        else
        {
            value = val;
        }

        return value;
    }
};