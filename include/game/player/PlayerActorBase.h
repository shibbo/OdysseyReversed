/**
 * @file PlayerActorBase.h
 * @brief Base class for all playable actors.
 */

#pragma once

#include "al/LiveActor.h"
#include "PlayerActorBase.h"

class PlayerActorBase : public al::LiveActor
{
pubic:
    PlayerActorBase(char const *);

    virtual void init(al::ActorInitInfo const &);

    virtual void movement();

    virtual void initPlayer(al::ActorInitInfo const &, PlayerInitInfo const &);
    virtual s32 getPortNo() const;
    virtual u64* getViewMtx() const;
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

    u64* _108; // IUsePlayerHack*
    u64* mViewMtx; // _110
    s32 mPortNo; // _118
    u32 _11C;

};