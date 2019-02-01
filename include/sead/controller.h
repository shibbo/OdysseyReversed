/**
 * @file controller.h
 * @brief Basic controller / gamepad implementation.
 */

#pragma once

#include "bound.h"
#include "heap.h"
#include "list.h"
#include "array.h"
#include "task.h"
#include "types.h"
#include "vector.h"

namespace sead
{
    class ControllerMgr;
    class TaskMgr;
    
    class ControllerDefine
    {
    public:

        // todo -- do me
        enum AddonId;
        enum ControllerId;
        enum DeviceId;
    };

    class ControllerBase
    {
    public:
        ControllerBase(s32, s32, s32, s32);

        void setPointerWithBound_(bool, bool, sead::Vector2<f32> const &);
        void updateDerivativeParams_(u32, bool);
        u32 getStickHold_(u32, sead::Vector2<f32> const &, f32, f32, s32);
        u32 createStickCrossMask_();
        u32 getPadHoldCount(s32 padID) const;
        void setPadRepeat(u32, u8, u8);
        void setLeftStickCrossThreshold(f32, f32);
        void setRightStickCrossThreshold(f32, f32);
        void setPointerBound(sead::BoundBox2<f32> const &);
        bool isIdleBase_();
        void setIdleBase_();

        u64 _10;
        u64 _18;
        f32 _20;
        u32 _24;
        f32 _28;
        u32 _2C;
        u8 _30[0xF0-0x30];
        f32 mLeftThresholdX; // _F0
        f32 mRightThresholdX; // _F4
        f32 mLeftThresholdY; // _F8
        f32 mRightThresholdY; // _FC
        u32 _100;
        u32 _10C;
        u32 _110;
        u32 _114;
        f32 mBoundX; // _118
        f32 mBoundY; // _11C
        sead::Vector3<f32> _120; // pretty sure that these are tilt axis values
        sead::Vector2<f32> _128;
        sead::Vector2<f32> _130;
    };

    class Controller : public sead::ControllerBase
    {
    public:
        Controller(sead::ControllerMgr *);
        virtual ~Controller();

        virtual void calc();
        virtual bool isConnected() const;
        virtual void calcImpl_() = 0;
        virtual bool isIdle_();
        virtual void setIdle_();

        u32 _138;
        u32 _13C;
        sead::ControllerMgr* mMgr; // _140
        u64 _148;
        u64 _150;
        u32 _158;
        u32 _15C;
        u64 _160;
        u64 _168;
        u32 _170;
        u32 _174;
    };

    class ControllerMgr : public sead::CalculateTask
    {
    public:
        
        class SingletonDisposer_
        {
        public:
            ~SingletonDisposer_();
        };

        ControllerMgr();
        ControllerMgr(sead::TaskConstructArg const &);
        virtual ~ControllerMgr();

        virtual void prepare();
        virtual void calc();

        void setInstance_(sead::TaskBase *);
        void deleteInstance();
        void initializeDefault(sead::Heap *);
        void finalize();
        void finalizeDefault();
        u64* getControlDevice(sead::ControllerDefine::DeviceId) const;
        u64* getControllerByOrder(sead::ControllerDefine::ControllerId, s32) const; // sead::Controller*
        u64* getControllerAddon(s32, sead::ControllerDefine::AddonId) const;
        u64* getControllerAddonByOrder(s32, sead::ControllerDefine::AddonId, s32) const;
        u64* findControllerPort(sead::Controller const *) const;
        u64* getFramework() const;

        u32 mIsInstanceSet; // _168
        u32 _16C; // padding?
        sead::ListNode _170;
        u32 mNumListNodes; // _188
        u32 _184;
        sead::PtrArrayImpl _188;

        static ControllerMgr* sInstance;
    };

    class ControllerAddon
    {
    public:
        virtual ~ControllerAddon();
    };
};