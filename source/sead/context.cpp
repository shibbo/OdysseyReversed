/**
 * @file context.cpp
 * @brief Drawing contexts for graphics.
 */

#include "sead/context.h"

namespace sead
{
    DrawLockContext::DrawLockContext()
    {
        this->_8 = 0;
        
        this->mContextSection = CriticalSection();
    }

    void DrawLockContext::initialize(sead::Heap *heap)
    {
        return;
    }

    void DrawLockContext::lock()
    {
        this->mContextSection.lock();
    }

    void DrawLockContext::unlock()
    {
        this->mContextSection.unlock();
    }

    void DrawLockContext::genMessage(sead::hostio::Context *context)
    {
        return;
    }
};