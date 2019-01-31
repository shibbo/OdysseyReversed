/**
 * @file AudioSoundDataMgrMulti.h
 * @brief A manager for multi-channel audio sound data.
 */

#pragma once

#include "nn/atk/SoundDataManager.h"
#include "sead/heap.h"
#include "sead/string.h"

namespace alsd
{
    class AudioSoundDataMgrMulti : public nn::atk::SoundDataManager
    {
    public:
        AudioSoundDataMgrMulti();
        
        virtual ~AudioSoundDataMgrMulti();

        bool isNwEnabled_() const;
        void setContentRootPath(char const *);
        void mountSoundArchiveFromFs(sead::SafeStringBase<char> const &, sead::Heap *, bool, bool);
        void setupManager_(sead::Heap *);
        void mountSoundArchiveFromMemory(void const *, sead::Heap *);
        void unmountSoundArchive();

        u64 _240;
        u64 _248;
        u64 _250;
        char* mRootPath; // _258
        u32 _260;
        u32 _264; // padding, possibly
    };
};