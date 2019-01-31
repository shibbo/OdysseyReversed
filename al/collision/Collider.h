/**
 * @file Collider.h
 * @brief Wrapper for colliders.
 */

#pragma once

#include "sead/vector.h"
#include "sead/matrix.h"
#include "al/execute.h"

namespace al
{
    class CollisionDirector
    {
    public:
        CollisionDirector(al::ExecuteDirector *);

        virtual void execute();

        void setPartsKeeper(u64 *); // al::ICollisionPartsKeeper *
        void endInit();
    };

    class Collider
    {
    public:
        Collider(al::CollisionDirector *, sead::Matrix34<f32> const*, sead::Vector3<f32> const*, sead::Vector3<f32> const*, f32, f32, u32);

        virtual al::CollisionDirector getDirector() const;

        al::CollisionDirector* mDirector; // _8
    };
};