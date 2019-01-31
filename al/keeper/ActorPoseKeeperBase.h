/**
 * @file ActorPoseKeeperBase.h
 * @brief Keeper for actor positions, rotation, gravity, velocity, and more.
 */

#pragma once

#include "types.h"
#include "sead/matrix.h"
#include "sead/quat.h"
#include "sead/vector.h"

namespace al
{
    class ActorPoseKeeperBase
    {
    public:
        ActorPoseKeeperBase();

        virtual sead::Vector3<f32>* getRotate() const;
        virtual sead::Vector3<f32>* getScale() const;
        virtual sead::Vector3<f32>* getVelocity() const;
        virtual sead::Vector3<f32>* getFront() const;
        virtual sead::Vector3<f32>* getUp() const;
        virtual sead::Quat<f32>* getQuat() const;
        virtual u64* getGravity() const;
        virtual sead::Matrix34<f32>* getMtx() const;
        virtual u64* getRotatePtr() const;
        virtual u64* getScalePtr() const;
        virtual u64* getVelocityPtr() const;
        virtual u64* getFrontPtr() const;
        virtual u64* getUpPtr() const;
        virtual u64* getQuatPtr() const;
        virtual u64* getGravityPtr() const;
        virtual u64* getMtxPtr() const;
        virtual void updatePoseTrans(sead::Vector3<f32> const &) = 0;
        virtual void updatePoseRotate(sead::Vector3<f32> const &) = 0;
        virtual void updatePoseQuat(sead::Quat<f32> const &) = 0;
        virtual void updatePoseMtx(sead::Matrix34<f32> const *) = 0;
        virtual void copyPose(al::ActorPoseKeeperBase const *keeper);
        virtual void calcBaseMtx(sead::Matrix34<f32> *) = 0;

        sead::Vector3<f32> mPosition; // _8

        static f64 sDefaultVelocity;
    };
};