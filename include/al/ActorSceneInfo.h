/**
 * @file ActorSceneInfo.h
 * @brief Storage container for an actors' scene information.
 */

#pragma once

#include "types.h"

namespace al
{
    class ActorSceneInfo
    {
    public:
        ActorSceneInfo();

        u64* _10; // al::ClippingDirector*
        u64* _18; // unknown class
        u64* _20; // ProjectDemoDirector*
        u64* _28; // unknown class
        u64* _30; // ^^
        u64* _38; // ^^
        u64* _40; // ^^
        u64* _48; // ^^
        u64* _50; // al::PadRumbleDirector*
        u64* _58; // al::PlayerHolder*
        u64* _60; // al::SceneObjHolder*
        u64* _68; // SceneStopCtrl*
        u64* _70; // unknown class
        u64* _78; // ^^
        u64* _80; // ^^
        u64* _88; // ^^
        u64* _90; // al::GraphicsSystemInfo*
        u64* _98; // al::ModelDrawBufferCounter*
    };
};