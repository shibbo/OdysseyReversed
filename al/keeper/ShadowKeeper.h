/**
 * @file ShadowKeeper.h
 * @brief Keeper for an actors' shadow, for cube maps and lighting.
 */

#pragma once

#include "types.h"

namespace al
{
    class GraphicsSystemInfo;

    class ShadowKeeper
    {
    public:
        ShadowKeeper();

        void initAfterPlacement(al::GraphicsSystemInfo *);
        void update();
        bool isHide() const;
        void hide();
        void show();

        u64* _0; // al::ShadowMaskCtrl*
        u64* _8; // al::DepthShadowMapCtrl*
    };
}