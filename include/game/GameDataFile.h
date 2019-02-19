/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "types.h"

class GameDataHolder;

class GameDataFile
{
public:
    GameDataFile(GameDataHolder *);

    void initializeData();

    u8 _0[0xB88];
};