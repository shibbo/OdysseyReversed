/**
 * @file delegate.h
 * @brief Delegate classes.
 */

#pragma once

#include "list.h"

namespace sead
{
    class Heap;

    template<typename T>
    class Delegate
    {
    public:
        void invoke();
        void clone(sead::Heap *) const;
    };

    template<typename T>
    class DelegateEvent
    {
    public:

        class Slot
        {
        public:
            virtual ~Slot();

            u64 _0;
            u64 _8;
            u64 _10;
            u64 _18;
            sead::ListNode mNode; // _20
            u64 _30;
            u64 _38;
            u8 _40[0x6C-0x40];
        };

        virtual ~DelegateEvent();
    };

    template<typename T, typename T2>
    class Delegate1
    {
    public:
        void invoke(T2 *);
        void clone(sead::Heap *) const;
    };

    template<typename T, typename T2, typename T3>
    class Delegate2
    {
    public:
        void invoke(T2 *, T3);
        void clone(sead::Heap *) const;
    };

    template<typename T>
    class IDelegate1
    {
    public:
        u64* clone(sead::Heap *);
    };

    template<typename T, typename T2>
    class IDelegate2
    {
        public:
        u64* clone(sead::Heap *);
    };

    template<typename T>
    class AnyDelegate1Const { };
};