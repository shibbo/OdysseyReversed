/**
 * @file Effect.h
 * @brief Basic effects.
 */

#pragma once

#include "types.h"
#include "sead/matrix.h"
#include "sead/vector.h"

namespace al
{
    class EffectSystemInfo;
    class EffectInfo;

    class Effect
    {
    public:
        Effect(al::EffectSystemInfo const *, al::EffectInfo const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Matrix34<f32> const *, u64);
    
        void setPosPtr(sead::Vector3<f32> const *);
        void setMtxPtr(sead::Matrix34<f32> const *);
        void update();

        u64 _0;
        u64* _8; // array of al::EffectEmitter*
        u64 mNumEmitters; // _10
        u64 _18;
        u64* _20;
        sead::Vector3<f32>* mPosition; // _28
        u64 _30;
        u64 _38;
        u64 _40;
        u64 _48;
        u64* _50; // al::EffectCameraHolder*
        u64 _58;
        f64 _60;
        f64 _68;
        f64 _70;
        f64 _78;
        f64 _80;
        f64 _88;
        f64 _90;
        f64 _98;
        f64 _A0;
        f64 _A8;
        f64 _B0;
        f64 _B8;
        f64 _C0;
        f64 _C8;
        f64 _D0;
        f64 _D8;
        f64 _E0;
        f64 _E8;
        f64 _F0;
        f64 _F8;
        f64 _100;
        f64 _108;
        f64 _110;
        f64 _118;
        f64 _120;
    };
};