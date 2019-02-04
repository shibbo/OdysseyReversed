/**
 * @file thread.h
 * @brief Thread functionality.
 */

#pragma once

#include "types.h"
#include "nn/os.h"
#include "delegate.h"
#include "heap.h"
#include "hostio.h"
#include "list.h"
#include "string.h"
#include "tick.h"

namespace sead
{
    struct CoreIdMask;

    class Thread : public sead::IDisposer
    {
    public:
        Thread(sead::SafeStringBase<char> const &, sead::Heap *, s32, u32, s64, s32, s32);
        Thread(sead::Heap *, nn::os::ThreadType *, u32);
        virtual ~Thread();
        
        virtual void destory();
        virtual bool sendMessage(s64, u32);
        virtual bool recvMessage(u32);
        virtual u64 getMessageQueue();
        virtual void start();
        virtual void quit(bool);
        virtual void waitDone();
        virtual void quitAndDestroySingleThread(bool);
        virtual void quitAndWaitDoneSingleThread(bool);
        virtual void setPriority(s32);
        virtual s32 getPriority() const;
        virtual u32 getBlockType() const;
        virtual u32 getStackSize() const;
        virtual u32 calcStackUsedSizePeak() const;
        virtual void run_();
        virtual void calc_(s64) = 0; // pure virtual, not implemented here
        virtual u64 getStackCheckStartAddress_() const;

        void ninThreadFunc_(void *);
        void setAffinity(sead::CoreIdMask const &);
        void yield();
        void sleep(sead::TickSpan howLong);
        void checkStackOverFlow(char const *, s32) const;
        void checkStackEndCorruption(char const *, s32);
        void checkStackPointerOverFlow(char const *, s32) const;
        void setStackOverflowExceptionEnable(bool);
        void initStackCheck_();
        void initStackCheckWithCurrentStackPointer_();

        sead::ListNode mNode; // _28
        u32 mNumListNodes; // _38
        u8 _3C[0x88-0x3C]; // sead::MessageQueue
        u32 mStackSize; // _88
        u32 _8C;
        u64 _90;
        u64 _98;
        u64 _A0;
        u64 _A8;
        u64 _B0;
        sead::FindContainHeapCache* mHeapCache; // _B8
        u32 mBlockType; // _C0 sead::MessageQueue::BlockType
        u32 _C4;
        u64 _C8;
        u32 _D0;
        u32 _D4;
        u32 _D8;
        u32 _DC;
        u64 _E0; // nn::os::ThreadType *
        u64 _E8;
        u64 _F0;
        u64 mStackStartAddr; // _F8
    };

    class ThreadMgr
    {
    public:
        class SingletonDisposer_
        {
        public:
            virtual ~SingletonDisposer_();

            static s64 sStaticDisposer;
        };

        ThreadMgr();

        void initialize(sead::Heap *);
        void destroy();
        void destroyMainThread_();
        void initHostIO();
        void quitAndWaitDoneMultipleThread(sead::Thread **, s32, bool);
        void waitDoneMultipleThread(sead::Thread * const *, s32);
        void checkCurrentThreadStackOverFlow(char const *, s32);
        void checkCurrentThreadStackEndCorruption(char const *, s32);
        void checkCurrentThreadStackPointerOverFlow(char const *, s32);
        void createInstance(sead::Heap *);
        void deleteInstance();
        void initMainThread_(sead::Heap *);
        void getCurrentThreadID_();

        sead::ThreadMgr::SingletonDisposer_* mDisposer; // _8
    };

    class MainThread : public sead::Thread
    {
    public:
        virtual ~MainThread();

        virtual void destroy();

        virtual void quit(bool);
        virtual void waitDone();
        virtual void quitAndDestroySingleThread(bool);
        virtual void setPriority(s32);
        virtual void calc_(s64);
    };
    class DelegateThread : public sead::Thread
    {
    public:
        DelegateThread(sead::SafeStringBase<char> const &, sead::IDelegate2<sead::Thread *,s64> *, sead::Heap *, s32, s64, s64, s32, s32);
        virtual ~DelegateThread();

        virtual void calc_(s64);

        sead::IDelegate2<sead::Thread *, s64>* mDelegate; // _100
    };

    class ThreadUtil
    {
    public:
        void ConvertPrioritySeadToPlatform(s32);
        void ConvertPriorityPlatformToSead(s32);
        u64* GetCurrentStackPointer();
    };
};