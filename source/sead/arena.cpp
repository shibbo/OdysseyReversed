/**
 * @file arena.cpp
 * @brief Arena implementation for heaps.
 */

#include "sead/arena.h"

namespace sead
{
    Arena::Arena()
    {
        this->mIsNotFreed = 0;
        this->_0 = 0;
        this->mSize = 0;
    }

    Arena::~Arena()
    {
        return;
    }

    void Arena::initialize(u64 size)
    {
        nn::os::AllocateMemoryBlock((u64*)this, (size + 0x1FFFFF) & 0xFFFFFFFFFFE00000LL);
        this->mSize = size;
    }

    void Arena::destroy()
    {
        if (!this->mIsNotFreed)
        {
            nn::os::FreeMemoryBlock(this->_0, (this->mSize + 0x1FFFFF) & 0xFFFFFFFFFFE00000LL);
        }

        this->mIsNotFreed = 0;
        this->_0 = 0;
        this->mSize = 0;
    }
};