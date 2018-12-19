#pragma once

#include "types.h"

namespace agl
{
    namespace driver
    {
        class NVNimage_
        {
            public:
            NVNimage_();
            NVNimage_(agl::driver::NVNimage_ const &);
            ~NVNimage_();

            void updateImageId(s32 id);

            u64 mImageId; // _0
        };
    };
};