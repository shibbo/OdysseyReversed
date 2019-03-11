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
