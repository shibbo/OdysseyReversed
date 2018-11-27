#pragma once

#include "types.h"

namespace al
{
    class KCollisionServer
    {
        public:
        KCollisionServer();

        void initKCollisionServer(void *, void const *byamlSrc);
        void setData(void *);

        u64* _18; // al::ByamlIter*
    };
};