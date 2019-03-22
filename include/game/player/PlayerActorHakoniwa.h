/**
 * @file PlayerActorHakoniwa.h
 * @brief Class for the main player.
 */

#pragma once

#include "al/sensor/HitSensor.h"
#include "PlayerActorBase.h"
#include "PlayerConst.h"
#include "PlayerOxygen.h'"

class PlayerActorHakoniwa : public PlayerActorBase
{
public:
    PlayerActorHakoniwa(char const *);

    virtual void initAfterPlacement();
    virtual void movement();
    virtual void attackSensor(al::HitSensor *,al::HitSensor *);
    virtual bool receiveMsg(al::SensorMsg const *, al::HitSensor *, al::HitSensor *);

    virtual void control();
    virtual void updateCollider();
    virtual void initPlayer(al::ActorInitInfo const &, PlayerInitInfo const &);
    virtual s32 getPortNo() const;

    virtual u64* getPlayerCollision() const;
    virtual u64* getPlayerHackKeeper() const;
    virtual bool isEnableDemo();
    virtual void startDemo();
    virtual void endDemo();
    virtual void startDemoPuppetable();
    virtual void endDemoPuppetable();
    virtual void startDemoShineGet();
    virtual void endDemoShineGet();
    virtual void startDemoMainShineGet();
    virtual void endDemoMainShineGet();
    virtual void startDemoHack();
    virtual void endDemoHack();PlayerInitInfo
    virtual void startDemoKeepBind();
    virtual void noticeDemoKeepBindExecute();
    virtual void endDemoKeepBind();
    virtual void startDemoKeepCarry();
    virtual void endDemoKeepCarry();
    virtual u64* getDemoActor();
    virtual u64* getDemoAnimator();
    virtual bool isDamageStopDemo() const;
    virtual u64* getPlayerPuppet();
    virtual PlayerInitInfo* getPlayerInfo() const;
    virtual bool checkDeathArea();
    virtual void sendCollisionMsg();
    virtual bool recievePushmsg(al::SensorMsg const *, al::HitSensor *, al::HitSensor *, f32);
    virtual u64* getActorDimensionKeeper() const;

    u64* _120;
    u64 _128;
    PlayerConst* mPlayerConst; // _130
    u64* _138; // PlayerInput*
    u64* _140; // PlayerTrigger*
    u64* _148; // HackCap*
    u64* _150; // ActorDimensionKeeper*
    u64* _158; // unknown
    u64* _160; // PlayerModelChangerHakoniwa*
    u64* _168; // PlayerAnimator*
    u64* _170; // PlayerColliderHakoniwa* (inherits IUsePlayerCollision)
    u64* _178; // PlayerStateHipDrop*
    u64* _180; // PlayerAreaChecker*
    u64* _188; // unknown
    PlayerOxygen* mPlayerOxygen; // _190
    u64* _198; // unknown
    u64* _1A0; // unknown
    u64* _1A8; // PlayerCapActionHistory*
    u64* _1B0; // PlayerCapManHeroEyesControl*
    u64* _1B8; // PlayerContinuousJump*
    u64* _1C0; // unknown
    u64* _1C8; // PlayerCounterAfterUpperPunch*
    u64* _1D0; // PlayerCounterForceRun*
    u64* _1D8; // PlayerCounterIceWater*
    u64* _1E0; // unknown
    u64* _1E8; // PlayerWallActionHistory*
    u64* _1F0; // PlayerBindKeeper*
    u64* _1F8; // PlayerCarryKeeper*
    u64* _200; // PlayerEquipmentUser*
    u64* _208; // PlayerHackKeeper*
    u64* _210; // PlayerFormSensorCollisionArranger*
    u64* _218; // PlayerJumpMessageRequest*
    u64* _220; // PlayerSandSinkAffect*
    u64* _228; // PlayerSpinCapAttack*
    u64* _230; // PlayerActionDiveInWater*
    u64* _238; // PlayerEffect*
    u64* _240; // PlayerEyeSensorHitHolder*
    u64* _248; // PlayerPushReceiver*
    u64* _250; // PlayerHitPush*
    u64* _258; // PlayerExternalVelocity*
    u64* _260; // PlayerStateSwim*
    u64* _268; // PlayerPainPartsKeeper*
    u64* _270; // PlayerRecoverySafetyPoint*
    u64* _278; // PlayerRippleGenerator*
    u64* _280; // unknown
    u64* _288; // PlayerWetControl*
    u64* _290; // PlayerStainControl*
    u64* _298; // unknown
    u64* _2A0; // GaugeAir*
    u64* _2A8; // unknown
    u64* _2B0; // WorldEndBorderKeeper*
    u64* _2B8; // al::ComboCounter*
    u64* _2C0; // PlayerSeCtrl*
    al::HitSensor* mColliderSensor; // _2C8
    u64* _2D0; // unknown
    u64* _2D8; // PlayerStateWait*
    u64* _2E0; // unknown
    u64* _2E8; // unknown
    u64* _2F0; // unknown
    u64* _2F8; // PlayerStateRolling*
    u64* _300; // unknown
    u64* _308; // PlayerStateJump*
    u64* _310; // unknown
    u64* _318; // unknown
    u64* _320; // PlayerStateWallCatch*
    u64* _328; // PlayerStateGrabCeil*
    u64* _330; // PlayerStatePoleClimb*
    u64* _338; // PlayerStateHipDrop*
    u64* _340; // unknown
    u64* _348; // unknown
    u64* _350; // PlayerStateFallHakoniwa*
    u64* _358; // PlayerStateSandSink*
    u64* _360; // ActorStateSandGeyser*
    u64* _368; // unknown
    u64* _370; // PlayerStateSwim*
    u64* _378; // PlayerStateDamageLife*
    u64* _380; // unknown
    u64* _388; // PlayerStateDamageFire*
    u64* _309; // unknown
    u64* _398; // PlayerStateBind*
    u64* _3A0; // PlayerStateHack*
    u64* _3A8; // unknown
    u64* _3B0; // unknown
    u64* _3B8; // PlayerStateAbyss*
    u64* _3C0; // unknown
    u64* _3C8; // PlayerJudgeCameraSubjective*
    u8 _3D0[0x4A0-0x3D0];
    u64* _4A0; // IJudge*
    u64* _4A8; // IJudge* (PlayerJudgePreInputCapThrow)
    u64* _4B0; // IJudge*
    u64* _4B8; // IJudge*
    u64* _4C0; // IJudge*
    u64* _4C8; // IJudge*
    u64* _4D0; // unknown
    u64* _4D8; // PlayerJudgeWallCatchInputDir*
    u64* _4E0; // unknown
    u64* _4E8; // unknown
    u64* _4F0; // unknown
    u64* _4F8; // unknown
    u64* _500; // unknown
};