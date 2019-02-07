/**
 * @file Nerve.h
 * @brief Implementation for a nerve.
 */

#pragma once

namespace al
{
    class NerveKeeper;

    class Nerve
    {
    public:
        // this function isn't virtual for a few reasons, it's never directly called
        // it is stored in tables that execute an actor's nerve
        void executeOnEnd(al::NerveKeeper *keeper) const;
    };
};