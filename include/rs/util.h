/**
 * @file item.h
 * @brief Helper functions for identifying items.
 */

#pragma once

#include "al/ActorInitInfo.h"
#include "al/LiveActor.h"
#include "game/actor/shine/Shine.h"

class QuestInfo;

namespace rs
{
    // DEMO
    void addDemoActor(al::LiveActor *, bool);
    void requestStartDemoShineGrandGet(Shine *);
    bool requestStartDemoShineMainGet(Shine *);
    bool requestStartDemoShineDotGet(Shine *);
    bool requestStartDemoShineGet(Shine *);

    // ITEM
    s32 getItemType(al::ActorInitInfo const &);
    s32 getItemType(char const *);
    bool isItemTypeKuriboMini(s32 *, s32);
    void initItemByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &, bool);
    void tryInitItemByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &, bool);
    void initItem2DByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &);
    bool tryInitItem2DByPlacementInfo(al::LiveActor *, al::ActorInitInfo const &);
    bool tryInitItem(al::LiveActor *, s32, al::ActorInitInfo const &, bool);

    // PLAYER
    void recoveryPlayerOxygen(al::LiveActor const *);
    sead::Vector3<f32>* getPlayerPos(al::LiveActor const *);

    // QUEST
    void invalidateQuest(QuestInfo const *);

    // STAGE
    bool isInvalidChangeStage(al::LiveActor const *);
};