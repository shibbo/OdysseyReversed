/**
 * @file JoyPadAccelPoseAnalyzer.h
 * @brief Check to see if joycons were moved in certain swings (gyro).
 */

#pragma once

#include "types.h"
#include "sead/vector.h"

namespace al
{
    class JoyPadAccelPoseAnalyzer
    {
    public:

        class HistoryInfo
        {
        public:
            HistoryInfo(s32);

            void calcHistory(sead::Vector3<f32> const &, sead::Vector3<f32> const &, f32);

            u32 _10;
            u32 _14;
            u64* _18;
            u64 _20;
            u32 _28;
            u32 _2C;
            u64* _30;
            u32 _38;
            u32 _3C;
            u32 _40;
            u32 _44;
            u64* _48;
            u64 _50;
            u32 _58;
            u32 _5C;
            u64 _60;
            u64 _68;
            u32 _70;
            f32 _74;
            f32 _78;
            f32 _7C;
            u64 _80;
            u32 _88;
            u32 _8C;
        };

        class PoseAxisDir
        {
        public:
            PoseAxisDir(s32);

            void calcHistory(sead::Vector3<f32> const &,sead::Vector3<f32> const &);

            u8 _0[0x98];
        };

        JoyPadAccelPoseAnalyzer();

        void update();
        void setSwingBorder(f32 borderWidth, f32 borderHeight);
        bool isSwingLeftHand() const;
        bool isSwingRightHand() const;
        bool isSwingAnyHand() const;
        bool isSwingDoubleHand() const;
        bool isSwingDoubleHandSameDir() const;
        bool isSwingDoubleHandReverseDir() const;
        bool isSwingDoubleHandReverseInsideDir() const;
        bool isSwingDoubleHandReverseOutsideDir() const;

        s32 _0;
        s32 _4;
        u8 _8;
        u8 _9;
        u16 _A;
        f32 mSwingBoxW; // _C
        f32 mSwingBoxH; // _10
        u32 _14;
        u64 _18;
        u64 _24;
        u64 _2C;
        u64 _34;
        u64 _3C;
        u32 _44;
        JoyPadAccelPoseAnalyzer::HistoryInfo _48;
        JoyPadAccelPoseAnalyzer::HistoryInfo _D8;
        u8 _168;
        u8 _169; // padding
        u8 _16A;
        u8 _16B;
        u32 _16C;
        JoyPadAccelPoseAnalyzer::PoseAxisDir _170;
        JoyPadAccelPoseAnalyzer::PoseAxisDir _208;
        JoyPadAccelPoseAnalyzer::PoseAxisDir _2A0;
        s64 _338;
    };
};