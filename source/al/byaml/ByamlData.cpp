/**
 * @file ByamlData.cpp
 * @brief Storage container for raw BYAML data.
 */

#include "al/byaml/ByamlData.h"

namespace al
{
    ByamlData::ByamlData()
    {
        this->mValue = 0;
        this->mType = 0;
    }

    void ByamlData::set(ByamlHashPair const *hashPair, bool swap)
    {
        this->mType = hashPair->mType;
        s32 hashPairVal = hashPair->mVal;
        s32 valReversed = (hashPairVal << 24) | ((hashPairVal << 8) & 0xFF0000) | ((hashPairVal >> 24) & 0xFF) | ((hashPairVal >> 8) & 0xFF00);

        if (swap)
        {
            hashPairVal = valReversed;
        }

        this->mValue = hashPairVal;
    }

    void ByamlData::set(u8 type, u32 val, bool swap)
    {
        s32 swapVal = (val << 24) | ((val << 8) & 0xFF0000) | ((val >> 24) & 0xFF) | ((val >> 8) & 0xFF00);
        
        if (!swap)
        {
            swapVal = val;
        }
  
        this->mType = type;
        this->mValue = swapVal;
    }

    u8 ByamlData::getType() const
    {
        return this->mType;
    }

    u32 ByamlData::getValue() const
    {
        return this->mValue;
    }
};