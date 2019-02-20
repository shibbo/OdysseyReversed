/**
 * @file ByamlHeader.cpp
 * @brief Storage container for a BYAML header.
 */

#include "al/byaml/ByamlHeader.h"

namespace al
{
    u16 ByamlHeader::getTag() const
    {
        u16 rawTag, reversedTag, tag;

        rawTag = this->mTag;
        reversedTag = (rawTag << 8) | (rawTag >> 8);

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
        u16 reversedVersion = (rawVersion << 8) | (rawVersion >> 8);

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
        u32 revHashTableOffset = (hashTableOffsetRaw << 24) | ((hashTableOffsetRaw << 8) & 0xFF0000) | ((hashTableOffsetRaw >> 24) & 0xFF) | ((hashTableOffsetRaw >> 8) & 0xFF00);

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
        u32 revStringTableOffset = (stringTableOffsetRaw << 24) | ((stringTableOffsetRaw << 8) & 0xFF0000) | ((stringTableOffsetRaw >> 24) & 0xFF) | ((stringTableOffsetRaw >> 8) & 0xFF00);
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
        u32 revDataOffset = (dataOffsetRaw << 24) | ((dataOffsetRaw << 8) & 0xFF0000) | ((dataOffsetRaw >> 24) & 0xFF) | ((dataOffsetRaw >> 8) & 0xFF00);

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