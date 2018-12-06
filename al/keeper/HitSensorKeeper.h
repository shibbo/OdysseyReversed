#pragma once

#include "types.h"
#include "sead/matrix.h"
#include "sead/vector.h"

namespace al
{
    class LiveActor;

    class HitSensorKeeper
    {
        public:
        HitSensorKeeper(s32 numSensors);

        void* addSensor(al::LiveActor *, char const *, u32, f32, u16, sead::Vector3<f32> const *, sead::Matrix34<f32> const *,sead::Vector3<f32> const &);
        void update();
        u32 getSensorNum() const;
        u64* getSensor(s32 sensorID) const; // al::HitSensor*
        void attackSensor();
        void clear();
        void validate();
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();
        u64* getSystem(char const *) const; // al::HitSensor*

        u32 mNumSensors; // _4
        u64* _8; // al::HitSensor* array
    };
};