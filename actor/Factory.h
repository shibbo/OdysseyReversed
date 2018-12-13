#pragma once

#include "types.h"

class PlayerActorBase;

namespace al
{
    class LiveActor;

    template<typename T>
    class Factory
    {
        public:
        virtual char* convertName(char const *) const;

        char* mName; // _8
        u64* mFactoryList; // _10
        u32 mNumFactoryEntries; // _18
    };
}

class ActorFactory : public al::Factory<al::LiveActor * (*)(char const *)>
{
    public:
    ActorFactory(char const *);
};

class ProjectActorFactory : public ActorFactory
{
    public:
    ProjectActorFactory();
};

class ProjectAppearSwitchFactory : public ActorFactory
{
    public:
    ProjectAppearSwitchFactory();
};

class PlayerFactory : public al::Factory<PlayerActorBase * (*)(char const *)>
{
    public:
    PlayerFactory();
};