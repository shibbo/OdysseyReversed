/**
 * @file TreasureBox.h
 * @brief Treasure box actor.
 */

#pragma once

#include "game/actor/shine/Shine.h"
#include "al/LiveActor.h"
#include "../item.h"

class TreasureBox : public al::LiveActor
{
public:
    TreasureBox(char const *);

    virtual void init(al::ActorInitInfo const &);
    virtual bool receivgeMsg(al::SensorMsg const *, al::HitSensor *, al::HitSensor *);
    virtual bool receiveMsgScreenPoint(al::SensorMsg const*,al::ScreenPointer *,al::ScreenPointTarget *);
    virtual void control();

    void changeOpenCollision();
    void setupOpenNerve();
    void exeWait();
    void exeTrampleReaction();
    void exeOpen();
    void exeBounce();
    void exeSenobiBounce();
    void exeOpenWait();
    void exeOpenTouchReaction();
    void exeOpenReaction();

    ItemType mItemType; // _108
    u32 _10C;
    Shine* mChildShine; // _110
    u64* mBoxClosedCollision; // al::CollisionObj* (_118)
    u64* mBoxOpenCollision; // al::CollisionObj* (_120)
    s32 mNumNutHitsLeft; // _128
    u32 _12C;
    u64* _138; // SaveObjInfo*
    bool mIsNut; // _140
    u32 _144;
    u32 _148;
    u32 _14C;
    u32 _150;
    bool mIsNearPlayer; // _154
};