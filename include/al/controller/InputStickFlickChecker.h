/**
 * @file InputStickFlickChecker.h
 * @brief Check for input stick "flicks" (sudden jerks).
 */

#pragma once

#include "sead/vector.h"
#include "types.h"

namespace al
{
    class InputStickFlickChecker
    {
    public:
        InputStickFlickChecker();

        void update(sead::Vector2<f32> const &);

        u64* _0;
    };
};