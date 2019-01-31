/**
 * @file InputStickSpinChecker.h
 * @brief Check for input stick "spins".
 */

#pragma once

#include "types.h"
#include "sead/vector.h"

namespace al
{
    class InputStickSpinChecker
    {
    public:
        InputStickSpinChecker();

        void update(sead::Vector2<f32> const &);
        void reset();
        bool isSpin(f32) const;
        bool isLeftSpin(f32) const;
        bool isRightSpin(f32) const;

        u64* _0;
        f32 _8;
        u32 _C;
        u32 _10;
    };
};