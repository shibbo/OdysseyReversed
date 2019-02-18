#pragma once

#include "types.h"

namespace nn
{
    namespace util
    {
        class RelocationTable
        {
        public:
            void Relocate();
            void Unrelocate();

            s32 mMagic; // _0
            u32 mPosition; // _4
            s32 mSectionCount; // _8
        };

        class BinaryFileHeader
        {
        public:
            bool IsValid(s64 packedSig, s32 majorVer, s32 minorVer, s32 microVer) const;
            bool IsRelocated() const;
            bool IsEndianReverse() const;
            nn::util::RelocationTable* GetRelocationTable();

            s32 mMagic; // _0
            u32 mSig; // _4
            u8 mVerMicro; // _8
            u8 mVerMinor; // _9
            u16 mVerMajor; // _A
            u16 mBOM; // _C
            u8 mAlignment; // _E
            u8 mTargetAddrSize; // _F
            u32 mFileNameOffset; // _10
            u16 mFlag; // _14
            u16 mFirstBlockOffs; // _16
            u32 mRelocationTableOffs; // _18
            u32 mSize; // _1C
        };
    };

    void ReferSymbol(void const *);
};