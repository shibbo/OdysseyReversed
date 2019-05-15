/**
 * @file util.h
 * @brief Wrapper functions for a lot of tasks.
 */

#pragma once

#include "al/ActorInitInfo.h"
#include "al/audio/BgmPlayingRequest.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseEffectKeeper.h"
#include "al/camera/CameraTicket.h"
#include "al/iuse/IUseCamera.h"
#include "al/PlacementId.h"
#include "al/PlacementInfo.h"
#include "al/resource.h"
#include "al/iuse/IUseStageSwitch.h"
#include "al/iuse/IUseNerve.h"
#include "nerve/Nerve.h"
#include "sead/heap.h"
#include "sead/quat.h"
#include "sead/string.h"
#include "sead/vector.h"
#include "types.h"

namespace al
{
    // ACTOR
    void calcQuat(sead::Quat<f32> *, al::LiveActor const *);
    //void calcUpDir(sead::Vector3<f32> *out, al::LiveActor const *);
    sead::Vector3<f32>* getGravity(al::LiveActor const *);
    sead::Vector3<f32>* getTrans(al::LiveActor const *);
    void hideModelIfShow(al::LiveActor *);
    void hideShadow(al::LiveActor *);
    void invalidateClipping(al::LiveActor *);
    void invalidateHitSensor(al::LiveActor *, char const *);
    void invalidateShadow(al::LiveActor *);
    bool isActionEnd(al::LiveActor const *);
    bool isExistDitherAnimator(al::LiveActor const *);
    bool isExistModel(al::LiveActor const *);
    bool isInWaterPos(al::LiveActor const *, sead::Vector3<f32> const &);
    void resetQuatPosition(al::LiveActor *, sead::Quat<f32> const &, sead::Vector3<f32> const &);
    void resetPosition(al::LiveActor *, sead::Vector3<f32> const &);
    void setModelAlphaMask(al::LiveActor *, f32);
    void setTrans(al::LiveActor *, sead::Vector3<f32> const &);
    void setVelocityZero(al::LiveActor *);
    void startAction(al::LiveActor *, char const *);
    void startHitReaction(al::LiveActor const *, char const *);
    void stopDitherAnimAutoCtrl(al::LiveActor *);
    bool tryGetArg(bool *, al::ActorInitInfo const &, char const *);
    void validateClipping(al::LiveActor *);

    // AUDIO
    void tryPauseBgmIfLowPriority(al::IUseAudioKeeper const *, char const *, s32);

    // BGM
    void stopBgm(al::IUseAudioKeeper const *, char const *, s32);
    void forceEndBgmSituation(al::IUseAudioKeeper const *, char const *, bool);
    void startBgm(al::IUseAudioKeeper const *, al::BgmPlayingRequest const &, bool, bool);
    void endBgmSituation(al::IUseAudioKeeper const *, char const *, bool);
    void disableBgmSituationChange(al::IUseAudioKeeper const *);
    void forceStartBgmSituation(al::IUseAudioKeeper const *, char const *, bool, bool);

    // CAMERA
    sead::Vector3<f32>* getCameraPos(al::IUseCamera const *, s32);
    void endCamera(al::IUseCamera const *, al::CameraTicket *, s32, bool);
    al::CameraTicket* initProgramableCamera(al::IUseCamera const *, al::ActorInitInfo const &, char const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *);
    al::CameraTicket* initDemoProgramableCamera(al::IUseCamera const *, al::ActorInitInfo const &, char const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *);
    bool isActiveCamera(al::CameraTicket const *);
    bool isActiveCameraInterpole(al::IUseCamera const *, s32);
    void startCamera(al::IUseCamera const * ,al::CameraTicket *, s32);

    // COLLISION
    void invalidateCollisionPartsBySystem(al::LiveActor *);

    // COMPRESSION
    s32 tryCompressByZlib(u8 *, u32 *, u8 const *, u32);
    s32 tryDecompressByZlib(u8 *, u32 *, u8 const*, u32);

    // DISPLAY
    s32 getDisplayWidth();
    s32 getDisplayHeight();
    s32 getSubDisplayWidth();
    s32 getSubDisplayHeight();
    s32 getVirtualDisplayWidth();
    s32 getVirtualDisplayHeight();

    // EFFECT
    void emitEffectCurrentPos(al::IUseEffectKeeper *, char const *);
    void emitEffect(al::IUseEffectKeeper *, char const *, sead::Vector3<f32> const *);
    void tryEmitEffect(al::IUseEffectKeeper *, char const *, sead::Vector3<f32> const *);
    void deleteEffect(al::IUseEffectKeeper *, char const *);
    void tryDeleteEffect(al::IUseEffectKeeper *, char const *);
    void deleteEffectAll(al::IUseEffectKeeper *);
    void tryKillEmitterAndParticleAll(al::IUseEffectKeeper *);
    void onCalcAndDrawEffect(al::IUseEffectKeeper *);
    void offCalcAndDrawEffect(al::IUseEffectKeeper *);
    void forceSetStopCalcAndDraw(al::IUseEffectKeeper *, bool);
    bool isEffectEmitting(al::IUseEffectKeeper const *, char const *);
    void setEffectEmitRatio(al::IUseEffectKeeper *, char const *, f32);
    void setEffectAllScale(al::IUseEffectKeeper *, char const *, sead::Vector3<f32> const &);
    void setEffectEmitterVolumeScale(al::IUseEffectKeeper *, char const *, sead::Vector3<f32> const &);

    // FILE
    void clearFileLoaderEntry();

    // HEAP
    void addNamedHeap(sead::Heap *, char const *name);
    sead::Heap* findNamedHeap(char const *name);
    sead::Heap* getStationedHeap();

    // LANGUAGE
    char* getLanguageString();
    void forceInitLanguage(char const *name);
    void initRegionAndLanguage();

    // MATH
    f32 sign(f32);
    s32 sign(s32);
    f32 cubeRoot(f32);
    f32 easeIn(f32);
    f32 easeOut(f32);
    f32 easeInOut(f32);
    f32 squareIn(f32);
    f32 squareOut(f32);
    f32 powerIn(f32, f32);
    f32 powerOut(f32, f32);
    f32 logarithmIn(f32, f32);
    f32 logarithmOut(f32, f32);
    f32 exponentIn(f32, f32);
    f32 exponentOut(f32, f32);
    f32 hermiteRate(f32, f32, f32);
    f32 calcFourthOrderRate(f32, f32);

    // MODEL
    void showModel(al::LiveActor *);
    void showModelIfHide(al::LiveActor *);
    bool isHideModel(al::LiveActor const *);
    void hideModel(al::LiveActor *);
    void hideModelIfShow(al::LiveActor *);
    bool isExistModel(al::LiveActor *);

    // NERVE
    s32 calcNerveRate(al::IUseNerve const *, s32);
    s32 getNerveStep(al::IUseNerve const *);
    bool isGreaterEqualStep(al::IUseNerve const *, s32);
    bool isFirstStep(al::IUseNerve const *);
    void setNerve(al::IUseNerve *, al::Nerve const *);
    void updateNerveState(al::IUseNerve *);

    // OBJECT
    bool isObjectName(al::ActorInitInfo const &, char const *);
    bool isObjectNameSubStr(al::ActorInitInfo const &, char const *);

    // RESOURCE
    u8* findResourceYaml(al::Resource const *, char const *, char const *);
    al::Resource* findOrCreateResource(sead::SafeStringBase<char> const &, char const *);
    bool tryGetActorInitFileIter(al::ByamlIter *outIter, al::Resource const *actorFile, char const *fileName, char const *);

    // SAVE
    void initSaveDirSync(char const *, u32, u32);
    bool isSuccessSaveDataSequence();
    void readSaveDataSync(char const *, u32, u32);

    // SOUND
    void startSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);
    bool verifySeKeeperNull(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);
    bool tryStartSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);
    void holdSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);
    bool tryHoldSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);

    // STRING
    void copyString(char *, char const *, u32);
    char* getBaseName(char const *);
    bool isEqualString(char const *, char const *);
    bool isEqualString(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);
    bool isEqualStringCase(char const *, char const *);
    bool isEqualStringCase(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);
    void makeLocalizedArchivePath(sead::BufferedSafeStringBase<char> *, sead::SafeStringBase<char> const &);
    void removeExtensionString(char *, u32, char const *);

    // SWITCH
    bool tryOnStageSwitch(al::IUseStageSwitch *, char const* );

    // PLACMENT
    s32 getCountPlacementInfo(al::PlacementInfo const &);
    s32 calcLinkCountClassName(al::PlacementInfo const &, char const *className);
    bool isClassName(al::PlacementInfo const &, char const *);
    void tryGetPlacementId(al::PlacementId *, al::PlacementInfo const &);
    void tryGetPlacementInfoByIndex(al::PlacementInfo *, al::PlacementInfo const &, s32);
    void tryGetPlacementInfoByKey(al::PlacementInfo *, al::PlacementInfo const &, char const *);
    void tryGetPlacementInfoAndKeyNameByIndex(al::PlacementInfo *, char const**, al::PlacementInfo const &, s32);

    // PLAYER
    sead::Vector3<f32>* getPlayerPos(al::LiveActor const *, s32 playerNum);
    bool isPlayerDead(al::LiveActor const *, s32 playerNum);
    bool isPlayerAreaTarget(al::LiveActor const *, s32 playerNum);

    // RESOURCE
    void addResourceCategory(sead::SafeStringBase<char> const &, s32, sead::Heap *);
    void createCategoryResourceAll(sead::SafeStringBase<char> const &);
};