#pragma once

#include "nn/gfx/api.h"
#include "nn/gfx/buffer.h"

namespace nn
{
    namespace gfx
    {
        namespace detail
        {
            template<typename T>
            class BufferImpl
            {
            public:
                BufferImpl();
                ~BufferImpl();

                void Initialize(nn::gfx::detail::DeviceImpl<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *, nn::gfx::BufferInfo const &);
            };

            template<typename T>
            class CommandBufferImpl
            {
            public:
                CommandBufferImpl();
                ~CommandBufferImpl();

                void Reset();
                void Begin();
                void End();
                void Dispatch(s32, s32, s32);
            };
        };
    };
};