/**
 * @file MoviePlayer.h
 * @brief MP4 player wrapper.
 */

#pragma once

#include "al/iuse/ISceneObj.h"
#include "MovieDecoderPlayer.h"
#include "sead/heap.h"

class MoviePlayer : public sead::IDisposer, public al::ISceneObj
{
public:
    MoviePlayer();

    virtual ~MoviePlayer();

    void update();

    void play(char const *);
    void stop();
    bool isPlay() const;
    bool isDecode() const;
    bool isLooped() const;

    // _20 is the vtable for al::ISceneObj
    MovieDecoderPlayer* mDecoderPlayer; // _28
    u8 _30[0x40-0x30];
    bool mIsDecode; // _40
    u8 _41[0x48-0x41];
};