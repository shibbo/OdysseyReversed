/**
 * @file mutex.cpp
 * @brief Mutex implementation using OS mutex types.
 */

#include "sead/mutex.h"

namespace sead
{
    Mutex::Mutex() : IDisposer()
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    Mutex::Mutex(sead::Heap *heap) : IDisposer(heap, IDisposer::HeapNullOption::UNKNOWN_1)
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    Mutex::Mutex(sead::Heap *heap, IDisposer::HeapNullOption nullOption) : IDisposer(heap, nullOption)
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    Mutex::~Mutex()
    {
        nn::os::FinalizeMutex(&this->mMutexType);
        delete this;
    }

    void Mutex::lock()
    {
        nn::os::LockMutex(&this->mMutexType);
    }

    bool Mutex::tryLock()
    {
        return nn::os::TryLockMutex(&this->mMutexType);
    }

    void Mutex::unlock()
    {
        nn::os::UnlockMutex(&this->mMutexType);
    }
};