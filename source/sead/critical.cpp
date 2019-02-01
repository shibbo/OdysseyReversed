#include "sead/critical.h"

namespace sead
{
    CriticalSection::CriticalSection() : IDisposer()
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    CriticalSection::CriticalSection(sead::Heap *heap) : IDisposer(heap, IDisposer::HeapNullOption::UNKNOWN_1)
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    CriticalSection::CriticalSection(sead::Heap *heap, IDisposer::HeapNullOption nullOption) : IDisposer(heap, nullOption)
    {
        nn::os::InitializeMutex(&this->mMutexType, 1, 0);
    }

    CriticalSection::~CriticalSection()
    {
        nn::os::FinalizeMutex(&this->mMutexType);
        delete this;
    }

    void CriticalSection::lock()
    {
        nn::os::LockMutex(&this->mMutexType);
    }

    bool CriticalSection::tryLock()
    {
        return nn::os::TryLockMutex(&this->mMutexType);
    }

    void CriticalSection::unlock()
    {
        nn::os::UnlockMutex(&this->mMutexType);
    }
};