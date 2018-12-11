#pragma once

#include "types.h"
#include "nn/gfx/api.h"
#include "nn/gfx/device.h"

namespace nn
{
    namespace g3d
    {
        typedef void* TextureRef;

        class ResFile
        {
            public:
            bool IsValid(void const *modelSrc);
            void Relocate();
            void Unrelocate();
            nn::g3d::ResFile* ResCast(void *);
            u64 BindTexture(nn::g3d::TextureRef (*)(char const *, void *), void *);
            void ReleaseTexture();
            void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<s32>, nn::gfx::ApiVersion<s32>>> *);
            void Reset();

            u8 _0[0xC4];
        };
    };
};