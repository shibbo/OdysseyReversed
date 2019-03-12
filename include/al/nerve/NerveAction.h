/**
 * @file NerveAction.h
 * @brief Storage for a nerve action in an actor.
 */

#pragma once

#include "types.h"

namespace al
{
    class NerveAction
    {
    public:
        NerveAction();

        u64 _8;
    };
};

class alNerveFunction
{
public:
    class NerveActionCollector
    {
    public:
        NerveActionCollector();

        void addNerve(al::NerveAction *);

        s32 mNumActions; // _0
        u32 _4;
        al::NerveAction* mActions; // _8
        al::NerveAction* _10;
    };
};