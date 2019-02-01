/**
 * @file PadRumbleDirector.h
 * @brief Manager for pad rumble.
 */

#pragma once

#include "types.h"
#include "PadRumbleParam.h"
#include "sead/vector.h"

namespace al
{
    class CameraDirector;
    class PlayerHolder;
    class WaveVibrationHolder;

    class PadRumbleDirector
    {
    public:
        PadRumbleDirector(al::PlayerHolder const *, al::CameraDirector const *);

        void setWaveVibrationHolder(al::WaveVibrationHolder *);
        void update();
        void updateInfoListAll();
        void startRumble(char const *, sead::Vector3<f32> const &, al::PadRumbleParam const &, s32);
        void findDeadInfoOneTime();
        void startRumbleNo3D(char const *, al::PadRumbleParam const &, s32);
        void stopPadRumbleOneTime(char const *, s32);
        void startRumbleLoop(char const *, sead::Vector3<f32> const *, al::PadRumbleParam const &, s32);
        void findDeadInfo();
        void startRumbleLoopNo3D(char const *, sead::Vector3<f32> const *, al::PadRumbleParam const &, s32);
        void stopRumbleLoop(char const *, sead::Vector3<f32> const *, s32);
        u64* findInfo(char const *, sead::Vector3<f32> const *, s32);
        bool checkIsAliveRumbleLoop(char const *, sead::Vector3<f32> const *, s32);
        void stopAllRumble();
        void clearAllInfoList();
        void pause();
        void endPause();
        void changeRumbleLoopVolume(char const *, sead::Vector3<f32> const *, f32, f32, s32);
        void updateInfoListLoop();
        void changeRumbleLoopPitch(char const *, sead::Vector3<f32> const *, f32, f32, s32);
        void startRumbleWithVolume(char const *, f32, f32, s32);
        void startRumbleDirectValue(f32, f32, f32, f32, f32, f32, s32);
        void stopRumbleDirectValue(s32);
        void updateInfoListOneTime();
        void testStartPadRumbleWithVolumeNoActor(char const *, f32, f32);

        al::WaveVibrationHolder* mVibrationHolder; // _0
        al::PlayerHolder* mPlayerHolder; // _ 8
        al::CameraDirector* mCameraDirector; // _10
        u64 _18;
        u64 _20;
        u64 _28;
        u32 _30;
        u32 _34;
        u8 _38;
        u8 mIsPaused; // _39
        u8 _3A[0x70-0x3A];
    };
};