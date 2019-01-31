/**
 * @file Config.h
 * @brief Particle configuration.
 */

#pragma once

#include "nn/vfx/Config.h"

namespace sead
{
    namespace ptcl
    {
        class Config : public nn::vfx::Config
        {
        public:
            virtual ~Config();
        };
    };
};