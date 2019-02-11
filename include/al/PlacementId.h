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
        bool isEqual(al::PlacementId const &) const;
        static bool isEqual(al::PlacementId const &, al::PlacementId const &);
        bool isValid() const;
        s32 makeString(sead::BufferedSafeStringBase<char> *);

        // these are formatted into %s(%s[%s]) using the first three members
        char* mStageId; // _0
        char* mUnitConfigName; // _8
        char* mZoneId; // _10
        char* mCommonId; // _18
    };
};