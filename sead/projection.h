#pragma once

#include "camera.h"
#include "matrix.h"
#include "ray.h"
#include "runtime.h"
#include "types.h"
#include "vector.h"
#include "viewport.h"

namespace sead
{
    class Graphics { public: enum DevicePosture; };

    class Projection
    {
    public:
        Projection();

        virtual ~Projection();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *) const;
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual f32 getNear() const = 0;
        virtual f32 getFar() const = 0;
        virtual f32 getFovy() const = 0;
        virtual f32 getAspect() const = 0;
        virtual void getOffset(sead::Vector2<f32> *) const = 0;
        virtual void updateAttributesForDirectProjection();
        virtual u32 getProjectionType() const = 0;
        virtual void doUpdateMatrix(sead::Matrix44<f32> *) const;
        virtual void doScreenPosToCameraPosTo(sead::Vector3<f32> *,sead::Vector3<f32> const &) const = 0;

        void project(sead::Vector2<f32> *, sead::Vector3<f32> const &, sead::Viewport const &) const;
        void unproject(sead::Vector3<f32> *, sead::Vector3<f32> const &, sead::Camera const &) const;
        void unprojectRay(sead::Ray<sead::Vector3<f32>> *, sead::Vector3<f32> const &, sead::Camera const &) const;
        void doUpdateDeviceMatrix(sead::Matrix44<f32> *, sead::Matrix44<f32> const &, sead::Graphics::DevicePosture) const;

        u8 _8;
        u8 _9;
        u16 _A;
        sead::Matrix44<f32> mProjectionMtx; // _C
        u8 _4C[0x90-0x4C];
        u32 _90;
        u32 _94;
    };
};