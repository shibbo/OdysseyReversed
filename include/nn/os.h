/**
 * @file os.h
 * @brief Operating System implementations.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace os
    {
        typedef u64* ThreadType;
        typedef u64 Tick;
        typedef u64 LightEventType;
        
        struct MessageQueueType;
        struct SystemEvent;
        struct SystemEventType;
        struct UserExceptionInfo;

        // MEMORY
        void InitializeVirtualAddressMemory();
        Result AllocateAddressRegion(u64 *, u64);
        Result AllocateMemory(u64 *, u64);
        Result AllocateMemoryPages(u64, u64);
        void AllocateMemoryBlock(u64 *, u64);
        void FreeMemoryBlock(u64, u64);

        // MUTEX
        struct MutexType
        {
            u8 curState; // _0
            bool isRecursiveMutex; // _1
            s32 lockLevel; // _2
            u8 _6[0x20-0x6];
        };

        void InitializeMutex(nn::os::MutexType *, bool, s32);
        void FinalizeMutex(nn::os::MutexType *);
        void LockMutex(nn::os::MutexType *);
        bool TryLockMutex(nn::os::MutexType *);
        void UnlockMutex(nn::os::MutexType *);
        bool IsMutexLockedByCurrentThread(nn::os::MutexType const *);

        // QUEUE
        void InitializeMessageQueue(nn::os::MessageQueueType *, u64 *buf, u64 queueCount);
        void FinalizeMessageQueue(nn::os::MessageQueueType *);
        bool TrySendMessageQueue(MessageQueueType* queue, u64* d);
        void SendMessageQueue(MessageQueueType* queue, u64* d);
        bool TryReceiveMessageQueue(u64* out, MessageQueueType* queue);
        void ReceiveMessageQueue(u64* out, MessageQueueType* queue);
        bool TryPeekMessageQueue(u64 *, nn::os::MessageQueueType const *);
        void PeekMessageQueue(u64 *, nn::os::MessageQueueType const *);
        bool TryJamMessageQueue(nn::os::MessageQueueType *, u64);
        void JamMessageQueue(nn::os::MessageQueueType *, u64);

        // THREAD
        Result CreateThread(nn::os::ThreadType *, void (*)(void *), void *arg, void *srcStack, u64 stackSize, s32 priority, s32 coreNum);
        void DestroyThread(nn::os::ThreadType *);
        void StartThread(nn::os::ThreadType *);
        void SetThreadName(nn::os::ThreadType *, char const *threadName);
        void SetThreadNamePointer(nn::os::ThreadType *, char const *);
        char* GetThreadNamePointer(nn::os::ThreadType const *);
        nn::os::ThreadType* GetCurrentThread();
        s32 ChangeThreadPriority(nn::os::ThreadType *thread, s32 priority);
        s32 GetThreadPriority(nn::os::ThreadType const *thread);
        void YieldThread();
        void SuspendThread(nn::os::ThreadType *);
        void ResumeThread(nn::os::ThreadType *);

        // OTHER
        void GenerateRandomBytes(void *, u64);
        nn::os::Tick GetSystemTick();
        u64 GetThreadAvailableCoreMask();
        void SetMemoryHeapSize(u64 size);
    };
};