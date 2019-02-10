/**
 * @file RailPart.cpp
 * @brief A node contained in a rail, which can include curves.
 */

#include "al/rail/RailPart.h"

namespace al
{
    RailPart::RailPart()
    {
        this->_10 = 0;
        this->mBezierCurve = 0;
        this->mLinearCurve = 0;
    }

    void RailPart::init(sead::Vector3<f32> const &a1, sead::Vector3<f32> const &a2, sead::Vector3<f32> const &a3, sead::Vector3<f32> const &a4)
    {
        f32 dist, v11, v12, v13, v14, v15;
        LinearCurve* linearCurve;
        BezierCurve* bezierCurve;

        dist = a1.mX - a2.mX;

        if (dist > 0.1
            || dist < -0.1
            || (v11 = a1.mY - a2.mY, v11 > 0.1)
            || v11 < -0.1
            || (v12 = a1.mZ - a2.mZ, v12 > 0.1)
            || v12 < -0.1
            || (v13 = a4.mX - a3.mX, v13 > 0.1)
            || v13 < -0.1
            || (v14 = a4.mY - a3.mY, v14 > 0.1)
            || v14 < -0.1
            || (v15 = a4.mZ - a3.mZ, v15 > 0.1)
            || v15 < -0.1)
        {
            bezierCurve = new BezierCurve();
            this->mBezierCurve = bezierCurve;
            bezierCurve->set(a1, a2, a3, a4);
        }
        else
        {
            linearCurve = new LinearCurve();
            this->mLinearCurve = linearCurve;
            linearCurve->set(a1, a4);
        }
    }

    void RailPart::calcPos(sead::Vector3<f32> *pos, f32 a2) const
    {
        if (this->mBezierCurve)
        {
            this->mBezierCurve->calcPos(pos, a2);
        }
        else
        {
            this->mLinearCurve->calcPos(pos, a2);
        }
    }

    void RailPart::calcVelocity(sead::Vector3<f32> *pos, f32 a2) const
    {
        if (this->mBezierCurve)
        {
            this->mBezierCurve->calcVelocity(pos, a2);
        }
        else
        {
            this->mLinearCurve->calcVelocity(pos, a2);
        }
    }

    void RailPart::calcStartPos(sead::Vector3<f32> *startPos) const
    {
        if (this->mBezierCurve)
        {
            this->calcStartPos(startPos);
        }
        else
        {
            this->mLinearCurve->calcStartPos(startPos);
        }
    }

    void RailPart::calcEndPos(sead::Vector3<f32> *endPos) const
    {
        if (this->mBezierCurve)
        {
            this->calcEndPos(endPos);
        }
        else
        {
            this->mLinearCurve->calcEndPos(endPos);
        }
    }

    f32 RailPart::calcLength(f32 a1, f32 a2, s32 a3) const
    {
        if (this->mBezierCurve)
        {
            this->mBezierCurve->calcLength(a1, a2, a3);
        }
        else
        {
            this->mLinearCurve->calcLength(a2, a3);
        }
    }

    f32 RailPart::calcCurveParam(f32 a1) const
    {
        if (this->mBezierCurve)
        {
            this->mBezierCurve->calcCurveParam(a1);
        }
        else
        {
            this->mLinearCurve->calcCurveParam(a1);
        }
    }

    void RailPart::calcNearestLength(f32 *length, sead::Vector3<f32> const &a2, f32 a3, f32 a4) const
    {
        if (this->mBezierCurve)
        {
            this->mBezierCurve->calcNearestLength(length, a2, a3, a4);
        }
        else
        {
            this->mLinearCurve->calcNearestLength(length, a2, a3);
        }
    }

    f32 RailPart::getPartLength() const
    {
        if (this->mBezierCurve)
        {
            return this->mBezierCurve->mLength;
        }
        else
        {
            return this->mLinearCurve->mLength;
        }
    }
};