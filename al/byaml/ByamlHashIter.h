#pragma once

#include "types.h"

namespace al
{
    class ByamlData;
    class ByamlHashPair;

    class ByamlHashIter
    {
    public:
        ByamlHashIter();
        ByamlHashIter(u8 const *srcByaml, bool swapEndianess);

        u32 getSize() const;
        u64 getPairTable() const;
        bool getDataByIndex(al::ByamlData *dest, s32 index) const;
        bool getDataByKey(al::ByamlData *dest, s32 key) const;
        al::ByamlHashPair* findPair(s32 key) const;
        al::ByamlHashPair* getPairByIndex(s32 index) const;
        u64 getOffsetData(s32 baseOffset) const;

        u8* mSrcByaml; // _0
        u32 mEndianess; // _8
    };
};