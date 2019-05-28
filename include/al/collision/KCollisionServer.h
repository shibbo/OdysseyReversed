/**
 * @file KCollisionServer.h
 * @brief Serves as a "server" (storage container) for collision attributes from a BYAML.
 */

#pragma once

#include "types.h"
#include "al/byaml/ByamlIter.h"
#include "al/collision/KCPrismHeader.h"
#include "sead/vector.h"

struct KCollisionServer_Data
{
    u32 magic;
    u32 octreeOffset;
    u32 modelListOffset;
    s32 modelCount;
    f32 minCoordX;
    f32 minCoordY;
    f32 minCoordZ;
    f32 maxCoordX;
    f32 maxCoordY;
    f32 maxCoordZ;
    s32 coordinateShift;
    s32 yShift;
    s32 zShift;
    s32 _34;
};

namespace al
{
    class KCollisionServer
    {
    public:
        KCollisionServer();

        void initKCollisionServer(void *, void const *byamlSrc);
        void setData(void *kclSrc);

        void getMinMax(sead::Vector3<f32> *, sead::Vector3<f32> *) const;
        void objectSpaceToAreaOffsetSpaceV3f(sead::Vector3<f32> *, sead::Vector3<f32> const &, al::KCPrismHeader const *) const;
        bool isInsideMinMaxInAreaOffsetSpace(sead::Vector3<u32> const &, al::KCPrismHeader const *) const;

        u32 _0;
        u32 _4;
        u32 _8;
        u32 _C;
        void* mData; // _10
        al::ByamlIter* mColIterator; // _18
        u64 mModelListAddr; // _20
        u64 mOctreeAddr; // _28
        u32 _30;
        u32 _34;
        u32 _38;
        u32 _3C;
        u32 _40;
        u32 _44;
        u64 _48;
    };
};