/**
 * @file AudioPlayerMulti.h
 * @brief A regular audio player that supports multi-channel.
 */

#pragma once

#include "types.h"
#include "nn/atk/SoundArchivePlayer.h"
#include "sead/critical.h"

namespace alsd
{
    class AudioSoundDataMgrMulti;
    
    class AudioPlayerMulti : public nn::atk::SoundArchivePlayer
    {
    public:
        AudioPlayerMulti();
        virtual ~AudioPlayerMulti();

        virtual void initialize();
        virtual void finalize();
        virtual void calc();
        virtual u32 getSoundCount();

        void stopAll(s32);

        u64 _2E8;
        u64 _2F0;
        u32 _2F8;
        u32 _2FC;
        u64 _300;
        u32 _308;
        u32 _30C;
        u64 _310;
        u64 _318;
        u64 _320;
        u64 _328;
        alsd::AudioSoundDataMgrMulti* mAudioSoundMgr; // _330
        u64 _338;
        u32 _340;
        u32 _344;
        sead::CriticalSection mCritSection; // _348
    };
};