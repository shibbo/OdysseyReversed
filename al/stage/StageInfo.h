#pragma once

#include "byaml/ByamlIter.h"
#include "PlacementInfo.h"
#include "resource.h"
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