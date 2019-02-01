/**
 * @file KeyRepeatCtrl.h
 * @brief Check for key repeat presses.
 */

#pragma once

#include "types.h"

namespace al
{
    class KeyRepeatCtrl
    {
    public:
        KeyRepeatCtrl();

        void init(s32, s32);
        void update(bool, bool);
        void reset();
        bool isUp() const;
        bool isDown() const;

        u64 _0;
        u32 _8;
        u32 _C; // might be a pressed flag
        u8 _10;
        u8 _11;
        u8 _12;
        u8 _13;
    };
};