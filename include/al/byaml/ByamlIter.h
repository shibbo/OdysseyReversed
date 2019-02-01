/**
 * @file ByamlIter.h
 * @brief Iterator for an entire BYAML.
 */

#pragma once

#include "types.h"
#include "al/byaml/ByamlData.h"

namespace al
{
    class ByamlIter
    {
    public:
        ByamlIter();
        ByamlIter(u8 const *srcByaml);
        ByamlIter(u8 const *srcByamlHeader, u8 const *srcByamlData);

        bool isValid() const;
        bool isTypeHash() const;
        bool isTypeArray() const;
        bool isTypeContainer() const;
        bool isExistKey(char const *key) const;
        s32 getKeyIndex(char const *key) const;
        bool isInvertOrder() const;
        u32 getSize() const;
        al::ByamlIter* getIterByIndex(s32 index) const;
        bool getByamlDataByIndex(al::ByamlData *, s32 index) const;
        al::ByamlIter* getIterByKey(char const *) const;
        bool getByamlDataByKey(al::ByamlData *, char const *) const;
        bool getByamlDataByKeyIndex(al::ByamlData *, s32) const;
        bool getByamlDataAndKeyName(al::ByamlData *, char const **, s32) const;
        bool getKeyName(char const **, s32) const;
        bool tryGetIterByIndex(al::ByamlIter *, s32) const;
        bool tryGetIterAndKeyNameByIndex(al::ByamlIter *,char const **, s32) const;
        bool tryGetIterByKey(al::ByamlIter *,char const *) const;
        bool tryGetStringByKey(char const **, char const *) const;
        bool tryConvertString(char const **, al::ByamlData const *) const;
        bool tryGetBinaryByKey(u8 const **, s32 *, char const *) const;
        bool tryGetBinary(u8 const **, s32 *, al::ByamlData const *) const;
        bool tryGetBoolByKey(bool *, char const *) const;
        bool tryConvertBool(bool *, al::ByamlData const *) const;
        bool tryGetInt32ByKey(s32 *, char const *) const;
        bool tryConvertInt32(s32 *, al::ByamlData const *) const;
        bool tryGetUInt32ByKey(u32 *, char const *) const;
        bool tryConvertUInt32(u32 *, al::ByamlData const *) const;
        bool tryGetFloatByKey(f32 *, char const *) const;
        bool tryConvertFloat(f32 *, al::ByamlData const *) const;
        bool tryGetInt64ByKey(s64 *, char const *) const;
        bool tryConvertInt64(s64 *, al::ByamlData const *) const;
        bool tryGetUInt64ByKey(u64 *, char const *) const;
        bool tryConvertUInt64(u64 *, al::ByamlData const *) const;
        bool tryGetDoubleByKey(f64 *, char const *) const;
        bool tryConvertDouble(f64 *, al::ByamlData const *) const;
        bool tryGetStringByIndex(char const **, s32) const;
        bool tryGetBinaryByIndex(u8 const **, s32 *, s32) const;
        bool tryGetBoolByIndex(bool *, s32) const;
        bool tryGetInt32ByIndex(s32 *, s32) const;
        bool tryGetUInt32ByIndex(u32 *, s32) const;
        bool tryGetFloatByindex(f32 *, s32) const;
        bool tryGetInt64ByIndex(s64 *, s32) const;
        bool tryGetUInt64ByIndex(u64 *, s32) const;
        bool tryGetDoubleByIndex(f64 *, s32) const;
        bool tryConvertIter(al::ByamlIter *, al::ByamlData const *) const;
        bool isEqualData(al::ByamlIter const&) const;

        u8* mSrcByamlHeader; // _0
        u8* mSrcByamlData; // _8
    };
};