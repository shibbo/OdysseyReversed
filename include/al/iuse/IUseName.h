/**
 * @file IUseName.h
 * @brief Basic implementation for an actor that stores a name.
 */

#pragma once

namespace al
{
    class IUseName
    {
    public:
        virtual char* getName() const = 0;
    };
}