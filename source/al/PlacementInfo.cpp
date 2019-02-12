/**
 * @file PlacementInfo.cpp
 * @brief Storage container for a stage and zone iterator for a stage.
 */

#include "al/PlacementInfo.h"

namespace al
{
    PlacementInfo::PlacementInfo()
    {
        ByamlIter stageIter;
        ByamlIter zoneIter;
        this->mStageIterator = stageIter;
        this->mZoneIterator = zoneIter;
    }

    void PlacementInfo::set(ByamlIter const &stageIter, ByamlIter const &zoneIter)
    {
        this->mStageIterator = stageIter;
        this->mZoneIterator = zoneIter;
    }
};