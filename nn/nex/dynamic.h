#pragma once

#include "RootObject.h"

namespace nn
{
    namespace nex
    {
        class DynamicRunTimeInterface : public nn::nex::RootObject
        {
        public:
            DynamicRunTimeInterface();

            virtual ~DynamicRunTimeInterface();

            u64* GetInstance();
        };
    };
};