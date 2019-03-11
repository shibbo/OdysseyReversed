/**
 * @file IUseCamera.h
 * @brief Basic class for a useable camera.
 */

#pragma once

namespace al
{
    class CameraDirector;

    class IUseCamera
    {
    public:
        virtual al::CameraDirector* getCameraDirector() const = 0;
    };
};