/**
 * @file EffectKeeper.h
 * @brief Keeper for effects on actors.
 */

#pragma once

#include "types.h"
#include "sead/color.h"
#include "sead/matrix.h"
#include "sead/vector.h"

namespace al
{
    class EffectSystemInfo;

    class EffectKeeper
    {
    public:
        EffectKeeper(al::EffectSystemInfo *, char const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Matrix34<f32> const *);
    
        void update();
        void tryUpdateMaterial(char const *);
        void emitEffectCurrentPos(char const *);
        u64* findEffect(char const *);
        void emitEffect(char const *, sead::Vector3<f32> const *);
        bool tryEmitEffect(char const *, sead::Vector3<f32> const *);
        void deleteEffect(char const *);
        void tryDeleteEffect(char const *);
        void tryKillEmitterAndParticleAll();
        void deleteEffectAll();
        void deleteAndClearEffectAll();
        void onCalcAndDraw();
        void offCalcAndDraw();
        void forceSetStopCalcAndDraw(bool);
        void setEmitRatio(char const *, f32);
        void setEmitterAllScale(char const *, sead::Vector3<f32> const &);
        void setEmitterVolumeScale(char const *, sead::Vector3<f32> const &);
        void setParticleScale(char const *, f32);
        void setParticleScale(char const *, sead::Vector3<f32> const &);
        void setParticleAlpha(char const *, f32);
        void setParticleColor(char const*, sead::Color4f const &);
        void setParticleLifeScale(char const *, f32);
        u64* findMtxPtr(char const *);
        u64* tryFindEffect(char const *) const;

        char* mEffectName; // _0
        u64 mNumEffects; // _8
        u64* _10; // array of al::Effect*
        u64 _18;
        u8 _20; // unknown if used
        u8 _21;
        u8 _22; // ^^
        u8 _23; // ^^
        u8 _24;
        u8 _25; // ^^
        u8 _26; // ^^
        u8 _27; // ^^
        u64* _28;
        u64* _30; // al::MtxPtrHolder*
    };
};