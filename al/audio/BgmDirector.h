/**
 * @file BgmDirector.h
 * @brief BGM director for managing all BGMs.
 */

#pragma once

#include "types.h"

namespace al
{
    class AudioDirector;
    class AudioSystemInfo;

    class BgmDirector
    {
    public:
        BgmDirector();

        void init(al::AudioSystemInfo const *, al::AudioDirector const *, al::BgmDirectorInitInfo const&, char const *, s32);
        void setDependentModule(al::BgmDirector *);
        void reset(char const *, s32);
        void update();
        void clearPlayData();
        void enableLineChange();
        void finalize();
        void startBgm(al::BgmPlayingRequest const &, bool);
        void prepareBgm(al::BgmPlayingRequest const &);
        void stopBgm(char const *, s32);
        void endSituation(char const *, bool, bool);
        void pauseBgm(char const *, s32);
        void resumeBgm(char const *, s32);
        bool isPlayingBgm();
        bool isPlayingBgm(char const *);
        bool isRunningBgm(char const *);
        void pauseBgmById(u32, s32, bool);
        void updatePauseIdForPause(u32);
        void pauseBgmIfFadeOut(s32);
        void resumeBgmById(u32, s32, bool);
        void updatePauseIdForResume(u32);
        void resumeBgmIfFadeOut(s32);
        void stopAllBgm(s32, bool);
        void stopAllBgmWithoutUpperLayer(s32);

        u64* _18; // al::BgmLineKeeper*
        u32 _20;
        u32 _24;
        u32 _28;
        u32 _2C;
        u64 _30;
        u64 _38;
        u64* _40; // al::BgmDirector*
        u64* _48; // al::BgmSituationDirector*
        u64* _50; // al::Bgm3DParamsController*
        u64* _58;
        u64* _60; // al::BgmRhythmSyncDirector*
        u64 _68;
    };

    struct BgmDirectorInitInfo
    {
        u8 _0;
        u8 _1;
        u8 _2;
        u8 _3;
        u64 _8;
    };

    struct BgmPlayingRequest
    {
        char* bgmName; // _0
        u64 _8;
        u64 _10;
        s32 _18;
        s32 _1C;
        s32 _20;
        u64 _24;
        u32 _2C;
    };
};