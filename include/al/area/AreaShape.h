#pragma once

#include "sead/bound.h"
#include "sead/matrix.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class AreaShape
    {
    public:
        AreaShape();

        virtual bool isInVolume(sead::Vector3<f32> const &) const = 0;
        virtual bool isInVolumeOffset(sead::Vector3<f32> const &, f32) const = 0;
        virtual void calcNearestEdgePoint(sead::Vector3<f32> *, sead::Vector3<f32> const &) const = 0;
        virtual bool checkArrowCollision(sead::Vector3<f32> *, sead::Vector3<f32> *, sead::Vector3<f32> const &, sead::Vector3<f32> const &) const = 0;
        virtual s32 calcLocalBoundingBox(sead::BoundBox3<f32> *) const = 0;

        void setBaseMtxPtr(sead::Matrix34<f32> const *);
        void setScale(sead::Vector3<f32> const &);
        void calcLocalPos(sead::Vector3<f32> *out, sead::Vector3<f32> const &) const;
        void calcWorldPos(sead::Vector3<f32> *out, sead::Vector3<f32> const &) const;
        void calcWorldDir(sead::Vector3<f32> *out, sead::Vector3<f32> const &) const;
        void calcTrans(sead::Vector3<f32> *) const;

        sead::Matrix34<f32>* mBaseMtx; // _8
        sead::Vector3<f32> mScale; // _10
    };
};