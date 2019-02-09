/**
 * @file Rail.h
 * @brief A class that represents a basic rail, which can icnlude rail nodes.
 */

#pragma once

#include "PlacementInfo.h"
#include "RailPart.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    class Rail
    {
    public:
        Rail();

        void init(al::PlacementInfo const &);
        void calcPos(sead::Vector3<f32> *, f32) const;
        s32 getIncludedSection(al::RailPart const **, f32 *, f32) const;
        void calcDirection(sead::Vector3<f32> *, f32) const;
        void calcPosDir(sead::Vector3<f32> *out, sead::Vector3<f32> *, f32) const;
        f32 getTotalLength() const;
        s32 getPartLength(s32) const;
        f32 getLengthToPoint(s32) const;
        void calcRailPointPos(sead::Vector3<f32> *, s32) const;

        s32 getIncludedSectionIndex(f32) const;
        bool isIncludeBezierRailPart() const;

        u64 _0;
        al::RailPart* mRailParts; // _8 (array of al::RailPart)
        u64 _10;
        u8 _18;
    };
};