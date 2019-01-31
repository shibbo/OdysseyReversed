/**
 * @file PlacementInfo.h
 * @brief Storage container for a stage and zone iterator for a stage.
 */

#pragma once

#include "types.h"
#include "al/byaml/ByamlIter.h"

namespace al
{
    class PlacementInfo : public al::ByamlIter
    {
    public:
        PlacementInfo();

        void set(al::ByamlIter const &, al::ByamlIter const &);

        al::ByamlIter mStageIterator; // _0
        al::ByamlIter mZoneIterator; // _10
    };
};