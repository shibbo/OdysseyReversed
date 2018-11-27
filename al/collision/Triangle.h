#pragma once

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

        u8 _0[0x48];
        sead::Vector3<f32> _48;
        sead::Vector3<f32> _54;
        sead::Vector3<f32> _60;
    };

    bool operator==(al::Triangle const &, al::Triangle const &);
    bool operator!=(al::Triangle const &, al::Triangle const &);
};