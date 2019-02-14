/**
 * @file Nerve.h
 * @brief Implementation for a nerve.
 */

#pragma once

namespace al
{
    class LiveActor;
    class NerveKeeper;

    class Nerve
    {
    public:
        virtual void execute(al::LiveActor *) = 0;
        virtual void executeOnEnd(al::NerveKeeper *keeper) const;
    };
};