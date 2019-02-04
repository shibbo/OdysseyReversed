/**
 * @file ByamlData.h
 * @brief Storage container for raw BYAML data.
 */

#pragma once

#include "ByamlHashPair.h"
#include "types.h"

namespace al
{
    class ByamlData
    {
    public:
        ByamlData();

        void set(al::ByamlHashPair const *hashPair, bool swapEndianess);
        void set(u8 type, u32 value, bool swapEndianess);
        u8 getType() const;
        u32 getValue() const;

        u32 mValue; // _0
        u8 mType; // _4
    };
};