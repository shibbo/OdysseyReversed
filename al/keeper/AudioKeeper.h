#pragma once

#include "types.h"
#include "al/audio/AudioDirector.h"

namespace al
{
    class AudioKeeper
    {
        public:
        AudioKeeper(al::AudioDirector const *);

        virtual ~AudioKeeper();

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