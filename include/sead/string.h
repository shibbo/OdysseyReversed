/**
 * @file string.h
 * @brief Protected String classes.
 */

#pragma once

#include "types.h"

namespace sead
{
    class Heap;
	
    template<typename T>
    class SafeStringBase
    {
    public:
        virtual ~SafeStringBase();
        virtual sead::SafeStringBase<T> operator=(sead::SafeStringBase<T> const &);
        virtual void assureTerminationImpl_();

        char* mCharPtr; // _8
    };

    template<typename T>
    class BufferedSafeStringBase : public sead::SafeStringBase<T>
    {
    public:
        virtual ~BufferedSafeStringBase();
        virtual sead::BufferedSafeStringBase<T> operator=(sead::BufferedSafeStringBase<T> const &);
        virtual void assureTerminationImpl_();

        s32 formatImpl_(T *, s32, T const *, s32);
        s32 formatV(T const *, s32);
        s32 format(T const *, ...);
        s32 appendWithFormatV(T const *, s32);
        s32 appendWithFormat(T const *, ...);

        char* mFormattedString; // _10
    };

    template<char16_t T>
    class FixedSafeString : public sead::BufferedSafeStringBase<char16_t>
    {
    public:
        virtual void assureTerminationImpl_();
    };

    template <char16_t T>
    class WFixedSafeString : public sead::BufferedSafeStringBase<char16_t>
    {
    public:
        virtual ~WFixedSafeString();
        virtual sead::WFixedSafeString<T> operator=(sead::SafeStringBase<char16_t> const &);
    };

    template <char16_t T>
    class WFormatFixedSafeString : public sead::WFixedSafeString<T>
    {
    public:
        virtual ~WFormatFixedSafeString();
        virtual sead::WFormatFixedSafeString<T> operator=(sead::SafeStringBase<char16_t> const &);
    };

    template<typename T>
    class HeapSafeStringBase : public sead::BufferedSafeStringBase<char16_t>
    {
    public:
        HeapSafeStringBase(sead::Heap *,sead::SafeStringBase<char> const &, s32);
        virtual ~HeapSafeStringBase();
        virtual sead::SafeStringBase<T> operator=(sead::SafeStringBase<T> const &);
    };
};