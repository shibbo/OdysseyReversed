#pragma once

#include "types.h"

namespace nn
{
    namespace atk
    {
        namespace detail
        {
            class StreamSoundRuntime
            {
            public:
                StreamSoundRuntime();
                ~StreamSoundRuntime();

                u8 _0[0xB0];
            };
        };
    };
};