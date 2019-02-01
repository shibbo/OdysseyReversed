/**
 * @file tick.h
 * @brief System tick wrapper functions.
 */

#pragma once

#include "types.h"

namespace sead
{
    class TickSpan
    {
    public:
        s64 toNanoSeconds() const;
        void setNanoSeconds(s64 seconds);

        s64 mSeconds; // _0

        static s64 cFrequency;
    };
};