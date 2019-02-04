/**
 * @file ByamlData.cpp
 * @brief Storage container for raw BYAML data.
 */

#include "al/byaml/ByamlData.h"
#include "endianess.h"

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
        s32 valReversed = swap32(hashPairVal);

        if (swap)
        {
            hashPairVal = valReversed;
        }

        this->mValue = hashPairVal;
    }

    void ByamlData::set(u8 type, u32 val, bool swap)
    {
        s32 swapVal = swap32(val);
        
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