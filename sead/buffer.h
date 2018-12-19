#pragma once

#include "context.h"
#include "color.h"

namespace sead
{
    class DisplayBuffer;

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
};