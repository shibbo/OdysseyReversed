/**
 * @file StageSwitchKeeper.cpp
 * @brief Keeper for stage switches.
 */

#include "al/keeper/StageSwitchKeeper.h"
#include "macros.h"

namespace al
{
    StageSwitchKeeper::StageSwitchKeeper()
    {
        this->_0 = 0;
        this->mLinkCount = 0;
        this->_10 = 0;
    }

    void StageSwitchKeeper::init(al::StageSwitchDirector *director, al::PlacementInfo const &info)
    {
        s32 linkCount = al::calcLinkCountClassName(info, "StageSwitch");
        s32 size;
        void* rawList;
        StageSwitchAccesser* list;

        if (is_mul_ok(linkCount, 0x28))
        {
            size = 0x28 * linkCount;
        }
        else
        {
            size = 1;
        }

        this->mLinkCount = linkCount;
        rawList = new StageSwitchAccesser[linkCount];

        if (linkCount)
        {
            u32 v12 = 0x28 * linkCount;
            do
            {
                rawList = new StageSwitchAccesser();
                rawList = &rawList + 0x28;
                v12 -= 0x28;
            }
            while(v12);
        }

        this->_0 = (StageSwitchAccesser*)rawList;

        PlacementInfo linksInfo;
        al::tryGetPlacementInfoByKey(&linksInfo, info, "Links");
        s32 count = al::getCountPlacementInfo(linksInfo);

        if (count >= 1)
        {
            u32 curCount = 0;
            u32 v17 = 0;

            do
            {
                PlacementInfo curInfo;
                char* v22;
                al::tryGetPlacementInfoAndKeyNameByIndex(&curInfo, &v22, linksInfo, curCount);

                PlacementInfo v19;
                al::tryGetPlacementInfoByIndex(&v19, curInfo, 0);

                if (al::isClassName(v19, "StageSwitch") & 0x1)
                {
                    PlacementId v18;
                    al::tryGetPlacementId(&v18, v19);
                    *(&this->_0 + 0x28LL * v17 + 8) = (StageSwitchAccesser*)this->_10;
                    (this->_0 + 0x28LL * v17++)->init(director, v22, v18);
                }
                ++curCount;
            } 
            while (count != curCount);
        }
    }

    StageSwitchAccesser* StageSwitchKeeper::tryGetStageSwitchAccesser(char const *stage) const
    {
        if (this->mLinkCount < 1)
        {
            return 0;
        }

        s32 curPos = 0;
        s32 curIndex = 0;

        // check each stage switch name to see if it matches the one we are looking for
        while ((!al::isEqualString(stage, *((char**)this->_0 + curPos + 0x10)) & 0x1))
        {
            ++curIndex;
            curPos += 0x28;

            if (curIndex >= this->mLinkCount)
            {
                return 0;
            }
        }

        return this->_0 + curPos;
    }
};