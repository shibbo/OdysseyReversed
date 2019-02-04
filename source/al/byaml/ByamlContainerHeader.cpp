/**
 * @file ByamlContainerHeader.cpp
 * @brief Container for a BYAML header.
 */

#include "al/byaml/ByamlContainerHeader.h"

namespace al
{
    u32 ByamlContainerHeader::getType() const
    {
        return this->mType;
    }

    u32 ByamlContainerHeader::getCount(bool swap) const
    {
        u32 count;

        if (swap & 0x1)
        {
            count = (((this->mType >> 8) & 0xFF00) | ((this->mType >> 24) & 0xFF00FFFF) | (this->mType >> 8 << 16));
        }
        else
        {
            count = this->mType >> 8;
        }

        return count;
    }
};