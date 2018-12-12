#pragma once

#include "types.h"
#include "ActorSceneInfo.h"

namespace al
{
    class ActorInitInfo
    {
        public:
        ActorInitInfo();

        u64 _0;
        u64 _8;
        u64 _10;
        al::ActorSceneInfo mSceneInfo; // _18
    };
};