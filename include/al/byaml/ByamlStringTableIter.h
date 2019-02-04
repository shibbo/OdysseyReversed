/**
 * @file ByamlStringTableIter.h
 * @brief Iterator for the string table.
 */

#pragma once

#include "types.h"

namespace al
{
    class ByamlStringTableIter
    {
    public:
        ByamlStringTableIter();
        ByamlStringTableIter(u8 const *strTableSrc, bool swapEndianess);

        u32 getSize() const;
        u64 getAddressTable() const;
        u32 getStringAddress(s32 idx) const;
        u32 getEndAddress() const;
        u8* getString(s32 idx) const;
        u32 getStringSize(s32 idx) const;
        s32 findStringIndex(char const *str) const;
        bool isValidate() const;

        u8* mStringTableSrc; // _0
        u32 mSwapEndianess; // _8
    };
};