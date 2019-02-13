/**
 * @file AchievementInfoReader.h
 * @brief Reads achivement info stored in the game.
 */

#pragma once

#include "types.h"

class AchievementInfoReader
{
public:
    AchievementInfoReader();

    void init();
    s32 tryFindIndexByName(char const *) const;

    u64 _0;
    u64 _8;
};