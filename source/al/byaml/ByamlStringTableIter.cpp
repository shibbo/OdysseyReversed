/**
 * @file ByamlStringTableIter.cpp
 * @brief Iterator for the string table.
 */

#include "al/byaml/ByamlStringTableIter.h"

#include "endianess.h"
#include "string.h"

namespace al
{
    ByamlStringTableIter::ByamlStringTableIter()
    {
        this->mStringTableSrc = 0;
        this->mSwapEndianess = 0;
    }

    ByamlStringTableIter::ByamlStringTableIter(u8 const *tableSrc, bool swap)
    {
        this->mStringTableSrc = (u8*)tableSrc;
        this->mSwapEndianess = swap & 0x1;
    }

    u32 ByamlStringTableIter::getSize() const
    {
        u32 size;

        // grabs first 4 bytes of the table
        u32 table = *(u32*)this->mStringTableSrc;

        if (this->mSwapEndianess)
        {
            size = ((((table >> 8) & 0xFF00) | (table >> 24)) & 0xFF00FFFF) | table >> 8 << 16;
        }
        else
        {
            size = table >> 8;
        }

        return size;
    }

    u64 ByamlStringTableIter::getAddressTable() const
    {
        // access u32 at 0x4
        return *(u64*)this->mStringTableSrc + 4;
    }

    u32 ByamlStringTableIter::getStringAddress(s32 idx) const
    {
        u32 addr;
    
        u32 rawAddr = *(u32*)&this->mStringTableSrc[4 * idx + 4];
        u32 swappedAddr = swap32(rawAddr);

        if (this->mSwapEndianess)
        {
            addr = swappedAddr;
        }
        else
        {
            addr = rawAddr;
        }

        return addr;
    }

    u32 ByamlStringTableIter::getEndAddress() const
    {
        s32 idx;
        u32 addr;

        u32 table = *(u32*)this->mStringTableSrc;

        if (this->mSwapEndianess)
        {
            idx = ((((table >> 8) & 0xFF00) | (table >> 24)) & 0xFF00FFFF) | (table >> 8 << 16);
        }
        else
        {
            idx = table >> 8;
        }

        u32 rawAddr = *(u32*)&this->mStringTableSrc[4 * idx + 4];
        u32 swappedAddr = swap32(rawAddr);

        if (this->mSwapEndianess)
        {
            addr = swappedAddr;
        }
        else
        {
            addr = rawAddr;
        }

        return addr;
    }

    u8* ByamlStringTableIter::getString(s32 idx) const
    {
        u32 addr;
        
        u32 rawAddr = swap32(*(u32*)&this->mStringTableSrc[4 * idx + 4]);

        if (this->mSwapEndianess)
        {
            addr = rawAddr;
        }
        else
        {
            addr = *(u32*)&this->mStringTableSrc[4 * idx + 4];
        }

        return &this->mStringTableSrc[addr];
    }

    u32 ByamlStringTableIter::getStringSize(int idx) const
    {
        u32 v6, v7;

        u8* src = &this->mStringTableSrc[4 * idx];

        u32 v4 = *((u32*)src + 0x4);
        u32 v3 = *((u32*)src + 0x8);
        u32 v5 = swap32(v3);

        if (this->mSwapEndianess)
        {
            v6 = v5;
        }
        else
        {
            v6 = v3;
        }

        v7 = swap32(v4);

        if (!this->mSwapEndianess)
        {
            v7 = v4;
        }

        return v6 - 1 - v7;
    }

    s32 ByamlStringTableIter::findStringIndex(char const *str) const
    {
        u8* tableSrc;
        u32 tableData;
        char* v4 = 0;
        s32 v1;
        s64 v6;
        s32 v7, v10, v11, v12;
        s32 v8 = 0;
        s32 idx = -1;

        tableSrc = this->mStringTableSrc;
        tableData = *(u32*)this->mStringTableSrc;

        if (this->mSwapEndianess)
        {
            v1 = ((((tableData >> 8) & 0xFF00) | (tableData >> 24)) & 0xFF00FFFF) | (tableData >> 8 << 16);
        }
        else
        {
            v1 = tableData >> 8;
        }

        if (v1 < 1)
        {
            idx = -1;
        }
        else
        {
            v6 = (s64)(tableSrc + 4);
            v7 = 0;

            if (this->mSwapEndianess)
            {
                do
                {
                    v8 = v7 + v1;

                    if (v7 + v1 < 0)
                    {
                        ++v8;
                    }

                    idx = v8 >> 1;
                    v10 = strcmp_0(v4, (char*)&tableSrc[swap32(*(u32*)(v6 + 4 * (v8 >> 1)))]);

                    if (!v10)
                    {
                        break;
                    }

                    if (v10 > 0)
                    {
                        v7 = idx + 1;
                    }

                    idx = -1;
                } 
                while (v7 < v1);
            }
            else
            {
                do
                {
                    v11 = v7 + v1;

                    if (v7 + v1 < 0)
                    {
                        ++v11;
                    }

                    idx = v11 >> 1;
                    v12 = strcmp_0(v4, (char*)&tableSrc[swap32(*(u32*)(v6 + 4 * (v8 >> 1)))]);

                    if (!v12)
                    {
                        break;
                    }

                    if (v12 <= 0)
                    {
                        v1 = idx;
                    }

                    if (v12 > 0)
                    {
                        v7 = idx + 1;
                    }

                    idx = -1;
                } 
                while (v7 < v1);
            }
        }

        return idx;
    }

    bool ByamlStringTableIter::isValidate() const
    {
        return *(u64*)this->mStringTableSrc != 0;
    }
};