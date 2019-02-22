/**
 * @file HitInfo.h
 * @brief Stores information about how an object is collided.
 */

#pragma once

#include "sead/vector.h"
#include "types.h"

namespace al
{
    class HitInfo
    {
    public:
        HitInfo();

        bool isCollisionAtFace() const;
        bool isCollisionAtEdge() const;
        bool isCollisionAtCorner() const;
        sead::Vector3<f32> tryGetHitEdgeNormal() const;

        u64 _0;
        u64 _8;
        u64 _10;
        sead::Vector3<f32> _18;
        sead::Vector3<f32> _24;
        sead::Vector3<f32> _30;
        sead::Vector3<f32> _3C;
        sead::Vector3<f32> _48;
        u8 _54[0x70-0x54];
        u64 _70;
        u64 _78;
        u64 _80;
    };
};