/**
 * @file RailRider.h
 * @brief Tracker for an actor using a rail.
 */

#pragma once

#include "Rail.h"
#include "sead/vector.h"

namespace al
{
    class RailRider
    {
    public:
        RailRider(al::Rail const *);

        void moveToRailStart();
        void move();
        void syncPosDir();
        void setCoord(f32);
        void moveToRailPoint(s32);
        void moveToRailEnd();
        void moveToBegin();
        void moveToGoal();
        void moveToNearestRail(sead::Vector3<f32> const &);
        void reverse();
        void setMoveGoingStart();
        void setMoveGoingEnd();
        void setSpeed(f32 speed);
        void addSpeed(f32 speed);
        void scaleSpeed(f32 speed);
        bool isReachedGoal() const;
        bool isReachedRailEnd() const;
        bool isReachedRailStart() const;
        bool isReachedEdge() const;

        al::Rail* mRider; // _0
        sead::Vector3<f32> mPosition; // _8
        sead::Vector3<f32> mDirection; // _14
        f32 mTotalLength; // _20
        f32 mSpeed; // _24
        u8 _28; // some sort of flag
    };
};