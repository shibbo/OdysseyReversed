/**
 * @file graphics.h
 * @brief Graphics implementation for contexts.
 */

#pragma once

#include "context.h"
#include "heap.h"
#include "types.h"

typedef void (*drawContextSetCb)(bool);

namespace sead
{
    class Graphics : public sead::IDisposer
    {
    public:
        Graphics();

        virtual ~Graphics();

        virtual void initializeDrawLockContext(sead::Heap *);

        void initialize(sead::Heap *);
        void lockDrawContext();
        void unlockDrawContext();
        void initHostIO();

        drawContextSetCb _20;
        sead::DrawLockContext* mLockContext; // _28
    };
};