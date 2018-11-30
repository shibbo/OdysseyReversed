#pragma once

#include "types.h"

namespace al
{
    class ByamlHashPair;

    class ByamlData
    {
        public:
        ByamlData();

        void setData(al::ByamlHashPair const *hashPair, bool swapEndianess);
        void setData(u8 type, u32 value, bool swapEndianess);
        u8 getType() const;
        u32 getValue() const;

        u32 mValue; // _0
        u8 mType; // _4
    };
};