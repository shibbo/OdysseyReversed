/**
 * @file util.h
 * @brief A bunch of functions used for reading / writing / verifying a BYAML file.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "sead/color.h"
#include "sead/stream.h"
#include "sead/vector.h"
#include "types.h"

bool verifiByaml(u8 const *srcByaml);
bool verifiByamlHeader(u8 const *srcByaml);
bool verifiByamlStringTable(u8 const *srcByaml, bool endianessSwap);

class alByamlLocalUtil
{
public:
    static u64 getHashKeyTable(u8 const *srcByaml);
    static u64 getStringTable(u8 const *srcByaml);
    static u64 getData64Bit(u8 const *srcByaml, u32 offset, bool endianessSwap);
    static void writeU24(sead::WriteStream *strm, s32 val);
    static bool verfiByaml(u8 const *srcByaml);
    static bool verifiByamlHeader(u8 const *srcByaml);
    static bool verifiByamlStringTable(u8 const *srcByaml, bool endianessSwap);
};

namespace al
{
    bool tryGetByamlU8(u8 *, al::ByamlIter const &, char const *);
    bool tryGetByamlU16(u16 *, al::ByamlIter const &, char const *);
    bool tryGetByamlS16(s16 *, al::ByamlIter const &, char const *);
    bool tryGetByamlS32(s32 *, al::ByamlIter const &, char const *);
    bool tryGetByamlU32(u32 *, al::ByamlIter const &, char const *);
    bool tryGetByamlS64(s64 *, al::ByamlIter const &, char const *);
    bool tryGetByamlU64(u64 *, al::ByamlIter const &, char const *);
    bool tryGetByamlF32(f32 *, al::ByamlIter const &, char const *);
    bool tryGetByamlV2f(sead::Vector2<f32> *, al::ByamlIter const &);
    bool tryGetByamlV3f(sead::Vector3<f32> *, al::ByamlIter const &);
    bool tryGetByamlV4f(sead::Vector4<f32> *, al::ByamlIter const &);
    bool tryGetByamlScale(sead::Vector3<f32> *, al::ByamlIter const &);
    bool tryGetByamlV2s32(sead::Vector2<s32> *, al::ByamlIter const &);
    bool tryGetByamlV3s32(sead::Vector3<s32> *, al::ByamlIter const &);
    bool tryGetByamlV3f(sead::Vector3<f32> *, al::ByamlIter const &, char const *);
    bool tryGetByamlV2f(sead::Vector2<f32> *, al::ByamlIter const &, char const *);
    bool tryGetByamlV4f(sead::Vector4<f32> *, al::ByamlIter const &, char const *);
    bool tryGetByamlScale(sead::Vector3<f32> *, al::ByamlIter const &, char const *);
    // bool tryGetByamlBox3f(sead::BoundBox3<f32> *, al::ByamlIter const &, char const *);
    bool tryGetByamlString(char const **, al::ByamlIter const &, char const *);
    bool tryGetByamlColor(sead::Color4f *, al::ByamlIter const &);
    bool tryGetByamlColor(sead::Color4f *, al::ByamlIter const &, char const *);
    bool tryGetByamlBool(bool *, al::ByamlIter const &,char const *);
    char* getByamlKeyString(al::ByamlIter const &, char const*);
    s32 getByamlKeyInt(al::ByamlIter const &, char const *);
    f32 getByamlKeyFloat(al::ByamlIter const &, char const *);
    bool getByamlKeyBool(al::ByamlIter const &, char const *);
    char* tryGetByamlKeyStringOrNULL(al::ByamlIter const &, char const *);
    s32 tryGetByamlKeyIntOrZero(al::ByamlIter const &, char const *);
    u32 tryGetByamlKeyU32OrZero(al::ByamlIter const &, char const *);
    f32 tryGetByamlKeyFloatOrZero(al::ByamlIter const &, char const *);
    bool tryGetByamlKeyBoolOrFalse(al::ByamlIter const &, char const *);
    bool tryGetByamlIterByKey(al::ByamlIter *, al::ByamlIter const &, char const *);
    bool getByamlIterByKey(al::ByamlIter *, al::ByamlIter const &, char const *);
    bool getByamlIterByIndex(al::ByamlIter *, al::ByamlIter const &, s32);
    bool isTypeBoolByIndex(al::ByamlIter const &, s32);
    bool isTypeBoolByKey(al::ByamlIter const &, char const *);
    bool isTypeIntByIndex(al::ByamlIter const &, s32);
    bool isTypeIntByKey(al::ByamlIter const &, char const *);
    bool isTypeFloatByIndex(al::ByamlIter const &, s32);
    bool isTypeFloatByKey(al::ByamlIter const &, char const *);
    bool isTypeStringByIndex(al::ByamlIter const &, s32);
    bool isTypeStringByKey(al::ByamlIter const &, char const *);
    bool isTypeArrayByIndex(al::ByamlIter const &, s32);
    bool isTypeArrayByKey(al::ByamlIter const &, char const *);
    bool isTypeHashByIndex(al::ByamlIter const &, s32);
    bool isTypeHashByKey(al::ByamlIter const &, char const *);
    bool tryGetByamlKeyAndIntByIndex(char const **, s32 *, al::ByamlIter const &, s32);
    u32 getByamlIterDataNum(al::ByamlIter const &);
    void printByamlIter(u8 const *);
    void printByamlIter(al::ByamlIter const &);
};