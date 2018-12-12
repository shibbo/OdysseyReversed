#pragma once

namespace sead
{
    template<typename T>
    class MathCalcCommon
    {
        public:
        T gcd(T, T);
        T lcm(T, T);
        // the following are reserved for a FLOAT template only
        u32 atanIdx_(T);
        T expTable(T);
        T logTable(T);
    };
}