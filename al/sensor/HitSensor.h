#pragma once

#include "types.h"
#include "sead/matrix.h"
#include "sead/vector.h"

namespace al
{
    class LiveActor;

    class HitSensor
    {
        public:
        HitSensor(al::LiveActor *, char const *, u32, f32, u16, sead::Vector3<f32> const *, sead::Matrix34<f32> const *, sead::Vector3<f32> const &);

        void trySensortSort();
        void setFollowPosPtr(sead::Vector3<f32> const *);
        void setFollowMtxPtr(sead::Matrix34<f32> const *);
        void validate();
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();
        void update();
        void addHitSensor(al::HitSensor *);

        u64 _0;
        u64 _8;
        u64 _10;
        u32 _18;
        u16 _1C;
        u16 _1E;
        u64 _20;
        u64 _28;
        u64* _30; // al::SensorHitGroup*
        u8 _38;
        u8 _39;
        u8 _3A;
        u8 _3B;
        u8 _3C[0x50-0x3C];
        sead::Vector3<f32>* mFollowPos; // _50
        sead::Matrix34<f32>* mFollowPosMtx; // _58
        u64 _60;
    };
};