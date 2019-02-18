#pragma once

#include "sead/heap.h"

namespace al
{
    class ShaderHolder
    {
    public:
        static void createInstance(sead::Heap *);
    };
};