#pragma once

#include "types.h"

namespace al
{
    class ByamlIter
    {
        public:
        ByamlIter();
        ByamlIter(u8 const *srcByaml);
        ByamlIter(u8 const *srcByamlHeader, u8 const *srcByamlData);

        bool isValid() const;
        bool isTypeHash() const;
        bool isTypeArray() const;
        bool isTypeContainer() const;
        bool isExistKey(char const *key) const;
        s32 getKeyIndex(char const *key) const;
        bool isInvertOrder() const;
        u32 getSize() const;
        al::ByamlIter* getIterByIndex(s32 index) const;

        u8* mSrcByamlHeader; // _0
        u8* mSrcByamlData; // _8
    };
};