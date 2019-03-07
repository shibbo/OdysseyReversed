/**
 * @file Factory.h
 * @brief All factories needed for actor creation.
 */

#pragma once

#include "types.h"

class PlayerActorBase;

namespace al
{
    class LiveActor;
    class AreaObj;
    class CameraPoser;
    class EventFlowNode;

    template<typename T>
    class Factory
    {
    public:
        virtual char* convertName(char const *) const;

        char* mName; // _8
        u64* mFactoryList; // _10
        u32 mNumFactoryEntries; // _18
        u32 mPadding; // _1C
    };

    class ActorFactory : public al::Factory<al::LiveActor * (*)(char const *)>
    {
    public:
        ActorFactory(char const *);
    };

    class AreaObjFactory : public al::Factory<al::AreaObj * (*)(char const *)>
    {
    public:
        AreaObjFactory();
       
        u64* mGraphicsAreaTable; // _20
        u32 mTableEntryCount; // _28
    };

    class CameraPoserFactory : public al::Factory<al::CameraPoser * (*)(char const *)>
    {
    public:
        CameraPoserFactory(char const *);
    };

    class EventFlowNodeFactory : public al::Factory<al::EventFlowNode * (*)(char const *)>
    {
    public:
        EventFlowNodeFactory(char const *);
    };
}

class ProjectActorFactory : public al::ActorFactory
{
public:
    ProjectActorFactory();
};

class ProjectAppearSwitchFactory : public al::ActorFactory
{
public:
    ProjectAppearSwitchFactory();
};

class PlayerFactory : public al::Factory<PlayerActorBase * (*)(char const *)>
{
public:
    PlayerFactory();
};

class ProjectCameraPoserFactory : public al::CameraPoserFactory
{
public:
    ProjectCameraPoserFactory();
};

class ProjectAreaFactory : public al::AreaObjFactory
{
public:
    ProjectAreaFactory();
};

class ProjectEventFlowNodeFactory : public al::EventFlowNodeFactory
{
public:
    ProjectEventFlowNodeFactory();
};