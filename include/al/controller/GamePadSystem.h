/**
 * @file GamePadSystem.h
 * @brief Wrapper for the gamepad.
 */

#pragma once

#include "types.h"
#include "sead/string.h"

namespace al
{
    class GamePadSystem
    {
    public:
        GamePadSystem();

        void changeSinglePlayMode();
        bool isDisconnectPlayable() const;
        sead::SafeStringBase<char16_t>* getPadName(u8) const;
        u32 getPadPlayStyle(u8) const;
        void update();
        bool isDisconnectPlayableImpl() const;
        void setDisconnectFrame(s32 frame);
        void setInvalidateDisconnectFrame(s32 frame);
        void setPadName(u8, sead::SafeStringBase<char16_t> const &);
        void changeMultiPlayMode(s32, s32);

        u64 _0;
        u32 _8;
        s32 mDisconectFrame; // _C
        s32 mInvalidDisconnectFrame; // _10
        u32 _14;
        u32 _18;
        u32 _1C;
        u64 _20;
        u64 _28;
    };
};