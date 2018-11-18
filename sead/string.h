#pragma once

namespace sead
{
    template<typename T>
    class SafeStringBase
    {
        public:
        virtual ~SafeStringBase();
        virtual operator=(sead::SafeStringBase<T> const &);
        virtual void assureTerminationImpl_();

        u64* mCharPtr; // _8
        u64* _10;
    };

    template<typename T>
    class BufferedSafeStringBase : sead::SafeStringBase
    {
        public:
        virtual ~BufferedSafeStringBase();
        virtual operator=(sead::BufferedSafeStringBase<T> const &);
        virtual void assureTerminationImpl_();

        u32 formatImpl_(T *, s32, T const *, s32);
        u32 formatV(T const *, s32);
        u32 format(T const *, ...);
        u32 appendWithFormatV(T const *, s32);
        u32 appendWithFormat(T const *, ...);
    };

    template<typename T>
    class FixedSafeString : sead::BufferedSafeStringBase
    {
        public:
        virtual void assureTerminationImpl_();
    };
};