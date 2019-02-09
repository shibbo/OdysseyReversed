/**
 * @file BezierCurve.cpp
 * @brief A class that represents a node in a bezier curve.
 */

#include "al/rail/curve/BezierCurve.h"

#include<math.h>

namespace al
{
    BezierCurve::BezierCurve()
    {
       this->mStartPosition.mZ = 0.0;
       this->mStartPosition.mX = 0.0;
       this->mControlPos1.mZ = 0.0;
       this->mControlPos1.mX = 0.0;
       this->mControlPos2.mZ = 0.0;
       this->mControlPos2.mX = 0.0;
       this->mEndPos.mZ = 0.0;
       this->mEndPos.mX = 0.0;
       this->mLength = 0.0;
    }

    void BezierCurve::set(sead::Vector3<f32> const &a1, sead::Vector3<f32> const &a2, sead::Vector3<f32> const &a3, sead::Vector3<f32> const &a4)
    {
        f32 v5, v6, v7, v8, v9, v10, v11, v12, v13, v15, v16, v17, v18, v19, v20;

        v5 = a2.mY;
        v6 = v5 - a1.mY;
        v7 = a3.mY;
        v8 = a2.mZ;
        v8 = v7 - v5;
        v10 = a4.mX - a3.mX;
        v11 = a3.mZ;
        v12 = a3.mX - a2.mX;
        v13 = a2.mX - a1.mX;
        v15 = v8 - a1.mZ;
        v17 = a4.mY;
        v16 = a4.mZ;
        this->mStartPosition.mX = a1.mX;
        v18 = v11 - v8;
        this->mStartPosition.mY = a1.mY;
        v19 = a1.mZ;
        this->mStartPosition.mY = a1.mY;
        v19 = a1.mZ;
        this->mControlPos1.mY = v6 * 3.0;
        this->mControlPos1.mX = v13 * 3.0;
        this->mControlPos1.mZ = v15 * 3.0;
        this->mEndPos.mY = ((v17 - v7) - v9) - (v9 - v6);
        this->mEndPos.mZ = ((v16 - v11) - v18) - (v18 - v15);
        this->mStartPosition.mZ = v19;
        this->mControlPos2.mX = (v12 - v13) * 3.0;
        this->mControlPos2.mY = (v9 - v6) * 3.0;
        this->mControlPos2.mZ = (v18 - v15) * 3.0;
        this->mEndPos.mX = (v10 - v12) - (v12 - v13);
        this->calcLength(0.0, 1.0, 10);
        this->mLength = v20;
    }

    f32 BezierCurve::calcLength(f32 a1, f32 a2, s32 a3) const
    {
        f32 v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20;
        s32 v21;
        f32 v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v38;

        v7 = (a1 * 3.0) * a1;
        v8 = (((a1 + a1) * this->mControlPos2.mX) + this->mControlPos1.mX) + (v7 * this->mEndPos.mX);
        v9 = (((a1 + a1) * this->mControlPos2.mY) + this->mControlPos1.mY) + (v7 * this->mEndPos.mY);
        v10 = (((a1 + a1) * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v7 * this->mEndPos.mZ);
        v11 = sqrtf(((v8 * v8) + (v9 * v9)) + (v10 * v10));
        v12 = (a2 * 3.0) * a2;
        v13 = (((a2 + a2) * this->mControlPos2.mX) + this->mControlPos1.mX) + (v12 * this->mEndPos.mX);
        v14 = (((a2 + a2) * this->mControlPos2.mY) + this->mControlPos1.mY) + (v12 * this->mEndPos.mY);
        v15 = (((a2 + a2) * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v12 * this->mEndPos.mZ);
        v16 = sqrtf(((v13 * v13) + (v14 * v14)) + (v15 * v15));
        v17 = (v11 + v16) * 0.5;
        v18 = (a2 - a1) * (1.0 / (a3 + a3));

        if (a3 < 1)
        {
            v20 = 0.0;
            v36 = 0.0;
        }
        else
        {
            v19 = 0.0;
            v20 = 0.0;
            v21 = 1;
            v38 = (v11 + v16) * 0.5;
            do
            {
                v22 = v21 + v21;
                v23 = (v18 * (v22 + -1.0)) + a1;
                v24 = v23 + v23;
                v25 = v23 * (v23 * 3.0);
                v26 = ((v24 * this->mControlPos2.mX) + this->mControlPos1.mX) + (v25 * this->mEndPos.mX);
                v27 = ((v24 * this->mControlPos2.mY) + this->mControlPos1.mY) + (v25 * this->mEndPos.mY);
                v28 = ((v24 * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v25 * this->mEndPos.mZ);
                v29 = sqrtf(((v26 * v26) + (v27 * v27)) + (v28 * v28));

                if (v21 != a3)
                {
                    v30 = (v18 * v22) + a1;
                    v31 = v30 + v30;
                    v32 = v30 * (v30 * 3.0);
                    v33 = ((v31 * this->mControlPos2.mX) + this->mControlPos1.mX) + (v32 * this->mEndPos.mX);
                    v34 = ((v31 * this->mControlPos2.mY) + this->mControlPos1.mY) + (v32 * this->mEndPos.mY);
                    v35 = ((v31 * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v32 * this->mEndPos.mZ);
                    v20 = v20 + sqrtf(((v33 * v33) + (v34 * v34)) + (v35 * v35));
                }
                v19 = v19 + v29;
                ++v21;
            }
            while (v21 - a3 != 1);
            v36 = v19 * 4.0;
            v17 = v38;
        }

        return floorf(((v18 * 0.33333) * ((v17 + (v20 + v20)) + v36)) * 1024.0) * 0.00097656;
    }

    void BezierCurve::calcPos(sead::Vector3<f32> *out, f32 a2) const
    {
        f32 posX, posY, v5, v6, v7, v8, v9, posZ;

        posX = (this->mControlPos1.mX * a2) + this->mStartPosition.mX;
        out->mX = posX;
        posY = (this->mControlPos1.mY * a2) + this->mStartPosition.mY;
        out->mY = posY;
        v5 = a2 * a2;
        v6 = (a2 * a2) * a2;
        v7 = (this->mControlPos1.mZ * a2) + this->mStartPosition.mZ;
        out->mZ = v7;
        v8 = (v5 * this->mControlPos2.mX) + posX;
        out->mX = v8;
        v9 = (v5 * this->mControlPos2.mY) + posY;
        out->mY = v9;
        posZ = (v5 * this->mControlPos2.mZ) + v7;
        out->mZ = posZ;
        out->mX = (v6 * this->mEndPos.mX) + v8;
        out->mY = (v6 * this->mEndPos.mY) + v9;
        out->mZ = (v6 * this->mEndPos.mZ) + posZ;
    }

    void BezierCurve::calcVelocity(sead::Vector3<f32> *out, f32 a2) const
    {
        f32 v3, v4, velocityX, velocityY, velocityZ;

        v3 = a2 + a2;
        v4 = (a2 * 3.0) * a2;
        velocityX = (v3 * this->mControlPos2.mX) + this->mControlPos1.mX;
        out->mX = velocityX;
        velocityY = (v3 * this->mControlPos2.mY) + this->mControlPos1.mY;
        out->mY = velocityY;
        velocityZ = (v3 * this->mControlPos2.mZ) + this->mControlPos1.mZ;
        out->mZ = velocityZ;
        out->mX = (v4 * this->mEndPos.mX) + velocityX;
        out->mY = (v4 * this->mEndPos.mY) + velocityY;
        out->mZ = (v4 * this->mEndPos.mZ) + velocityZ;
    }

    f32 BezierCurve::calcDeltaLength(f32 a1) const
    {
        f32 v2, v3, v4, v5, v6;

        v2 = a1 + a1;
        v3 = (a1 * 3.0) * a1;
        v4 = ((v2 * this->mControlPos2.mX) + this->mControlPos1.mX) + (v3 * this->mEndPos.mX);
        v5 = ((v2 * this->mControlPos2.mY) + this->mControlPos1.mY) + (v3 * this->mEndPos.mY);
        v6 = ((v2 * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v3 * this->mEndPos.mZ);
        return sqrtf(((v4 * v4) + (v5 * v5)) + (v6 * v6));
    }

    f32 BezierCurve::calcCurveParam(f32 a1) const
    {
        f32 v3, v4, v5, v6, v7;
        s32 v8;
        f32 v9, v10, v11, v12, v13, v14, v15, v16, v17;
        f32 res;
        bool v18;

        v3 = a1;
        v4 = a1 / this->mLength;
        v5 = this->calcLength(0.0, v4, 10);
        v6 = v5;
        v7 = v3 - v5;

        if (v7 <= 0.0)
        {
            v7 = -v7;
        }

        if (v7 > 0.01)
        {
            v8 = 0;
            while (1)
            {
                v9 = v4 * (v4 * 3.0);
                v10 = (((v4 + v4) * this->mControlPos2.mX) + this->mControlPos1.mX) + (v9 * this->mEndPos.mX);
                v11 = (((v4 + v4) * this->mControlPos2.mY) + this->mControlPos1.mY) + (v9 * this->mEndPos.mY);
                v12 = (((v4 + v4) * this->mControlPos2.mZ) + this->mControlPos1.mZ) + (v9 * this->mEndPos.mZ);
                v13 = v4 + ((v3 - v6) / fmaxf(sqrtf(((v10 * v10) + (v11 * v11)) + (v12 * v12)), 0.001));
                v4 = 0.0;

                if (v13 >= 0.0)
                {
                    v4 = v13;
                    if (v13 > 1.0)
                    {
                        v4 = 1.0;
                    }
                }
                v14 = this->calcLength(0.0, v4, 10);
                v6 = v14;
                v15 = v3 - v14;

                if (v15 <= 0.0)
                {
                    v15 = -v15;
                }

                if (v15 <= 0.01)
                {
                    break;
                }

                if (++v8 > 4)
                {
                    res = 1.0;

                    if (v4 <= 1.0 && v6 >= 0.0)
                    {
                        return v4;
                    }

                    if (v4 >= 0.0)
                    {
                        v17 = v4;
                    }
                    else
                    {
                        v17 = 0.0;
                    }

                    if (v4 > 1.0 )
                    {
                        v18 = v4 < 0.0;
                    }
                    else
                    {
                        v18 = 1;
                    }

                    if (v18)
                    {
                        res = v17;
                    }

                    return res;
                }
            }
        }

        return v4;
    }

    f32 BezierCurve::calcNearestParam(sead::Vector3<f32> const &a1, f32 a2) const
    {
        f32 v3, v4, v5, v6, v7, v8, v9, v10;

        v4 = 0.0;
        v3 = -1.0;
        v5 = 3.4028e38;

        do
        {
            v6 = v4 * (v4 * v4);
            v7 = (((v4 * this->mControlPos1.mY) + this->mStartPosition.mY) + ((v4 * v4) * this->mControlPos2.mY)) + (v6 * this->mEndPos.mY);
            v8 = (((v4 * this->mControlPos1.mZ) + this->mStartPosition.mZ) + ((v4 * v4) * this->mControlPos2.mZ)) + (v6 * this->mEndPos.mZ);
            v9 = ((((v4 * this->mControlPos1.mX) + this->mStartPosition.mX) + ((v4 * v4) * this->mControlPos2.mX)) + (v6 * this->mEndPos.mX)) - a1.mX;
            v10 = ((v9 * v9) + ((v7 - a1.mY) * (v7 - a1.mY))) + ((v8 - a1.mZ) * (v8 - a1.mZ));

            if (v10 < v5)
            {
               v3 = v4;
            }
            v4 = v4 + a2;

            if (v10 < v5)
            {
                v5 = v10;
            }
        }
        while (v4 <= 1.0);

        return v3;  
    }

    f32 BezierCurve::calcNearestLength(f32 *a1, sead::Vector3<f32> const &a2, f32 a3, f32 a4) const
    {
        f32 v5, v6, v11, v13, v14, v15, v16, v17, v18, res, length;

        if (a3 <= 0.0)
        {
            res = 3.4028e38;
            length = -1.0;
        }
        else
        {
            res = 3.4028e38;
            v11 = 0.0;
            length = -1.0;
            do
            {
                v13 =this->calcCurveParam(v11);
                v14 = v13 * (v13 * v13);
                v15 = ((((v13 * this->mControlPos1.mX) + this->mStartPosition.mX) + ((v13 * v13) * this->mControlPos2.mX)) + (v14 * this->mEndPos.mX)) - a2.mX;
                v16 = ((((v13 * this->mControlPos1.mY) + this->mStartPosition.mY) + ((v13 * v13) * this->mControlPos2.mY)) + (v14 * this->mEndPos.mY)) - a2.mY;
                v17 = ((((v13 * this->mControlPos1.mZ) + this->mStartPosition.mZ) + ((v13 * v13) * this->mControlPos2.mZ)) + (v14 * this->mEndPos.mZ)) - a2.mZ;
                v18 = ((v15 * v15) + (v16 * v16)) + (v17 * v17);

                if (v18 < res)
                {
                    length = v11;
                }

                v11 = v11 + a4;
                if (v18 < res)
                {
                    res = v18;
                }
            }
            while (v11 < a3);
        }

        *a1 = length;
        return res;
    }

    void BezierCurve::calcNearestPos(sead::Vector3<f32> *a1, sead::Vector3<f32> const &a2, f32 a3) const
    {
        f32 ctrlPos1X, startPosX, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21;

        ctrlPos1X = this->mControlPos1.mX;
        startPosX = this->mStartPosition.mX;
        v7 = 0.0;
        v8 = -1.0;
        v9 = 3.4028e38;
        do
        {
            v10 = v7 * (v7 * v7);
            v11 = ((this->mStartPosition.mY + (this->mControlPos1.mY * v7)) + (this->mControlPos2.mY * (v7 * v7))) + (this->mEndPos.mY * v10);
            v12 = ((this->mStartPosition.mZ + (this->mControlPos1.mZ * v7)) + (this->mControlPos2.mZ * (v7 * v7))) + (this->mEndPos.mZ * v10);
            v13 = (((startPosX + (ctrlPos1X * v7)) + (this->mControlPos2.mX * (v7 * v7))) + (this->mEndPos.mX * v10)) - a2.mX;
            v14 = ((v12 - a2.mZ) * (v12 - a2.mZ)) + ((v13 * v13) + ((v11 - a2.mY) * (v11 - a2.mY)));

            if (v14 < v9)
            {
                v8 = v7;
            }
            v7 = v7 + a3;

            if (v14 < v9)
            {
                v9 = v14;
            }
        }
        while (v7 <= 1.0);

        v15 = (v8 * ctrlPos1X) + startPosX;
        a1->mX = v15;
        v16 = (v8 * this->mControlPos1.mY) + this->mStartPosition.mY;
        a1->mY = v16;
        v17 = (v8 * this->mControlPos1.mZ) + this->mStartPosition.mZ;
        a1->mZ = v17;
        v18 = v8 * (v8 * v8);
        v19 = v15 + ((v8 * v8) * this->mControlPos2.mX);
        a1->mX = v19;
        v20 = v16 + ((v8 * v8) * this->mControlPos2.mY);
        a1->mY = v20;
        v21 = v17 + ((v8 * v8) * this->mControlPos2.mZ);
        a1->mZ = v21;
        a1->mX = v19 + (v18 * this->mEndPos.mX);
        a1->mY = v20 + (v18 * this->mEndPos.mY);
        a1->mZ = v21 + (v18 * this->mEndPos.mZ);
    }

    void BezierCurve::calcStartPos(sead::Vector3<f32> *startPos) const
    {
        startPos->mX = this->mStartPosition.mX;
        startPos->mY = this->mStartPosition.mY;
        startPos->mZ = this->mStartPosition.mZ;
    }

    void BezierCurve::calcCtrlPos1(sead::Vector3<f32> *ctrlPos1) const
    {
        f32 v2, v3, v4;

        v2 = this->mControlPos1.mX * 0.33333;
        ctrlPos1->mX = v2;
        v3 = this->mControlPos1.mY * 0.33333;
        ctrlPos1->mY = v3;
        v4 = this->mControlPos1.mZ * 0.33333;
        ctrlPos1->mZ = v4;
        ctrlPos1->mX = v2 + this->mStartPosition.mX;
        ctrlPos1->mY = v3 + this->mStartPosition.mY;
        ctrlPos1->mZ = v4 + this->mStartPosition.mZ;
    }

    void BezierCurve::calcCtrlPos2(sead::Vector3<f32> *ctrlPos2) const
    {
        f32 v2, v3, v4, v5, v6, v7;

        v2 = this->mControlPos2.mX * 0.33333;
        ctrlPos2->mX = v2;
        v3 = this->mControlPos2.mY * 0.33333;
        ctrlPos2->mY = v3;
        v4 = this->mControlPos2.mZ * 0.33333;
        ctrlPos2->mZ = v4;
        v5 = (this->mControlPos1.mX * 0.66667) + v2;
        ctrlPos2->mX = v5;
        v6 = (this->mControlPos1.mY * 0.66667) + v3;
        ctrlPos2->mY = v6;
        v7 = (this->mControlPos1.mZ * 0.66667) + v4;
        ctrlPos2->mZ = v7;
        ctrlPos2->mX = v5 + this->mStartPosition.mX;
        ctrlPos2->mY = v6 + this->mStartPosition.mY;
        ctrlPos2->mZ = v7 + this->mStartPosition.mZ;
    }

    void BezierCurve::calcEndPos(sead::Vector3<f32> *endPos) const
    {
        f32 endPosX, endPosY, endPosZ, v5, v6, v7;

        endPosX = this->mStartPosition.mX + this->mControlPos1.mX;
        endPos->mX = endPosX;
        endPosY = this->mStartPosition.mY + this->mControlPos1.mY;
        endPos->mY = endPosY;
        endPosZ = this->mStartPosition.mZ + this->mControlPos1.mZ;
        endPos->mZ = endPosZ;
        v5 = endPosX + this->mControlPos2.mX;
        endPos->mX = v5;
        v6 = endPosY + this->mControlPos2.mY;
        endPos->mY = v6;
        v7 = endPosZ + this->mControlPos2.mZ;
        endPos->mZ = v7;
        endPos->mX = v5 + this->mEndPos.mX;
        endPos->mY = v6 + this->mEndPos.mY;
        endPos->mZ = v7 + this->mEndPos.mZ; 
    }
};