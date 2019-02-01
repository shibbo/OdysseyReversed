#include "sead/camera.h"

namespace sead
{
    void Camera::getWorldPosByMatrix(sead::Vector3<f32> *out) const
    {
        f32 v2 = this->_14;
        f32 v3 = this->_24;
        f32 v4 = this->_34;
        f32 v5 = (-(v2 * mRightY) - (v3 * mUpY)) - (v4 * mLookY);
        f32 v6 = (-(v2 * mRightZ) - (v3 * mUpZ)) - (v4 * mLookZ);
        out->mX = (-(mRightX * v2) - (mUpX * v3)) - (mLookX * v4);
        out->mY = v5;
        out->mZ = v6;
    }

    void Camera::getLookVectorByMatrix(sead::Vector3<f32> *out) const
    {
        out->mX = mLookX;
        out->mZ = mLookZ;
    }

    void Camera::getRightVectorByMatrix(sead::Vector3<f32> *out) const
    {
        out->mX = mRightX;
        out->mY = mRightY;
        out->mZ = mRightZ;
    }

    void Camera::getUpVectorByMatrix(sead::Vector3<f32> *out) const
    {
        out->mX = mUpX;
        out->mZ = mUpZ;
    }

    void Camera::worldPosToCameraPosByMatrix(sead::Vector3<f32> *out, sead::Vector3<f32> const &a3) const
    {
        f32 v3 = a3.mX;
        f32 v4 = a3.mY;
        f32 v5 = a3.mZ;
        out->mX = this->_14 + (((a3.mX * mRightX) + (v4 * mRightY)) + (v5 * mRightZ));
        out->mY = this->_24 + (((v3 * mUpX) + (v4 * mUpY)) + (v5 * mUpZ));
        out->mZ = this->_34 + (((v3 * mLookX) + (v4 * mLookY)) + (v5 * mLookZ));
    }

    void Camera::cameraPosToWorldPosByMatrix(sead::Vector3<f32> *out, sead::Vector3<f32> const &a3) const
    {
        f32 v3 = a3.mZ;
        f32 v4 = a3.mY;
        f32 v5 = this->mRightZ;
        f32 v6 = this->_14;
        f32 v7 = this->mUpZ;
        f32 v8 = this->_24;
        f32 v9 = this->mLookZ;
        f32 v10 = this->_34;
        f32 v11 = v5 * a3.mX;
        f32 v12 = (this->mRightY * a3.mX) + ((this->mLookY * v3) + ((this->mUpY * v4) + ((-(v6 * this->mRightY) - (v8 * this->mUpY)) - (v10 * this->mLookY))));
        out->mX = (this->mRightX * a3.mX) + ((this->mLookX * v3) + ((this->mUpX * v4) + ((-(this->mRightX * v6) - (this->mUpX * v8)) - (this->mLookX * v10))));
        out->mY = v12;
        out->mZ = v11 + ((v9 * v3) + ((v7 * v4) + ((-(v6 * v5) - (v8 * v7)) - (v10 * v9))));
    }
};