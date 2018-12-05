#pragma once

#include "collision/Collider.h"
#include "keeper/ActorActionKeeper.h"
#include "keeper/ActorItemKeeper.h"
#include "keeper/ActorPoseKeeperBase.h"
#include "keeper/ActorScoreKeeper.h"
#include "keeper/AudioKeeper.h"
#include "keeper/EffectKeeper.h"
#include "keeper/StageSwitchKeeper.h"
#include "ActorExecuteInfo.h"
#include "ActorSceneInfo.h"
#include "types.h"

namespace al
{
    class LiveActor
    {
        public:
        LiveActor(char const *objName);

        u64* _8;  // IUseEffectKeeper*
        u64* _10; // IUseAudioKeeper*
        u64* _18;
        u64* _20; // IUseSceneObjHolder*
        u64* _28; // IUseAreaObj*
        u64* _30; // IUseCamera*
        u64* _38; // IUseCollision*
        u64* _40; // IUseRail*
        u64* _48;
        al::ActorPoseKeeperBase* mPoseKeeper; // _50
        al::ActorExecuteInfo* mExecInfo; // _58
        al::ActorActionKeeper* mActionKeeper; // _60
        al::ActorItemKeeper* mItemKeeper; // _68
        al::ActorScoreKeeper* mScoreKeeper; // _70
        al::Collider* mCollider; // _78
        u64* _80; // unknown
        u64* _88; // ModelKeeper*
        u64* _90; // NerveKeeper*
        u64* _98; // HitSensorKeeper*
        u64* _A0; // ScreenPointKeeper*
        al::EffectKeeper* mEffectKeeper; // _A8
        al::AudioKeeper* mAudioKeeper; // _B0
        u64* _B8; // unknown
        al::StageSwitchKeeper* mStageSwitchKeeper; // _C0
        u64* _C8; // RailRider*
        u64* _D0; // ShadowKeeper*
        u64* _D8; // ActorPrePassLightKeeper*
        u64* _E0; // ActorOcclusionKeeper*
        u64* _E8; // SubActorKeeper*
        u64* _F0; // unknown
        ActorSceneInfo* mActorSceneInfo; // _F8
        LiveActorFlag mActorFlags; // _100
    };

    class LiveActorFlag
    {
        public:
        LiveActorFlag();

        u64 _0;
        u32 _8;
    };
};