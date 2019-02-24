/**
 * @file Shine.h
 * @brief Class for the Shine actor.
 */

#pragma once

#include "al/LiveActor.h"
#include "al/camera/CameraTicket.h"
#include "al/param/RateParam.h"
#include "sead/quat.h"
#include "sead/vector.h"
#include "ShineInfo.h"

class Shine : public al::LiveActor
{
public:
    Shine(char const *name);

    al::LiveActor* getCurrentModel();
    void tryExpandShadowAndClipping();
    void initAppearDemo(al::ActorInitInfo const &);

    void showCurrentModel();
    void hideAllModel();
    void invalidateKillSensor();
    void getDirect();
    void setGrandShine();
    void setShopShine();

    u64 _108;
    u64* _110; // al::MtxConnector*
    f32 mConnectLength; // _118
    bool mEmptyShineForDemoGetGrand; // _11C
    u8 _11D;
    u16 _11E;
    ShineInfo* mShineInfo; // _120
    sead::Vector3<f32> _128; // some sort of reset position
    sead::Quat<f32> _134;
    u32 _144;
    al::CameraTicket* mCameraTicket; // _148
    sead::Vector3<f32> _150;
    sead::Vector3<f32> _15C;
    u16 _168;
    bool mIsPlayAppearCameraOnlyOnce; // _16A
    u8 _16B;
    sead::Vector3<f32> mShineMovePoint; // _16C
    u8 _178[0x188-0x178];
    al::RateParamF32* mRateParam; // _188
    u64* _190; // ParabolicPathMovement*
    u64* _198; // ParabolicPath*
    u32 mShineMode; // _1A0
    u32 _1A4; // possible padding
    u64* _1A8; // KeyMoveMovement*
    u64 _1B0;
    u64* _1B8; // ChangeStageInfo*
    u8 _1C0[0x260-0x1C0];
    sead::Vector3<f32> mDisplayOffset; // _260
    bool mIsUseAppear; // _26C
    u8 _26D;
    u16 _26E;
    u64* _270; // al::CameraTicket*
    u64* _278; // QuestInfo*
    bool mIsUseAppearDemoAfterGet; // _280
    u8 _281[0x288-0x281];
    u64* _288; // ActorDimensionKeeper *
    s32 mShineIndex; // _290
    u32 _294;
    sead::Quat<f32> _298;
    u32 _2A4;
    bool mIsShopShine; // _2A8
    u8 _2A9;
    bool mIsConnectSide; // _2AA
    bool mIsAppearCamera; // _2AB
    u32 _2AC;
    al::LiveActor* _2B0;
    u8 _2B8[0x2D4-0x2B8];
    bool mIsAddHeight; // _2D4
    u8 _2D5[0x2E0-0x2D5];
    al::LiveActor* _2E0; // "Shine [Sky Model]"
    al::LiveActor* _2E8; // "Shine [model]"
    u64 _2F0;
    u32 _2F8;
    bool mIsNoRotate; // _2FC
    u8 _2FD;
    u16 _2FE;
    u64* _300; // al::CameraTicket*
    bool mIsUseGetDemoCamera; // _308
    u8 _309;
    u8 _30A;
    u8 _30B;
    u32 _30C;
    u64* _310; // WaterSurfaceShadow*
    u64* _318; // FukankunZoomCapMessage*
    f32 mShadowLength; // _320
    f32 mShadowMaskDropLengthMax; // _324
    u64 _328;
    u64* _330; // ActorCameraTarget*
    bool mIsCheckGroundHeightMoon; // _338
    u8 _339[0x350-0x339];
    char* mShineOptionalId; // _350
    bool mIsUseAppearDemoForce; // _358
    u8 _359;
    u16 _35A;
    u32 _35C;
    u64* _360; // whatever al::registDemoRequesterToAddDemoInfo returns
    u32 _368;
    u8 _36C;
    bool mIsAppearDemoHeightHigh; // _36D
    u16 _36E;
    al::RateParamF32* _370;
};
