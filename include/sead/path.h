/**
 * @file path.h
 * @brief Drive Path class.
 */

#pragma once

#include "string.h"
#include "types.h"

namespace sead
{
    class Path
    {
    public:
        static bool getDriveName(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static void getPathExceptDrive(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static bool getExt(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static bool getFileName(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static bool getBaseFileName(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static bool getDirectoryName(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
        static bool join(sead::BufferedSafeStringBase<char> *,char const *,char const *);
        static bool changeDelimiter(sead::BufferedSafeStringBase<char> *, char);
    };
};