/**
 * @file PtclSystem.h
 * @brief Particle system.
 */

#pragma once

#include "Config.h"
#include "nn/vfx/System.h"
#include "types.h"

namespace sead
{
    namespace ptcl
    {
        class PtclSystem : public nn::vfx::System
        {
        public:
            PtclSystem(sead::ptcl::Config const &);

            virtual ~PtclSystem();
            
            u8 _1700[0x2900-0x1700];
        };
    };
};