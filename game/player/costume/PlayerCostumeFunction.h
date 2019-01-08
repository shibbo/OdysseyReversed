#pragma once

#include "../al/resource.h"
#include "PlayerBodyCostumeInfo.h"
#include "PlayerHeadCostumeInfo.h"

class PlayerCostumeFunction
{
public:
    PlayerBodyCostumeInfo* createBodyCostumeInfo(al::Resource *, char const *);
    PlayerHeadCostumeInfo* createHeadCostumeInfo(al::Resource *, char const *, bool);
};