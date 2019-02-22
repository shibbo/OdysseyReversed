/**
 * @file Triangle.h
 * @brief Serves as a simple triangle.
 */

#pragma once

#include "CollisionParts.h"
#include "KCPrismData.h"
#include "KCPrismHeader.h"
#include "types.h"
#include "sead/vector.h"

namespace al
{
    class Triangle
    {
    public:
        Triangle();

        void fill(sead::Vector3<f32> const &vert1, sead::Vector3<f32> const &vert2, sead::Vector3<f32> const &vert3);
        bool isHostMoved() const;
        bool isValid() const;
        sead::Vector3<f32> getNormal(s32 idx) const;
        sead::Vector3<f32> getPos(s32 idx) const;
        void calcCenterPos(sead::Vector3<f32> *destPos) const;

        al::CollisionParts* mCollisionParts; // _0
        al::KCPrismData* mPrismData; // _8
        al::KCPrismHeader* mPrismHeader; // _10
        u8 _18[0x30];
        sead::Vector3<f32> _48;
        sead::Vector3<f32> _54;
        sead::Vector3<f32> _60;
    };

    bool operator==(al::Triangle const &, al::Triangle const &);
    bool operator!=(al::Triangle const &, al::Triangle const &);
};