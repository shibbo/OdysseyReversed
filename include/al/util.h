/**
 * @file util.h
 * @brief Wrapper functions for a lot of tasks.
 */

#pragma once

#include "al/PlacementId.h"
#include "al/PlacementInfo.h"
#include "sead/string.h"
#include "types.h"

namespace al
{
    // STRING
    bool isEqualString(char const *, char const *);
    bool isEqualString(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);
    bool isEqualStringCase(char const *, char const *);
    bool isEqualStringCase(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);

    // PLACMENT
    s32 getCountPlacementInfo(al::PlacementInfo const &);
    s32 calcLinkCountClassName(al::PlacementInfo const &, char const *className);
    bool isClassName(al::PlacementInfo const &, char const *);
    void tryGetPlacementId(al::PlacementId *, al::PlacementInfo const &);
    void tryGetPlacementInfoByIndex(al::PlacementInfo *, al::PlacementInfo const &, s32);
    void tryGetPlacementInfoByKey(al::PlacementInfo *, al::PlacementInfo const &, char const *);
    void tryGetPlacementInfoAndKeyNameByIndex(al::PlacementInfo *, char const**, al::PlacementInfo const &, s32);
};