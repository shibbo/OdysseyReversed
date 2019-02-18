/**
 * @file util.h
 * @brief Wrapper functions for a lot of tasks.
 */

#pragma once

#include "al/ActorInitInfo.h"
#include "al/audio/IUseAudioKeeper.h"
#include "al/camera/CameraTicket.h"
#include "al/camera/IUseCamera.h"
#include "al/PlacementId.h"
#include "al/PlacementInfo.h"
#include "al/switch/IUseStageSwitch.h"
#include "nerve/IUseNerve.h"
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

    // CAMERA
    sead::Vector3<f32>* getCameraPos(al::IUseCamera const *, s32);
    void endCamera(al::IUseCamera const *, al::CameraTicket *, s32, bool);
    al::CameraTicket* initProgramableCamera(al::IUseCamera const *, al::ActorInitInfo const &, char const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *);
    al::CameraTicket* initDemoProgramableCamera(al::IUseCamera const *, al::ActorInitInfo const &, char const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *, sead::Vector3<f32> const *);
    bool isActiveCamera(al::CameraTicket const *);
    bool isActiveCameraInterpole(al::IUseCamera const *, s32);
    void startCamera(al::IUseCamera const * ,al::CameraTicket *, s32);

    // DISPLAY
    s32 getDisplayWidth();
    s32 getDisplayHeight();
    s32 getSubDisplayWidth();
    s32 getSubDisplayHeight();
    s32 getVirtualDisplayWidth();
    s32 getVirtualDisplayHeight();

    // HEAP
    void addNamedHeap(sead::Heap *, char const *name);
    sead::Heap* findNamedHeap(char const *name);
    sead::Heap* getStationedHeap();

    // LANGUAGE
    char* getLanguageString();
    void forceInitLanguage(char const *name);
    void initRegionAndLanguage();

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

    // SAVE
    void initSaveDirSync(char const *, u32, u32);
    bool isSuccessSaveDataSequence();
    void readSaveDataSync(char const *, u32, u32);

    // STRING
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

    // RESOURCE
    void addResourceCategory(sead::SafeStringBase<char> const &, s32, sead::Heap *);
    void createCategoryResourceAll(sead::SafeStringBase<char> const &);
};