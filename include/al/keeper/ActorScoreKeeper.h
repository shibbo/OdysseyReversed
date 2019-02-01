/**
 * @file ActorScoreKeeper.h
 * @brief Storage class for a score, defined from a BYAML.
 */

#pragma once

#include "types.h"

namespace al
{
    class ByamlIter;

    class ActorScoreKeeper
    {
    public:
        ActorScoreKeeper();

        void init(al::ByamlIter const &);
        char* getCategoryName() const;
        char* tryGetCategoryName(char const *) const;

        u64* _0;
        u32 mByamlSize; // _8
    };
};