/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "GameDataFile.h"
#include "types.h"

class GameDataFile
{
public:
    GameDataFile(GameDataHolder *);

    void initializeData();

    u8 _0[0xB88];
};