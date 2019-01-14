#pragma once

#include "matrix.h"
#include "runtime.h"
#include "vector.h"

namespace sead
{
    class Camera
    {
    public:
        virtual ~Camera();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual void doUpdateMatrix(sead::Matrix34<f32> *) = 0;

        void getWorldPosByMatrix(sead::Vector3<f32> *) const;
        void getLookVectorByMatrix(sead::Vector3<f32> *) const;
        void getRightVectorByMatrix(sead::Vector3<f32> *) const;
        void getUpVectorByMatrix(sead::Vector3<f32> *) const;
        void worldPosToCameraPosByMatrix(sead::Vector3<f32> *, sead::Vector3<f32> const &) const;

        f32 _8;
        f32 _C;
        f32 _10;
        f32 _14;
        f32 _18;
        f32 _1C;
        f32 _20;
        f32 _24;
        f32 _28;
        f32 _2C;
        f32 _30;
        f32 _34;
    };
};