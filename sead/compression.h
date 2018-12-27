#pragma once

#include "resource.h"

namespace sead
{
    class Decompressor : public sead::IDisposer
    {
    public:
        virtual ~Decompressor();

        virtual void* tryDecompFromDevice(u32 const &rsrcMgrLoadArg, sead::Resource *, u32 *, u32 *, bool *) = 0;
    };

    class SZSDecompressor : public sead::Decompressor
    {
    public:

        class DecompContext
        {
        public:
            DecompContext();
            DecompContext(void *src);

            void Initialize(void *src);

            void* mSrc; // _0
            u64 _8;
            u16 _10;
            u16 _12;
            u16 _14;
            u16 _18;
            u16 _1A;
        };

        SZSDecompressor(u32, u8 *);
        virtual ~SZSDecompressor();

        virtual void* tryDecompFromDevice(u32 const &rsrcMgrLoadArg, sead::Resource *, u32 *, u32 *, bool *);

        u32 getDecompSize(void const *); // arg unused
        u32 getDecompAlignment(void const *); // ^
        static u32 readHeader_(sead::SZSDecompressor::DecompContext *context, u8 const *, u32);
        static u32 streamDecomp(sead::SZSDecompressor::DecompContext *context, void const *, u32);
        static u32 decomp(void *, u32, void const *, u32);

        u64 _20; 
        u64 _28;
        u64 _30;
        u64 _38;
        u64 _40;
        u64 _48;
        u64 _50;
        u64 _58;
        u64 _60;
        u64 _68;
        u64 _70;
        u64 _78;
        u64 _80;
    };
};