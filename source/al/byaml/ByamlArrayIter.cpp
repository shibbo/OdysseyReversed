/**
 * @file ByamlArrayIter.cpp
 * @brief Iterator for array types in a BYAML.
 */

#include "al/byaml/ByamlArrayIter.h"

#include "endianess.h"

namespace al
{
    ByamlArrayIter::ByamlArrayIter()
    {
        this->mArraySrc = 0;
        this->mSwapEndianess = 0;
    }

    ByamlArrayIter::ByamlArrayIter(u8 const *src, bool swap)
    {
        this->mArraySrc = (u8*)src;
        this->mSwapEndianess = swap;
    }

    u32 ByamlArrayIter::getSize() const
    {
        u32 size;

        u32 tableHeader = *(u32*)this->mArraySrc;
        
        if (this->mSwapEndianess)
        {
            size = ((((tableHeader >> 8) & 0xFF00) | (tableHeader >> 24)) & 0xFF00FFFF) | (tableHeader >> 8 << 16);
        }
        else
        {
            size = tableHeader >> 8;
        }

        return size;
    }

    u8* ByamlArrayIter::getTypeTable() const
    {
        return this->mArraySrc + 4;
    }

    u8* ByamlArrayIter::getDataTable() const
    {
        u32 size;

        u32 tableHeader = *(u32*)this->mArraySrc;

        if (this->mSwapEndianess)
        {
            size = ((((tableHeader >> 8) & 0xFF00) | (tableHeader >> 24)) & 0xFF00FFFF) | (tableHeader >> 8 << 16);
        }
        else
        {
            size = tableHeader >> 8;
        }
        
        return &this->mArraySrc[(size + 7) & 0xFFFFFFFC];
    }

    bool ByamlArrayIter::getDataByIndex(ByamlData *out, s32 idx) const
    {
        u32 tableHeader;
        u32 v1, v7, rawValue, swapValue, outValue;
        bool ret;

        if (idx & 0x80000000)
        {
            return 0;
        }

        tableHeader = *(u32*)this->mArraySrc;

        if (this->mSwapEndianess)
        {
            v1 = ((((tableHeader >> 8) & 0xFF00) | (tableHeader >> 24)) & 0xFF00FFFF) | (tableHeader >> 8 << 16);
        }
        else
        {
            v1 = tableHeader >> 8;
        }

        if (v1 <= idx)
        {
            return 0;
        }

        if (this->mSwapEndianess)
        {
            v7 = ((((*(u32*)this->mArraySrc >> 8) & 0xFF00) | (*(u32*)this->mArraySrc >> 24)) & 0xFF00FFFF) | (*(u32*)this->mArraySrc >> 8 << 16);
        }
        else
        {
            v7 = *(u32*)this->mArraySrc >> 8;
        }
        
        u8 type = this->mArraySrc[idx + 4];
        ret = 1;
        rawValue = *(u32*)&this->mArraySrc[4 * idx + ((v7 + 7) & 0xFFFFFFFC)];
        out->mType = type;
        swapValue = swap32(rawValue);
        
        if (this->mSwapEndianess)
        {
            outValue = swapValue;
        }
        else
        {
            outValue = rawValue;
        }
        
        out->mValue = outValue;
        return ret;
    }

    u8* ByamlArrayIter::getOffsetData(u32 idx) const
    {
        return &this->mArraySrc[idx];
    }
};