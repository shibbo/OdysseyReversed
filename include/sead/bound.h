/**
 * @file bound.h
 * @brief Classes for sizeable bounding boxes.
 */

#pragma once

#include "types.h"

namespace sead
{
    template<typename T>
    class BoundBox2
    {
    public:
        T _0;
        T _4;
        T _8;
        T _C;
    };

    template<typename T>
    class BoundBox3
    {
    public:
        T _0;
        T _4;
        T _8;
        T _C;
        T _10;
        T _14;
    };
};