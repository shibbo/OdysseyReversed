#pragma once

#include "types.h"
#include "ActorSceneInfo.h"
#include "byaml/ByamlIter.h"

namespace al
{
    class ActorInitInfo
    {
    public:
        ActorInitInfo();

        u64 _0;
        al::ByamlIter* mActorContainer; // _8
        u64 _10;
        al::ActorSceneInfo mSceneInfo; // _18
    };
};