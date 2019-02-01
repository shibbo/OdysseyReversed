/**
 * @file NerveExecutor.h
 * @brief Executor for a specific nerve in an actor.
 */

#pragma once

#include "../keeper/NerveKeeper.h"

namespace al
{
    class NerveExecutor
    {
    public:
        NerveExecutor(char const *);

        virtual al::NerveKeeper* getNerveKeeper() const;
        virtual ~NerveExecutor();

        void initNerve(al::Nerve const *, s32);
        void updateNerve();

        al::NerveKeeper* mNerveKeeper; // _8
    };
};