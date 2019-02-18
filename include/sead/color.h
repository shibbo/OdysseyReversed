/**
 * @file color.h
 * @brief Color types.
 */

#pragma once

#include "types.h"

namespace sead
{
    class Color4u8
    {
    public:
        void setf(f32, f32, f32, f32);
        void setLerp(sead::Color4u8 const &,sead::Color4u8 const &, f32);
        void setGammaCollection(sead::Color4u8 const &, f32);
        void lerp(sead::Color4u8 const &, sead::Color4u8 const &, f32);
        void operator+=(sead::Color4u8 const &);
        void operator-=(sead::Color4u8 const &);
        void operator*=(sead::Color4u8 const &);
        void operator/=(sead::Color4u8 const &);
        void operator|=(sead::Color4u8 const &);
        void operator&=(sead::Color4u8 const &);
        void operator+=(u8);
        void operator-=(u8);

        u8 r; // _0
        u8 g; // _1
        u8 b; // _2
        u8 a; // _3

        static u32 cBlack;
        static u32 cGrey;
        static u32 cWhite;
        static u32 cRed;
        static u32 cGreen;
        static u32 cBlue;
        static u32 cYellow;
        static u32 cMagenta;
        static u32 cCyan;
    };

    class Color4f
    {
    public:

        void setLerp(sead::Color4f const &, sead::Color4f const &, f32);
        void setGammaCollection(sead::Color4f const &, f32);
        void lerp(sead::Color4f const &, sead::Color4f const &, f32);
        void adjustOverflow();

        void operator+=(sead::Color4f const &);
        void operator-=(sead::Color4f const &);
        void operator*=(sead::Color4f const &);
        void operator/=(sead::Color4f const &);
        void operator|=(sead::Color4f const &);
        void operator&=(sead::Color4f const &);
        void operator+=(f32);
        void operator-=(f32);
        void operator*=(f32);
        void operator/=(f32);

        f32 r; // _0
        f32 g; // _4
        f32 b; // _8
        f32 a; // _C

        static sead::Color4f cBlack;
    };
};