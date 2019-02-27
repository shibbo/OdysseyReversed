/**
 * @file camera.h
 * @brief Basic camera implementation.
 */

#pragma once

#include "matrix.h"
#include "runtime.h"
#include "vector.h"

namespace sead
{
    class OrthoProjection;

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
        void cameraPosToWorldPosByMatrix(sead::Vector3<f32> *, sead::Vector3<f32> const &) const;

        f32 mRightX; // _8
        f32 mRightY; // _C
        f32 mRightZ; // _10
        f32 _14;
        f32 mUpX; // _18
        f32 mUpY; // _1C
        f32 mUpZ; // _20
        f32 _24;
        f32 mLookX; // _28
        f32 mLookY; // _2C
        f32 mLookZ; // _30
        f32 _34;
    };

    class LookAtCamera : public sead::Camera
    {
    public:
        LookAtCamera(sead::Vector3<f32> const &, sead::Vector3<f32> const &, sead::Vector3<f32> const &);

        virtual ~LookAtCamera();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;

        virtual void doUpdateMatrix(sead::Matrix34<f32> *);
    };

    class DirectCamera : public sead::Camera
    {
    public:
        virtual ~DirectCamera();

        virtual void doUpdateMatrix(sead::Matrix34<f32> *);
    };

    class OrthoCamera : public sead::LookAtCamera
    {
    public:
        OrthoCamera();
        OrthoCamera(sead::Vector2<f32> const &, f32);
        OrthoCamera(sead::OrthoProjection const &);

        virtual ~OrthoCamera();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;

        void setByOrthoProjection(sead::OrthoProjection const &);
        void setRotation(f32 rotation);
    };
};