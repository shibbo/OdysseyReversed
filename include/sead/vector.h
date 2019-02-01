/**
 * @file vector.h
 * @brief Vector implementation.
 */

#pragma once

namespace sead
{
    template<typename T>
    class Vector2
    {
    public:

        T mX;
        T mY;

        static T zero;
        static T ex;
    };

    template<typename T>
    class Vector3
    {
    public:
        
        T mX;
        T mY;
        T mZ;
    };

    template<typename T>
    class Vector4
    {
    public:
        
        T mX;
        T mY;
        T mZ;
        T mH;
    };
};