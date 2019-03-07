#include "custom/actorFactory.h"

CustomActorFactory::CustomActorFactory() : al::ActorFactory("アクター生成")
{
    this->mFactoryList = (u64*)getEntries();
    this->mNumFactoryEntries = 0x23B;
}