/**
 * @file item.h
 * @brief Helper functions for identifying items.
 */

#pragma once

#include "al/ActorInitInfo.h"
#include "al/LiveActor.h"

namespace rs
{
    s32 getItemType(al::ActorInitInfo const &);
    s32 getItemType(char const *);
    bool isItemTypeKuriboMini(s32 *, s32);
    void initItemByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &, bool);
    void tryInitItemByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &, bool);
    void initItem2DByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &);
    bool tryInitItem2DByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &);
    bool tryInitItem(al::LiveActor *, s32, al::ActorInitInfo const &, bool);
};