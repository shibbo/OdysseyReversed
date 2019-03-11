#pragma once

#include "LiveActor.h"
#include "resource.h"

namespace al
{
    class ActorParamHolder
    {
    public:
        ActorParamHolder(al::LiveActor *, al::Resource const *, char const *);
        
        static al::ActorParamHolder* tryCreate(al::LiveActor *, al::Resource const *, char const *);

        s32* findParamS32(char const *param);
        u64* tryFindParamInfoByName(char const *param) const;
        f32* findParamF32(char const *param) const;
        u64* findParamMove(char const *) const;
        u64* findParamJump(char const *) const;
        u64* findParamSight(char const *) const;
        u64* findParamRebound(char const *) const;

        u32 mParamSize; // _0
        u32 _4;
        char* mParams; // _8
    };
};