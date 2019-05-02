/**
 * @file PlayerHolder.h
 * @brief Container for all player instances.
 */

#pragma once

#include "al/LiveActor.h"
#include "types.h"

namespace al
{
    class PadRumbleKeeper;

    class PlayerHolder
    {
    public:
        PlayerHolder(s32 bufSize);

        void clear();
        void registerPlayer(al::LiveActor *, al::PadRumbleKeeper *);
        al::LiveActor* getPlayer(s32) const;
        al::LiveActor* tryGetPlayer(s32) const;
        s32 getPlayerNum() const;
        s32 getBufferSize() const;
        bool isFull() const;
        bool isExistPadRumbleKeeper(s32) const;
        al::PadRumbleKeeper* getPadRumbleKeeper(s32) const;

        al::LiveActor* mPlayerBuffer; // _0
        s32 mBufSize; // _8
        s32 mPlayerNum; // _C
    };
};