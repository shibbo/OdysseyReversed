/**
 * @file ByamlHeader.cpp
 * @brief Storage container for a BYAML header.
 */

#include "al/byaml/ByamlHeader.h"

#include "endianess.h"

namespace al
{
    u16 ByamlHeader::getTag() const
    {
        u16 rawTag, reversedTag, tag;

        rawTag = this->mTag;
        reversedTag = swap16(rawTag);

        // "YB" in ASCII
        if (rawTag == 0x5942)
        {
            tag = reversedTag;
        }
        else
        {
            tag = this->mTag;
        }
        
        return tag;
    }

    bool ByamlHeader::isinvertOrder() const
    {
        return this->mTag == 0x5942;
    }

    u16 ByamlHeader::getVersion() const
    {
        u16 version;

        u16 rawVersion = *(u16*)&this->mTag >> 16;
        u16 reversedVersion = swap16(rawVersion);

        // it seems to do some weird stuff to get to a simple variable
        // it also does checks to see if the tag is right, so I guess that's why
        if ((*(u16*)&this->mTag & 0xFFFF) == 0x5942)
        {
            version = reversedVersion;
        }
        else
        {
            version = rawVersion;
        }

        return version;
    }

    u32 ByamlHeader::getHashKeyTableOffset() const
    {
        u32 hashTableOffset;

        u32 hashTableOffsetRaw = this->mHashTableOffset;
        u32 revHashTableOffset = swap32(hashTableOffsetRaw);

        if (this->mTag == 0x5942)
        {
            hashTableOffset = revHashTableOffset;
        }
        else
        {
            hashTableOffset = hashTableOffsetRaw;
        }
        
        return hashTableOffset;
    }

    u32 ByamlHeader::getStringTableOffset() const
    {
        u32 stringTableOffset;

        u32 stringTableOffsetRaw = this->mStringTableOffset;
        u32 revStringTableOffset = swap32(stringTableOffsetRaw);

        if (this->mTag == 0x5942)
        {
            stringTableOffset = revStringTableOffset;
        }
        else
        {
            stringTableOffset = stringTableOffsetRaw;
        }
        
        return stringTableOffset;
    }

    u32 ByamlHeader::getDataOffset() const
    {
        u32 dataOffset;

        u32 dataOffsetRaw = this->mDataOffset;
        u32 revDataOffset = swap32(dataOffsetRaw);

        if (this->mTag == 0x5942)
        {
            dataOffset = revDataOffset;
        }
        else
        {
            dataOffset = dataOffsetRaw;
        }
        
        return dataOffset;
    }
};