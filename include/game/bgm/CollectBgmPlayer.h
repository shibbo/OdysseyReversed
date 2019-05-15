/**
 * @file CollectBgmPlayer.h
 * @brief Controls playing the music in the music list that the player has collected.
 */

#pragma once

#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/ISceneObj.h"

class CollectBgmPlayer : public al::ISceneObj
{
public:
    CollectBgmPlayer();

    virtual ~CollectBgmPlayer();

    void init(al::IUseAudioKeeper const *);
    void prepare();
    void start(char const *, char const *);
    void stop(s32);
    bool isPlaying(char const *, char const *) const;

    al::IUseAudioKeeper* mAudioKeeper; // _8
    char* _10;
    char* _18;
    
};