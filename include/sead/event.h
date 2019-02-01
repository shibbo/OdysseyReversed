/**
 * @file event.h
 * @brief Basic thread / core events.
 */

#pragma once

#include "disposer.h"
#include "heap.h"
#include "tick.h"
#include "nn/os.h"

namespace sead
{
    class Event : public sead::IDisposer
    {
    public:
        Event();
        Event(bool);
        Event(sead::Heap *);
        Event(sead::Heap *, sead::IDisposer::HeapNullOption);
        Event(sead::Heap *, bool);
        Event(sead::Heap *, sead::IDisposer::HeapNullOption, bool);

        virtual ~Event();

        void initialize(bool);
        void wait();
        void wait(sead::TickSpan);
        void setSignal();
        void resetSingle();

        nn::os::LightEventType* mType; // _20
    };
};