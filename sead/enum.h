/**
 * @file enum.h
 * @brief Enumeration utilities.
 */

#pragma once

#include "types.h"

namespace sead
{
    class EnumUtil
    {
    public:
        static u64 getInitValueArrayCS_();
        static void ParseFailed_(char **, s32);
        static void parseText_(char **, char *, s32);
        static void skipToWordStart_(char **);
        static void skipToWordEnd_(char **, char **);
    };
};