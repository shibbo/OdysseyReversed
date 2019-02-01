/**
 * @file stack.h
 * @brief Stack Trace API.
 */

#pragma once

#include "buffer.h"
#include "heap.h"
#include "string.h"
#include "types.h"

namespace sead
{
    class StackTraceBase
    {
    public:
        StackTraceBase();

        virtual ~StackTraceBase();
        // none of these pure virtual classes are ever defined in this game
        // Splatoon 2 implements these, though
        virtual u64* get(s32) const = 0;
        virtual u32 size() const = 0;
        virtual void clear() = 0;
        virtual void push_(u64 addr) = 0;
        virtual bool isFull_() = 0;

        void trace(void const *);
    };

    class StackSymbolResolver
    {
    public:
        StackSymbolResolver();
        ~StackSymbolResolver();

        void loadMapFile(sead::Heap *, sead::SafeStringBase<char> const &);
        void unload();
        void resolveOne(sead::BufferedSafeStringBase<char> *, sead::BufferedSafeStringBase<char> *, u64) const;
        static bool isIllegalSymbolAddress(u64, u64);
        void resolve(sead::Buffer<sead::BufferedSafeStringBase<char> *> *, sead::Buffer<sead::BufferedSafeStringBase<char> *> *, sead::StackTraceBase const &) const;

        u64 _0;
        u32 _8;
    };

    class StackPrinter
    {
    public:
        StackPrinter();
        ~StackPrinter();

        void show(sead::StackTraceBase const &, sead::Buffer<sead::BufferedSafeStringBase<char> *> const *, sead::Buffer<sead::BufferedSafeStringBase<char> *> const *) const;
    };
};