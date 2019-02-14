/**
 * @file string.h
 * @brief String wrapper classes for al.
 */

#pragma once

#include "sead/string.h"

namespace al
{
    template<int T>
    class StringTmp : public sead::FixedSafeString<T>
    {
    public:
        StringTmp(char const *, ...);

        virtual ~StringTmp();
    };
};