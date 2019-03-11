/**
 * @file IUseNerve.h
 * @brief Basic implemetation for an actor using nerves.
 */

#pragma once

#include "al/keeper/NerveKeeper.h"

namespace al
{
    class IUseNerve
    {
    public:
        virtual al::NerveKeeper* getNerveKeeper() const = 0;
    };
};