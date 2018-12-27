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
            bool isDerived(sead::RuntimeTypeInfo::Interface const *) const;
        };
    };
};