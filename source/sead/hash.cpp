/**
 * @file hash.h
 * @brief Basic CRC implementation.
 */

#include "sead/hash.h"

namespace sead
{
    void HashCRC16::Initialize()
    {
        s32 tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tableIndex;

       tableIndex = 0;

        do
        {
            tab0 = tableIndex >> 1;

            if (tableIndex & 1)
            {
                tab0 = (tableIndex >> 1) ^ 0xA001;
            }
            if (tab0 & 1)
            {
                tab1 = (tab0 >> 1) ^ 0xA001;
            }
            else
            {
                tab1 = tab0 >> 1;
            }
            if (tab1 & 1)
            {
                tab2 = (tab1 >> 1) ^ 0xA001;
            }
            else
            {
                tab2 = tab1 >> 1;
            }
            if (tab2 & 1)
            {
                tab3 = (tab2 >> 1) ^ 0xA001;
            }
            else
            {
                tab3 = tab2 >> 1;
            }
            if (tab3 & 1)
            {
                tab4 = (tab3 >> 1) ^ 0xA001;
            }
            else
            {
                tab4 = tab3 >> 1;
            }
            if (tab4 & 1)
            {
                tab5 = (tab4 >> 1) ^ 0xA001;
            }
            else
            {
                tab5 = tab4 >> 1;
            }
            if (tab5 & 1)
            {
                tab6 = (tab5 >> 1) ^ 0xA001;
            }
            else
            {
                tab6 = tab5 >> 1;
            }
            if (tab6 & 1)
            {
                tab7 = (tab6 >> 1) ^ 0xA001;
            }
            else
            {
                tab7 = tab6 >> 1;
            }

            HashCRC16::sTable[tableIndex++] = tab7;
        }
        while (tableIndex != 0x100);
        
        HashCRC16::sInitialized = 1;
    }

    s16 HashCRC16::calcHash(void const *source, u32 length)
    {
        u8 curByte;
        s16 curHash;
        s32 tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tableIndex;

        if (!HashCRC16::sInitialized)
        {
            tableIndex = 0;

            do
            {
                tab0 = tableIndex >> 1;

                if (tableIndex & 1)
                {
                    tab0 = (tableIndex >> 1) ^ 0xA001;
                }
                if (tab0 & 1)
                {
                    tab1 = (tab0 >> 1) ^ 0xA001;
                }
                else
                {
                    tab1 = tab0 >> 1;
                }
                if (tab1 & 1)
                {
                    tab2 = (tab1 >> 1) ^ 0xA001;
                }
                else
                {
                    tab2 = tab1 >> 1;
                }
                if (tab2 & 1)
                {
                    tab3 = (tab2 >> 1) ^ 0xA001;
                }
                else
                {
                    tab3 = tab2 >> 1;
                }
                if (tab3 & 1)
                {
                    tab4 = (tab3 >> 1) ^ 0xA001;
                }
                else
                {
                    tab4 = tab3 >> 1;
                }
                if (tab4 & 1)
                {
                    tab5 = (tab4 >> 1) ^ 0xA001;
                }
                else
                {
                    tab5 = tab4 >> 1;
                }
                if (tab5 & 1)
                {
                    tab6 = (tab5 >> 1) ^ 0xA001;
                }
                else
                {
                    tab6 = tab5 >> 1;
                }
                if (tab6 & 1)
                {
                    tab7 = (tab6 >> 1) ^ 0xA001;
                }
                else
                {
                    tab7 = tab6 >> 1;
                }

                HashCRC16::sTable[tableIndex++] = tab7;
            }
            while (tableIndex != 0x100);
            
            HashCRC16::sInitialized = 1;
        }

        if (length)
        {
            curHash = 0;
            do
            {
                curByte = *(u8*)source;
                source = (u8*)source + 1;
                curHash = HashCRC16::sTable[curByte ^ curHash] ^ (curHash >> 8);
                --length;
            } 
            while (length);
        }
        else
        {
            curHash = 0;
        }

        return ~curHash;
    }

    void HashCRC32::Initialize()
    {
        s32 tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tableIndex;

        tableIndex = 0;

        do
        {
            tab0 = tableIndex >> 1;

            if (tableIndex & 1)
            {
                tab0 = (tableIndex >> 1) ^ 0xEDB88320;
            }
            if (tab0 & 1)
            {
                tab1 = (tab0 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab1 = tab0 >> 1;
            }
            if (tab1 & 1)
            {
                tab2 = (tab1 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab2 = tab1 >> 1;
            }
            if (tab2 & 1)
            {
                tab3 = (tab2 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab3 = tab2 >> 1;
            }
            if (tab3 & 1)
            {
                tab4 = (tab3 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab4 = tab3 >> 1;
            }
            if (tab4 & 1)
            {
                tab5 = (tab4 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab5 = tab4 >> 1;
            }
            if (tab5 & 1)
            {
                tab6 = (tab5 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab6 = tab5 >> 1;
            }
            if (tab6 & 1)
            {
                tab7 = (tab6 >> 1) ^ 0xEDB88320;
            }
            else
            {
                tab7 = tab6 >> 1;
            }

            HashCRC32::sTable[tableIndex++] = tab7;
        }
        while (tableIndex != 0x100);
        
        HashCRC32::sInitialized = 1;
    }

    s32 HashCRC32::calcHash(void const *source, s32 length)
    {
        u8 curByte;
        s32 curHash, tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tableIndex;

        if (!HashCRC32::sInitialized)
        {
            tableIndex = 0;

            do
            {
                tab0 = tableIndex >> 1;

                if (tableIndex & 1)
                {
                    tab0 = (tableIndex >> 1) ^ 0xEDB88320;
                }
                if (tab0 & 1)
                {
                    tab1 = (tab0 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab1 = tab0 >> 1;
                }
                if (tab1 & 1)
                {
                    tab2 = (tab1 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab2 = tab1 >> 1;
                }
                if (tab2 & 1)
                {
                    tab3 = (tab2 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab3 = tab2 >> 1;
                }
                if (tab3 & 1)
                {
                    tab4 = (tab3 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab4 = tab3 >> 1;
                }
                if (tab4 & 1)
                {
                    tab5 = (tab4 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab5 = tab4 >> 1;
                }
                if (tab5 & 1)
                {
                    tab6 = (tab5 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab6 = tab5 >> 1;
                }
                if (tab6 & 1)
                {
                    tab7 = (tab6 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab7 = tab6 >> 1;
                }

                HashCRC32::sTable[tableIndex++] = tab7;
            }
            while (tableIndex != 0x100);
            
            HashCRC32::sInitialized = 1;
        }

        if (!length)
        {
            return 0;
        }

        curHash = -1;
        do
        {
            // we get it byte by byte, so cast to a u8 ptr and then dereference it
            curByte = *(u8*)source;
            // go to next byte
            source = (u8*)source + 1;
            // calc the current hash through our already created table
            curHash = HashCRC32::sTable[curByte ^ curHash] ^ (curHash >> 8);
            --length;
        } 
        while (length);
        
        return ~curHash;
    }

    s32 HashCRC32::calcStringHash(char const *source)
    {
        u8 curByte, nextByte, v13;
        s32 curHash, tab0, tab1, tab2, tab3, tab4, tab5, tab6, tab7, tableIndex;

        if (!HashCRC32::sInitialized)
        {
            tableIndex = 0;

            do
            {
                tab0 = tableIndex >> 1;

                if (tableIndex & 1)
                {
                    tab0 = (tableIndex >> 1) ^ 0xEDB88320;
                }
                if (tab0 & 1)
                {
                    tab1 = (tab0 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab1 = tab0 >> 1;
                }
                if (tab1 & 1)
                {
                    tab2 = (tab1 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab2 = tab1 >> 1;
                }
                if (tab2 & 1)
                {
                    tab3 = (tab2 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab3 = tab2 >> 1;
                }
                if (tab3 & 1)
                {
                    tab4 = (tab3 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab4 = tab3 >> 1;
                }
                if (tab4 & 1)
                {
                    tab5 = (tab4 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab5 = tab4 >> 1;
                }
                if (tab5 & 1)
                {
                    tab6 = (tab5 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab6 = tab5 >> 1;
                }
                if (tab6 & 1)
                {
                    tab7 = (tab6 >> 1) ^ 0xEDB88320;
                }
                else
                {
                    tab7 = tab6 >> 1;
                }

                HashCRC32::sTable[tableIndex++] = tab7;
            }
            while (tableIndex != 0x100);
            
            HashCRC32::sInitialized = 1;
        }

        curByte = *(u8*)source;

        if (!*source)
        {
            return 0;
        }
        nextByte = (u8)source + 1;
        curHash = -1;
        do
        {
            curHash = HashCRC32::sTable[(curByte ^ curHash) & 0xFF] ^ (curHash >> 8);
            v13 = *(u8*)nextByte++;
            curByte = v13;
        }
        while (v13);

        return ~curHash;
    }
};