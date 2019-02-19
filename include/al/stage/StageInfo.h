/**
 * @file StageInfo.h
 * @brief Container for a stage, which stores zone and placement information.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "al/PlacementInfo.h"
#include "al/resource.h"
#include "types.h"

namespace al
{
    class StageInfo
    {
    public:
        StageInfo(al::Resource *, al::ByamlIter const &, al::ByamlIter const &);

        al::PlacementInfo* getPlacementIter() const;
        al::ByamlIter getZoneIter() const;

        al::Resource* mResource; // _0
        al::PlacementInfo* mPlacementInfo; // _8
    };
};