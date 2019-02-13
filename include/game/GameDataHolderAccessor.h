/**
 * @file GameDataHolderAccessor.h
 * @brief Wrapper class for GameDataHolder.
 */

#pragma once

#include "al/Scene.h"
#include "types.h"

class GameDataHolderAccessor
{
public:
    GameDataHolderAccessor(al::IUseSceneObjHolder const *);
    GameDataHolderAccessor(al::SceneObjHolder const *);
};