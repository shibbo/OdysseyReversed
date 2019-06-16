/**
 * @file LiveActor.h
 * @brief Base class for all used actors in the game.
 */

#pragma once

#include "collision/Collider.h"
#include "keeper/ActorActionKeeper.h"
#include "keeper/ActorItemKeeper.h"
#include "keeper/ActorPoseKeeperBase.h"
#include "keeper/ActorScoreKeeper.h"
#include "keeper/AudioKeeper.h"
#include "keeper/EffectKeeper.h"
#include "keeper/HitSensorKeeper.h"
#include "keeper/ModelKeeper.h"
#include "keeper/NerveKeeper.h"
#include "keeper/ScreenPointKeeper.h"
#include "keeper/ShadowKeeper.h"
#include "keeper/StageSwitchKeeper.h"
#include "keeper/SubActorKeeper.h"
#include "iuse/IUseAreaObj.h"
#include "iuse/IUseAudioKeeper.h"
#include "iuse/IUseCamera.h"
#include "iuse/IUseEffectKeeper.h"
#include "iuse/IUseName.h"
#include "iuse/IUseNerve.h"
#include "iuse/IUseSceneObjHolder.h"
#include "sead/matrix.h"
#include "ActorExecuteInfo.h"
#include "ActorSceneInfo.h"
#include "types.h"

namespace al
{
	class ActorParamHolder;
    class ScreenPointer;
    class ScreenPointTarget;
	class SensorMsg;

	class LiveActorFlag
    {
    public:
        LiveActorFlag();

        bool isAlive; // _0
        u8 _1;
        u8 _2;
        u8 _3;
        bool isOffCalcAnim; // _4
        u8 _5;
        bool isNoCollide; // _6
        u8 _7;
        bool isValidMaterialCode; // _8
        bool isValidPuddleMaterial; // _9
        bool isAreaTarget; // _A
        bool isUpdateEffectAudioCollisionSensor; // _B
    };
	
    class LiveActor : public al::IUseNerve
    {
    public:
        LiveActor(char const *objName);

        virtual al::NerveKeeper* getNerveKeeper() const;
        virtual void init(al::ActorInitInfo const &);
        virtual void initAfterPlacement();
        virtual void appear();
        virtual void makeActorAlive();
        virtual void kill();
        virtual void makeActorDead();
        virtual void movement();
        virtual void calcAnim();
        virtual void draw();
        virtual void startClipped();
        virtual void endClipped();
        virtual void attackSensor(al::HitSensor *,al::HitSensor *);
        virtual bool receiveMsg(al::SensorMsg const *, al::HitSensor *, al::HitSensor *);
        virtual bool receiveMsgScreenPoint(al::SensorMsg const*,al::ScreenPointer *,al::ScreenPointTarget *);
        virtual char* getName() const;
        virtual sead::Matrix34<f32>* getBaseMtx() const;
        virtual al::EffectKeeper* getEffectKeeper() const;
        virtual al::AudioKeeper* getAudioKeeper() const;
        virtual al::StageSwitchKeeper* getStageSwitchKeeper() const;
        virtual u64* getRailRider() const;
        virtual u64* getSceneObjHolder() const;
        virtual u64* getCollisionDirector() const;
        virtual u64* getAreaObjDirector() const;
        virtual u64* getCameraDirector() const;
        virtual void initStageSwitchKeeper();
        virtual void control();
        virtual void updateCollider();

        al::IUseEffectKeeper* mUseEffectKeeper; // _8
        al::IUseAudioKeeper* mUseAudioKeeper; // _10
        al::IUseName* mUseName; // _18
        al::IUseSceneObjHolder* mUseSceneObjHolder; // _20
        al::IUseAreaObj* mUseAreaObj; // _28
        al::IUseCamera* mUseCamera; // _30
        u64* _38; // al::IUseCollision*
        u64* _40; // al::IUseRail*
        char* mName; // _48
        al::ActorPoseKeeperBase* mPoseKeeper; // _50
        al::ActorExecuteInfo* mExecInfo; // _58
        al::ActorActionKeeper* mActionKeeper; // _60
        al::ActorItemKeeper* mItemKeeper; // _68
        al::ActorScoreKeeper* mScoreKeeper; // _70
        al::Collider* mCollider; // _78
        u64* _80; // al::CollisionParts*
        al::ModelKeeper* mModelKeeper; // _88
        al::NerveKeeper* mNerveKeeper; // _90
        al::HitSensorKeeper* mHitSensorKeeper; // _98
        al::ScreenPointKeeper* mScreenPointKeeper; // _A0
        al::EffectKeeper* mEffectKeeper; // _A8
        al::AudioKeeper* mAudioKeeper; // _B0
        u64* _B8; // al::HitReactionKeeper*
        al::StageSwitchKeeper* mStageSwitchKeeper; // _C0
        u64* _C8; // al::RailRider*
        al::ShadowKeeper* mShadowKeeper; // _D0
        u64* _D8; // al::ActorPrePassLightKeeper*
        u64* _E0; // al::ActorOcclusionKeeper*
        al::SubActorKeeper* mSubActorKeeper; // _E8
        al::ActorParamHolder* mParamHolder; // _F0
        al::ActorSceneInfo* mActorSceneInfo; // _F8
        al::LiveActorFlag* mActorFlags; // _100
    };

    class LiveActorGroup
    {
    public:
        LiveActorGroup(char const *groupName, s32 numActors);

        virtual void registerActor(al::LiveActor *actor);

        void removeActor(al::LiveActor const *actor);
        void removeActorAll();
        bool isExistActor(al::LiveActor const *actor) const;
        bool isFull() const;
        u32 calcAliveActorNum() const;
        al::LiveActor* getDeadActor() const;
        al::LiveActor* tryFindDeadActor() const;
        void appearAll();
        void killAll();
        void makeActorAliveAll();
        void makeActorDeadAll();

        char* mGroupName; // _8
        s32 mActorCount; // _10
        u32 mMaxSize; // _14
        al::LiveActor* mActors; // _18
    };

    template<typename T>
    al::LiveActor* createActorFunction(char const *actorName);

    template<typename T>
    T* createAreaObjFunction(char const *areaName);

    template<typename T>
    T* createCameraPoserFunction(char const *poserName);

    template<typename T>
    T* createEventFlowNode(char const *eventFlowName);
};

template<typename T>
T* createPlayerFunction(char const *name);