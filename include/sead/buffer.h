/**
 * @file buffer.h
 * @brief Basic buffers.
 */

#pragma once

#include "context.h"
#include "runtime.h"
#include "color.h"

namespace sead
{
    class DisplayBuffer;

    template<typename T>
    class Buffer
    {

    };

    class FrameBuffer
    {
    public:
        virtual ~FrameBuffer();
        virtual void copyToDisplayBuffer(sead::DrawContext *, sead::DisplayBuffer const *);
        virtual void clear(sead::DrawContext *, u32, sead::Color4f const &, f32, u32) = 0;
        virtual void clearMRT(sead::DrawContext *, u32, sead::Color4f const &);
        virtual void bindImpl_(sead::DrawContext *) const = 0;

        void bind(sead::DrawContext *);
    };

    class LogicalFrameBuffer
    {
    public:
        virtual ~LogicalFrameBuffer();

        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const *) const;
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const;
    };
};