/**
 * @file ResFile.h
 * @brief Resource file for models.
 */

#pragma once

#include "types.h"
#include "nn/gfx/api.h"
#include "nn/gfx/device.h"
#include "nn/gfx/memory.h"

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
            void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *);
            void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>,nn::gfx::ApiVersion<8>>> *, nn::gfx::TMemoryPool<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *, s64, u64);
            void Cleanup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *);
            void Reset();

            u8 _0[0xC4];
        };
    };
};