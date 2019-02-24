/**
 * @file HitSensor.h
 * @brief Sensor for collisions.
 */

#pragma once

#include "types.h"
#include "sead/matrix.h"
#include "sead/vector.h"

enum SensorType : s32
{
    SENSOR_TYPE_EYE             = 0,
    SENSOR_TYPE_1               = 1,
    SENSOR_TYPE_ATTACK          = 2,
    SENSOR_TYPE_3               = 3,
    SENSOR_TYPE_4               = 4,
    SENSOR_TYPE_5               = 5,
    SENSOR_TYPE_NPC             = 6,
    SENSOR_TYPE_RIDE            = 7,
    SENSOR_TYPE_8               = 8,
    SENSOR_TYPE_ENEMY_BODY      = 9,
    SENSOR_TYPE_ENEMY_ATTACK    = 10,
    SENSOR_TYPE_11              = 11,
    SENSOR_TYPE_MAPOBJ          = 12
};

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

        char* mSensorName; // _0
        SensorType mSensorType; // _8
        sead::Vector3<f32> mPosition; // _C
        s32 mRadius; // _18
        u16 _1C;
        u16 _1E;
        u64 _20;
        u64 _28;
        u64* _30; // al::SensorHitGroup*
        u8 _38;
        u8 _39;
        u8 _3A;
        u8 _3B;
        u32 _3C;
        al::LiveActor* mActor; // _40
        u64 _48;
        sead::Vector3<f32>* mFollowPos; // _50
        sead::Matrix34<f32>* mFollowPosMtx; // _58
        u64 _60;
    };
};