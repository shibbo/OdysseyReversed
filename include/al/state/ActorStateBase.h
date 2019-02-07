/**
 * @file ActorStateBase.h
 * @brief Base for actor states.
 */

#pragma once

#include "al/LiveActor.h"
#include "al/nerve/NerveStateBase.h"

namespace al
{
    class ActorStateBase : public al::NerveStateBase
    {
    public:
        ActorStateBase(char const *, al::LiveActor *);

        virtual ~ActorStateBase();

        al::LiveActor* mActor; // _18
    };
};