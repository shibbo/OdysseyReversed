#pragma once

#include "types.h"

namespace al
{
    class ActorItemInfo
    {
    public:
        ActorItemInfo(char const *, char const *, char const *, s32);

        bool isEqualTiming(char const *) const;
        bool isEqualFactor(char const *) const;

        char* _0;
        char* mTiming; // _8
        char* mFactor; // _10
        s32 _18;
        s32 _1C;
    };
};