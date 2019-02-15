/**
 * @file GameDataFunction.h
 * @brief Holds static functions for getting / storage save data.
 */

#pragma once

#include "al/LiveActor.h"
#include "GameDataHolderAccessor.h"

class GameDataFunction
{
public:
    static s32 getCurrentWorldId(GameDataHolderAccessor);
    static char* getCurrentStageName(GameDataHolderAccessor);
    static s32 getScenarioNo(al::LiveActor const *);
    static bool isCityWorldCeremonyAll(s32, s32);
    static s32 tryFindShineIndex(al::LiveActor const *, al::ActorInitInfo const &);
    static bool isGameClear(GameDataHolderAccessor);
    static bool isWorldPeach(GameDataHolderAccessor);

    static void recoveryPlayerMax(al::LiveActor const *);

};