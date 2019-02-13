/**
 * @file GameConfigData.h
 * @brief Configuration file for basic controls, such as camera and gyro.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "al/byaml/ByamlWriter.h"

class GameConfigData
{
public:
    GameConfigData();

    virtual void write(al::ByamlWriter *);
    virtual void read(al::ByamlIter const &);

    void init();
    bool isCameraReverseInputH() const;
    void onCameraReverseInputH();
    void offCameraReverseInputH();
    bool isCameraReverseInputV() const;
    void onCameraReverseInputV();
    void offCameraReverseInputV();
    s32 getCameraStickSensitivityLevel() const;
    void setCameraStickSensitivityLevel(s32);
    bool isValidCameraGyro() const;
    void validateCameraGyro();
    void invalidateCameraGyro();
    s32 getCameraGyroSensitivityLevel() const;
    void setCameraGyroSensitivityLevel(s32);
    bool isUseOpenListAdditionalButton() const;
    void onUseOpenListAdditionalButton();
    void offUseOpenListAdditionalButton();
    bool isValidPadRumble() const;
    void validatePadRumble();
    void invalidatePadRumble();
    s32 getPadRumbleLevel() const;
    void setPadRumbleLevel(s32);
    bool isEnableBalloonNotice() const;
    void enableBalloonNotice();
    void disableBalloonNotice();

    s32 mCameraStickSensitivityLevel; // _8
    bool mIsCameraReverseH; // _C
    bool mIsCameraReverseV; // _D
    bool mIsValidCameraGyro; // _E
    u8 _F; // padding
    s32 mCameraGyroSensitivity; // _10
    bool mIsOpenListAdditionalButton; // _14
    bool mIsPadRumble; // _15
    u8 _16; // padding
    u8 _17; // ^^
    s32 mPadRumbleLevel; // _18
    bool mIsEnableBalloonNotice; // _1C
    u8 _1D; // padding
    u8 _1E; // ^^
    u8 _1F; // ^^
};