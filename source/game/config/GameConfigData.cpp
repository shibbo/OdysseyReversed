/**
 * @file GameConfigData.cpp
 * @brief Configuration file for basic controls, such as camera and gyro.
 */

#include "al/byaml/util.h"
#include "game/config/GameConfigData.h"

GameConfigData::GameConfigData()
{
    this->mCameraStickSensitivityLevel = -1;
    this->mCameraGyroSensitivity = -1;
    this->mIsValidCameraGyro = 1;
    this->mIsOpenListAdditionalButton = 0;
    this->mIsCameraReverseH = 0;
    this->mIsPadRumble = 1;
    this->mPadRumbleLevel = 0;
    this->mIsEnableBalloonNotice = 1;
}

void GameConfigData::init()
{
    this->mIsValidCameraGyro = 1;
    this->mCameraStickSensitivityLevel = -1;
    this->mIsCameraReverseH = 0;
    this->mCameraGyroSensitivity = -1;
    this->mIsOpenListAdditionalButton = 0;
    this->mIsPadRumble = 1;
    this->mPadRumbleLevel = 0;
    this->mIsEnableBalloonNotice = 1;
}

bool GameConfigData::isCameraReverseInputH() const 
{
    return this->mIsCameraReverseH;
}

void GameConfigData::onCameraReverseInputH()
{
    this->mIsCameraReverseH = 1;
}

void GameConfigData::offCameraReverseInputH()
{
    this->mIsCameraReverseH = 0;
}

bool GameConfigData::isCameraReverseInputV() const 
{
    return this->mIsCameraReverseV;
}

void GameConfigData::onCameraReverseInputV()
{
    this->mIsCameraReverseV = 1;
}

void GameConfigData::offCameraReverseInputV()
{
    this->mIsCameraReverseV = 0;
}

s32 GameConfigData::getCameraStickSensitivityLevel() const
{
    return this->mCameraStickSensitivityLevel;
}

void GameConfigData::setCameraStickSensitivityLevel(s32 level)
{
    this->mCameraStickSensitivityLevel = level;
}

bool GameConfigData::isValidCameraGyro() const 
{
    return this->mIsValidCameraGyro;
}

// todo -- finish getters / setters

void GameConfigData::read(al::ByamlIter const &iter)
{
    al::ByamlIter newIter;

    al::tryGetByamlIterByKey(&newIter, iter, "GameConfigData");
    al::tryGetByamlS32(&this->mCameraStickSensitivityLevel, newIter, "CameraStrickSensitivityLevel");
    al::tryGetByamlBool(&this->mIsCameraReverseH, newIter, "IsCameraReverseInputH");
    al::tryGetByamlBool(&this->mIsCameraReverseV, newIter, "IsCameraReverseInputV");
    al::tryGetByamlBool(&this->mIsValidCameraGyro, newIter, "IsValidCameraGyro");
    al::tryGetByamlS32(&this->mCameraStickSensitivityLevel, newIter, "CameraGyroSensitivityLevel");
    al::tryGetByamlBool(&this->mIsOpenListAdditionalButton, newIter, "IsUseOpenListAdditionalButton");
    al::tryGetByamlBool(&this->mIsPadRumble, newIter, "IsPadRumble");
    al::tryGetByamlS32(&this->mPadRumbleLevel, newIter, "PadRumbleLevel");
    al::tryGetByamlBool(&this->mIsEnableBalloonNotice, newIter, "BalloonNotice");
}