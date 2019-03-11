/**
 * @file Scene.h
 * @brief Has classes that set up scenes / animations.
 */

#pragma once

#include "ActorInitInfo.h"
#include "keeper/AudioKeeper.h"
#include "keeper/StageResourceKeeper.h"
#include "iuse/IUseSceneObjHolder.h"
#include "nerve/NerveExecutor.h"

static char* sceneObjectName;

namespace al
{
    class AudioDirector;
    class CameraDirector;
    class GameDataHolderBase;
    class GameSystemInfo;
    class GraphicsInitArg;
    class LiveActorKit;
    class ScreenCaptureExecutor;
    class ScreenCoverCtrl;
    class SceneStopCtrl;

    class ISceneObj
    {
    public:
        virtual ~ISceneObj();
        virtual char* getSceneObjName() const;
        virtual void initAfterPlacementSceneObj(al::ActorInitInfo const &);
        virtual void initSceneObj();
    };

    class SceneObjHolder
    {
    public:
        SceneObjHolder(al::ISceneObj * (*)(s32), s32);

        al::ISceneObj* create(s32);
        al::ISceneObj* tryGetObj(s32) const;
        al::ISceneObj* getObj(s32) const;
        bool isExist(s32) const;
        void setSceneObj(al::ISceneObj *, s32);

        u64* _0;
        al::ISceneObj* mObjs; // _8
        u32 _10;
    };

    class SceneMsgCtrl
    {
    public:
        SceneMsgCtrl();

        u8 _0[0x2700];
    };

    class SceneInitInfo
    {
    public:
        SceneInitInfo(al::GameSystemInfo const*, al::GameDataHolderBase *, al::ScreenCaptureExecutor *, char const *, s32, char const *, al::AudioDirector *);
    };

    class Scene : public al::NerveExecutor
    {
    public:
        Scene(char const *);
        
        virtual void init(al::SceneInitInfo const &);
        virtual void appear();
        virtual void kill();
        virtual void movement();
        virtual void control();
        virtual void drawMain() const;
        virtual void drawSub() const;
        virtual al::AudioKeeper* getAudioKeeper() const;
        virtual al::SceneObjHolder* getSceneObjHolder() const;
        virtual al::CameraDirector* getCameraDirector() const;

        void initializeAsync(al::SceneInitInfo const &);
        void initSceneObjHolder(al::SceneObjHolder *);
        void initAndLoadStageResource(char const *name, s32 numResources);
        void initLiveActorKit(al::SceneInitInfo const &, s32, s32, s32);
        void initLiveActorKitImpl(al::SceneInitInfo const &, s32, s32, s32);
        void initDrawSystemInfo(al::SceneInitInfo const &);
        void initLiveActorKitWithGraphics(al::GraphicsInitArg const &, al::SceneInitInfo const &, s32, s32, s32);
        void initLayoutKit(al::SceneInitInfo const &);
        void initSceneStopCtrl();
        void initScreenCoverCtrl();
        void endInit(al::ActorInitInfo const &);

        u32 mIsAlive; // _28
        u32 _2C;
        u8 _30[0x88-0x30];
        al::StageResourceKeeper* mResourceKeeper; // _88
        al::LiveActorKit* mActorKit; // _90 
        u64* _98; // todo -- who am i?
        al::SceneObjHolder* mObjHolder; // _A0
        al::SceneStopCtrl* mSceneStopControl; // _A8
        al::SceneMsgCtrl* mSceneMsgCtrl; // _B0
        al::ScreenCoverCtrl* mScreenCoverControl; // _B8
        al::AudioDirector* mAudioDirector; // _C0
        al::AudioKeeper* mAudioKeeper; // _C8
        u64* _D0; // something that stores the draw context
    };
};