/**
 * @file heap.h
 * @brief Standard heaps.
 */

#pragma once

#include "hostio.h"
#include "list.h"
#include "tick.h"
#include "types.h"
#include "runtime.h"
#include "string.h"

namespace sead
{
    class Arena;
    class CriticalSection;
    class Heap;

    class IDisposer
    {
    public:

        enum HeapNullOption
        {
            UNKNOWN_0 = 0,
            UNKNOWN_1 = 1,
            UNKNOWN_2 = 2,
            UNKNOWN_3 = 3
        };

        IDisposer();
        IDisposer(sead::Heap *heap, sead::IDisposer::HeapNullOption nullOption);

        virtual ~IDisposer();

        sead::Heap* mHeapPtr; // _8
        u64 _10;
        u64 _18;
    };

    class Heap : public sead::IDisposer
    {
    public:

        enum HeapDirection
        {
            HEAD = 0,
            TAIL = 1
        };

        Heap(sead::SafeStringBase<char> const &, sead::Heap *, void *src, u64 srcSize, sead::Heap::HeapDirection, bool);
        
        virtual ~Heap();
        virtual s32 checkDerivedRuntimeTypeInfo(u32 *);
        virtual u32* getRuntimeTypeInfo();
        virtual void destroy() = 0;
        virtual void adjust() = 0;
        virtual void* tryAlloc(u64, s32) = 0;
        virtual void free(void *) = 0;
        virtual void resizeFront(void *, u64) = 0;
        virtual void resizeBack(void *, u64) = 0;
        virtual void tryRealloc(void *, u64, s32);
        virtual void freeAll() = 0;
        virtual u64 getStartAddress() const = 0;
        virtual u64 getEndAddress() const = 0;
        virtual u64 getSize() const = 0;
        virtual u64 getFreeSize() const = 0;
        virtual u64 getMaxAllocatableSize(s32) const = 0;
        virtual bool isInclude(void const *) const = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFreeable() const = 0;
        virtual bool isResizeable() const = 0;
        virtual bool isAdjustable() const = 0;
        virtual void dump();
        // virtual void dumpYAML(sead::WriteStream &, int);
        virtual void makeMetaString_(sead::BufferedSafeStringBase<char> *);
        virtual void pushBackChild_(sead::Heap *);

        void destruct_();
        void dispose_(void const *, void const *);
        void eraseChild_(sead::Heap *);
        void appendDisposer_(sead::IDisposer *);
        void removeDisposer_(sead::IDisposer *);
        sead::Heap* findContainHeap_(void const *);
        void checkAccessThread_();
        //void dumpTreeYAML(sead::WriteStream &, s32);

        u64* _20;
        u64* _28;
        u64* _30;
        u64 mStartAddr; // _38
        u64 mSize; // _40
        sead::Heap* mHeap; // _48
        sead::ListNode mRootNode; // _50
        u32 mChildHeapCount; // _60
        sead::ListNode* mChildHeaps; // _64
        u32 _6C;
        u64 _70;
        sead::ListNode* mDisposers; // _78
        u64* _80;
        u32 mNumDisposers; // _88
        u32 _8C;
        u32 mNodeInsertionDirection; // _90
        u32 _94;
        u8 _98[0xD8-0x98]; // critical section
        u16 _D8;
        u16 _DA;
        u32 mBlockSize; // _DC
    };

    class ExpHeap : public sead::Heap
    {
    public:
        enum FindFreeBlockMode
        {
            BlockMode_Auto = 0,
            BlockMode_FromFreeList = 1,
            BlockMode_IterateMemBlock = 2
        };

        enum FindMode
        {

        };

        ExpHeap(sead::SafeStringBase<char> const &, sead::Heap *, void *src, u64 srcSize, sead::Heap::HeapDirection, bool);

        virtual ~ExpHeap();
        virtual s32 checkDerivedRuntimeTypeInfo(u32 *);
        virtual u32* getRuntimeTypeInfo();
        virtual void destroy() = 0;
        virtual void adjust() = 0;
        virtual void* tryAlloc(u64, s32) = 0;
        virtual void free(void *) = 0;
        virtual void resizeFront(void *, u64) = 0;
        virtual void resizeBack(void *, u64) = 0;
        virtual void tryRealloc(void *, u64, s32);
        virtual void freeAll() = 0;
        virtual u64 getStartAddress() const = 0;
        virtual u64 getEndAddress() const = 0;
        virtual u64 getSize() const = 0;
        virtual u64 getFreeSize() const = 0;
        virtual u64 getMaxAllocatableSize(s32) const = 0;
        virtual bool isInclude(void const *) const = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFreeable() const = 0;
        virtual bool isResizeable() const = 0;
        virtual bool isAdjustable() const = 0;
        virtual void dump();
        // virtual void dumpYAML(sead::WriteStream &, int);

        void destruct_();
        void dispose_(void const *, void const *);
        void eraseChild_(sead::Heap *);
        void appendDisposer_(sead::IDisposer *);
        void removeDisposer_(sead::IDisposer *);
        sead::Heap* findContainHeap_(void const *);
        void pushBackChild_(sead::Heap *);
        void checkAccessThread_();
        //void dumpTreeYAML(sead::WriteStream &, s32);
        virtual u64 destroyAndGetAllocatableSize(s32);
        virtual void setFindFreeBlockMode(sead::ExpHeap::FindFreeBlockMode);

        static sead::ExpHeap* create(u64, sead::SafeStringBase<char> const &, sead::Heap *, s32, sead::Heap::HeapDirection, bool);
        static sead::ExpHeap* tryCreate(void *, u64, sead::SafeStringBase<char> const &, bool);
        u64 freeAndGetAllocatableSize(void *, s32);
        u64 adjustBack_();
        u64 adjustFront_();
        u64* findLastMemBlockIfFree_(); // most likely sead::MemBlock*
        u64* findFirstMemBlockIfFree_(); // ^^
        u64* allocFromHead_(u64);
        u64* allocFromHead(u64, s32);
        u64* allocFromTail_(u64);
        u64* allocFromTail_(u64, s32);
        u64* findFreeMemBlockFromHead_(u64, sead::ExpHeap::FindMode) const;
        u64* findFreeMemBlockFromHead_(u64, s32, sead::ExpHeap::FindMode) const;
        u64* findFreeMemBlockFromTail_(u64, sead::ExpHeap::FindMode) const;
        u64* findFreeMemBlockFromTail_(u64, s32, sead::ExpHeap::FindMode) const;
        
        u64 _E0;
        u64 _E8;
        s32 mFreeListSize; // _F0
        u64 _F4;
        s32 mUseListSize; // _108
        u32 _10C;
    };
    
    class FrameHeap : public sead::Heap
    {
    public:
        struct State
        {
            void* src; // _0
            u64* tailPtr; // _8
        };

        FrameHeap(sead::SafeStringBase<char> const &, sead::Heap *, void *src, u64 srcSize, sead::Heap::HeapDirection, bool);

        virtual ~FrameHeap();
        virtual s32 checkDerivedRuntimeTypeInfo(u32 *);
        virtual u32* getRuntimeTypeInfo();
        virtual void destroy();
        virtual void adjust();
        virtual void* tryAlloc(u64, s32);
        virtual void free(void *);
        virtual void resizeFront(void *, u64);
        virtual void resizeBack(void *, u64);
        virtual void freeAll();
        virtual u64 getStartAddress() const;
        virtual u64 getEndAddress() const;
        virtual u64 getSize() const;
        virtual u64 getFreeSize() const;
        virtual u64 getMaxAllocatableSize(s32) const;
        virtual bool isInclude(void const *) const;
        virtual bool isEmpty() const;
        virtual bool isFreeable() const;
        virtual bool isResizeable() const;
        virtual bool isAdjustable() const;
        virtual void dump();
        // virtual void dumpYAML(sead::WriteStream &, int);

        static sead::FrameHeap* create(u64, sead::SafeStringBase<char> const &, sead::Heap *, s32, sead::Heap::HeapDirection, bool);
        void restoreState(sead::FrameHeap::State const &);

        u64 mHeadPtr; // _E0
        u64 mTailPtr; // _E8
    };

    class UnitHeap : public sead::Heap
    {
    public:
        UnitHeap(sead::SafeStringBase<char> const &, sead::Heap *, void *, u64, u32, bool);

        virtual ~UnitHeap();
        virtual s32 checkDerivedRuntimeTypeInfo(u32 *);
        virtual u32* getRuntimeTypeInfo();
        virtual void destroy();
        virtual void adjust();
        virtual void* tryAlloc(u64, s32);
        virtual void free(void *);
        virtual void resizeFront(void *, u64);
        virtual void resizeBack(void *, u64);
        virtual void freeAll();
        virtual u64 getStartAddress() const;
        virtual u64 getEndAddress() const;
        virtual u64 getSize() const;
        virtual u64 getFreeSize() const;
        virtual u64 getMaxAllocatableSize(s32) const;
        virtual bool isInclude(void const *) const;
        virtual bool isEmpty() const;
        virtual bool isFreeable() const;
        virtual bool isResizeable() const;
        virtual bool isAdjustable() const;
        virtual void dump();
        // virtual void dumpYAML(sead::WriteStream &, int);
        virtual void genInformation_(sead::hostio::Context *);

        u64 mAreaStart; // _E0
        u64 mAreaSize; // _E8
        u64 mFreeSize; // _F0
        u64 _F8;
        u64 _100;
    };

    class HeapMgr : public sead::hostio::Node
    {
    public:
        HeapMgr();

        virtual ~HeapMgr();

        static void initialize(u64);
        static void initializeImpl_();
        static void initialize(sead::Arena *);
        void createRootHeap_();
        void destroy();
        void initHostIO();
        sead::Heap* getCurrentHeap() const;
        sead::Heap* findContainHeap(void const *);
        bool isContainedInAnyHeap(void const *);
        //void dumpTreeYAML(sead::WriteStream &, int);
        void setAllocFromNotSeadThreadHeap(sead::Heap *);
        void removeFromFindContainHeapCache_(sead::Heap *);
        sead::Heap* setCurrentHeap_(sead::Heap *);

        sead::Heap* mHeap; // _8
        u64 _10;

        static u32 sHeapCheckTag;
        static sead::CriticalSection* sHeapTreeLockCS;
        static sead::HeapMgr* sInstance;
        static sead::HeapMgr* sInstancePtr;
        static sead::Heap* sRootHeaps;
        static sead::Arena* sArena;
        static sead::Arena* sDefaultArena;
        static s64 sSleepSpanAtRemoveCacheFailure;
    };

    class FindContainHeapCache
    {
    public:
        FindContainHeapCache();

        bool tryRemoveHeap(sead::Heap *);

        sead::Heap* _0;
    };
};