/**
 * @file AnimInfoTable.h
 * @brief Storing animation data (such as frames) in a table.
 */

#pragma once

#include "types.h"
#include "AnimResInfo.h"

namespace al
{
    class AnimInfoTable
    {
    public:
        AnimInfoTable(s32);

        void add(char const *animName, void *, f32 frameMax, bool doesLoop);
        al::AnimResInfo* findAnimInfo(char const *animName) const;
        al::AnimResInfo* tryFindAnimInfo(char const *animName) const;
        void sort();

        u64 mNumEntries; // _0
        al::AnimResInfo* mResInfoTable; // _8
        u32 mIsSorted; // _10
    };
};