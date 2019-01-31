/**
 * @file ByamlContainerHeader.h
 * @brief Container for a BYAML header.
 */

#pragma once

#include "types.h"

namespace al
{
    class ByamlContainerHeader
    {
    public:
        u32 getType() const;
        u32 getCount(bool swapEndianess) const;

        u32 mType; // _0
    };
};