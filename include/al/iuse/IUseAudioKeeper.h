/**
 * @file IUseAudioKeeper.h
 * @brief Basic implementation of an audio keeper.
 */

#pragma once

namespace al
{
    class AudioKeeper;

    class IUseAudioKeeper
    {
    public:
        virtual al::AudioKeeper* getAudioKeeper() const = 0;
    };
};