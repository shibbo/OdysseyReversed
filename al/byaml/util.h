#pragma once

#include "sead/stream.h"
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