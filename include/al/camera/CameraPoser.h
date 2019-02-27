/**
 * @file CameraPoser.h
 * @brief Base poser class for cameras.
 */

#pragma once

#include "al/byaml/ByamlIter.h"
#include "al/keeper/AudioKeeper.h"
#include "al/keeper/NerveKeeper.h"
#include "al/PlacementInfo.h"
#include "CameraAngleCtrlInfo.h"
#include "CameraAngleSwingInfo.h"
#include "CameraObjectRequestInfo.h"
#include "CameraParamMoveLimit.h"
#include "CameraStartInfo.h"
#include "GyroCameraCtrl.h"
#include "sead/camera.h"
#include "types.h"

namespace al
{
    class CameraTurnInfo;

    // interpole classes are custom named since they are all inlined
    class LocalInterpole
    {
    public:
        inline LocalInterpole();

        s32 _0;
        u64 _4;
        u64 _C;
        u64 _14;
        u32 _1C;
    };
    
    class LookAtInterpole
    {
    public:
        inline LookAtInterpole();

        u64 _0;
        u32 _8;
        f32 _C;
    };

    class EaseOutInterpole
    {
    public:
        inline EaseOutInterpole();

        s32 mStepType; // _0
        u32 _4;
        u8 _8;
    };

    class EndInterpole
    {
    public:
        inline EndInterpole();

        s32 _0;
        s32 mStep; // _4
    };

    class OrthoProjectionParam
    {
    public:
        inline OrthoProjectionParam();

        bool mIsSetOrthoProjectionInfo; // _0
        u8 _1;
        u16 _2;
        f32 mOrthoProjectionNearClipWidth; // _4
        f32 mOrthoProjectionNearClipHeight; // _8
    };

    class CameraPoserFlag
    {
    public:
        CameraPoserFlag();

        void load(al::ByamlIter const &);
        bool isValidKeepPreSelfPoseNextCamera() const;

        u16 _0;
        bool mIsColliderValidated; // _2
        u8 _3;
        bool mIsValidKeepPreSelfPoseNextCameraByParam; // _4
        u8 _5;
        bool mIsInvalidKeepPreSelfPoseNext; // _6
        bool mIsInvalidKeepDistanceNextCamera; // _7
        bool mIsKeepDistanceNextCameraValidated; // _8
        bool mIsCtrlSubjectiveValidated; // _9
        bool mIsInvalidChangeSubjective; // _A
        u8 reserved[0xD-0xB];
        bool mIsPreCameraEndAfterInterpoleValidated; // _D
        u16 reserved1;
    };

    class CameraPoser
    {
    public:
        CameraPoser(char const *name);

        virtual u64* getAreaObjDirector() const;
        virtual void init();
        virtual void initByPlacementObj(al::PlacementInfo const &);
        virtual void endInit();
        virtual void start(al::CameraStartInfo const &);
        virtual void update();
        virtual void end();
        virtual void loadParam(al::ByamlIter const &);
        virtual void makeLookAtCamera(sead::LookAtCamera *) const;
        virtual u32 recieveRequestFromObject(al::CameraObjectRequestInfo const &);
        virtual bool isZooming() const;
        virtual bool isEnableRotateByPad() const;
        virtual void startSnapShotMode();
        virtual void endSnapShotMode();
        virtual char* getName() const;
        virtual u64* getCollisionDirector() const;
        virtual u64* getNerveKeeper() const;
        virtual u64* getAudioKeeper() const;
        virtual u64* getRailRider() const;
        virtual void load(al::ByamlIter const &);
        virtual void movement();
        virtual void calcCameraPose(u64 *) const;
        virtual u32 requestTurnToDirection(al::CameraTurnInfo const *);

        f32 getFovyDegree() const;
        f32 getSceneFovyDegree() const;
        u64* getInputHolder() const; // al::CameraInputHolder*
        u64* getTargetHolder() const; // al::CameraTargetHolder*
        u64* getFlagCtrl() const;
        bool isInterpoleByCameraDistance() const;
        s32 getInterpoleStep() const;
        void setInterpoleStep(s32);
        void resetInterpoleStep();
        bool isInterpoleEaseOut() const;
        void setInterpoleEaseOut();
        bool isEndInterpoleByStep() const;

        u64 _8;
        u64 _10;
        u64 _18;
        u64 _20;
        u64 _28;
        char* mName; // _30
        u32 mState; // _38
        u32 _3C;
        u8 _40[0x60-0x40];
        f32 mFovyDegree; // _60
        u32 _64;
        u8 _68[0x30]; // matrix34
        u8 _98[0xB0-0x98];
        al::CameraPoserFlag* mPoserFlag; // _B0
        u64* _B8; // al::CameraVerticalAbsorber*
        al::CameraAngleCtrlInfo* mAngleCtrlInfo; // _C0
        al::CameraAngleSwingInfo* mSwingInfo; // _C8
        u64* _D0; // al::CameraArrowCollider*
        u64* _D8; // unknown
        al::LocalInterpole* _E0;
        al::LookAtInterpole* _E8;
        al::CameraParamMoveLimit* mParamMoveLimit; // _F0
        u64* _F8; // al::CameraTargetAreaLimitter*
        al::GyroCameraCtrl* mGyroControl; // _100
        u64* _108; // al::SnapShotCameraCtrl*
        al::AudioKeeper* mAudioKeeper; // _110
        al::NerveKeeper* mNerveKeeper; // _118
        u64* _120; // al::RailKeeper*
        al::EaseOutInterpole* _128;
        al::EndInterpole* _130;
        al::OrthoProjectionParam* _138;
    };
};

class alCameraPoserFunction
{
public:
    static void startResetSnapShotCameraCtrl(al::CameraPoser *, s32);
    static void setSnapShotMaxZoomOutFovyDegree(al::CameraPoser *, f32);
    static f32 getSnapShotRollDegree(al::CameraPoser const *);

    static bool isInvalidCollider(al::CameraPoser const *);
    static void validateCollider(al::CameraPoser *);
    static void invalidateCollider(al::CameraPoser *);
};