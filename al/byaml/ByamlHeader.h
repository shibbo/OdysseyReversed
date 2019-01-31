/**
 * @file ByamlHeader.h
 * @brief Storage container for a BYAML header.
 */

#pragma once

#include "types.h"

namespace al
{
    class ByamlHeader
    {
    public:
        u16 getTag() const;
        bool isinvertOrder() const;
        u16 getVersion() const;
        u32 getHashKeyTableOffset() const;
        u32 getStringTableOffset() const;
        u32 getDataOffset() const;

        u16 mTag; // _0
        u16 mVersion; // _2
        u32 mHashTableOffset; // _4
        u32 mStringTableOffset; // _8
        u32 mDataOffset; // _C
    };
}