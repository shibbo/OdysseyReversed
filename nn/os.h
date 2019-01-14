#pragma once

#include "types.h"

namespace nn
{
    namespace os
    {
        typedef u64* MutexType;
        typedef u64* ThreadType;
        typedef u64 Tick;

        struct UserExceptionInfo;

        void InitializeMutex(nn::os::MutexType *, bool, s32);
        void FinalizeMutex(nn::os::MutexType *);
        void LockMutex(nn::os::MutexType *);
        bool TryLockMutex(nn::os::MutexType *);
        void UnlockMutex(nn::os::MutexType *);
        bool IsMutexLockedByCurrentThread(nn::os::MutexType const *);

        void GenerateRandomBytes(void *, u64);
        nn::os::Tick GetSystemTick();
        u64 GetThreadAvailableCoreMask();
        void SetMemoryHeapSize(u64 size);
    };
};