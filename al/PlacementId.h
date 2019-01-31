/**
 * @file PlacementId.h
 * @brief Storage container for an actors' placement identification.
 */

#pragma once

#include "PlacementInfo.h"
#include "sead/string.h"

namespace al
{
    class PlacementId
    {
    public:
        PlacementId();
        PlacementId(char const *, char const *, char const *);

        void init(al::PlacementInfo const &);
        bool isEqual(al::PlacementInfo const &) const;
        static bool isEqual(al::PlacementInfo const &, al::PlacementInfo const &);
        bool isValid() const;
        void makeString(sead::BufferedSafeStringBase<char> *);

        // these are formatted into %s(%s[%s]) using the first three members
        char* _0;
        char* _8;
        char* _10;
        u64 mIsInit; // _18
    };
};