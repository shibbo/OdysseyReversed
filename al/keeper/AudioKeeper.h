/**
 * @file AudioKeeper.h
 * @brief Keeper for audio.
 */

#pragma once

#include "types.h"
#include "al/audio/AudioDirector.h"
#include "sead/vector.h"
#include "sead/matrix.h"

namespace al
{
    class CameraDirector;
    class ModelKeeper;

    class AudioKeeper
    {
    public:
        AudioKeeper(al::AudioDirector const *);

        virtual ~AudioKeeper();

        void initSeKeeper(al::AudioDirector const *, char const *, sead::Vector3<f32> const *, sead::Matrix34<f32> const *, al::ModelKeeper const *, al::CameraDirector *);
        void initBgmKeeper(al::AudioDirector const *, char const *);
        void validate();
        void invalidate();
        void startClipped();
        void endClipped();
        void appear();
        void kill();

        u64 _0;
        u64 _8;
        u64 _10;
        u64 _18;
        u64* _20; // al::SeKeeper*
    };
};

class alAudioKeeperFunction
{
    void createAudioKeeper(al::AudioDirector const *);
    void createAudioKeeper(al::AudioDirector const *, char const *, char const *);
};