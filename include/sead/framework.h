/**
 * @file framework.h
 * @brief Framework implementation.
 */

#pragma once

#include "color.h"
#include "delegate.h"
#include "hostio.h"
#include "list.h"
#include "nn/os.h"
#include "runtime.h"
#include "string.h"
#include "task.h"
#include "tick.h"
#include "types.h"
#include "vector.h"

class NVNcounterData;

namespace sead
{
    class DisplayBufferNvn;
    class Heap;
    class ProcessMeter;
    class SingleScreenMethodTreeMgr;

    class Framework : public sead::hostio::Node
    {
    public:
        class CreateSystemTaskArg
        {
        public:
            CreateSystemTaskArg();

            u64 _0;
            u64 _8;
            u64 _10;
            u32 _18;
        };

        class InitializeArg
        {
        public:
            InitializeArg();

            u64 _0;
            u64 _8;
        };

        class RunArg
        {
        public:
            RunArg();

            u64 _0;
        };

        enum ProcessPriority
        {

        };

        Framework();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *) const;
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual ~Framework();
        virtual void run(sead::Heap *, sead::TaskBase::CreateArg const &, sead::Framework::RunArg const &);
        virtual void createSystemTasks(sead::TaskBase *, sead::Framework::CreateSystemTaskArg const &);
        virtual u64* getMethodFrameBuffer(s32) const = 0;
        virtual u32 setProcessPriority(sead::Framework::ProcessPriority);
        virtual void reserveReset(void *);
        virtual void initRun_(sead::Heap *);
        virtual void quitRun_(sead::Heap *);
        virtual void runImpl_();
        virtual sead::SingleScreenMethodTreeMgr* createMethodTreeMgr_(sead::Heap *) = 0;
        virtual void procReset_();

        void initialize(sead::Framework::InitializeArg const &);

        u32 _8;
        u32 _C;
        void* _10;
        sead::DelegateEvent<void *>* _18;
        sead::ListNode mNode; // _20
        u32 _30;
        u32 _34;
        sead::TaskMgr* mTaskMgr; // _38
        u64 _40;
        u64 _48;
    };

    class GameFramework : public sead::Framework
    {
    public:
        GameFramework();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *) const;
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual ~GameFramework();

        virtual void createSystemTasks(sead::TaskBase *, sead::Framework::CreateSystemTaskArg const &);
        virtual u64* getMethodFrameBuffer(s32) const = 0;
        virtual void quitRun_(sead::Heap *);
        virtual sead::SingleScreenMethodTreeMgr* createMethodTreeMgr_(sead::Heap *) = 0;

        virtual void createControllerMgr(sead::TaskBase *);
        virtual void createHostIOMgr(sead::TaskBase *, u64 *, sead::Heap *);
        virtual sead::ProcessMeter* createProcessMeter(sead::TaskBase *);
        virtual void createSeadMenuMgr(sead::TaskBase *);
        virtual void createInfLoopChecker(sead::TaskBase *, sead::TickSpan const &, s32);
        virtual void createCuckooClock(sead::TaskBase *);
        virtual f32 calcFps() = 0;
        virtual void saveScreenShot(sead::SafeStringBase<char> const &);
        virtual bool isScreenShotBusy() const;
        virtual void waitStartDisplayLoop_();
        virtual void initHostIO_();

        static void initialize(sead::Framework::InitializeArg const &);

        u32 _50;
        u32 _54;
        u64 _58;
        u64 _60;
        u64 _68;
        u64 _70;
        u64 _78;
        u64 _80;
        u64 _88;
        u64 _90;
        void* mGraphicsContextCtrl; // _98
    };

    class GameFrameworkNx : public sead::GameFramework
    {
    public:
        struct CreateArg
        {
            s32 presentInterval; // _0
            sead::Color4f _4;
            sead::Color4f _C;
            u32 _14;
            u32 _18;
            u8 _1C;
            u8 _1D;
            u8 _1E;
            u8 _1F;
            u32 _20;
            u32 _24;
            u32 _28;
            u32 _2C;
            u32 _30;
            u32 _34;
            u32 _38;
            u32 _3C;
            u32 _40;
            u32 _44;
        };

        GameFrameworkNx();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *) const;
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
        virtual ~GameFrameworkNx();

        virtual u64* getMethodFrameBuffer(s32) const;
        virtual u64* getMethodLogicalFrameBuffer(s32);
        virtual void initRun_(sead::Heap *);
        virtual void runImpl_();
        virtual sead::SingleScreenMethodTreeMgr* createMethodTreeMgr_(sead::Heap *);

        virtual f32 calcFps();

        virtual void setCaption(sead::SafeStringBase<char> const &);
        virtual void mainLoop_();
        virtual void procFrame_();
        virtual void procDraw_();
        virtual void procCalc_();
        virtual void present_();
        virtual void swapBuffer_();
        virtual void clearFrameBuffers_(s32);
        virtual void waitForGpuDone_();
        virtual void setGpuTimeStamp_();
        
        void requestChangeUseGPU(bool);
        void initializeGraphicsSystem(sead::Heap *, sead::Vector2<f32> const &);

        u8 _A0[0xF0-0xA0];
        nn::os::Tick mSysTick; // _F0
        u64 _F8;
        u64 _100;
        u32 _108;
        u32 _10C;
        u32 _110;
        u32 _114;
        u32 _118;
        u32 _11C;
        u64 _120;
        sead::DisplayBufferNvn* mDisplayBuffer; // _128
        u8 _130[0x160-0x130];
        NVNcounterData* mCounterData; // _160
        u8 _168[0x210-0x168];
    };
};