/**
 * @file IUseEffectKeeper.h
 * @brief Basic implementation of an effect keeper.
 */

#pragma once

namespace al
{
    class EffectKeeper;

    class IUseEffectKeeper
    {
    public:
        virtual al::EffectKeeper* getEffectKeeper() const = 0;
    };
};
