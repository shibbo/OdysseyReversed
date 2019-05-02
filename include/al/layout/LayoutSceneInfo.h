/**
 * @file LayoutSceneInfo.h
 * @brief Contains information on layout scenes.
 */

#pragma once

#include "types.h"

namespace al
{
    class LayoutSceneInfo
    {
    public:
        LayoutSceneInfo();
        
        u64 _0;
        u64 _8; // al::CameraDirector*
        u64 _10; // al::PadRumbleDirector*
        u64 _18; // al::SceneObjHolder*
        u64 _20; // al::MessageSystem*
        u64 _28;
    };
}