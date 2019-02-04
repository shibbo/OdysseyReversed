/**
 * @file ByamlArrayIter.h
 * @brief Iterator for array types in a BYAML.
 */

#pragma once

#include "ByamlData.h"
#include "types.h"

namespace al
{
    class ByamlArrayIter
    {
    public:
        ByamlArrayIter();
        ByamlArrayIter(u8 const *arraySrc, bool swapEndianess);

        u32 getSize() const;
        u8* getTypeTable() const;
        u8* getDataTable() const;
        bool getDataByIndex(al::ByamlData *dest, s32 idx) const;
        u8* getOffsetData(u32 idx) const;

        u8* mArraySrc; // _0
        u8 mSwapEndianess; // _8
    };
};