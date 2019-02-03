/**
 * @file task.h
 * @brief Application Task API.
 */

#pragma once

#include "critical.h"
#include "delegate.h"
#include "heap.h"
#include "hostio.h"
#include "string.h"
#include "thread.h"
#include "tree.h"
#include "types.h"

namespace sead
{
    class FaderTaskBase;
    class MethodTreeMgr;
    struct HeapArray;
    class MethodTreeNode;
    class TaskMgr;
    
    struct TaskConstructArg
    {
        u64 _0;
        sead::TaskMgr* taskMgr; // _8
        u64 _10;
    };

    class TaskEvent
    {
    public:
        virtual u64* getRuntimeTypeInfo() const;
    };

    class TaskClassID
    {
    public:
        u64* create(sead::TaskConstructArg const &);

        u32 mTaskType; // _0
        u32 _4; // padding?
        void* _8;

        static u64* sIntTaskCreator;
        static u64* sStringTaskCreator;
    };

    class TaskBase : public sead::IDisposer
    {
    public:
        enum State
        {

        };

        class CreateArg
        {
        public:
            CreateArg();
            CreateArg(sead::TaskClassID const &);

            u64 mTaskType; // _0
            void* _8;
            u8 _10[0xB8-0x10];
        };

        class MgrTaskArg
        {
        public:
            MgrTaskArg(sead::TaskClassID const &);

            u8 _0[0x108];
        };

        class SystemMgrTaskArg
        {
        public:
            SystemMgrTaskArg(sead::TaskClassID const &);

            u8 _0[0xB8];
        };

        class TakeoverArg
        {
        public:
            TakeoverArg(sead::TaskBase *, sead::TaskClassID const &, sead::FaderTaskBase *);
            TakeoverArg(sead::TaskClassID const &, sead::FaderTaskBase *);

            u8 _0[0xB8];
        };

        class PushArg
        {
        public:
            PushArg(sead::TaskBase *, sead::TaskClassID const &, sead::FaderTaskBase *);
            PushArg(sead::TaskClassID const &, sead::FaderTaskBase *);

            u8 _0[0xB8];
        };

        TaskBase(TaskConstructArg const &);
        TaskBase(TaskConstructArg const &, char const *taskName);
        virtual ~TaskBase();

        virtual void pauseCalc(bool) = 0;
        virtual void pauseDraw(bool) = 0;
        virtual void pauseCalcRec(bool) = 0;
        virtual void pauseDrawRec(bool) = 0;
        virtual void pauseCalcChild(bool) = 0;
        virtual void pauseDrawChild(bool) = 0;
        virtual void prepare();
        virtual void enterCommon();
        virtual void enter();
        virtual void exit();
        virtual void onEvent(sead::TaskEvent const &);
        virtual void attachCalcImpl() = 0;
        virtual void attachDrawImpl() = 0;
        virtual void detachCalcImpl() = 0;
        virtual void detachDrawImpl() = 0;
        virtual u64* getCorrespondingMethodTreeMgrTypeInfo() const = 0;
        virtual sead::MethodTreeNode* getMethodTreeNode(s32) = 0;
        virtual void calc();
        virtual void draw();

        bool isDescendantOf(sead::TaskBase *childTask) const;
        void attachCalc();
        void attachDraw();
        void attachCalcDraw();
        void adjustHeap(s32 newHeapSize);
        void adjustHeapWithSlackWithoutLock_(s32 newHeapSize, u32);
        void adjustHeapAll();
        void adjustHeapWithSlack(s32, u32);
        bool requestCreateTask(sead::TaskBase::CreateArg const &);
        u64* createTaskSync(sead::TaskBase::CreateArg const &);
        u64* createChildTaskSync(sead::TaskBase::CreateArg &);
        bool requestTakeover(sead::TaskBase::TakeoverArg const &);
        bool requestTransition(sead::TaskBase *, sead::FaderTaskBase *);
        bool requestPush(sead::TaskBase::PushArg const &);
        void pushSync(sead::TaskBase::PushArg const &);
        bool requestPop();
        void doneDestroy();
        u64* getFramework() const; // might be GameframeworkNX*?
        sead::MethodTreeMgr* getMethodTreeMgr() const;
        bool isConnectable(sead::TaskBase *) const;
        void attachMethodWithCheck(s32, sead::MethodTreeNode *);

        sead::TreeNode mRootTaskNode; // _20
        u64 _40;
        u64 _48; 
        u64* _50;
        u64* _58;
        u32 _60;
        u32 _64;
        u64 _68;
        u64 _70;
        u64 _78;
        u64 _80;
        u8 _88[0xB0-0x88];
        sead::TaskMgr* mTaskMgr; // _B0
        u32 _B8;
        u32 _BC;
        u32 _C0;
        u32 _C4;
        u64 _C8;
    };

    class Task : public sead::TaskBase
    {
    public:
        Task(sead::TaskConstructArg const &);
        Task(sead::TaskConstructArg const &, char const *);
        virtual ~Task();

        virtual void pauseCalc(bool);
        virtual void pauseDraw(bool);
        virtual void pauseCalcRec(bool);
        virtual void pauseDrawRec(bool);
        virtual void pauseCalcChild(bool);
        virtual void pauseDrawChild(bool);

        virtual void attachCalcImpl();
        virtual void attachDrawImpl();
        virtual void detachCalcImpl();
        virtual void detachDrawImpl();
        virtual u64* getCorrespondingMethodTreeMgrTypeInfo();
        virtual sead::MethodTreeNode* getMethodTreeNode(s32);

        virtual void calc();
        virtual void draw();

        sead::MethodTreeNode mCalcMethodTreeNode; // _D0
        u8 _170[0x1C0-0x170];
        u64 _1C0;
        u64 _1C8;
        u64 _1D0;
        u64 _1D8;
        u64 _1E0;
        u64 _1E8;
        u64 _1F0;
        u64 _1F8;
    };

    class CalculateTask : public sead::TaskBase
    {
    public:
        CalculateTask(sead::TaskConstructArg const &);
        CalculateTask(sead::TaskConstructArg const &, char const *);
        virtual ~CalculateTask();

        virtual void pauseCalc(bool);
        virtual void pauseDraw(bool);
        virtual void pauseCalcRec(bool);
        virtual void pauseDrawRec(bool);
        virtual void pauseCalcChild(bool);
        virtual void pauseDrawChild(bool);

        virtual void attachCalcImpl();
        virtual void attachDrawImpl();
        virtual void detachCalcImpl();
        virtual void detachDrawImpl();
        virtual u64* getCorrespondingMethodTreeMgrTypeInfo();
        virtual sead::MethodTreeNode* getMethodTreeNode(s32);

        virtual void calc();

        sead::MethodTreeNode mCalcMethodTreeNode; // _D0
        u64 _150;
        u64 _158;
        u64 _160;
    };

    class FaderTaskBase : public sead::TaskBase
    {
    public:
        FaderTaskBase(sead::TaskConstructArg const &);
        FaderTaskBase(sead::TaskConstructArg const &, char const *);

        sead::TaskBase::CreateArg mCreateArg; // _E0
        u64 _198;
        sead::IDisposer _1A0;
        u64 _1C0;
        u64 _1C8;
        u64 _1D0;
        u64 _1D8;
        u64 _1E0;
        u64 _1E8;
        u64 _1F0;
        u64 _1F8;
        u64 _200;
        u64 _208;
        sead::IDisposer _210;
        sead::TreeNode _230;
        u64 _250;
        u8 _258[0x2A8-0x258];
        sead::IDisposer _2A8;
        sead::TreeNode _2C8;
        u8 _2E8[0x360-0x2E8];
    };

    class TaskMgr : public sead::hostio::Node
    {
    public:
        class InitializeArg
        {
        public:
            InitializeArg(sead::TaskBase::CreateArg const &);

            u32 _0; // init'd to 0x20
            u32 _4; // init'd to 0x1000
            s32 _8; // init'd to -1
            u32 _C;
            sead::TaskBase::CreateArg* mCreateArg; // _10
            u64 _18;
            u64 _20;
        };

        TaskMgr(sead::TaskMgr::InitializeArg const &);

        void doInit_();
        void beginCreateRootTask_();
        static sead::TaskMgr* initialize(sead::TaskMgr::InitializeArg const &);
        void initHostIO();
        void finalize();
        void destroyTaskSync(sead::TaskBase *);
        bool requestCreateTask(sead::TaskBase::CreateArg const &);
        void createHeap_(sead::HeapArray *, sead::TaskBase::CreateArg const &);
        sead::TaskBase* createTaskSync(sead::TaskBase::CreateArg const &);
        sead::TaskClassID* doCreateTask_(sead::TaskBase::CreateArg const &, sead::HeapArray *);
        bool changeTaskState_(sead::TaskBase *, sead::TaskBase::State);
        u32 doRequestCreateTask_(sead::TaskBase::CreateArg const &, sead::DelegateEvent<sead::TaskBase *>::Slot *);
        bool requestTakeover(sead::TaskBase::TakeoverArg const &);
        bool requestTransition(sead::TaskBase *, sead::TaskBase *, sead::FaderTaskBase *);
        bool requestPush(sead::TaskBase::PushArg const &);
        sead::TaskBase* pushSync(sead::TaskBase::PushArg const &);
        bool requestPop(sead::TaskBase *, sead::FaderTaskBase *);
        bool popSync(sead::TaskBase *);
        void doDestroyTask_(sead::TaskBase *);
        bool requestPop(sead::TaskBase *, sead::TaskBase *, sead::FaderTaskBase *);
        void prepare_(sead::Thread *, s64);
        u64* requestDestroyTask(sead::TaskBase *, sead::FaderTaskBase *);
        bool destroyable_(sead::TaskBase *);
        void calcCreation_();
        void calcDestruction_();
        void destroyAllAndCreateRoot();
        sead::TaskBase* findTask(sead::TaskClassID const &);
        void beforeCalc();
        void afterCalc();

        sead::CriticalSection mCritSection; // _8
        u64 _30;
        u64 _38;
        sead::SafeStringBase<char> _40;
        u64 _50;
        u64* _58;
        u8 _60[0x88-0x60];
        sead::FaderTaskBase* _88;
        u8 _90[0x1B8-0x90];
        sead::FaderTaskBase* _1B8;
    };
};

class RootTask : public sead::Task
{
public:
    RootTask(sead::TaskConstructArg const &);

    u64 _200;
    u64 _208;
    u64 _210;
};