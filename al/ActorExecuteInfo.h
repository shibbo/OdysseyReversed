#pragma once

#include "al/execute.h"

namespace al
{
    class ActorExecuteInfo
    {
    public:
        ActorExecuteInfo(al::ExecuteRequestKeeper *);

        al::ExecuteRequestKeeper* mReqKeeper; // _0
        u32 _8;
        u32 _C;
        u64 _10;
        u64 _18;
        u64 _20;
        u64 _28;
        u32 _30;
        u32 _34;
        u8 _38[0x90-0x38];
    };
};