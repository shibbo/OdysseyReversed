#pragma once

#include "types.h"
#include "nn/gfx/api.h"
#include "nn/gfx/device.h"

namespace nn
{
    namespace g3d
    {
        typedef void* TextureRef;
        class ResMaterial
        {
            public:
            u64 BindTexture(nn::g3d::TextureRef (*)(char const *, void *), void *);
            void ForceBindTexture(nn::g3d::TextureRef const &, char const *);
            void ReleaseTexture();
            void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<s32>, nn::gfx::ApiVersion<s32>>> *);
            void Cleanup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<s32>, nn::gfx::ApiVersion<s32>>> *);
            void Reset();
            void Reset(u32);

            u8 _0[0xB4];
        };
    };
};