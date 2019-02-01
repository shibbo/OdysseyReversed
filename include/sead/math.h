/**
 * @file math.h
 * @brief Simple math operations.
 */

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
        u32 atan2Idx(T, T);

        static u64* cSinCosTbl;
        static u64* cAtanTbl;
        static u64* cExpTbl;
        static u64* cLogTbl;
    };
}