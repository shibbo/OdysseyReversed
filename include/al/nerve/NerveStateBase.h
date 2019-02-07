/**
 * @file NerveStateBase.h
 * @brief Base class for a nerve state.
 */

#pragma once

#include "NerveExecutor.h"

namespace al
{
    class NerveStateBase : public al::NerveExecutor
    {
    public:
        NerveStateBase(char const *);

        virtual ~NerveStateBase();

        virtual void init();
        virtual void appear();
        virtual void kill();
        virtual void update();
        virtual void control();

        bool mIsInactive; // _10
        u8 reserved[0x18-0x11]; // padding
    };
};