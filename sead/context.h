#pragma once

#include "types.h"

namespace sead
{
    class DrawContext
    {
    public:
        DrawContext();
        virtual ~DrawContext();

        u32 _8;
        u32 _C;
        u64 _10;
        u8 _18[0xC0-0x18];
        u64 _C0;
        u64 _C8;
        u64 _D0;
        u64 _D8;
        u64 _E0;
        u64 _E8;
    };
};