/**
 * @file ActorExecuteInfo.h
 * @brief Storage container for an actors' execution.
 */

#pragma once

#include "al/ActorInitInfo.h"
#include "al/execute.h"
#include "al/PlacementInfo.h"

namespace al
{
    class ActorExecuteInfo
    {
    public:
        ActorExecuteInfo(al::ExecuteRequestKeeper *);

        void initViewIdSelf(al::PlacementInfo const *, al::ActorInitInfo const &);
        void copyHostInfo(al::ActorInitInfo const &, al::PlacementInfo const *);
        void initViewIdHost(al::PlacementInfo const *, al::ActorInitInfo const &);
        void initViewIdHostActor(al::ActorInitInfo const &, al::LiveActor const *);
        void initNoViewId(al::PlacementInfo const *, al::ActorInitInfo const &);

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