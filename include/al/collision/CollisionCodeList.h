/**
 * @file CollisionCodeList.h
 * @brief Stores information on collision codes.
 */

#pragma once

#include "types.h"

namespace al
{
    struct CollisionCodeList
    {
        u64* _0;
        u64* _8;
        char* mCodeNameList; // _10
        char* mDisplayNameList; // _18
        u64* _20;
        u64* _28;
    };
};

al::CollisionCodeList* tyrCreateCollisionCodeList(char const *);

char* getCodeNameByIdx(al::CollisionCodeList const *, s32);
char* getDispNameByIdx(al::CollisionCodeList const *, s32);
s32 getIdxByCodeName(al::CollisionCodeList const *, char const *);
bool isExistCodeName(al::CollisionCodeList const *, char const *);
bool isValidUserType(al::CollisionCodeList const *, char const *);
