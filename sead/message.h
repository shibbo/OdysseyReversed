/**
 * @file message.h
 * @brief Message Query Implementations.
 */

#pragma once

#include "heap.h"
#include "string.h"
#include "message/message.h"

namespace sead
{
    class MessageSetBase
    {
    public:
        virtual ~MessageSetBase();

        bool initialize(void *, sead::Heap *);
        void* allocForLibms_(u64);
        void freeForLibms_(void *);
        void finalize();
        u64* getInitializeData() const;
        s32 calcTextSizeByIndex(s32) const;
        bool searchTextLabelByIndex(sead::BufferedSafeStringBase<char> *, s32 idx) const;

        MessageBinary* mBinary; // _8
        u32 _10;
    };

    class MessageProject
    {
    public:
        virtual ~MessageProject();

        bool initialize(void *, sead::Heap *);
        void* allocForLibms_(u64);
        void freeForLibms_(void *);
        void finalize();
        u64* getInitializeData() const;

        MessageProject* mProject; // _8
        u32 _10;
        u32 _14;
        u64 _18;
        u32 _20;
        u32 _24;
        u64 _28;
        u32 _30;
        u32 _34;
        u64 _38;
        u32 mNumContents;

        static sead::Heap* sHeap;
    };
};