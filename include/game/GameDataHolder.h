/**
 * @file GameDataHolder.h
 * @brief Holds scenario / game data.
 */

#pragma once

#include "al/MessageSystem.h"
#include "al/PlacementId.h"
#include "al/Scene.h"
#include "game/GameDataFile.h"
#include "game/config/GameConfigData.h"
#include "sead/heap.h"
#include "sead/string.h"

class GameDataHolder : public al::ISceneObj
{
public:
    GameDataHolder(al::MessageSystem const *);
    GameDataHolder();

    virtual ~GameDataHolder();

    virtual char* getSceneObjName() const;
    virtual al::MessageSystem* getMessageSystem() const;

    void setPlayingFileId(s32 file);
    void intitalizeData();
    void initialzeDataCommon();
    void resetTempSaveData(bool);
    void initializeDataId(s32);
    void readByamlData(s32, char const *);
    s32 tryFindEmptyFileId() const;

    bool isRequireSave() const;
    void setRequireSave();
    void setRequireSaveFalse();
    void setRequireSaveFrame();
    void updateRequireSaveFrame();
    bool isInvalidSaveForMoonGet() const;
    void invalidateSaveForMoonGet();
    void validateSaveForMoonGet();
    void setLanguage(char const *);
    char* getLanguage() const;

    void resetLocationName();
    void changeNextStageWithDemoWorldWarp(char const *);
    bool tryChangeNextStageWithWorldWarpHole(char const *);
    void returnPrevStage();
    char* getNextStageName() const;
    char* getNextStageName(s32 idx) const;
    GameDataFile* getGameDataFile(s32 idx) const;
    u64 getNextPlayerStartId() const;
    char* getCurrentStageName() const;
    char* tryGetCurrentStageName() const;
    char* getCurrentStageName(s32 idx) const;
    void setCheckpointId(al::PlacementId const *);
    char* tryGetRestartPointIdString() const;
    void endStage();
    void startStage(char const *, s32);
    void onObjNoWriteSaveData(al::PlacementId const *);
    void offObjNoWriteSaveData(al::PlacementId const *);
    bool isOnObjNoWriteSaveData(al::PlacementId const *) const;
    void onObjNoWriteSaveDataResetMiniGame(al::PlacementId const*);
    void offObjNoWriteSaveDataResetMiniGame(al::PlacementId const *);
    bool isOnObjNoWriteSaveDataResetMiniGame(al::PlacementId const *) const;
    void onObjNoWriteSaveDataInSameScenario(al::PlacementId const *);
    bool isOnObjNoWriteSaveDataInSameScenario(al::PlacementId const *) const;
    void writeTempSaveDataToHash(char const *, bool);

    void resetMiniGameData();
    s32 getPlayingFileId() const;

    s32 findUnlockShineNum(bool *, s32) const;
    s32 calcBeforePhaseWorldNumMax(s32) const;
    bool isFindKoopaNext(s32) const;
    bool isBossAttackedHomeNext(s32) const;
    void playScenarioStartCamera(s32);
    bool isPlayAlreadyScenarioStartCamera() const;

    s32 getShineAnimFrame(s32) const;
    s32 getCoinCollectNumMax(s32) const;

    void readFromSaveDataBufferCommonFileOnlyLanguage();

    u64* _8;
    al::MessageSystem* mMessageSystem; // _10
    GameDataFile* mDataFileArr; // _18
    GameDataFile* _20;
    u64 _28;
    u64 _30;
    u64* _38; // SaveDataAccessSequence*
    u32 _40;
    u32 mRequireSaveFrame; // _44
    bool mIsInvalidSaveForMoonGet; // _48
    bool mChangeStageRelated; // _49
    u8 _4A;
    u8 _4B;
    u32 _4C;
    sead::BufferedSafeStringBase<char> mLanguage; // _50
    u8 _58[0x90-0x60];
    sead::Heap* _90;
    u8 _98[0xB9-0x98];
    u64* _B8; // TempSaveData*
    u8 _C0[0x1A0-0xC0];
    u64* _1A0; // WorldList*
    u8 _1A8[0x228-0x1A8];
    u64* _228; // UniqObjInfo*
};