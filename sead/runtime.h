/**
 * @file runtime.h
 * @brief Static Runtime Info for classes.
 */

#pragma once

namespace sead
{
    class RuntimeTypeInfo
    {
    public:
        class Interface;

        template<typename T>
        class Derive
        {
        public:
            virtual bool isDerived(sead::RuntimeTypeInfo::Interface const *) const;
        };
    };
};