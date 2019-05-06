/**
 * @file ScreenPointKeeper.h
 * @brief Keeper for screen points(?)
 */

#pragma once

#include "types.h"

namespace al
{
    class ScreenPointKeeper
    {
    public:
        ScreenPointKeeper();

        void initArray(s32 numEntries);
        void update();
        void validate();
        u64* getTarget(s32 idx) const;
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();
        u64* getTarget(char const *) const;
        bool isExistTarget(char const *) const;

        s32 mNumTargets; // _0
        u8 pad[0x4]; // _4
        u64* _8; // al::ScreenPointTarget[]
        u64* _10; // al::ParameterIo*
        u64* _18; // al::ParameterArray*
        u64* _20; // al::ParameterObj*
        u64* _28;
    };
};