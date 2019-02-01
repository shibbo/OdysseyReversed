/**
 * @file Parameter.h
 * @brief Parameter template for a attribute in an actor.
 */

#pragma once

namespace al
{
    template<typename T>
    class Parameter
    {
    public:
        T* ptr() const;
        u32 size() const;
        char* getParamTypeStr() const;
        u64 getParamType() const;
    };

};