/**
 * @file archive.h
 * @brief Wrapper functions for archives.
 */

#pragma once

#include "sead/string.h"

namespace al
{
    void makeStageDataArchivePath(sead::BufferedSafeStringBase<char> *, char const *stageName, char const *stageType);
};