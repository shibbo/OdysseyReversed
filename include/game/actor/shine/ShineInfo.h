/**
 * @file ShineInfo.h
 * @brief Stores information about a Shine actor.
 */

#pragma once

#include "sead/string.h"
#include "types.h"

class QuestInfo;

class ShineInfo
{
public:
    ShineInfo();

    void clear();
    void init(char const *, char const *, char const *, QuestInfo const *, s32);

    bool isEmpty() const;
    bool isEqual(ShineInfo const *) const;

    void copyShineInfo(ShineInfo const *);

    u64 _0;
    u64 _8;
    sead::FixedSafeString<128> _10; 

    sead::BufferedSafeStringBase<char> _98;

    sead::BufferedSafeStringBase<char> _130;
};