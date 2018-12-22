#pragma once

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
};