/**
 * @file GameFrameworkNx.h
 * @brief AL implementation of the NX framework.
 */

#pragma once

#include "sead/framework.h"
#include "sead/heap.h"
#include "sead/vector.h"

namespace al
{
    class GameFrameworkNx : public sead::GameFrameworkNx
    {
    public:
        GameFrameworkNx(sead::GameFrameworkNx::CreateArg const &);

        virtual ~GameFrameworkNx();

        virtual u64* getMethodFrameBuffer(s32);
        virtual sead::SingleScreenMethodTreeMgr* createMethodTreeMgr_(sead::Heap *);
        virtual f32 calcFps();

        void initAgl(sead::Heap *, s32 displayWidth, s32 displayHeight, s32, s32, s32, s32);
    };
};