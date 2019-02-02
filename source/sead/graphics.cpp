/**
 * @file graphics.cpp
 * @brief Graphics implementation for contexts.
 */

#include "sead/graphics.h"

namespace sead
{
    Graphics::Graphics() : IDisposer()
    {
        this->_20 = 0;
        this->mLockContext = 0;
    }

    Graphics::~Graphics()
    {
        return;
    }

    void Graphics::initialize(sead::Heap *heap)
    {
        //void* lockContext = operator new(0x60, heap, 8);
    }

    void Graphics::lockDrawContext()
    {
        if (this->_20)
        {
            this->_20(1);
        }
        else
        {
            this->mLockContext->lock();
        }
    }

    void Graphics::unlockDrawContext()
    {
        if (this->_20)
        {
            this->_20(0);
        }
        else
        {
            this->mLockContext->unlock();
        }
    }

    void Graphics::initHostIO()
    {
        return;
    }

    void Graphics::initializeDrawLockContext(sead::Heap* heap)
    {
        this->mLockContext->initialize(heap);
    }
};